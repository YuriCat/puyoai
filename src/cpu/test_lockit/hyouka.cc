int COMAI_HI::hyouka(int ba3[6][TATE], int nex, int nex2, int nnx, int nnx2, int zenkesi_own, int aite_ba[6][TATE],
                     int zenkesi_aite)
{
    int ba[6][TAT_SIZE] {};
    int ba_a[6][TAT_SIZE] {};
    int ba2[6][TAT_SIZE] {};
    int point[6][12];
    int i, j;
    int num = 0;
    int n;
    int chain;
    int nx1, nx2, nn1, nn2;
    int aa, bb;
    int hym[22] {};
    int zenchk;
    int zenchain;
    int dabuchk[20] {};
    int hyktmp;
    int dd;
    int keschk = 0;
    int maxch = 0, maxach = 0;
    int saisoku;
    int kesu;
    int zenkes[22][22][22] {};
    int zenke[22] {};
    int setti_basyo[4];
    int myf_kosuu_kesi = 0, myf_kosuu_iro = 0;
    int kurai_large, kurai_middle, kurai_small;
    int aite_kosuu_iro = 0, kes2;
    int yokoyose = 2;
    int ichiren_kesi = 0;

    int ee;
    int ba_ee[6][TAT_SIZE];
    int keshiko_aa, keshiko_bb;
    int syuusoku = 0;

    int ccolor, cplace, coita, cyy = 0, nidub_point_a[22] = { 0 };
    int score = 0, maxscore = 0;
    int score_tmp;
    int kuraichk = 0;
    int quick = 0;
    int score_aonly = -10;
    int taiouchk = 0;
    int kurai_mini = 0;
    int score_tmp2, score_tai = -10, tai_max_score = 0;
    int wariko_taiou = 0;
    int chig_aa, chig_bb;
    int aite_ojama = 0;

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
    kesu = int(myf_kosuu / 55);
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
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 13; j++) {
            ba2[i][j] = ba3[i][j];
        }
    }

    // aaaaaaaaaaaaaaaaaaaaaa
    int maxpont[TM_TMNMUM][22] {};
    int maxp_matome[22] = { 0 };
    int adubpt[22][22][22] {};
    int apos[22] = { 0 };

    tm_moni = 0;

    if (hukks < 255) {
        for (aa = 0; aa < 22; aa++) {
            if (tobashi_hantei_a(ba2, aa, nx1, nx2))
                continue;
            memcpy(ba_a, ba2, sizeof(ba));
            putPuyos(ba_a, aa, nx1, nx2, setti_basyo);
            if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                chig_aa = 1;
            else
                chig_aa = 0;
            keshiko_aa = chousei_syoukyo_2(ba_a, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score_tmp);
            if ((chain == 2) && (dabuchk[1] > 1)) {
                for (bb = 0; bb < 22; bb++) {
                    for (dd = 0; dd < 22; dd++) {
                        adubpt[aa][bb][dd] = 1;
                    }
                }
            }
            if (keshiko_aa != 0)
                continue;
            if (ba_a[2][11] != 0)
                continue;

            for (bb = 0; bb < 22; bb++) {
                if (tobashi_hantei_a(ba_a, bb, nn1, nn2))
                    continue;
                memcpy(ba_ee, ba_a, sizeof(ba));
                putPuyos(ba_ee, bb, nn1, nn2, setti_basyo);
                if ((setti_basyo[0] != setti_basyo[2]) && (setti_basyo[1] != setti_basyo[3]))
                    chig_bb = 1;
                else
                    chig_bb = 0;
                keshiko_bb = chousei_syoukyo_2(ba_ee, setti_basyo, &chain, dabuchk, &ichiren_kesi, &score_tmp);
                if ((chain == 2) && (dabuchk[1] > 1)) {
                    for (dd = 0; dd < 22; dd++) {
                        adubpt[aa][bb][dd] = 1;
                    }
                }
                if (keshiko_bb != 0)
                    continue;
                if (ba_ee[2][11] != 0)
                    continue;
            }
        }
    } // hukks

    for (aa = 0; aa < 22; aa++) {
        for (i = 0; i < numg; i++) {
            if (maxp_matome[aa] < maxpont[i][aa])
                maxp_matome[aa] = maxpont[i][aa];
        }
    }
    for (aa = 0; aa < 22; aa++) {
        for (bb = 0; bb < 22; bb++) {
            for (dd = 0; dd < 22; dd++) {
                if (adubpt[aa][bb][dd] == 1)
                    apos[aa] = 1;
            }
        }
    }
    // aaaaaaaaaaaaaaaaaaaaaa

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
    if (aite_hakka_nokori < 5) {
        if ((aite_hakka_rensa > 3) || (aite_hakka_kosuu > 15) || (aite_hakka_zenkesi == 1)) {
            syuusoku = 1;
        } else if ((aite_hakka_kosuu > 12)) {
            syuusoku = 1;
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
                            if (is_2dub_cpu) {
                                if ((myf_kosuu < 46) && (chain == 2) && (dabuchk[1] > 1))
                                    nidub_point_a[aa] = 3000;
                            } else {
                                if ((myf_kosuu < 46) && (chain == 2) && (dabuchk[1] > 1))
                                    nidub_point_a[aa] = 1200;
                            }
                        }
                    } // cyy
                } // cc
            } // aa
        }

    } // aite_hakka_honsen==0

    if (a_t == 0)
        wariko_taiou = taiouchk;

    cchai = 0;

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
                tai_max_score = aa;
            }
        }
        if ((myf_kosuu_iro - keshiko_aa + 8) < cchai * 4)
            continue;
        if (ba_a[2][11] != 0) {
            for (bb = 0; bb < 22; bb++) {
                for (dd = 0; dd < 221; dd++) {
                    for (ee = 0; ee < EE_SIZE; ee++) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -3000;
                    }
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
            score_tmp2 = score_tmp;
            if ((kuraichk == 1) && (aite_hakka_nokori < 2) && (score_aonly > 0))
                score_tmp = 0; // only
            if ((kuraichk == 1) && ((aite_hakka_nokori < 1)
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
                    tai_max_score = aa;
                }
            }
            if ((myf_kosuu_iro - keshiko_aa - keshiko_bb + 8) < cchai * 4)
                continue;
            if (ba_ee[2][11] != 0) {
                for (ee = 0; ee < EE_SIZE; ee++) {
                    for (dd = 0; dd < 221; dd++) {
                        chainhyk[aa][bb][dd][ee] = 0;
                        poihyo[aa][bb][dd][ee] = -3000;
                    }
                }
                continue;
            } // 110604
        } // bb
    } // aa

    for (aa = 0; aa < 22; aa++) {
        for (bb = 0; bb < 22; bb++) {
            for (dd = 0; dd < 221; dd++) {
                for (ee = 0; ee < EE_SIZE; ee++) {
                    if ((key_ee == 0) && (ee > 0))
                        break; // t2
                    hyktmp = chainhyk[aa][bb][dd][ee] * 1000 + poihyo[aa][bb][dd][ee]
                             + (((myf_kosuu > 40) || syuusoku) * (ee == 0) * 300) + score_hukasa[aa][bb][dd];
                    if (hym[aa] < hyktmp) {
                        hym[aa] = hyktmp;
                        max_ee = ee;
                    }
                }
            }
        }
    }
    if (((myf_kosuu > 50) || (syuusoku == 1)) && (max_ee == 0))
        key_ee = 0;
    if ((myf_kosuu < 44) && (syuusoku == 0))
        key_ee = 1;
    for (aa = 0; aa < 22; aa++) {
        hym[aa] += zenke[aa];
        hym[aa] += nidub_point_a[aa];
    }
    kuraichk_mon = kuraichk;
    score_mon = -1;
    if (((kesu == 1) && (score_max < score_aa)) || ((kuraichk == 1) && (score_aa > 530))) {
        hym[aa_max_score] += 100000;
        score_mon = score_aa;
    } else if ((kesu == 1) && (mmmax != -1)) {
        hym[mmmax] += 60000;
        score_mon = score_aa;
    }
    if (u_t == 1) {
        if ((wariko_taiou == 1) && (((score_tai > 270) && ((myf_kosuu > 36) || (ba2[2][10] != 0)
                                                           || (aite_hakka_zenkesi == 1))) || (score_tai > 840))) {
            hym[tai_max_score] += 140000;
            score_mon = score_tai;
        }
    }

    // 低い場所
    for (i = 0; i < 6; i++) {
        n = 0;
        for (j = 0; j < 13; j++) {
            if (ba2[i][j] == 0)
                n++;
        }
        hym[i] += n * 2;
        hym[i + 6] += n * 2;
        if (i != 0)
            hym[i + 11] += n * 1;
        if (i != 5)
            hym[i + 12] += n * 1;
        if (i != 0)
            hym[i + 16] += n * 1;
        if (i != 5)
            hym[i + 17] += n * 1;
        if ((i == 0) || (i == 5)) {
            hym[i] += yokoyose * 4;
            hym[i + 6] += yokoyose * 4;
            if (i != 0)
                hym[i + 11] += yokoyose * 2;
            if (i != 5)
                hym[i + 12] += yokoyose * 2;
            if (i != 0)
                hym[i + 16] += yokoyose * 2;
            if (i != 5)
                hym[i + 17] += yokoyose * 2;
        }
        if ((i == 1) || (i == 4)) {
            hym[i] += yokoyose * 2;
            hym[i + 6] += yokoyose * 2;
            if (i != 0)
                hym[i + 11] += yokoyose;
            if (i != 5)
                hym[i + 12] += yokoyose;
            if (i != 0)
                hym[i + 16] += yokoyose;
            if (i != 5)
                hym[i + 17] += yokoyose;
        }
    }

    if ((zenkesi_own == 1) && (myf_kosuu_iro == 0)) {
        hym[5] += 5000;
        hym[11] += 5000;
        hym[16] += 5000;
        hym[21] += 5000;
    }

    // chigiri
    if (((zenkesi_own == 1) && (zenkesi_aite != 1)) || ((aite_hakka_honsen == 0) && (w_t)) || (zenkesi_aite == 1)) {
        for (aa = 0; aa < 22; aa++) {
            memcpy(ba, ba2, sizeof(ba));
            if (aa < 6) {
                for (j = 0; j < 13; j++) {
                    if (ba[aa][j] == 0) {
                        ba[aa][j] = nx1;
                        ba[aa][j + 1] = nx2;
                        break;
                    }
                }
            } else if (aa < 12) {
                for (j = 0; j < 13; j++) {
                    if (ba[aa - 6][j] == 0) {
                        ba[aa - 6][j] = nx2;
                        ba[aa - 6][j + 1] = nx1;
                        break;
                    }
                }
            } else if (aa < 17) {
                for (j = 0; j < 13; j++) {
                    if (ba[aa - 11][j] == 0) {
                        ba[aa - 11][j] = nx1;
                        break;
                    }
                }
                for (j = 0; j < 13; j++) {
                    if (ba[aa - 12][j] == 0) {
                        ba[aa - 12][j] = nx2;
                        break;
                    }
                }
            } else if (aa < 22) {
                for (j = 0; j < 13; j++) {
                    if (ba[aa - 17][j] == 0) {
                        ba[aa - 17][j] = nx1;
                        break;
                    }
                }
                for (j = 0; j < 13; j++) {
                    if (ba[aa - 16][j] == 0) {
                        ba[aa - 16][j] = nx2;
                        break;
                    }
                }
            }
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 12; j++) {
                    point[i][j] = 0;
                }
            }
            num = 0;
            for (i = 0; i < 6; i++) {
                for (j = 0; j < 12; j++) {
                    if (ba[i][j] == 0)
                        break;
                    if ((point[i][j] != 1) && (ba[i][j] != 6)) {
                        saiki(ba, point, i, j, &num, ba[i][j]);
                        if (num != 0) {
                            if (num == 2)
                                hym[aa] += 30 * renketu_bairitu;
                            if (num == 3)
                                hym[aa] += 120 * renketu_bairitu;
                            if ((zenkesi_aite == 1) && (num == 2))
                                hym[aa] += 120;
                            if ((zenkesi_aite == 1) && (num == 3))
                                hym[aa] += 480;
                            num = 0;
                        }
                    }
                }
            }
        }
    }

    for (aa = 0; aa < 22; aa++) {
        if ((myf_kosuu < 52) && (myf_kosuu_iro > 23) && (aite_hakka_rensa < 4) && (aite_hakka_honsen == 0))
            hym[aa] += apos[aa] * 2000;
        if (is_2dub_cpu) {
            if ((myf_kosuu < 52) && (aite_hakka_rensa < 4) && (aite_hakka_honsen == 0))
                hym[aa] += apos[aa] * 2000;
        }
    }

    for (aa = 0; aa < 22; aa++) {
        if (aa < 6)
            para[aa] = hym[aa] * 10 + 4;
        else if (aa < 12)
            para[aa + 5] = hym[aa] * 10 + 3;
        else if (aa < 17)
            para[aa + 5] = hym[aa] * 10 + 2;
        else if (aa < 22)
            para[aa - 11] = hym[aa] * 10 + 1;
    }
    return 0;
}
