
int COMAI_HI::syou_2(int ba[][TAT_SIZE], int x, int y, int incol)
{
    ba[x][y] = 0;
    if ((x != 0) && (ba[x - 1][y] == incol))
        syou_2(ba, x - 1, y, incol);
    if ((x != 0) && (ba[x - 1][y] == 6))
        ba[x - 1][y] = 0;
    if ((y != 11) && (ba[x][y + 1] == incol))
        syou_2(ba, x, y + 1, incol);
    if ((y != 11) && (ba[x][y + 1] == 6))
        ba[x][y + 1] = 0;
    if ((x != 5) && (ba[x + 1][y] == incol))
        syou_2(ba, x + 1, y, incol);
    if ((x != 5) && (ba[x + 1][y] == 6))
        ba[x + 1][y] = 0;
    if ((y != 0) && (ba[x][y - 1] == incol))
        syou_2(ba, x, y - 1, incol);
    if ((y != 0) && (ba[x][y - 1] == 6))
        ba[x][y - 1] = 0;
    return 0;
}
