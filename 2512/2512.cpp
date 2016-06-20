#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 10000
using namespace std;
 
static int arr[MAX + 1];
int size, t_budget;
 
int getAnswer(int left, int right){
    int mid = (left + right) / 2;
    int bg = 0;
 
    if (left == mid) return left;
    else{
        for (int i = 0; i < size; i++){
            if (arr[i] <= mid) bg += arr[i];
            else {
                bg += mid*(size-i);
                break;
            }
        }
    }
 
    if (bg == t_budget) return mid;
    else if (bg > t_budget) return getAnswer(left, mid);
    else  return getAnswer(mid, right);
}
 
int main(){
 
    scanf("%d", &size);
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    scanf("%d", &t_budget);
    sort(arr, arr + size);
 
    printf("%d\n", getAnswer(0, arr[size-1]+1));
    //system("pause");
    return 0;
}
