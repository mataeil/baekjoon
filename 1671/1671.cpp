#include<cstdio>
#include<vector>
using namespace std;
 
struct Shark{
    int a1,a2,a3;
}shk[1001];
 
struct MaximumFlow{
    struct Edge{
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity): to(to), capacity(capacity){         
        };
    };
    vector< vector < Edge * > > graph;
    vector< bool > check;
    int n, source, sink;
    MaximumFlow(int n, int source, int sink):n(n), source(source), sink(sink){
        graph.resize(n);
        check.resize(n);
    }
    void add_edge(int u, int v, int cap){
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c){
        if(check[x]==true) return 0;
        check[x]=true;
        if(x == sink)   return c;
        for(int i=0; i<graph[x].size(); i++){
            if(graph[x][i]->capacity > 0){
                int nc = graph[x][i]->capacity;
                if(c != 0 && c < nc)
                    nc = c;         
                int f = dfs(graph[x][i]->to, nc);
                if(f){
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow(){
        int ans = 0;
        while(true){
            fill(check.begin(), check.end(), false);
            int f = dfs(source, 0);
            if(f == 0) break;
            ans += f;
        }
        return ans;
    }
};
 
int main(){
    //freopen("test/11375.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d",&shk[i].a1,&shk[i].a2,&shk[i].a3);
    }
    //ÀÌºÐ¸ÅÄª 0, 1~n, n+1~2n, 2n+1 
    MaximumFlow mf(2*n+2, 0, 2*n+1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i != j){
                if(shk[i].a1 >= shk[j].a1 && shk[i].a2 >= shk[j].a2 && shk[i].a3 >= shk[j].a3 ){
                    if(shk[i].a1 == shk[j].a1 && shk[i].a2 == shk[j].a2 && shk[i].a3 == shk[j].a3 ){
                        if(i<j)
                            mf.add_edge(i,n+j,1);   
                    }else{
                        mf.add_edge(i,n+j,1);   
                    }                   
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        mf.add_edge(0,i,2);
        mf.add_edge(n+i,2*n+1,1);
    }
    printf("%d\n",n-mf.flow());
    return 0;
}
