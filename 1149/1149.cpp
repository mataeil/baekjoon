#include <cstdio>
#include <algorithm> 
using namespace std;
 
int d[1001][3];
int arr[1001][3];
 
int main(){
    //freopen("test/ccc.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
     
    d[1][0] = arr[1][0], d[1][1] = arr[1][1], d[1][2] = arr[1][2];
    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + arr[i][j];
        }
    }
     
    int ans = min(d[n][0], d[n][1]);
    ans = min(ans, d[n][2]);
    printf("%d\n",ans);
     
    return 0;
}
