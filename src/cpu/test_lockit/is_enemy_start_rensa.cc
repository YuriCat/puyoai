bool COMAI_HI::isEnemyStartRensa(int ba3[6][TATE], int zenkesi_aite, int scos, int hakata)
{
    int ba[6][TAT_SIZE] {};
    copyField(ba3, ba);
    int kosuu_mae = countColoredPuyos(ba);

    int score = 0;
    int quick = 0;
    aite_hakka_rensa = simulateChain(ba, &score, &quick);
    aite_hakka_nokori = aite_hakka_rensa;
    hakkatime = hakata;

    int kosuu_ato = countColoredPuyos(ba);

    if (aite_hakka_rensa > 0) {
        aite_hakka_zenkesi = zenkesi_aite;
        aite_hakkaji_score = scos + score;
        aite_hakka_jamako = aite_hakkaji_score / 70 - aite_hakkaji_score / 70;
        aite_hakka_quick = quick;
        if (kougeki_on || kougeki_edge)
            aite_hakka_jamako -= kougeki_iryoku;
        if (aite_hakka_jamako < -11)
            aite_hakka_jamako += kougeki_iryoku;
        kougeki_on = 0;
        kougeki_iryoku = 0;
    }

    kougeki_edge = 0;
    aite_hakka_kosuu = kosuu_mae - kosuu_ato;
    if (aite_hakka_kosuu * 2 > kosuu_mae)
        aite_hakka_honsen = 1;
    return aite_hakka_rensa > 0;
}
