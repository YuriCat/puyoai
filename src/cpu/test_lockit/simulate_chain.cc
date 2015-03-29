int COMAI_HI::simulateChain(int ba[][TAT_SIZE], int* score, int* quick)
{
    int vanish_puyo_num[19][5] {};
    int renketsu_bonus[19] {};
    int vanish_height[6] {};

    (*quick) = 1;
    int chain = 0;
    for (bool vanished = true; vanished;) {
        int point[6][12] {};
        int rakkaflg[6] {};

        vanished = false;
        for (int i = 0; i < 6; ++i)
          rakkaflg[i] = 0;

        for (int i = 0; i < 6; i++) {
            for (int j = vanish_height[i]; j < 12; j++) {
                if (point[i][j] != 0)
                    continue;
                if (ba[i][j] == TEST_PUYO_COLOR_EMPTY)
                    break;
                if (ba[i][j] == TEST_PUYO_COLOR_OJAMA)
                  continue;

                int num = 0;
                int color = ba[i][j];
                saiki(ba, point, i, j, &num, color);
                if (num < 4)
                  continue;

                vanished = true;
                vanish_puyo_num[chain][color - 1] += num;
                if (num > 10)
                  renketsu_bonus[chain] += 10;
                else if (num > 4)
                  renketsu_bonus[chain] += num - 3;
                vanish(ba, i, j, ba[i][j], rakkaflg);
            }
        }

        if (vanished)
            (*quick) = 1;
        for (int i = 0; i < 6; i++) {
            vanish_height[i] = 12;
            if (rakkaflg[i] == 0)
              continue;

            int distance = 0;
            for (int j = 0; j < 13; j++) {
                if (ba[i][j] == TEST_PUYO_COLOR_EMPTY) {
                    if (distance == 0)
                        vanish_height[i] = j;
                    distance++;
                } else if (distance != 0) {
                    ba[i][j - distance] = ba[i][j];
                    ba[i][j] = 0;
                    *quick = 0;
                }
            }
        }
        if (vanished)
            chain++;
    }

    static const int kRensaRate[] = { 0, 8, 16, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512 };
    static const int kColorRate[] = { 0, 3, 6, 12, 24 };

    *score = 0;
    for (int i = 0; i < chain; i++) {
        int bonus = 0;
        int color_num = 0;
        int vanish_num = 0;
        for (int j = 0; j < 5; j++) {
            color_num += (vanish_puyo_num[i][j] != 0);
            vanish_num += vanish_puyo_num[i][j];
        }
        bonus = kColorRate[color_num - 1] + renketsu_bonus[i] + kRensaRate[i];
        if (bonus == 0)
            bonus = 1;
        *score += vanish_num * bonus * 10;
    }
    return chain;
}
