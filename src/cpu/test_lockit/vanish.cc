void COMAI_HI::vanish(int field[][TAT_SIZE], int sx, int sy, int color, int drop_flag[])
{
    static const int dx[] = {-1, 0, 1, 0};
    static const int dy[] = {0, -1, 0, 1};
  
    typedef std::pair<int,int> Point;
    std::queue<Point> vanish_points;
  
    vanish_points.push(Point(sx, sy));
    while (!vanish_points.empty()) {
        auto& front = vanish_points.front();
        int x = front.first, y = front.second;
        vanish_points.pop();

        field[x][y] = TEST_PUYO_COLOR_EMPTY;
        drop_flag[x] = 1;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= FieldConstant::WIDTH || yy < 0 || yy >= FieldConstant::HEIGHT)
                continue;
            int c = field[xx][yy];
            if (c == TEST_PUYO_COLOR_OJAMA) {
                field[xx][yy] = TEST_PUYO_COLOR_EMPTY;
                drop_flag[xx] = 1;
            } else if (c == color) {
                vanish_points.push(Point(xx, yy));
            }
        }
    }
}
