int COMAI_HI::syou_downx(int field[][TAT_SIZE], int x, int y, int color, int drop_flag[], int* num)
{
    *num += 1;
    if ((x != 0) && (field[x - 1][y] == color))
        syou_left_num(field, x - 1, y, color, drop_flag, num);
    if ((x != 0) && (field[x - 1][y] == 6)) {
        field[x - 1][y] = 0;
        drop_flag[x - 1] = 1;
    }
    if ((x != 5) && (field[x + 1][y] == color))
        syou_right_num(field, x + 1, y, color, drop_flag, num);
    if ((x != 5) && (field[x + 1][y] == 6)) {
        field[x + 1][y] = 0;
        drop_flag[x + 1] = 1;
    }
    if ((y != 0) && (field[x][y - 1] == color))
        syou_down_num(field, x, y - 1, color, drop_flag, num);
    if ((y != 0) && (field[x][y - 1] == 6))
        field[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_right_num(int field[][TAT_SIZE], int x, int y, int color, int drop_flag[], int* num)
{
    field[x][y] = 0;
    drop_flag[x] = 1;
    if ((y != 11) && (field[x][y + 1] == color))
        syou_up_num(field, x, y + 1, color, drop_flag, num);
    if ((y != 11) && (field[x][y + 1] == 6))
        field[x][y + 1] = 0;
    if ((x != 5) && (field[x + 1][y] == color))
        syou_right_num(field, x + 1, y, color, drop_flag, num);
    if ((x != 5) && (field[x + 1][y] == 6)) {
        field[x + 1][y] = 0;
        drop_flag[x + 1] = 1;
    }
    if ((y != 0) && (field[x][y - 1] == color))
        syou_down_num(field, x, y - 1, color, drop_flag, num);
    if ((y != 0) && (field[x][y - 1] == 6))
        field[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_left_num(int field[][TAT_SIZE], int x, int y, int color, int drop_flag[], int* num)
{
    field[x][y] = 0;
    drop_flag[x] = 1;
    if ((x != 0) && (field[x - 1][y] == color))
        syou_left_num(field, x - 1, y, color, drop_flag, num);
    if ((x != 0) && (field[x - 1][y] == 6)) {
        field[x - 1][y] = 0;
        drop_flag[x - 1] = 1;
    }
    if ((y != 11) && (field[x][y + 1] == color))
        syou_up_num(field, x, y + 1, color, drop_flag, num);
    if ((y != 11) && (field[x][y + 1] == 6))
        field[x][y + 1] = 0;
    if ((y != 0) && (field[x][y - 1] == color))
        syou_down_num(field, x, y - 1, color, drop_flag, num);
    if ((y != 0) && (field[x][y - 1] == 6))
        field[x][y - 1] = 0;
    return 0;
}
int COMAI_HI::syou_up_num(int field[][TAT_SIZE], int x, int y, int color, int drop_flag[], int* num)
{
    field[x][y] = 0;
    if ((x != 0) && (field[x - 1][y] == color))
        syou_left_num(field, x - 1, y, color, drop_flag, num);
    if ((x != 0) && (field[x - 1][y] == 6)) {
        field[x - 1][y] = 0;
        drop_flag[x - 1] = 1;
    }
    if ((y != 11) && (field[x][y + 1] == color))
        syou_up_num(field, x, y + 1, color, drop_flag, num);
    if ((y != 11) && (field[x][y + 1] == 6))
        field[x][y + 1] = 0;
    if ((x != 5) && (field[x + 1][y] == color))
        syou_right_num(field, x + 1, y, color, drop_flag, num);
    if ((x != 5) && (field[x + 1][y] == 6)) {
        field[x + 1][y] = 0;
        drop_flag[x + 1] = 1;
    }
    return 0;
}
int COMAI_HI::syou_down_num(int field[][TAT_SIZE], int x, int y, int color, int drop_flag[], int* num)
{
    field[x][y] = 0;
    if ((x != 0) && (field[x - 1][y] == color))
        syou_left_num(field, x - 1, y, color, drop_flag, num);
    if ((x != 0) && (field[x - 1][y] == 6)) {
        field[x - 1][y] = 0;
        drop_flag[x - 1] = 1;
    }
    if ((x != 5) && (field[x + 1][y] == color))
        syou_right_num(field, x + 1, y, color, drop_flag, num);
    if ((x != 5) && (field[x + 1][y] == 6)) {
        field[x + 1][y] = 0;
        drop_flag[x + 1] = 1;
    }
    if ((y != 0) && (field[x][y - 1] == color))
        syou_down_num(field, x, y - 1, color, drop_flag, num);
    if ((y != 0) && (field[x][y - 1] == 6))
        field[x][y - 1] = 0;
    return 0;
}
