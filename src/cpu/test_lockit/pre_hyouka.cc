int COMAI_HI::pre_hyouka(int ba3[6][TATE], int nex, int nex2, int nnx, int nnx2, int zenkesi_own, int aite_ba[6][TATE],
                         int zenkesi_aite, int fast)
{
    int ba[6][TAT_SIZE] {};
    int ba_a[6][TAT_SIZE] {};
    int ba2[6][TAT_SIZE] {};
    int bass[6][TAT_SIZE];
    int point[6][12];
    int point2[6][12] = {
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}};
    int i, j;
    int num = 0;
    int chain;
    int nx1, nx2, nn1, nn2;
    int aa, bb;
    int pois, poi2s;
    int hym[22];
    int zenchk;
    int zenchain;
    int dabuchk[20];
    int i2, j2;
    int dd, nk1, nk2, num2;
    int keschk = 0;
    int maxch = 0, maxach;
    int tokus;
    int saisoku;
    int teimen[6];
    int zenkes[22][22][22] {};
    int zenke[22] = { 0 };
    int setti_basyo[4];
    int myf_kosuu_kesi = 0, myf_kosuu_iro = 0;
    int kurai_large, kurai_middle, kurai_small;
    int aite_kosuu_iro = 0, kes2;
    int yokotate = 4;
    int yokopoint = 200;
    int ichiren_kesi = 0;

    int ee, eex, eecol;
    int ba_ee[6][TAT_SIZE];
    int keshiko_aa, keshiko_bb, keshiko_dd;

    int ccolor, cplace, coita, cyy = 0;
    int score = 0, maxscore = 0;
    int score_tmp, score_mm = 0;
    int kuraichk = 0;
    int quick = 0;
    int score_aonly = -10, score_bonly = -10;
    int taiouchk = 0;
    int kurai_mini = 0;
    int score_tmp2, score_tai = -10;
    int aveteimen = 0;
    int hakkatakasa = 0;
    int wariko_taiou = 0;
    int chig_aa, chig_bb, chig_dd;
    int aite_ojama = 0;
    int tanpatu_on = 0;

    hukks++;

    score_max = 0;
    mmmax = -1;
    score_aa = -10;
    aa_max_score = 0;
    zenchk = 0;
    zenchain = 0;

    if (kougeki_on == 1) {
        kougeki_on = 0;
        kougeki_edge = 1;
    }

    myf_kosuu = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 13; j++) {
            if (ba3[i][j] != 0) {
                myf_kosuu++;
            }
            if ((ba3[i][j] != 0) && (ba3[i][j] < 6)) {
                myf_kosuu_iro++;
            }
        }
    }

    if (aite_hakka_rensa > 3)
        saisoku_flag = 0;
    saisoku = (saisoku_flag) && (myf_kosuu / 38);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 13; j++) {
            if ((aite_ba[i][j] != 0) && (aite_ba[i][j] < 6)) {
                aite_kosuu_iro++;
            }
            if ((aite_ba[i][j] != 0)) {
                aite_ojama++;
            }
        }
    }
    aite_ojama = aite_ojama - aite_kosuu_iro;
    if (aite_ojama > 5)
        one_tanpatu = 0;
    if ((myf_kosuu_iro >= aite_kosuu_iro * 2) && (cchai > 6) && (aite_hakka_rensa < 4)) {
        kes2 = 1;
    } else {
        kes2 = 0;
    }

    nx1 = nex;
    nx2 = nex2;
    nn1 = nnx;
    nn2 = nnx2;
    nk1 = 1;
    nk2 = 1;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 13; j++) {
            ba2[i][j] = ba3[i][j];
        }
    }

    for (dd = 0; dd < 221; dd++) {
        for (aa = 0; aa < 22; aa++) {
            for (bb = 0; bb < 22; bb++) {
                score_hukasa[aa][bb][dd] = 3000;
                for (ee = 0; ee < EE_SIZE; ee++) {
                    chainhyk[aa][bb][dd][ee] = 0;
                    poihyo[aa][bb][dd][ee] = -2000;
                }
            }
        }
    }

    for (aa = 0; aa < 22; aa++) {
        hym[aa] = -10000;
        zenke[aa] = 0;
    }

    kurai_large = 0;
    kurai_middle = 0;
    kurai_small = 0;
    if (aite_hakka_nokori < 3) {
        if ((((aite_hakka_rensa > 3) || (aite_hakka_kosuu > 15)) && (aite_hakka_jamako > 4))
            || ((aite_hakka_zenkesi == 1) && (aite_hakka_jamako > 35))
            || ((aite_hakka_zenkesi == 1) && (aite_hakka_jamako > 35))) {
            kurai_large = 1;
        } else if ((aite_hakka_kosuu > 12) && (aite_hakka_jamako > 4)) {
            kurai_middle = 1;
        } else if ((aite_hakka_kosuu > 8) && (aite_hakka_jamako > 4)) {
            kurai_small = 1;
        } else if ((aite_hakka_jamako > y_t)) {
            kurai_mini = 1;
        }
    }

    wariko_taiou = 0;
    if ((((aite_hakka_rensa > 3) || (aite_hakka_kosuu > 15)) && (aite_hakka_jamako > 4))
        || ((aite_hakka_zenkesi == 1) && (zenkesi_own != 1))) {
        wariko_taiou = 1;
    } else if ((aite_hakka_kosuu > 12) && (aite_hakka_jamako > 4)) {
        wariko_taiou = 1;
    } else if ((aite_hakka_kosuu > 8) && (aite_hakka_jamako > 4)) {
        wariko_taiou = 1;
    } else if ((aite_hakka_jamako > 3)) {
        wariko_taiou = 1;
    }

    if (aite_hakka_rensa < 5) {
        if (myf_kosuu < 15) {
            for (aa = 0; aa < 22; aa++) {
                memcpy(ba_a, ba2, sizeof(ba_a));
                putPuyos(ba_a, aa, nx1, nx2, setti_basyo);
                if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                    chig_aa = 1;
                else
                    chig_aa = 0;
                simulateChain(ba_a, &score, &quick);
                if ((ba_a[0][0] == 0) && (ba_a[1][0] == 0) && (ba_a[2][0] == 0) && (ba_a[3][0] == 0)
                    && (ba_a[4][0] == 0) && (ba_a[5][0] == 0)) {
                    for (bb = 0; bb < 22; bb++) {
                        for (dd = 0; dd < 22; dd++) {
                            zenkes[aa][bb][dd] += score + 2100 - chig_aa * 3;
                        }
                    }
                }

                if (myf_kosuu < 13) {
                    for (bb = 0; bb < 22; bb++) {
                        memcpy(ba_ee, ba_a, sizeof(ba_ee));
                        putPuyos(ba_ee, bb, nn1, nn2, setti_basyo);
                        if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                            chig_bb = 1;
                        else
                            chig_bb = 0;
                        simulateChain(ba_ee, &score, &quick);
                        if ((ba_ee[0][0] == 0) && (ba_ee[1][0] == 0) && (ba_ee[2][0] == 0) && (ba_ee[3][0] == 0)
                            && (ba_ee[4][0] == 0) && (ba_ee[5][0] == 0)) {
                            for (dd = 0; dd < 22; dd++) {
                                zenkes[aa][bb][dd] += score + 2100 - (chig_aa + chig_bb) * 3;
                            }
                        }
                    }
                } // p<6
            }
        } // p<7
    }

    for (aa = 0; aa < 22; aa++) {
        for (bb = 0; bb < 22; bb++) {
            for (dd = 0; dd < 22; dd++) {
                if (zenchain <= zenkes[aa][bb][dd]) {
                    zenchain = zenkes[aa][bb][dd];
                    zenchk = aa;
                }
            }
        }
    }
    if (zenchain > 2100)
        zenke[zenchk] += 120000;

    num = 0;

    for (aa = 0; aa < 22; aa++) {

        for (i = 0; i < 20; i++) {
            dabuchk[i] = 0;
        }
        ichiren_kesi = 0;

        if (tobashi_hantei_a(ba2, aa, nx1, nx2))
            continue;

        chain = 0;

        memcpy(ba, ba2, sizeof(ba));

        putPuyos(ba, aa, nx1, nx2, setti_basyo);
        chain = simulateChain(ba, &score, &quick);

        // つぶし
        if ((e_t) && (aite_hakka_rensa < 4)) {
            if ((chain == 2) && (score > aite_rensa_score + 260) && (score > 1600)) {
                hym[aa] += 77000 + score;
                keschk = 1;
                kougeki_iryoku = score / 70;
                kougeki_on = 1;
            }
        }

        if ((hukks > tubushiturn) && (aite_hakka_rensa < 4) && (aite_kosuu_iro > 12)) {
            if ((chain == 2) && (score > aite_rensa_score + 260) && (score > 690)) {
                hym[aa] += 77000 + score;
                keschk = 1;
                kougeki_iryoku = score / 70;
                kougeki_on = 1;
            }
            if (((chain == 3) || (chain == 4)) && (aite_rensa_score_cc < 3)) {
                hym[aa] += 72000 + score;
                keschk = 1;
                kougeki_iryoku = score / 70;
                kougeki_on = 1;
            }
        }
        if ((maxch <= chain) && (maxscore < score)) {
            maxch = chain;
            maxach = aa;
            maxscore = score;
        }
        myf_kosuu_kesi = 0;
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 13; j++) {
                if ((ba[i][j] != 0) && (ba[i][j] < 6)) {
                    myf_kosuu_kesi++;
                }
            }
        }
        if ((chain == 1) && (score > 690) && (aite_hakka_rensa == 0)) {
            hym[aa] += 74000;
            keschk = 1;
        }
        // さいそく
        if (saisoku == 1) {
            if ((myf_kosuu_iro - myf_kosuu_kesi + 10 < myf_kosuu_kesi) && (score > nocc_aite_rensa_score + 130 * chain)
                && (chain > 1) && (aite_hakka_rensa == 0)) {
                hym[aa] += 73000;
                keschk = 1;
                kougeki_iryoku = score / 70;
                kougeki_on = 1;
            }
        }
        // kurai 対応
        if (u_t == 0) {
            if (((score > aite_hakka_jamako * 70 - 280) && (score < aite_hakka_jamako * 70 + 1400))
                && ((kurai_small == 1) || (kurai_middle == 1) || (kurai_large == 1)) && (aite_hakka_honsen == 0)
                && (chain > 1)) {
                hym[aa] += 120000;
                keschk = 1;
            }
        }
        if (zenkesi_own == 1) { // aaaa0909
            if ((chain == 1) && (aite_hakka_zenkesi == 1) && (aite_hakka_jamako < 36)) { // add121014
                hym[aa] += 74000;
            }
            if ((chain > 0) && (zenkesi_aite != 1)) {
                hym[aa] += 74000;
            }
        }
    } // aa

    if (kes2 == 1) {
        if ((maxch > cchai) && (cchai > 1)) {
            hym[maxach] += 150000;
            keschk = 1;
        } else if ((maxch > cchai - 1) && (cchai - 1 > 1)) {
            hym[maxach] += 148000;
            keschk = 1;
        } else if ((maxch > cchai - 2) && (cchai - 2 > 1)) {
            hym[maxach] += 146000;
            keschk = 1;
        }
    }
    if ((wariko_taiou == 1) && (aite_hakka_honsen == 0) && (keschk == 0)) {
        wariko_taiou = 1;
    } else {
        wariko_taiou = 0;
    }

    if (((kurai_mini == 1) || (kurai_small == 1) || (kurai_middle == 1) || (kurai_large == 1))
        && (aite_hakka_honsen == 0) && (keschk == 0)) {
        taiouchk = 1;
    }
    if (((kurai_mini == 1) && (keschk == 0) && (myf_kosuu > 64)) || ((kurai_large == 1) && (keschk == 0))
        || ((kurai_middle == 1) && (keschk == 0)) || ((kurai_small == 1) && (keschk == 0))
        || ((aite_hakka_honsen == 1) && (aite_hakka_nokori < 3))) {
        kuraichk = 1;
    }

    num = 0;
    if ((aite_hakka_honsen == 0) && (q_t)) {
        if (myf_kosuu > 23) {
            for (aa = 0; aa < 22; aa++) {
                if (tobashi_hantei_a(ba2, aa, nx1, nx2))
                    continue;
                memcpy(ba_a, ba2, sizeof(ba));
                putPuyos(ba_a, aa, nx1, nx2, setti_basyo);
                if (chousei_syoukyo(ba_a, setti_basyo) != 0)
                    continue;
                for (cplace = 0; cplace < 6; cplace++) {
                    if (ba_a[0][11] != 0) {
                        if (cplace == 0)
                            continue;
                    }
                    if (ba_a[1][11] != 0) {
                        if ((cplace == 0) || (cplace == 1))
                            continue;
                    }
                    if (ba_a[3][11] != 0) {
                        if ((cplace == 3) || (cplace == 4) || (cplace == 5))
                            continue;
                    }
                    if (ba_a[4][11] != 0) {
                        if ((cplace == 4) || (cplace == 5))
                            continue;
                    }
                    if (ba_a[5][11] != 0) {
                        if (cplace == 5)
                            continue;
                    }
                    for (cyy = 0; cyy < 2; cyy++) {
                        for (ccolor = 1; ccolor < 5; ccolor++) {
                            memcpy(ba, ba_a, sizeof(ba));
                            coita = 0;
                            for (j = 0; j < (12 - cyy); j++) {
                                if (ba[cplace][j + cyy] == 0) {
                                    ba[cplace][j + cyy] = ccolor;
                                    coita = 1;
                                    setti_basyo[0] = cplace;
                                    setti_basyo[1] = j + cyy;
                                    setti_basyo[2] = -1;
                                    setti_basyo[3] = -1;
                                    break;
                                }
                            }
                            if (coita == 0)
                                continue;
                            chain = 0;
                            chousei_syoukyo_2(ba, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score);
                        }
                    } // cyy
                } // cc
            } // aa
        }

    } // aite_hakka_honsen==0

    if (a_t == 0)
        wariko_taiou = taiouchk;

    cchai = 0;
    tesuu_mon = 0;
    chig_aa = 0;
    chig_bb = 0;
    chig_dd = 0;

    for (dd = 0; dd < 221; dd++) {
        if ((fast != 0) && (dd < 220))
            continue;
        if (dd < 22) {
            nk1 = 1;
            nk2 = 1;
        } else if (dd < 22 * 2) {
            nk1 = 1;
            nk2 = 2;
        } else if (dd < 22 * 3) {
            nk1 = 1;
            nk2 = 3;
        } else if (dd < 22 * 4) {
            nk1 = 1;
            nk2 = 4;
        } else if (dd < 22 * 5) {
            nk1 = 2;
            nk2 = 2;
        } else if (dd < 22 * 6) {
            nk1 = 2;
            nk2 = 3;
        } else if (dd < 22 * 7) {
            nk1 = 2;
            nk2 = 4;
        } else if (dd < 22 * 8) {
            nk1 = 3;
            nk2 = 3;
        } else if (dd < 22 * 9) {
            nk1 = 3;
            nk2 = 4;
        } else if (dd < 22 * 10) {
            nk1 = 4;
            nk2 = 4;
        } else {
            nk1 = 0;
            nk2 = 0;
        }
        if ((nk1 == 1) && (nk1 == 1)) {
            if (((dd > 5) && (dd < 12)) || ((dd > 13) && (dd < 19)))
                continue;
        }
        if ((nk1 == 2) && (nk1 == 2)) {
            if (((dd > 5 + 88) && (dd < 12 + 88)) || ((dd > 13 + 88) && (dd < 19 + 88)))
                continue;
        }
        if ((nk1 == 3) && (nk1 == 3)) {
            if (((dd > 5 + 154) && (dd < 12 + 154)) || ((dd > 13 + 154) && (dd < 19 + 154)))
                continue;
        }
        if ((nk1 == 4) && (nk1 == 4)) {
            if (((dd > 5 + 198) && (dd < 12 + 198)) || ((dd > 13 + 198) && (dd < 19 + 198)))
                continue;
        }

        for (aa = 0; aa < 22; aa++) {
            if (tobashi_hantei_a(ba2, aa, nx1, nx2))
                continue;
            memcpy(ba_a, ba2, sizeof(ba));
            putPuyos(ba_a, aa, nx1, nx2, setti_basyo);
            if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                chig_aa = 1;
            else
                chig_aa = 0;
            keshiko_aa = chousei_syoukyo_sc(ba_a, setti_basyo, &score_tmp);
            score_aonly = score_tmp; // only
            score_tmp2 = score_tmp;
            if ((ba_a[2][11] == 0) && (score_tmp > score_aa)) {
                score_aa = score_tmp;
                aa_max_score = aa;
                tesuu_mon = 1;
            }
            if ((ba_a[2][11] == 0) && (score_tmp2 > score_tai) && (score_tmp2 > 270)
                && (aite_hakka_jamako * 70 > score_tmp2 - 1400) && (score_tmp2 + 150 > aite_hakka_jamako * 70)) {
                if ((myf_kosuu_iro - 1 > keshiko_aa * 2) || (i_t)) {
                    score_tai = score_tmp2;
                }
            }
            if ((myf_kosuu_iro - keshiko_aa + 8) < cchai * 4)
                continue;
            if (ba_a[2][11] != 0) {
                for (bb = 0; bb < 22; bb++) {
                    for (ee = 0; ee < EE_SIZE; ee++) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -3000;
                    }
                }
                continue;
            } // 110604

            for (bb = 0; bb < 22; bb++) {
                if (tobashi_hantei_a(ba_a, bb, nn1, nn2))
                    continue;
                memcpy(ba_ee, ba_a, sizeof(ba));
                putPuyos(ba_ee, bb, nn1, nn2, setti_basyo);
                if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                    chig_bb = 1;
                else
                    chig_bb = 0;
                keshiko_bb = chousei_syoukyo_sc(ba_ee, setti_basyo, &score_tmp);
                score_bonly = score_tmp; // only
                score_tmp2 = score_tmp;
                if ((kuraichk == 1) && (aite_hakka_nokori < 2) && (score_aonly > 0))
                    score_tmp = 0; // only
                if ((kuraichk == 1)
                    && ((aite_hakka_nokori < 1)
                        || ((aite_hakka_nokori < 2) && ((aite_puyo_uki == 0) && (aite_hakka_quick == 1)))))
                    score_tmp = 0; // 0225
                if ((ba_ee[2][11] == 0) && (score_tmp > score_aa)) {
                    score_aa = score_tmp;
                    aa_max_score = aa;
                    tesuu_mon = 2;
                }
                if ((wariko_taiou == 1) && (aite_hakka_nokori < 2) && (score_aonly > 0))
                    score_tmp2 = 0; // only
                if ((wariko_taiou == 1)
                    && ((aite_hakka_nokori < 1)
                        || ((aite_hakka_nokori < 2) && ((aite_puyo_uki == 0) && (aite_hakka_quick == 1)))))
                    score_tmp2 = 0; // 0225
                if ((ba_ee[2][11] == 0) && (score_tmp2 > score_tai) && (score_tmp2 > 270)
                    && (aite_hakka_jamako * 70 > score_tmp2 - 1400) && (score_tmp2 + 150 > aite_hakka_jamako * 70)) {
                    if ((myf_kosuu_iro + 1 > (keshiko_aa + keshiko_bb) * 2) || (i_t)) {
                        score_tai = score_tmp2;
                    }
                }
                if ((myf_kosuu_iro - keshiko_aa - keshiko_bb + 8) < cchai * 4)
                    continue;
                if (ba_ee[2][11] != 0) {
                    for (ee = 0; ee < EE_SIZE; ee++) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -3000;
                    }
                    continue;
                } // 110604
                if (dd < 220) {
                    if (tobashi_hantei_b(ba_ee, dd % 22))
                        continue;
                    putPuyos(ba_ee, dd % 22, nk1, nk2, setti_basyo);
                    if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                        chig_dd = 1;
                    else
                        chig_dd = 0;
                    keshiko_dd = chousei_syoukyo_sc(ba_ee, setti_basyo, &score_tmp);
                    score_tmp2 = score_tmp;
                    if ((kuraichk == 1) && ((score_aonly > 0) || (score_bonly > 0)))
                        score_tmp = 0; // only
                    if ((kuraichk == 1) && (aite_hakka_nokori < 3))
                        score_tmp = 0;

                    if (myf_kosuu < 56) {
                        if ((ba_ee[2][11] == 0) && (score_tmp > score_aa)) {
                            score_aa = score_tmp;
                            aa_max_score = aa;
                            tesuu_mon = 3;
                        }
                    } else if (myf_kosuu < 62) {
                        if ((ba_ee[2][11] == 0) && (score_tmp * 6 / 7 > score_aa)) {
                            score_aa = score_tmp * 6 / 7;
                            aa_max_score = aa;
                            tesuu_mon = 3;
                        }
                    } else if (myf_kosuu < 64) {
                        if ((ba_ee[2][11] == 0) && (score_tmp * 3 / 4 > score_aa)) {
                            score_aa = score_tmp * 3 / 4;
                            aa_max_score = aa;
                            tesuu_mon = 3;
                        }
                    } else {
                        if ((ba_ee[2][11] == 0) && (score_tmp * 1 / 2 > score_aa)) {
                            score_aa = score_tmp * 1 / 2;
                            aa_max_score = aa;
                            tesuu_mon = 3;
                        }
                    }
                    if ((myf_kosuu_iro - keshiko_aa - keshiko_bb - keshiko_dd + 8) < cchai * 4)
                        continue;
                    if (ba_ee[2][11] != 0) {
                        for (ee = 0; ee < EE_SIZE; ee++) {
                            chainhyk[aa][bb][dd][ee] = 0;
                            poihyo[aa][bb][dd][ee] = -3000;
                        }
                        continue;
                    } // 110604
                } // dd220

                if (aite_hakka_honsen == 0) {
                    if (p_t == 4)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 3 + chig_bb * 2 + chig_dd * 1) * 400;
                    if (p_t == 3)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 3 + chig_bb * 2 + chig_dd * 1) * 30;
                    if (p_t == 2)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 2 + chig_bb * 1 + chig_dd * 1);
                    if (p_t == 1)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 1 + chig_bb * 1 + chig_dd * 1);
                } else {
                    if (p_t == 4)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 2 + chig_bb * 1 + chig_dd * 1);
                    if (p_t == 3)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 2 + chig_bb * 1 + chig_dd * 1);
                    if (p_t == 2)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 2 + chig_bb * 1 + chig_dd * 1);
                    if (p_t == 1)
                        score_hukasa[aa][bb][dd] -= (chig_aa * 1 + chig_bb * 1 + chig_dd * 1);
                }
                if (ba_ee[2][10] != 0)
                    score_hukasa[aa][bb][dd] -= 1200;
                if (ba_ee[3][10] != 0)
                    score_hukasa[aa][bb][dd] -= 1200;
                for (j = 0; j < 9; j++) {
                    if (ba_ee[0][j] == 0) {
                        if (ba_ee[1][j + 1] != 0)
                            score_hukasa[aa][bb][dd] -= 300;
                        break;
                    }
                }
                for (i = 1; i < 5; i++) {
                    for (j = 0; j < 9; j++) {
                        if (ba_ee[i][j] == 0) {
                            if ((ba_ee[i - 1][j + 1] != 0) && (ba_ee[i + 1][j + 1] != 0))
                                score_hukasa[aa][bb][dd] -= 300;
                            break;
                        }
                    }
                }
                for (j = 0; j < 9; j++) {
                    if (ba_ee[5][j] == 0) {
                        if (ba_ee[4][j + 1] != 0)
                            score_hukasa[aa][bb][dd] -= 300;
                        break;
                    }
                }

                if ((zenkesi_own != 1) && (zenkesi_aite != 1) && (o_t)) {
                    if (hukks < 10)
                        score_hukasa[aa][bb][dd] += gtr(ba_ee);
                }

                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 14; j++) {
                        if (ba_ee[i][j] == 0) {
                            teimen[i] = j;
                            break;
                        }
                    }
                }
                if ((zenkesi_aite != 1) && (r_t)) {
                    aveteimen = teimen[0] + teimen[1] + teimen[2] + teimen[3] + teimen[4] + teimen[5];
                    teimen[0] = (teimen[0] - 3) * 6 - aveteimen;
                    if (teimen[0] < 0)
                        teimen[0] = teimen[0] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[0] * 10;
                    teimen[1] = (teimen[1]) * 6 - aveteimen;
                    if (teimen[1] < 0)
                        teimen[1] = teimen[1] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[1] * 10;
                    teimen[2] = (teimen[2] + 1) * 6 - aveteimen;
                    if (teimen[2] < 0)
                        teimen[2] = teimen[2] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[2] * 10;
                    teimen[3] = (teimen[3] + 1) * 6 - aveteimen;
                    if (teimen[3] < 0)
                        teimen[3] = teimen[3] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[3] * 10;
                    teimen[4] = (teimen[4]) * 6 - aveteimen;
                    if (teimen[4] < 0)
                        teimen[4] = teimen[4] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[4] * 10;
                    teimen[5] = (teimen[5] - 3) * 6 - aveteimen;
                    if (teimen[5] < 0)
                        teimen[5] = teimen[5] * (-1);
                    score_hukasa[aa][bb][dd] -= teimen[5] * 10;
                }

                tanpatu_on = keshiko_aa * 2 + keshiko_bb;
                if ((keshiko_aa < 5) && (keshiko_bb < 5))
                    tanpatu_on = 0;
                if ((keshiko_aa > 7) || (keshiko_bb > 7))
                    tanpatu_on = 0;
                if ((tanpatu_on > 0) && (myf_kosuu_iro > aite_kosuu_iro + 1) && (myf_kosuu_iro > 23) && (one_tanpatu)
                    && (aite_hakka_kosuu == 0) && (aite_hakka_rensa == 0))
                    score_hukasa[aa][bb][dd] += tanpatu_on * 120;

                for (ee = 0; ee < EE_SIZE; ee++) {
                    if ((key_ee == 0) && (ee > 0))
                        break; // t2
                    if (ee == 0) {
                        eex = 0;
                        eecol = 0;
                    } else {
                        eex = (ee - 1) % 6;
                        eecol = (ee - 1) / 6 + 1;
                        if ((eex == 2) || (eex == 3))
                            continue;
                        if (ba_ee[0][11] != 0) {
                            if (eex == 0)
                                continue;
                        }
                        if (ba_ee[1][11] != 0) {
                            if ((eex == 0) || (eex == 1))
                                continue;
                        }
                        if (ba_ee[3][11] != 0) {
                            if ((eex == 4) || (eex == 5))
                                continue;
                        }
                        if (ba_ee[4][11] != 0) {
                            if ((eex == 4) || (eex == 5))
                                continue;
                        }
                        if (ba_ee[5][11] != 0) {
                            if (eex == 5)
                                continue;
                        }
                    }
                    memcpy(ba, ba_ee, sizeof(ba));
                    if (ee != 0) {
                        if (setti_puyo_1(ba, eex, eecol))
                            continue;
                    }

                    if (ba[2][11] != 0) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -3000;
                        continue;
                    }
                    if ((ba[0][10] == 0) && (ba[1][11] != 0) && (ba2[1][11] == 0)) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -2000;
                        continue;
                    }
                    if (((ba[5][10] == 0) || (ba[4][10] == 0)) && (ba[3][11] != 0) && (ba2[3][11] == 0)) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -2000;
                        continue;
                    }
                    if ((ba[5][10] == 0) && (ba[4][11] != 0) && (ba2[4][11] == 0)) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -2000;
                        continue;
                    }
                    for (i = 0; i < 6; i++) {
                        for (j = 0; j < 12; j++) {
                            point2[i][j] = 8;
                            if ((ba[i][j] != 0) && (ba[i][j] != 6)) {
                                if ((ba[i][j + 1] == 0) && ((ba[i + 1][j] == 0) && (i != 5))) {
                                    if ((j != 11) && ((i != 4) || (ba[3][11] == 0))) {
                                        point2[i][j] = 2;
                                        point2[i][j + 1] = 9;
                                        break;
                                    }
                                }
                                if ((ba[i][j + 1] == 0) && ((ba[i - 1][j] == 0) && (i != 0))) {
                                    if ((j != 11) && ((i != 5) || (ba[3][11] == 0))) {
                                        point2[i][j] = 3;
                                        point2[i][j + 1] = 9;
                                        break;
                                    }
                                }
                                if (ba[i][j + 1] == 0) {
                                    if ((j != 11) && (((i != 0) || (ba[1][11] == 0)) && ((i != 4) || ((ba[3][11] == 0)))
                                                      && ((i != 5) || ((ba[3][11] == 0) && (ba[4][11] == 0))))) {
                                        point2[i][j] = 4;
                                        point2[i][j + 1] = 9;
                                        break;
                                    }
                                }
                                if (((ba[i + 1][j] == 0) && (i != 5)) && ((ba[i - 1][j] == 0) && (i != 0))) {
                                    if (ba[i][11] == 0) {
                                        point2[i][j] = 5;
                                        continue;
                                    }
                                }
                                if ((ba[i + 1][j] == 0) && (i != 5)) {
                                    if (((i != 4) || ((ba[3][11] == 0) && (ba[4][11] == 0)))
                                        && ((i != 3) || (ba[3][11] == 0))) {
                                        point2[i][j] = 6;
                                        continue;
                                    }
                                }
                                if ((ba[i - 1][j] == 0) && (i != 0)) {
                                    if (((i != 1) || (ba[1][11] == 0)) && ((i != 5) || (ba[3][11] == 0))) {
                                        point2[i][j] = 7;
                                        continue;
                                    }
                                }
                            }
                        }
                    }

                    num2 = 3;
                    for (i2 = 0; i2 < 6; i2++) {
                        hakkatakasa = 0;
                        for (j2 = 0; j2 < 12; j2++) {
                            if (point2[i2][j2] == 9)
                                break;
                            if (point2[i2][j2] == 8)
                                continue;
                            if (hakkatakasa < 6)
                                hakkatakasa++;
                            if (point2[i2][j2] == 1)
                                continue;
                            if ((num2 > 2))
                                memcpy(bass, ba, sizeof(bass));
                            chain = 0;
                            num2 = 0;
                            poi2s = 0;
                            tokus = point2[i2][j2];
                            saiki_3(bass, point2, i2, j2, &num2, bass[i2][j2]);
                            if ((num2 < 3))
                                goto POSS;
                            poi2s = j2 * takasa_point;
                            if (j2 > 5)
                                poi2s += takasa_point;
                            if ((tokus > 1) && (tokus < 5))
                                poi2s += 100 * t_t;
                            if (zenkesi_aite == 1)
                                poi2s = hakkatakasa * 300;

                            chain = chousei_syoukyo_3(bass, setti_basyo, &poi2s, &score_mm, tokus, i2, j2);

                            if ((dd < 220) && (myf_kosuu > 63))
                                score_mm = score_mm * 1 / 2;
                            else if ((dd < 220) && (myf_kosuu > 61))
                                score_mm = score_mm * 3 / 4;
                            else if ((dd < 220) && (myf_kosuu > 55))
                                score_mm = score_mm * 6 / 7;

                        POSS:
                            pois = 0;
                            if (cchai <= chain) {
                                cchai = chain;
                                memset(point, 0, sizeof(point));
                                num = 0;
                                for (i = 0; i < 6; i++) {
                                    for (j = 0; j < 12; j++) {
                                        if (bass[i][j] == 0)
                                            break;
                                        if ((point[i][j] != 1) && (bass[i][j] != 6)) {
                                            saiki(bass, point, i, j, &num, bass[i][j]);
                                            pois = pois + num * num * num;
                                            num = 0;
                                        }
                                    }
                                }
                            }
                            if (chain > cchai - 3) {
                                for (i = 0; i < 5; i++) {
                                    for (j = 0; j < yokotate; j++) {
                                        if ((bass[i][j] != 0) && (bass[i][j] != 6)) {
                                            if (bass[i][j] == bass[i + 1][j])
                                                pois += yokopoint;
                                        }
                                    }
                                } // 12-2
                            }
                            if (chainhyk[aa][bb][dd][ee] < chain) {
                                chainhyk[aa][bb][dd][ee] = chain;
                                poihyo[aa][bb][dd][ee] = (pois + poi2s);
                            } else if (chainhyk[aa][bb][dd][ee] == chain) {
                                if (poihyo[aa][bb][dd][ee] < (pois + poi2s)) {
                                    poihyo[aa][bb][dd][ee] = (pois + poi2s);
                                }
                            }
                            if (kuraichk == 1)
                                score_mm = 0;
                            if (score_mm > score_max) {
                                score_max = score_mm;
                                mmmax = aa;
                            }
                        }
                    }
                } // ee
            } // bb
        } // aa
    } // dd
    return 0;
}
