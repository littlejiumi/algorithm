#include<iostream>
#include<string>
using namespace std;
const int maxn = 105;
int main(){
    string a, b;
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    int d[maxn][maxn] = {0};
    for(int i = 0; i < la; i++){
        d[i][0] = 0;
    }
    for(int j = 0; j < lb; j++){
        d[0][j] = 0;
    }
    for(int i = 1; i <= la; i++){
        for(int j = 1; j <= lb; j++){
            if( a[i-1] != b[j-1]){ d[i][j] = max(d[i][j-1], d[i-1][j]);}
            else{ d[i][j] = d[i-1][j-1] + 1;}
        }
    }
    cout << d[la][lb]<<endl;
    return 0;
}
/*
给定两个字符串A和B，长度分别为m和n，要求找出它们最长的公共子序列，并返回其长度。例如：

　　A = "HelloWorld"

　   B = "loop"

则A与B的最长公共子序列为 "loo",返回的长度为3。此处只给出动态规划的解法：定义子问题dp[i][j]为字符串A的第一个字符到第 i 个字符串和字符串B的第一个字符到第 j 个字符的最长公共子序列，如A为“app”,B为“apple”，dp[2][3]表示 “ap” 和 “app” 的最长公共字串。注意到代码中 dp 的大小为 (n + 1) x (m + 1) ，这多出来的一行和一列是第 0 行和第 0 列，初始化为 0，表示空字符串和另一字符串的子串的最长公共子序列，例如dp[0][3]表示  "" 和 “app” 的最长公共子串。

当我们要求dp[i][j]，我们要先判断A的第i个元素B的第j个元素是否相同即判断A[i - 1]和 B[j -1]是否相同，如果相同它就是dp[i-1][j-1]+ 1，相当于在两个字符串都去掉一个字符时的最长公共子序列再加 1；否则最长公共子序列取dp[i][j - 1] 和dp[i - 1][j]中大者。所以整个问题的初始状态为：
 
dp[i][0]=0,dp[0][j]=0
相应的状态转移方程为：
dp[i][j]={max{dp[i−1][j],dp[i][j−1]},dp[i−1][j−1]+1,A[i−1]!=B[j−1]A[i−1]==B[j−1]
*/
