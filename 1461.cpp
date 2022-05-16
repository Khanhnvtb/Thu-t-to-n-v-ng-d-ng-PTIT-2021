//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>
using namespace std;

string str;
int n, dp[105][105]; //mảng dp là độ dài xâu đối xứng dài nhất của xâu có điểm bắt đầu bằng i kết thúc bằng j

void init() { //hàm khởi tạo
    cin.ignore();
    cin >> str;
    n = str.length(); //n là độ dài của xâu

}
void solve() { //hàm xử lý
    for (int i = 0; i < n - 1; i++) dp[i][i] = 1; //xâu đối xứng có điểm đầu và điểm cuối trùng nhau có độ dài là 1
    for (int cl = 1; cl <= n; cl++) //tìm xâu con chung dài nhất của xâu ban đầu với xâu nghịch đảo của nó
        for (int i = 0; i < n - cl; i++) { //i là vị trí được duyệt đến của xâu ban đầu
            int j = i + cl; //j là vị trí của i ở xâu nghịch đảo
            if (str[i] == str[j] && cl == 1) dp[i][j] = 2; //khởi tạo giá trị ban đầu
            else if (str[i] == str[j]) dp[i][j] = dp[i + 1][j - 1] + 2; //dp[i][j] bằng độ dài của xâu trước +2
                //nếu khác nhau thì bằng max của xâu có độ dài j-i
            else dp[i][j] = max (dp[i + 1][j], dp[i][j - 1]);
        }
    cout << n - dp[0][n - 1] << endl; //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}