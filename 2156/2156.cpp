#include <cstdio>
#include <cstdlib>
 
int d[10001];
int arr[10001];
 
int main(){
    //freopen("test/9465.txt","r",      stdin);
    int n;
    scanf("%d",&n); 
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);    
    }
     
    d[1] = arr[1];
    d[2] = arr[1] + arr[2];     
     
    for(int i=3; i<=n; i++){
        d[i] = d[i-1];
        if(d[i] < d[i-2] + arr[i])       
            d[i] = d[i-2] + arr[i];     
        if(d[i] < d[i-3] + arr[i]+arr[i-1])      
            d[i] = d[i-3] + arr[i]+arr[i-1];                            
    }
 
    printf("%d\n",d[n]);
    return 0;
}
