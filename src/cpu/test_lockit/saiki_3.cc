int COMAI_HI::saiki_3(int ba[][TAT_SIZE], int point[][12], int x, int y, int* num, int incol)
{
    point[x][y] = 1;
    *num += 1;
    if ((x != 0) && (incol == ba[x - 1][y]) && (point[x - 1][y] != 1))
        saiki_3_left(ba, point, x - 1, y, num, incol);
    if ((y != 11) && (incol == ba[x][y + 1]) && (point[x][y + 1] != 1))
        saiki_3_up(ba, point, x, y + 1, num, incol);
    if ((x != 5) && (incol == ba[x + 1][y]) && (point[x + 1][y] != 1))
        saiki_3_right(ba, point, x + 1, y, num, incol);
    if ((y != 0) && (incol == ba[x][y - 1]) && (point[x][y - 1] != 1))
        saiki_3_down(ba, point, x, y - 1, num, incol);
    return 0;
}
int COMAI_HI::saiki_3_right(int ba[][TAT_SIZE], int point[][12], int x, int y, int* num, int incol)
{
    point[x][y] = 1;
    *num += 1;
    if ((y != 11) && (incol == ba[x][y + 1]) && (point[x][y + 1] != 1))
        saiki_3_up(ba, point, x, y + 1, num, incol);
    if ((x != 5) && (incol == ba[x + 1][y]) && (point[x + 1][y] != 1))
        saiki_3_right(ba, point, x + 1, y, num, incol);
    if ((y != 0) && (incol == ba[x][y - 1]) && (point[x][y - 1] != 1))
        saiki_3_down(ba, point, x, y - 1, num, incol);
    return 0;
}
int COMAI_HI::saiki_3_left(int ba[][TAT_SIZE], int point[][12], int x, int y, int* num, int incol)
{
    point[x][y] = 1;
    *num += 1;
    if ((x != 0) && (incol == ba[x - 1][y]) && (point[x - 1][y] != 1))
        saiki_3_left(ba, point, x - 1, y, num, incol);
    if ((y != 11) && (incol == ba[x][y + 1]) && (point[x][y + 1] != 1))
        saiki_3_up(ba, point, x, y + 1, num, incol);
    if ((y != 0) && (incol == ba[x][y - 1]) && (point[x][y - 1] != 1))
        saiki_3_down(ba, point, x, y - 1, num, incol);
    return 0;
}
int COMAI_HI::saiki_3_up(int ba[][TAT_SIZE], int point[][12], int x, int y, int* num, int incol)
{
    point[x][y] = 1;
    *num += 1;
    if ((x != 0) && (incol == ba[x - 1][y]) && (point[x - 1][y] != 1))
        saiki_3_left(ba, point, x - 1, y, num, incol);
    if ((y != 11) && (incol == ba[x][y + 1]) && (point[x][y + 1] != 1))
        saiki_3_up(ba, point, x, y + 1, num, incol);
    if ((x != 5) && (incol == ba[x + 1][y]) && (point[x + 1][y] != 1))
        saiki_3_right(ba, point, x + 1, y, num, incol);
    return 0;
}
int COMAI_HI::saiki_3_down(int ba[][TAT_SIZE], int point[][12], int x, int y, int* num, int incol)
{
    point[x][y] = 1;
    *num += 1;
    if ((x != 0) && (incol == ba[x - 1][y]) && (point[x - 1][y] != 1))
        saiki_3_left(ba, point, x - 1, y, num, incol);
    if ((x != 5) && (incol == ba[x + 1][y]) && (point[x + 1][y] != 1))
        saiki_3_right(ba, point, x + 1, y, num, incol);
    if ((y != 0) && (incol == ba[x][y - 1]) && (point[x][y - 1] != 1))
        saiki_3_down(ba, point, x, y - 1, num, incol);
    return 0;
}
