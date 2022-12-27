//
// Created by Nguyen Van Khanh on 10/31/2021.
//
/*
Khu dân cư ABC tiến hành bầu tổ trưởng dân phố. Có M ứng viên và N cử tri. Người dân trong khu dân cư đã chán ngấy với việc các ứng viên vận động tranh cử, câu kéo phiếu bầu trong các nhiệm kỳ trước nên họ quyết định đặt ra quy định mới như sau:

Các ứng viên được đánh số từ 1 tới M. Mỗi cử tri sẽ viết ra đúng 1 số thứ tự ứng viên mình muốn chọn và bỏ vào hòm phiếu.
Người trúng cử là người có số phiếu bầu nhiều thứ hai
Nếu không có người đứng thứ hai thì kết quả bầu cử sẽ bị hủy bỏ
Nếu có nhiều hơn 1 người cùng có số phiếu nhiều thứ hai thì người nào có số thứ tự nhỏ nhất sẽ được chọn.
Viết chương trình xác định người trúng cử.

Input

Dòng đầu ghi hai số N và M (1 < M < 10, 5 < N < 500).

Dòng thứ 2 ghi N giá trị trong các phiếu bầu. Các giá trị đảm bảo hợp lệ (tức là từ 1 đến M).

Output

Ghi ra số thứ tự của người trúng cử.

Hoặc nếu không có ai trúng cử thì ghi ra NONE

Ví dụ

Input

10 4

2 3 1 2 3 4 1 2 3 2

8 4

1 2 3 4 4 3 2 1

Output
3
NONE
*/

#include <bits/stdc++.h>

using namespace std;

int m, n, a[505];
map<int, int> hm;
map<int, int>::iterator it;

int cmp(pair<int, int> x, pair<int, int> y) {
    if (x.first > y.first) return 1;
    else if (x.first == y.first && x.second < y.second) return 1;
    return 0;
}

void input() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        hm[a[i]]++;
    }
}

void solve() {
    vector<pair<int, int>> v;
    for (it = hm.begin(); it != hm.end(); it++)
        v.push_back({it->second, it->first});
    sort(v.begin(), v.end(), cmp);
    if (v.size() < 2) printf("NONE");
    else {
        if (v[v.size() - 1].first == v[0].first) printf("NONE");
        else
            for (int i = 1; i < v.size(); i++) {
                if (v[i].first != v[i - 1].first) {
                    printf("%d", v[i].second);
                    break;
                }
            }
    }
}

int main() {
    input();
    solve();
    return 0;
}
