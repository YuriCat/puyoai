int COMAI_HI::gtr(int f[][TAT_SIZE])
{
    int score = 0;

    static const int same_position[][4] = {
        {0, 0, 1, 0}, {0, 0, 1, 2}, {0, 0, 2, 1},  // A     #BA....#
        {1, 0, 1, 2}, {1, 0, 2, 1}, {1, 2, 2, 1},  // A for #BBA...#
        {0, 1, 0, 2}, {0, 1, 1, 1}, {1, 1, 0, 2},  // B     #AA....#
    }
    for (auto p : same_position) {
        int x0 = p[0], y0 = p[1], x1 = p[2], y1 = p[3];
        int c0 = f[x0][y0], c1 = f[x1][y1];
        if (c0 != TEST_PUYO_COLOR_EMPTY && c1 != TEST_PUYO_COLOR_EMPTY) {
          score += (c0 == c1) ? 1000 : -1000;
        }
    }

    static const int diff_position[][5] = {
        {0, 2, 0, 3, 2000}, {1, 2, 1, 3, 500}, {1, 2, 2, 2, 500},
        {1, 0, 2, 0, 1000}, {2, 1, 2, 0, 1000}, {2, 1, 2, 2, 500},
    };
    for (auto p : diff_position) {
        int x0 = p[0], y0 = p[1], x1 = p[2], y1 = p[3];
        int c0 = f[x0][y0], c1 = f[x1][y1];
        int cost = p[4];
        if (c0 != TEST_PUYO_COLOR_EMPTY && c0 == c1) {
          score -= cost;
        }
    }

    return score;
}
