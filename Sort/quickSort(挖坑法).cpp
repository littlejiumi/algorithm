#include<iostream>
using namespace std;
//快速排序，平均时间复杂度nlogn：挖坑法 
int partition(int arr[], int st, int ed){
    int pivot = arr[st];   //取第一个位置的元素作为基准元素
    int left = st;
    int right = ed;
    int index = st;     //坑位置

    while(right >= left){  //大循环在左右指针重合或交错时结束
        while(right >= left){
            if(arr[right] < pivot){  //right指针从右向左比较
                arr[left] = arr[right];
                index = right;
                left++;
                break;
            }
            right--;
        }
        while(right >= left){
            if(arr[left] > pivot){
                arr[right] = arr[left];
                index = left;
                right--;
                break;
            }
            left++;
        }
    }
    arr[index] = pivot;
    return index;
}
void quickSort(int arr[], int st, int ed){ //分治法
    if(st >= ed)return;   //递归结束
    int pivot = partition(arr, st, ed); //得到基准位置
    quickSort(arr, st, pivot - 1);    //分治法递归数列的两部分
    quickSort(arr, pivot + 1, ed);
}

int main(){
    int arr[8] = {4, 7, -3, 5, 3, 2, 8, 1};
    quickSort(arr, 0, 7);
    for(int i=0; i<7; i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
