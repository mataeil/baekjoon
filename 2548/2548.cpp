#include <stdio.h>
#include <algorithm>
#define MAX 20000
using namespace std;
 
struct NUM{
    int val, sum;
    bool operator()(const NUM& a, const NUM& b){
        return a.val < b.val;
    }
}n[MAX+1];
 
int main(){
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++) scanf("%d",&n[i].val);
     
    sort(n, n+size, NUM()); 
    for(int i=0; i<size; i++) {
            if(i==0) n[i].sum =  n[i].val;
            else n[i].sum = n[i-1].sum + n[i].val;
    }
     
    int preSum = n[size-1].sum - n[0].val*size; 
    int answer = n[0].val;
    int temp;
    for(int i=1; i<size; i++) {      
        temp = n[i].val*i-n[i-1].sum - n[i].sum + n[size-1].sum - n[i].val*(size -1 - i );      
        if(preSum < temp) break;
        else if(preSum > temp) preSum = temp, answer = n[i].val; 
    }
     
    printf("%d",answer);    
    return 0;
}
