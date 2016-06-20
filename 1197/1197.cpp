#include<cstdio>
#include<algorithm>
#include<vector>
#define V_MAX 100000
#define E_MAX 1000000
using namespace std;
 
static int set[V_MAX+1];
int path;
 
struct EDGE{
    int left,right,value;
}edge[E_MAX+1];
 
bool comp(const EDGE& A, const EDGE& B){
    return A.value < B.value;
}
 
 
int findSet(int x){
    if(set[x] == x){
        return x;
    }
    else{
        set[x] = findSet(set[x]);
        return set[x];
    }
}
 
/*int findSet(int x){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;   
}*/
 
void unionSet(int x, int y){
    int a = findSet(x);
    int b = findSet(y);
    set[b] = a;
}
 
int main(){
     
    int v_size,e_size,a,b,c;
    scanf("%d %d",&v_size,&e_size);
    for(int i=0; i<e_size; i++){
        scanf("%d %d %d",&edge[i].left,&edge[i].right,&edge[i].value);      
    }
     
    sort(edge, edge+e_size, comp);
     
    for(int i=1; i<v_size+1; i++){
        set[i] = i;
    }
     
    path = 0;
    for(int i=0; i<e_size; i++){ 
        int x = edge[i].left;
        int y = edge[i].right;
        if(findSet(x) != findSet(y)){
            unionSet(x,y);
            path += edge[i].value;
        }
    }
     
    printf("%d\n",path);
     
    return 0;
}
