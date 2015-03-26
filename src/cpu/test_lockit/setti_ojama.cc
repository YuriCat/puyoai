int COMAI_HI::setti_ojama(int f[][TAT_SIZE], int ojamako)
{
    int i, j;
    int cnt;
    int okiko;

    okiko = (ojamako + 3) / 6;

    for (i = 0; i < 6; i++) {
        cnt = 0;
        for (j = 0; j < 13; j++) {
            if (f[i][j] == 0) {
                f[i][j] = 6;
                cnt++;
            }
            if (cnt == okiko)
                break;
        }
    }
    return 0;
}
