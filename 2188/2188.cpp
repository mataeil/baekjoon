#include<cstdio>
#include<vector>
using namespace std;
 
struct MaximumFlow{
    struct Edge{
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity):to(to),capacity(capacity){       
        };
    };
    vector< vector < Edge * > > graph;
    vector< bool > check;
    int n, source, sink;
    MaximumFlow(int n, int source, int sink):n(n),source(source),sink(sink){
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap){
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c){
        if(check[x] == true) return 0;
        check[x] = true;
        if(x == sink)
            return c;
             
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
    int n,m;
    scanf("%d %d",&n,&m);
    //1~n, n+1 ~ n+m, n+m+1
    MaximumFlow mf(n+m+2,0,n+m+1);
    for(int i=1; i<=n; i++){
        int x,y;
        scanf("%d",&x);
        for(int j=0; j<x; j++){
            scanf("%d",&y); 
            mf.add_edge(i,y+n,1);       
        }       
        mf.add_edge(0,i,1);
    }
    for(int i=1; i<=m; i++){     
        mf.add_edge(n+i,n+m+1,1);
    }
     
    printf("%d\n",mf.flow());
    return 0;
}
