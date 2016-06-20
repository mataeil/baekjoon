#include<cstdio>
#include<vector>
#define MAX 262144 
using namespace std;
 
typedef pair<int,int> pi;
static pi tree[262144];
static int arr[262144];
 
//first : max , second : min
void makeTree(int node, int st, int ed){
    if(st == ed){
        tree[node].first = tree[node].second = arr[st];             
    }else{
        makeTree(node*2, st, (st+ed)/2);
        makeTree(node*2+1, (st+ed)/2+1, ed);
        tree[node] = make_pair(max(tree[node*2].first,tree[node*2+1].first),min(tree[node*2].second,tree[node*2+1].second));            
    }   
}
 
pi searchTree(int node, int st, int ed, int i, int j){
    if(j < st || i > ed){
        return make_pair(-1,-1);
    }
    if(i <= st && ed <= j){
        return tree[node];
    }
    pi x = searchTree(node*2, st, (st+ed)/2, i, j);
    pi y = searchTree(node*2+1, (st+ed)/2+1, ed, i, j);
    if(x.first == -1) return y;
    if(y.first == -1) return x;
    return make_pair(max(x.first,y.first),min(x.second,y.second));
}
 
 
int main(){
    //freopen("test/2357.txt","r",stdin);
    int size,a_size;
    scanf("%d %d",&size,&a_size);
    for(int i=1; i<=size; i++){
        scanf("%d",&arr[i]);
    }
     
    makeTree(1,1,size);
     
    int a,b;
    for(int i=0; i<a_size; i++){
        scanf("%d %d",&a,&b);       
        pi t = searchTree(1,1,size,a,b);
        printf("%d %d\n",t.second,t.first);
    }
     
    return 0;
}
