//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, a[505][505], d[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool check(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

void input() { //hàm khởi tạo
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
}

void solve() { //hàm xử lý
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = INT_MAX; //đánh dấu chưa có đường đi
    d[1][1] = a[1][1]; //khởi tạo giá trị ban đầu
    queue<pair<int, int> > q;
    q.push({1, 1}); //đưa điểm đầu vào hàng đợi
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) { //thử với 4 hướng
            int x = i + dx[k];
            int y = j + dy[k];
            if (check(x, y) && d[i][j] + a[x][y] < d[x][y]) {
                d[x][y] = d[i][j] + a[x][y]; //cập nhật kết quả
                q.push({x, y}); //đưa điểm hiện tại vào hàng đợi
            }
        }
    }
    printf("%d\n", d[n][m]); //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}