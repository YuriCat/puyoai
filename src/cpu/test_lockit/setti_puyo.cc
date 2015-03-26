int COMAI_HI::setti_puyo(int ba[][TAT_SIZE], int aa, int nx1, int nx2, int setti_basyo[])
{
    int j;
    if (aa < 6) {
        for (j = 0; j < 13; j++) {
            if (ba[aa][j] == 0) {
                ba[aa][j] = nx1;
                ba[aa][j + 1] = nx2;
                setti_basyo[0] = aa;
                setti_basyo[1] = j;
                setti_basyo[2] = aa;
                setti_basyo[3] = j + 1;
                break;
            }
        }
    } else if (aa < 12) {
        for (j = 0; j < 13; j++) {
            if (ba[aa - 6][j] == 0) {
                ba[aa - 6][j] = nx2;
                ba[aa - 6][j + 1] = nx1;
                setti_basyo[0] = aa - 6;
                setti_basyo[1] = j;
                setti_basyo[2] = aa - 6;
                setti_basyo[3] = j + 1;
                break;
            }
        }
    } else if (aa < 17) {
        for (j = 0; j < 13; j++) {
            if (ba[aa - 11][j] == 0) {
                ba[aa - 11][j] = nx1;
                setti_basyo[0] = aa - 11;
                setti_basyo[1] = j;
                break;
            }
        }
        for (j = 0; j < 13; j++) {
            if (ba[aa - 12][j] == 0) {
                ba[aa - 12][j] = nx2;
                setti_basyo[2] = aa - 12;
                setti_basyo[3] = j;
                break;
            }
        }
    } else if (aa < 22) {
        for (j = 0; j < 13; j++) {
            if (ba[aa - 17][j] == 0) {
                ba[aa - 17][j] = nx1;
                setti_basyo[0] = aa - 17;
                setti_basyo[1] = j;
                break;
            }
        }
        for (j = 0; j < 13; j++) {
            if (ba[aa - 16][j] == 0) {
                ba[aa - 16][j] = nx2;
                setti_basyo[2] = aa - 16;
                setti_basyo[3] = j;
                break;
            }
        }
    }
    return 0;
}
