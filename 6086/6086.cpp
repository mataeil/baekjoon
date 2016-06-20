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
    int n,source,sink;
    vector< vector < Edge * > > graph;
    vector< bool > check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink){
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
        if(check[x]==true) return 0;
        check[x]=true;
        if(x == sink)
            return c;
        for(int i=0; i<graph[x].size(); i++){            
            if(graph[x][i]->capacity > 0){
                int nc = graph[x][i]->capacity;
                if(c != 0 && c < nc){
                    nc = c;
                }
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
            if(f==0) break;
            ans +=f;
        }
        return ans;
    }
};
 
int node(char a){
    if(a >= 'A' && a <= 'Z'){
        return a - 'A';
    }else{
        return a - 'a' + 26;
    }
}
 
int main(){
    //freopen("test/totalFlow.txt","r",stdin);
    int m;
    scanf("%d",&m);
    MaximumFlow mf(52,0,'Z'-'A');
    for(int i=0; i<m; i++){
        char u,v;
        int cap;
        scanf(" %c",&u);        
        scanf(" %c",&v);
        scanf(" %d",&cap);
        mf.add_edge(node(u),node(v),cap);
        mf.add_edge(node(v),node(u),cap);   
    }
    printf("%d\n",mf.flow());
    return 0;
}
