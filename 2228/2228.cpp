#include<cstdio>
#include<cstring>
#define MAX 100
using namespace std;
 
static int arr[MAX+1];
static int dm[MAX+1][MAX+1];
static bool chk[MAX+1][MAX+1];
 
int getCost(int s, int e){
    int sum=0;
    for(int i=s;i<=e;i++) sum+=arr[i];
    return sum;
}
 
int dfs(int n, int m){ //6 2    
    if(m == 0) return 0;
    if(n < 0) return -99999999;
    if(n+1 < 2*m-1) return -99999999;
    //printf("@@");    
    if(chk[n][m]) return dm[n][m];
    //printf("!!");
    chk[n][m] = true;
    dm[n][m] = dfs(n-1,m);
    for(int i=n; i>=0; i--){
        int temp = dfs(i-2,m-1)+getCost(i,n);
        if(dm[n][m] < temp)
            dm[n][m] = temp;
    }
    return dm[n][m];
}
 
int main(){
    //freopen("./7568.txt","r",stdin);
    //memset(chk,false,sizeof(chk));
    int n,m;
    scanf("%d %d",&n,&m);
    //printf("%d, %d",n,m);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }   
    printf("%d\n",dfs(n-1,m));
     
    return 0;   
}
