/*输入n个整数，找出其中最小的k个数。

注意：

数据保证k一定小于等于输入数组的长度;
输出数组内元素请按从小到大顺序排序;*/

/*
求最小的k个数，建立大根队；求最大的k个建立小根队。
优先队列默认的就是大根队；
priority_queue<int> heap;//大根堆。
priority_queue<int, vector<int>, greater<int>> min_heap;//小根堆。
*/
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> heap;//大根堆。
        for (auto x : input) {
            heap.push(x);
            if (heap.size() > k) heap.pop();//如果堆元素超过k，那么去掉堆顶元素，保证k个最小的元素。
        }
        vector<int> res;
        while(heap.size()) {
            res.push_back(heap.top());
            heap.pop();
        }
        reverse(res.begin(), res.end());//从小到大排列。
        return res;
    }
};
