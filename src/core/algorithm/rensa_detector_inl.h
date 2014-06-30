#ifndef CORE_ALGORITHM_RENSA_DETECTOR_INL_H_
#define CORE_ALGORITHM_RENSA_DETECTOR_INL_H_

template<typename SimulationCallback>
void RensaDetector::findRensas(const CoreField& field, RensaDetector::Mode mode, SimulationCallback callback)
{
    for (int x = 1; x <= CoreField::WIDTH; ++x) {
        for (int y = field.height(x); y >= 1; --y) {
            switch (mode) {
            case Mode::DROP:
                tryDropFire(x, y, field, callback);
                break;
            case Mode::FLOAT:
                tryFloatFire(x, y, field, callback);
                break;
            }
        }
    }
}

template<typename SimulationCallback>
static inline void tryDropFire(int x, int y, const CoreField& field, const SimulationCallback& callback)
{
    PuyoColor c = field.color(x, y);

    DCHECK(c != PuyoColor::EMPTY);
    if (c == PuyoColor::OJAMA)
        return;

    // Drop puyo on
    for (int d = -1; d <= 1; ++d) {
        if (x + d <= 0 || CoreField::WIDTH < x + d)
            continue;
        if (d == 0) {
            if (field.color(x, y + 1) != PuyoColor::EMPTY)
                continue;
        } else {
            if (field.color(x + d, y) != PuyoColor::EMPTY)
                continue;
        }

        CoreField f(field);
        int necessaryPuyos = 0;
        while (necessaryPuyos <= 4 && f.countConnectedPuyos(x, y) < 4 && f.height(x + d) <= 13) {
            f.dropPuyoOn(x + d, c);
            ++necessaryPuyos;
        }

        if (necessaryPuyos > 4)
            continue;

        callback(&f, x + d, c, necessaryPuyos);
    }

}

template<typename SimulationCallback>
static inline void tryFloatFire(
    int x, int y, const CoreField& field, const SimulationCallback& callback) {
  PuyoColor c = field.color(x, y);

  DCHECK(c != PuyoColor::EMPTY);
  if (c == PuyoColor::OJAMA)
    return;

  int necessaryPuyos = 4 - field.countConnectedPuyos(x, y);
  int restPuyos = necessaryPuyos;
  CoreField f(field);

  int dx = x - 1;
  // float puyo col dx
  for (; dx <= x + 1 && restPuyos > 0; ++dx) {
    if (dx <= 0 || CoreField::WIDTH < dx) {
     continue;
    }


    // Check y
    if (dx != x) {
      if (field.color(dx, y) != PuyoColor::EMPTY) {
        continue;
      } else { // restPuyos must be more than 0
        f.unsafeSet(dx, y, c);
        --restPuyos;
      }
    }

    int dy_min = y - 1;
    // Check under y
    for (; restPuyos > 0 && dy_min > 0 && field.color(dx ,dy_min) == PuyoColor::EMPTY;
        --dy_min) {
      f.unsafeSet(dx, dy_min, c);
      --restPuyos;
    }

    // Check over y
    for (int dy = y + 1;
        restPuyos > 0 && dy <= 12 && field.color(dx ,dy) == PuyoColor::EMPTY; ++dy) {
      f.unsafeSet(dx, dy, c);
      --restPuyos;
    }

    // Fill ojama
    for(; dy_min > 0 && field.color(dx, dy_min) == PuyoColor::EMPTY; --dy_min) {
      f.unsafeSet(dx, dy_min, PuyoColor::OJAMA);
    }

    f.recalcHeightOn(dx);
  }

  if (restPuyos <= 0) {
    callback(&f, dx, c, necessaryPuyos);
  }
}

#endif
