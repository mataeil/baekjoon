#include<cstdio>
#include<vector>
using namespace std;
 
const int inf = 100;
static char arr[101][101];
 
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
    int n,m;
    scanf("%d %d",&n,&m);
     
    //in : m*i+j , out : n*m+(m*i + j)
    int source, sink;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            scanf(" %c",&x);
            if(x == 'K'){
                source = n*m+(m*i + j);
            }else if(x == 'H'){
                sink = m*i+j;
            }
            arr[i][j]=x;            
        }
    }
    //printf("source=%d, sink=%d\n",source, sink);
    MaximumFlow mf(n*m+n*m, source, sink);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] != '#'){
            //  printf("@@@ %d %d\n",i,j);
                if(j+1 < m){ //east
                    if(arr[i][j+1] != '#'){
                        mf.add_edge(n*m+(m*i + j), m*i+j+1,inf);
                    //  printf("u=%d, v=%d\n",n*m+(m*i + j),m*i+j+1);
                    }
                }
                if(i+1 < n){//souch
                    if(arr[i+1][j] != '#'){
                        mf.add_edge(n*m+(m*i + j), m*(i+1)+j,inf);
                    //  printf("u=%d, v=%d\n",n*m+(m*i + j),m*(i+1)+j);
                    }
                }
                if(j-1 >= 0){//west
                    if(arr[i][j-1] != '#'){
                        mf.add_edge(n*m+(m*i + j), m*i+j-1,inf);
                //      printf("u=%d, v=%d\n",n*m+(m*i + j),m*i+j-1);
                    }
                }
                if(i-1 >= 0){//north
                    if(arr[i-1][j] != '#'){
                        mf.add_edge(n*m+(m*i + j), m*(i-1)+j,inf);
                //      printf("u=%d, v=%d\n",n*m+(m*i + j),m*(i-1)+j);
                    }
                }
                mf.add_edge(m*i+j ,n*m+(m*i + j),1);
            //  printf("u=%d, v=%d\n",(m*i+j) ,n*m+(m*i + j));
            }
        }       
    }
     
     
    int ans = mf.flow();
    if (ans >= 5) {
        ans = -1;
    }
    printf("%d\n",ans);
    //printf("%d\n",mf.flow());
    return 0;
}
