#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int d[101][10001];
int arr[10001];
 
int main(){ 
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    memset(d,10001,sizeof(d));
    for(int i=0; i<=n; i++){
        d[i][0] = 0;        
    }
     
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){                     
            for(int l=0; j-l*arr[i]>=0; l++){
                d[i][j] = min(d[i][j], d[i-1][j-l*arr[i]] + l);             
            }                       
        }
    }   
    if(d[n][k] >= 10001)
        printf("-1\n");
    else
        printf("%d\n",d[n][k]);
     
    return 0;
}
