#include <cstdio>
#include <cstring>
using namespace std;
 
int d[41];
 
int go(int n){
    if(n <= 1) return d[n];
    if(d[n]!=0) return d[n];
 
    d[n] = go(n-1) + go(n-2);
    return d[n];
}
 
int main(){
    int t;
    scanf("%d",&t);
     
    while(t--){
        int n;
        scanf("%d",&n);
        memset(d,0,sizeof(d));
        d[0] = 1;
        int ans1 = go(n);
        memset(d,0,sizeof(d));
        d[1] = 1;
        int ans2 = go(n);
        printf("%d %d\n",ans1,ans2);    
    }
         
    return 0;
}
