int COMAI_HI::read_template()
{
    int i, j;
    FILE* fp;
    char str[256];
    int cnt = 0;
    int a[78];

    if ((fp = fopen("rensa.dat", "r")) == NULL) {
        return 0;
    }
    i = 0;

    while (1) {
        if (cnt == 0) {
            if ((fscanf(fp, "%d", &numg)) == EOF)
                break;
            colko[i] = numg + 1;
            if (numg >= TM_COLNUM)
                break;
        } else if (cnt == 1) {
            for (j = 1; j < colko[i]; j++) {
                if ((fscanf(fp, "%d%*c", &colscore[i][j])) == EOF)
                    break;
            }
        } else if (cnt == 2) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6],
                        &a[7], &a[8], &a[9], &a[10], &a[11], &a[12])) == EOF)
                break;
        } else if (cnt == 3) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[13], &a[14], &a[15], &a[16], &a[17], &a[18],
                        &a[19], &a[20], &a[21], &a[22], &a[23], &a[24], &a[25])) == EOF)
                break;
        } else if (cnt == 4) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[26], &a[27], &a[28], &a[29], &a[30], &a[31],
                        &a[32], &a[33], &a[34], &a[35], &a[36], &a[37], &a[38])) == EOF)
                break;
        } else if (cnt == 5) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[39], &a[40], &a[41], &a[42], &a[43], &a[44],
                        &a[45], &a[46], &a[47], &a[48], &a[49], &a[50], &a[51])) == EOF)
                break;
        } else if (cnt == 6) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[52], &a[53], &a[54], &a[55], &a[56], &a[57],
                        &a[58], &a[59], &a[60], &a[61], &a[62], &a[63], &a[64])) == EOF)
                break;
        } else if (cnt == 7) {
            if ((fscanf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &a[65], &a[66], &a[67], &a[68], &a[69], &a[70],
                        &a[71], &a[72], &a[73], &a[74], &a[75], &a[76], &a[77])) == EOF)
                break;
            for (j = 0; j < 78; j++) {
                if ((a[j] > 0) && (a[j] < TM_COLNUM)) {
                    katax[i][a[j]][kko[i][a[j]]] = j / 13;
                    katay[i][a[j]][kko[i][a[j]]] = j % 13;
                    kko[i][a[j]]++;
                } else if (a[j] == -1) {
                    tankinx[i][tankinko[i]] = j / 13;
                    tankiny[i][tankinko[i]] = j % 13;
                    tankinko[i]++;
                } else if (a[j] > 100) {
                    jatax[i][a[j] - 101] = j / 13;
                    jatay[i][a[j] - 101] = j % 13;
                    jatako[i]++;
                }
            }
        } else if (cnt == 8) {
            if ((fscanf(fp, "%d", &numg)) == EOF)
                break;
            kinko[i] = numg;
            if (numg > TM_KINPT)
                break;
        } else if (cnt == 9) {
            for (j = 0; j < kinko[i]; j++) {
                if ((fscanf(fp, "%d%*c", &kinsi_a[i][j])) == EOF)
                    break;
                if ((fscanf(fp, "%d%*c", &kinsi_b[i][j])) == EOF)
                    break;
            }
        } else if (cnt == 10) {
            if ((fscanf(fp, "%d", &numg)) == EOF)
                break;
            jakkinko[i] = numg;
            if (numg > TM_JAKKINPT)
                break;
        } else if (cnt == 11) {
            for (j = 0; j < jakkinko[i]; j++) {
                if ((fscanf(fp, "%d%*c", &jakkin_a[i][j])) == EOF)
                    break;
                if ((fscanf(fp, "%d%*c", &jakkin_b[i][j])) == EOF)
                    break;
            }
        } else if (cnt == 12) {
            if ((fscanf(fp, "%d", &numg)) == EOF)
                break;
            tm_turn[i] = numg;
        } else if (cnt == 13) {
            if ((fscanf(fp, "%s", str)) == EOF)
                break;
            if (strcmp(str, "####################") == 0)
                i++;
            else
                break;
            cnt = -1;
        }
        cnt++;
    }
    numg = i;
    fclose(fp);
    return numg;
}
