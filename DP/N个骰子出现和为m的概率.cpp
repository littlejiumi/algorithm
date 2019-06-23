/*
典型的可以用动态规划的思想来完成

1.现在变量有：骰子个数，点数和。当有k个骰子，点数和为n时，出现次数记为f(k,n)。那与k-1个骰子阶段之间的关系是怎样的？

2.当我有k-1个骰子时，再增加一个骰子，这个骰子的点数只可能为1、2、3、4、5或6。那k个骰子得到点数和为n的情况有：
(k-1,n-1)：第k个骰子投了点数1
(k-1,n-2)：第k个骰子投了点数2
(k-1,n-3)：第k个骰子投了点数3
…
(k-1,n-6)：第k个骰子投了点数6
在k-1个骰子的基础上，再增加一个骰子出现点数和为n的结果只有这6种情况！
所以：f(k,n)=f(k-1,n-1)+f(k-1,n-2)+f(k-1,n-3)+f(k-1,n-4)+f(k-1,n-5)+f(k-1,n-6)

3.有1个骰子，f(1,1)=f(1,2)=f(1,3)=f(1,4)=f(1,5)=f(1,6)=1。
用递归就可以解决这个问题：
*/
#include<iostream>
using  namespace std;
int getCount(int n, int sum){
    if(n<1||sum<n||sum>6*n){
        return 0;
    }
    if( n== 1){
        return 1;
    }
    int c = 0;
    c = getCount( n-1, sum -1) + getCount( n-1, sum -2) +
            getCount(n-1, sum - 3) + getCount( n-1, sum -4) +
            getCount(n-1, sum - 5) + getCount( n-1, sum -6) ;
    return c;
}
int main(){
    int n = 0;
    while(true){
        cin >> n;
        for(int i = n ; i<6*n; i++){
            cout << getCount(n , i)<<endl;
        }
    }
    return 0;
}
