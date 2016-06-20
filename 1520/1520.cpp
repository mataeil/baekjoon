#include<cstdio>
#define MAX 501
  
static int dm[MAX+1][MAX+1];
static int arr[MAX+1][MAX+1];
 
int n,m;
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
 
int dfs(int i, int j){
    if(i == 0 && j == 0){
        return 1;
    }
    if(dm[i][j] != -1) return dm[i][j];
     
    dm[i][j] = 0;   
    for(int k=0; k<4; k++){
        int c_i = i+di[k];
        int c_j = j+dj[k];
        if(c_i >=0 && c_j >= 0 && c_j<m && c_i<n){
            if(arr[i][j] < arr[c_i][c_j]) dm[i][j] += dfs(c_i,c_j);
        }           
    }
 
    return dm[i][j];
}
 
int main(){
    //freopen("test/1520.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&arr[i][j]);
            dm[i][j] = -1;
        }
    }
    printf("%d\n",dfs(n-1,m-1));
    return 0;
}
