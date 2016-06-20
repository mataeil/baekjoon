#include <cstdio>
#define MAX 1000000
int d[MAX+1];
int arr[MAX+1];
 
int go(int n){
    if(n == 1)
        return 0;
    if(d[n] > 0) return d[n];
    d[n] = go(n-1) +1 ;
    if(n%3 == 0){
        if(d[n] > go(n/3) +1)
            d[n] = go(n/3) +1;
    }
    if(n%2 == 0){
        if(d[n] > go(n/2) +1)
            d[n] = go(n/2) +1;  
    }
    return d[n];
}
 
int main(){
//  freopen("case.txt","r",stdin);
//  for(int i=0; i<MAX+1; i++) d[i] = 0;
    int n;
    scanf("%d",&n);
    printf("%d\n",go(n));
    return 0;
}
