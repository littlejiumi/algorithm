#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1100;

int main() {
    int n;
    cin >> n;
    int ta[maxn][maxn], dp[maxn][maxn];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> ta[i][j];
            cout<< ta[i][j];
        }
    }
    for (int j = 1; j <= n; j++) {
        dp[n][j] = ta[n][j];
    }
    for (int i = n - 1; i >= 1; i--) {
        for(int j = 1; j <= i; j++ ) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+ ta[i][j];
        }
    }
    cout << dp[1][1]<<endl;
    return 0;
}
