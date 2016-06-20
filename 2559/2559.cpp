#include<cstdio>
#define MAX 100000
int arr[MAX+1];
int main(){
    //freopen("7568.txt","r",stdin);
    int size,cond;
    scanf("%d %d",&size,&cond);
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
     
    int max,c_sum = 0;
    for(int i=0; i<cond; i++){
        c_sum += arr[i];
    }
    max = c_sum;
    for(int i=cond; i<size; i++){
        c_sum = c_sum + arr[i] - arr[i-cond];
        if(max < c_sum) max = c_sum;
    }
     
    printf("%d\n",max);
     
    return 0;   
}
