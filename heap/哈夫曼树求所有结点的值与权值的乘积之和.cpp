/*哈夫曼树，第一行输入一个数n，表示叶结点的个数。
需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有结点的值与权值的乘积之和。*/

#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n, a, b, k;
    int sum;
    priority_queue<int, vector<int>, greater<int> > min_h;
    while(cin >> n){
        sum = 0;
        for(int i=0;i<n;i++){
            cin >> k;
            min_h.push(k);
        }
        while(min_h.size()!= 1){
            a = min_h.top();
            min_h.pop();
            b = min_h.top();
            min_h.pop();
            sum = sum + a + b;
            min_h.push(a + b);
        }
        cout << sum <<endl;
        min_h.pop();
    }
    return 0;
}
