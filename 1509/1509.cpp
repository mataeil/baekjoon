#include<cstdio>
#include<vector>
#include<cstring>
#define MAX 2500
using namespace std;
 
static char arr[MAX+1];
static int dm[MAX+1][MAX+1];
static int d[MAX+1];
 
int dfs(int i, int j){
    if(i>j)
        swap(i,j);
    if(dm[i][j]>-1)
        return dm[i][j];
    if(arr[i] == arr[j] && i+1 == j){
        dm[i][j] = 1;
    }else if(arr[i] == arr[j] && dfs(i+1,j-1) == 1){
        dm[i][j] = 1;
    }else{
        dm[i][j] = 0;
    }
    return dm[i][j];
}
 
int dfs2(int i){
    if(dfs(0,i)==1)
        return 1;
    if(d[i] > -1)
        return d[i];
    d[i] = i+1;
    for(int j=0; j<i; j++){
        if(dfs(j+1,i) == 1){
            if(d[i] > dfs2(j)+1)
                d[i] = dfs2(j)+1;
        }
    }
    return d[i];
}
 
int main(){
    //freopen("test/1509.txt","r",stdin);
    for(int i=0; i<MAX+1; i++){
        for(int j=0; j<MAX+1; j++){
            dm[i][j] = -1;
        }
    }
     
    gets(arr);
    int size = strlen(arr);
    for(int i=0; i<size; i++){       
        dm[i][i] = 1;   
        d[i]=-1;
    }
 
    printf("%d",dfs2(size-1));
     
    return 0;
}
