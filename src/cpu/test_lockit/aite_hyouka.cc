int COMAI_HI::aite_hyouka(int ba3[][TATE], int nex, int nex2, int nnx, int nnx2)
{
    int ba2[6][TAT_SIZE] {};
    int ba[6][TAT_SIZE] {};
    int ba_a[6][TAT_SIZE] {};
    int ba_b[6][TAT_SIZE] {};
    int ba_d[6][TAT_SIZE] {};
    int point[6][12];
    int i, j;
    int num;
    int n;
    int syo;
    int chain;
    int nx1, nx2, nn1, nn2;
    int nk1, nk2;

    int aa, bb, dd;
    int rakkaflg[6];
    int kiept[6];
    int keshiko_aa = 0;
    int keshiko_bb = 0;
    int keshiko_dd = 0;
    int keshikos;

    int setti_basyo[4];
    int dabuchk[20];
    int ichiren_kesi;
    int score_aa = 0;
    int score_bb = 0;
    int score_dd = 0;
    int scores = 0;
    int irokosuu = 0;

    int cc;
    int chain2 = 0;

    aite_rensa_score = 0;
    aite_rensa_score_cc = 0;
    nocc_aite_rensa_score = 0;

    nx1 = nex;
    nx2 = nex2;
    nn1 = nnx;
    nn2 = nnx2;
    copyField(ba3, ba2);
    irokosuu = countColoredPuyos(ba3);

    for (aa = 0; aa < 22; aa++) {
        if (tobashi_hantei_a(ba2, aa, nx1, nx2))
            continue;
        memcpy(ba_a, ba2, sizeof(ba));
        putPuyos(ba_a, aa, nx1, nx2, setti_basyo);
        keshiko_aa = chousei_syoukyo_2(ba_a, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score_aa);
        if (ba_a[2][11] != 0)
            continue;
        for (bb = 0; bb < 22; bb++) {
            if (tobashi_hantei_a(ba_a, bb, nn1, nn2))
                continue;
            memcpy(ba_b, ba_a, sizeof(ba));
            putPuyos(ba_b, bb, nn1, nn2, setti_basyo);
            keshiko_bb = chousei_syoukyo_2(ba_b, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score_bb);
            if (ba_b[2][11] != 0)
                continue;

            for (cc = 1; cc < 5; cc++) {
                nk1 = cc;
                nk2 = cc;
                for (dd = 0; dd < 6; dd++) {
                    if (tobashi_hantei_a(ba_b, dd, nk1, nk2))
                        continue;
                    memcpy(ba_d, ba_b, sizeof(ba));
                    putPuyos(ba_d, dd, nk1, nk2, setti_basyo);
                    keshiko_dd = chousei_syoukyo_2(ba_d, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score_dd);
                    if (ba_d[2][11] != 0)
                        continue;

                    scores = score_aa;
                    keshikos = keshiko_aa;
                    if (scores < score_bb) {
                        scores = score_bb;
                        keshikos = keshiko_bb;
                    }
                    if (scores < score_dd) {
                        scores = score_dd;
                        keshikos = keshiko_dd;
                    }

                    if (aite_rensa_score < scores) {
                        aite_rensa_score = scores;
                    }
                    if (keshikos * 2 < irokosuu) {
                        if (nocc_aite_rensa_score < scores) {
                            nocc_aite_rensa_score = scores;
                            moni_kesiko[0] = keshiko_aa;
                            moni_iroko[0] = score_aa;
                            moni_kesiko[1] = keshiko_bb;
                            moni_iroko[1] = score_bb;
                            moni_kesiko[2] = keshiko_dd;
                            moni_iroko[2] = score_dd;
                        }
                    }
                } // dd
            } // cc

            // aaaaaaaa 111119
            for (cc = 0; cc < 25; cc++) {
                memcpy(ba, ba_b, sizeof(ba));
                if (cc == 0) {
                    continue;
                } else if (cc < 7) {
                    for (j = 0; j < 13; j++) {
                        if (ba[cc - 1][j] == 0) {
                            ba[cc - 1][j] = 1;
                            ba[cc - 1][j + 1] = 1;
                            break;
                        }
                    }
                } else if (cc < 13) {
                    for (j = 0; j < 13; j++) {
                        if (ba[cc - 7][j] == 0) {
                            ba[cc - 7][j] = 2;
                            ba[cc - 7][j + 1] = 2;
                            break;
                        }
                    }
                } else if (cc < 19) {
                    for (j = 0; j < 13; j++) {
                        if (ba[cc - 13][j] == 0) {
                            ba[cc - 13][j] = 3;
                            ba[cc - 13][j + 1] = 3;
                            break;
                        }
                    }
                } else if (cc < 25) {
                    for (j = 0; j < 13; j++) {
                        if (ba[cc - 19][j] == 0) {
                            ba[cc - 19][j] = 4;
                            ba[cc - 19][j + 1] = 4;
                            break;
                        }
                    }
                }

                if (ba[1][11] != 0) {
                    if ((cc % 6) == 1)
                        continue;
                }
                if (ba[2][11] != 0) {
                    if ((cc % 6) != 3)
                        continue;
                }
                if (ba[3][11] != 0) {
                    if ((cc % 6) == 5)
                        continue;
                    if (((cc % 6) == 0) && (cc != 0))
                        continue;
                }
                if (ba[4][11] != 0) {
                    if (((cc % 6) == 0) && (cc != 0))
                        continue;
                }

                syo = 1;
                chain2 = 0;
                num = 0;

                kiept[0] = 0;
                kiept[1] = 0;
                kiept[2] = 0;
                kiept[3] = 0;
                kiept[4] = 0;
                kiept[5] = 0;
                while (syo) {
                    syo = 0;
                    memset(point, 0, sizeof(point));
                    for (i = 0; i < 6; i++) {
                        for (j = kiept[i]; j < 12; j++) {
                            if (ba[i][j] == 0)
                                break;
                            if ((point[i][j] != 1) && (ba[i][j] != 6)) {
                                saiki(ba, point, i, j, &num, ba[i][j]);
                                point[i][j] = num;
                                num = 0;
                            }
                        }
                    }
                    rakkaflg[0] = 0;
                    rakkaflg[1] = 0;
                    rakkaflg[2] = 0;
                    rakkaflg[3] = 0;
                    rakkaflg[4] = 0;
                    rakkaflg[5] = 0;
                    for (i = 0; i < 6; i++) {
                        for (j = kiept[i]; j < 12; j++) {
                            if (point[i][j] > 3) {
                                syo = 1;
                                syou(ba, i, j, ba[i][j], rakkaflg);
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
                        chain2++;
                } // while
                if (aite_rensa_score_cc < chain2) {
                    aite_rensa_score_cc = chain2;
                }
            } // cc
        } // bb
    } // aa
    return 0;
}
