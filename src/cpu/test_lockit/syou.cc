
int COMAI_HI::syou(int ba[][TAT_SIZE], int x, int y, int incol, int flg[])
{
    ba[x][y] = 0;
    flg[x] = 1;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left(ba, x - 1, y, incol, flg);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up(ba, x, y + 1, incol, flg);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right(ba, x + 1, y, incol, flg);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down(ba, x, y - 1, incol, flg);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_right(int ba[][TAT_SIZE], int x, int y, int incol, int flg[])
{
    ba[x][y] = 0;
    flg[x] = 1;
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up(ba, x, y + 1, incol, flg);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right(ba, x + 1, y, incol, flg);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down(ba, x, y - 1, incol, flg);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_left(int ba[][TAT_SIZE], int x, int y, int incol, int flg[])
{
    ba[x][y] = 0;
    flg[x] = 1;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left(ba, x - 1, y, incol, flg);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up(ba, x, y + 1, incol, flg);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down(ba, x, y - 1, incol, flg);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_up(int ba[][TAT_SIZE], int x, int y, int incol, int flg[])
{
    ba[x][y] = 0;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left(ba, x - 1, y, incol, flg);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up(ba, x, y + 1, incol, flg);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right(ba, x + 1, y, incol, flg);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    return 0;
}
int COMAI_HI::syou_down(int ba[][TAT_SIZE], int x, int y, int incol, int flg[])
{
    ba[x][y] = 0;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left(ba, x - 1, y, incol, flg);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right(ba, x + 1, y, incol, flg);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down(ba, x, y - 1, incol, flg);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_downx(int ba[][TAT_SIZE], int x, int y, int incol, int flg[], int* num)
{
    *num += 1;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left_num(ba, x - 1, y, incol, flg, num);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right_num(ba, x + 1, y, incol, flg, num);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down_num(ba, x, y - 1, incol, flg, num);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_right_num(int ba[][TAT_SIZE], int x, int y, int incol, int flg[], int* num)
{
    ba[x][y] = 0;
    flg[x] = 1;
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up_num(ba, x, y + 1, incol, flg, num);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right_num(ba, x + 1, y, incol, flg, num);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down_num(ba, x, y - 1, incol, flg, num);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_left_num(int ba[][TAT_SIZE], int x, int y, int incol, int flg[], int* num)
{
    ba[x][y] = 0;
    flg[x] = 1;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left_num(ba, x - 1, y, incol, flg, num);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up_num(ba, x, y + 1, incol, flg, num);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down_num(ba, x, y - 1, incol, flg, num);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_up_num(int ba[][TAT_SIZE], int x, int y, int incol, int flg[], int* num)
{
    ba[x][y] = 0;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left_num(ba, x - 1, y, incol, flg, num);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_up_num(ba, x, y + 1, incol, flg, num);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right_num(ba, x + 1, y, incol, flg, num);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    return 0;
}
int COMAI_HI::syou_down_num(int ba[][TAT_SIZE], int x, int y, int incol, int flg[], int* num)
{
    ba[x][y] = 0;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_left_num(ba, x - 1, y, incol, flg, num);
    if ((x != 0) && (ba[x - 1][y] == 6)) {
        ba[x - 1][y] = 0;
        flg[x - 1] = 1;
    }
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_right_num(ba, x + 1, y, incol, flg, num);
    if ((x != 5) && (ba[x + 1][y] == 6)) {
        ba[x + 1][y] = 0;
        flg[x + 1] = 1;
    }
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_down_num(ba, x, y - 1, incol, flg, num);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
