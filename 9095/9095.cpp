#include <cstdio>
int d[12];
 
int go(int n){
    if(n <= 1) return 1; 
    if(d[n] > 0)  return d[n];
    d[n] = go(n-1);
    if(n >= 2)
        d[n]+= go(n-2);
    if(n >= 3)
        d[n]+= go(n-3); 
    return d[n];
}
 
int main(){ 
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);     
        for(int i=0; i<=n; i++) d[i]=0;
        printf("%d\n",go(n));   
    }
     
    return 0;
}

