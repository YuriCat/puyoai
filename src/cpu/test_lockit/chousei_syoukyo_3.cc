int COMAI_HI::chousei_syoukyo_3(int bass[][TAT_SIZE], int[], int* poi2s, int* score, int tokus, int i2,
                                int j2)
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
    int point[6][12] {};
    int i, j;
    int syo = 1;
    int kiept[6] = { 0 };
    int rakkaflg[6] = { 0 };
    int n;
    int chain = 1;
    int rakka_ruiseki = 0;
    *score = 0;
    rakkaflg[0] = 0;
    rakkaflg[1] = 0;
    rakkaflg[2] = 0;
    rakkaflg[3] = 0;
    rakkaflg[4] = 0;
    rakkaflg[5] = 0;
    color = bass[i2][j2];
    if (tokus < 5) {
        syou_downx(bass, i2, j2 + 1, bass[i2][j2], rakkaflg, &num);
    } else if (tokus < 7) {
        syou_downx(bass, i2 + 1, j2, bass[i2][j2], rakkaflg, &num);
    } else if (tokus == 7) {
        syou_downx(bass, i2 - 1, j2, bass[i2][j2], rakkaflg, &num);
    }
    renketsu[0][color - 1] = num;
    if (num > 10)
        renketsubonus[0] += 10; // bugggggg 111102
    else if (num > 4)
        renketsubonus[0] = num - 3;

    num = 0;

    kiept[0] = 0;
    kiept[1] = 0;
    kiept[2] = 0;
    kiept[3] = 0;
    kiept[4] = 0;
    kiept[5] = 0;
    for (i = 0; i < 6; i++) {
        kiept[i] = 12;
        if (rakkaflg[i] == 1) {
            n = 0;
            for (j = 0; j < 13; j++) {
                if (bass[i][j] == 0) {
                    if (n == 0)
                        kiept[i] = j;
                    n++;
                } else if (n != 0) {
                    bass[i][j - n] = bass[i][j];
                    bass[i][j] = 0;
                }
            }
            rakka_ruiseki += n;
        }
    }

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
                if (point[i][j] != 0)
                    continue;
                if (bass[i][j] == 0)
                    break;
                if (bass[i][j] != 6) {
                    saiki(bass, point, i, j, &num, bass[i][j]);
                    if (num > 3) {
                        syo = 1;
                        color = bass[i][j];
                        renketsu[chain][color - 1] += num;
                        if (num > 10)
                            renketsubonus[chain] += 10; // bugggggg 111102
                        else if (num > 4)
                            renketsubonus[chain] += num - 3;
                        (*poi2s) = (*poi2s) - num * num;
                        syou(bass, i, j, bass[i][j], rakkaflg);
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
                    if (bass[i][j] == 0) {
                        if (n == 0)
                            kiept[i] = j;
                        n++;
                    } else if (n != 0) {
                        bass[i][j - n] = bass[i][j];
                        bass[i][j] = 0;
                    }
                }
                rakka_ruiseki += n;
            }
        }
        chain++;
    } // while
    chain--;

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
    (*poi2s) = (*poi2s) - rakka_ruiseki * ruiseki_point;
    return chain;
}
