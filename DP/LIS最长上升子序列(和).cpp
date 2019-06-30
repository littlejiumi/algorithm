#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n, arr[1005], ans = -1, dp[1005];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <=n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(dp[i], ans);
    }
    printf("%d", ans);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1005], n, MAX;
int arr[1005];
int main()
{
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;
        MAX = -1;
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for(int i = 0; i < n; i++){
            dp[i] = arr[i];
            for(int j = 0 ; j < i; j++){
                if(dp[i] < dp[j] + arr[i] && arr[i] > arr[j]){
                    dp[i] = dp[j] + arr[i];
                }
                MAX = max(dp[i], MAX);
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
