void COMAI_HI::putPuyos(int field[][TAT_SIZE], int id, int nx1, int nx2, int places[])
{
    int x = idToX(id), r = idToR(id);

    if (r == 0) {
        for (int y = 0; y < FieldConstant::HEIGHT + 1; ++y) {
            if (field[x][y] == TEST_PUYO_COLOR_EMPTY) {
                field[x][y] = nx1;
                field[x][y + 1] = nx2;
                places[0] = x;
                places[1] = y;
                places[2] = x;
                places[3] = y + 1;
                break;
            }
        }
    } else if (r == 2) {
        for (int y = 0; y < FieldConstant::HEIGHT + 1; ++y) {
            if (field[x][y] == TEST_PUYO_COLOR_EMPTY) {
                field[x][y] = nx2;
                field[x][y + 1] = nx1;
                places[0] = x;
                places[1] = y + 1;
                places[2] = x;
                places[3] = y;
                break;
            }
        }
    } else {
        for (int y = 0; y < FieldConstant::HEIGHT + 1; ++y) {
            if (field[x][y] == TEST_PUYO_COLOR_EMPTY) {
                field[x][y] = nx1;
                places[0] = x;
                places[1] = y;
                break;
            }
        }
        int xx = x + (r == 1) ? 1 : -1;
        for (int y = 0; y < FieldConstant::HEIGHT + 1; ++y) {
            if (field[xx][y] == TEST_PUYO_COLOR_EMPTY) {
              field[xx][y] = nx1;
              places[2] = xx;
              places[3] = y;
              break;
            }
        }
    }
}
