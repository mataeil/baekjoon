#include <cstdio>
#define MAX 100
static long long dm[MAX+10][MAX+10];
static int arr[MAX+1][MAX+1];
 
int main(){
    //freopen("1890.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&arr[i][j]);     
        }
    }
    dm[1][1] = 1LL;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x = arr[i][j];
            if(x==0) continue;      
            if(i+x<=n)
                dm[i+x][j] += dm[i][j];
            if(j+x<=n)
                dm[i][j+x] += dm[i][j];                     
        }
    }
 
    printf("%lld\n",dm[n][n]);
     
    return 0;
}
