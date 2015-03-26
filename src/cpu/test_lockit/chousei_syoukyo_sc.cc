int COMAI_HI::chousei_syoukyo_sc(int ba[][TAT_SIZE], int setti_basyo[], int* score)
{
    int rensa_rate[19] = { 0, 8, 16, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512 };
    int color_rate[5] = { 0, 3, 6, 12, 24 };
    int renketsu[19][5] {};
    int colnum;
    int renketsunum;
    int renketsubonus[19] = { 0 };
    int rate;
    int color;

    int num = 0;
    int numa = 0;
    int numb = 0;
    int point[6][12] {};
    int i, j;
    int syo = 1;
    int kiept[6] = { 0 };
    int rakkaflg[6] = { 0 };
    int n;
    int a, b, c, d;
    int keshiko = 0;
    int chain;
    *score = 0;

    a = setti_basyo[0];
    b = setti_basyo[1];
    c = setti_basyo[2];
    d = setti_basyo[3];
    if ((b < 12) && (b >= 0)) {
        saiki(ba, point, a, b, &numa, ba[a][b]);
    }
    if ((d < 12) && (d >= 0)) {
        if (point[c][d] == 0) {
            saiki(ba, point, c, d, &numb, ba[c][d]);
        }
    }
    (chain) = 0;
    if ((numa < 4) && (numb < 4))
        return 0;
    if (numa > 3) {
        color = ba[a][b];
        renketsu[chain][color - 1] += numa;
        if (numa > 10)
            renketsubonus[chain] += 10; // bugggggg 111102
        else if (numa > 4)
            renketsubonus[chain] += numa - 3;
        syou(ba, a, b, ba[a][b], rakkaflg);
        keshiko += numa;
    }
    if (numb > 3) {
        color = ba[c][d];
        renketsu[chain][color - 1] += numb;
        if (numb > 10)
            renketsubonus[chain] += 10; // bugggggg 111102
        else if (numb > 4)
            renketsubonus[chain] += numb - 3;
        syou(ba, c, d, ba[c][d], rakkaflg);
        keshiko += numb;
    }

    for (i = 0; i < 6; i++) {
        kiept[i] = 12;
        if (rakkaflg[i] == 1) {
            n = 0;
            for (j = 0; j < 13; j++) {
                if (ba[i][j] == 0) {
                    if (n == 0)
                        kiept[i] = j;
                    n++;
                } else if (n != 0) {
                    ba[i][j - n] = ba[i][j];
                    ba[i][j] = 0;
                }
            }
        }
    }
    (chain) = 1;

    while (syo) {
        syo = 0;
        memset(point, 0, sizeof(point));
        rakkaflg[0] = 0;
        rakkaflg[1] = 0;
        rakkaflg[2] = 0;
        rakkaflg[3] = 0;
        rakkaflg[4] = 0;
        rakkaflg[5] = 0;
        for (i = 0; i < 6; i++) {
            for (j = kiept[i]; j < 12; j++) {
                if (ba[i][j] == 0)
                    continue;
                if ((point[i][j] != 1) && (ba[i][j] != 6)) {
                    saiki(ba, point, i, j, &num, ba[i][j]);
                    if (num > 3) {
                        syo = 1;
                        color = ba[i][j];
                        renketsu[chain][color - 1] += num;
                        if (num > 10)
                            renketsubonus[chain] += 10; // bugggggg 111102
                        else if (num > 4)
                            renketsubonus[chain] += num - 3;
                        syou(ba, i, j, ba[i][j], rakkaflg);
                        keshiko += num;
                    }
                    num = 0;
                }
            }
        }
        for (i = 0; i < 6; i++) {
            kiept[i] = 12;
            if (rakkaflg[i] == 1) {
                n = 0;
                for (j = 0; j < 13; j++) {
                    if (ba[i][j] == 0) {
                        if (n == 0)
                            kiept[i] = j;
                        n++;
                    } else if (n != 0) {
                        ba[i][j - n] = ba[i][j];
                        ba[i][j] = 0;
                    }
                }
            }
        }
        if (syo == 1)
            chain += 1;
    }
    for (i = 0; i < (chain); i++) {
        rate = 0;
        colnum = 0;
        renketsunum = 0;
        for (j = 0; j < 5; j++) {
            colnum += (renketsu[i][j] != 0);
            renketsunum += renketsu[i][j];
        }
        rate = color_rate[colnum - 1] + renketsubonus[i] + rensa_rate[i];
        if (rate == 0)
            rate = 1;
        *score += renketsunum * rate * 10;
    }
    return keshiko;
}
