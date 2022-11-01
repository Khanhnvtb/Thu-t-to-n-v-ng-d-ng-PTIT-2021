//
// Created by khanh on 10/8/2021.
//

/*
TÌM ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG

Bài làm tốt nhất
Cho đồ thị có hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
Ví dụ:

Input:

1

6  9  1  6

1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4

Output:

1 2 5 6
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, start, dest, vs[1005], previous[1005];
vector<int> adj[1005];

void input() {
    scanf("%d %d %d %d", &v, &e, &start, &dest);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
    }
}

void dfs(int u) {
    if (vs[dest])
        return;
    vs[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int tmp = adj[u][i];
        if (!vs[tmp]) {
            previous[tmp] = u;
            dfs(tmp);
        }
    }
}

void solve() {
    for (int i = 1; i <= v; i++) {
        previous[i] = 0;
        vs[i] = 0;
    }
    dfs(start);
    if (previous[dist]) {
        stack<int> s;
        while (dist != 0) {
            s.push(dest);
            dist = previous[dest];
        }
        while (!s.empty()) {
            printf("%d ", s.top());
            s.pop();
        }
    } else
        printf("-1");
    printf("\n");
    for (int i = 1; i <= v; i++)
        adj[i].clear();
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
