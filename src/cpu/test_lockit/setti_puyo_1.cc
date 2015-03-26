int COMAI_HI::setti_puyo_1(int ba[][TAT_SIZE], int eex, int eecol)
{
    int j;
    int oita = 0;
    int num = 0;
    int setti_basyoy;
    for (j = 0; j < 12; j++) {
        if (ba[eex][j] == 0) {
            ba[eex][j] = eecol;
            setti_basyoy = j;
            oita = 1;
            break;
        }
    }
    if (oita == 0)
        return 1;
    saiki_4(ba, eex, setti_basyoy, &num, eecol);
    if (num > 3)
        return 1;

    return 0;
}

int COMAI_HI::saiki_4(int ba[][TAT_SIZE], int x, int y, int* num, int incol)
{
    ba[x][y] = 0;
    *num += 1;
    if (*num > 3) {
        ba[x][y] = incol;
        return 0;
    }
    if ((x != 0) && (incol == ba[x - 1][y]))
        saiki_4(ba, x - 1, y, num, incol);
    if ((y != 11) && (incol == ba[x][y + 1]))
        saiki_4(ba, x, y + 1, num, incol);
    if ((x != 5) && (incol == ba[x + 1][y]))
        saiki_4(ba, x + 1, y, num, incol);
    if ((y != 0) && (incol == ba[x][y - 1]))
        saiki_4(ba, x, y - 1, num, incol);
    ba[x][y] = incol;
    return 0;
}
