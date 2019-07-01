#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1100;

int main() {
    int n;
    cin >> n;
    int a[maxn], dp[maxn]; //dp[i]是以a[i]结尾的连续序列
   for(int i = 0; i < n; i++ ) {
       cin >> a[i];
   }
   dp[0] = a[0];  //边界条件
   for(int i = 1 ; i<n;i++ ){
       dp[i] = max(a[i], dp[i-1] + a[i]);  //状态转移方程
   }
   int k = 0;
   for(int i = 1; i < n; i++ ) {
       if(dp[i] > dp[k]) {
           k = i;
       }
   }
   cout << dp[k] <<endl;
    return 0;
}
