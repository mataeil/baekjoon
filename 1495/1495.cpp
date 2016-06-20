#include<cstdio>
#include<cstring>
#define N_MAX 100
#define M_MAX 1000
 
static bool dm[N_MAX+1][M_MAX+1];
static int arr[N_MAX+1];
int size,bl;
 
void dfs(int level, int cur){
    if(cur < 0 || cur > bl || level > size )
        return;
    if(dm[level][cur] == true) return;
    dm[level][cur] = true;
    dfs(level+1,cur+arr[level]); // 1 5 -> 1 8, 1 2 ->
    dfs(level+1,cur-arr[level]); // 1 0 
    return;
}
 
int main(){
    //freopen("test/1495.txt","r",stdin);
    int st;
    memset(dm,0,sizeof(dm));
    scanf("%d %d %d",&size,&st,&bl);
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
                 
    dfs(0,st);
     
    int cnt = -1;
 
    for(int i=bl; i>=0; i--){
        if(dm[size][i] == true) {
            cnt = i;
            break;  
        }
    }
 
    printf("%d\n",cnt);
     
    return 0;
}
