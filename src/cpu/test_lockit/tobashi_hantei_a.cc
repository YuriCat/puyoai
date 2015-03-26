int COMAI_HI::tobashi_hantei_a(int ba2[][TAT_SIZE], int aa, int nx1, int nx2)
{
    if (nx1 == nx2) {
        if (((aa > 5) && (aa < 12)) || ((aa > 13) && (aa < 19)))
            return 1;
    }
    if (ba2[0][11] != 0) {
        if ((aa == 0) || (aa == 6) || (aa == 12) || (aa == 17))
            return 1;
    }
    if (ba2[1][11] != 0) {
        if ((aa == 0) || (aa == 6) || (aa == 12) || (aa == 17))
            return 1;
        if ((aa == 1) || (aa == 7) || (aa == 13) || (aa == 18))
            return 1;
    }
    if (ba2[3][11] != 0) {
        if ((aa == 3) || (aa == 9) || (aa == 14) || (aa == 19))
            return 1;
        if ((aa == 4) || (aa == 10) || (aa == 15) || (aa == 20))
            return 1;
        if ((aa == 5) || (aa == 11) || (aa == 16) || (aa == 21))
            return 1;
    }
    if (ba2[4][11] != 0) {
        if ((aa == 4) || (aa == 10) || (aa == 15) || (aa == 20))
            return 1;
        if ((aa == 5) || (aa == 11) || (aa == 16) || (aa == 21))
            return 1;
    }
    if (ba2[5][11] != 0) {
        if ((aa == 5) || (aa == 11) || (aa == 16) || (aa == 21))
            return 1;
    }
    return 0;
}
