#include<cstdio>
#include<vector>
#include<deque>
#define N_MAX 40000
using namespace std;
 
static int parent[N_MAX+1];
static int depth[N_MAX+1];
static int path[N_MAX+1] = {0};
static bool chk[N_MAX+1] = {false};
vector< vector< pair<int,int> > > v(N_MAX+1);
deque<int> dq;
 
int findLCA(int a, int b){
    if(depth[a] < depth[b])
        swap(a,b);
    while(depth[a] != depth[b]){
        a = parent[a];
    }
    while(a != b){
        a = parent[a];
        b = parent[b];      
    }
    return a;
}
 
int main(){
    int size,a,b,c;
    scanf("%d",&size);
    for(int i=0; i<size-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    parent[1] = 1;
    chk[1] = true;
    path[1] = 0;
    depth[1] = 0;
    dq.push_back(1);
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].first;
            if(chk[y] == false){
                path[y] = v[x][i].second + path[x];
                parent[y] = x;
                depth[y] = depth[x] + 1;
                chk[x] = true;
                dq.push_back(y);
            }
        }
    }
     
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        scanf("%d %d",&a,&b);
        int anc = findLCA(a,b);
        printf("%d\n",path[a]+path[b]-path[anc]*2); 
    }
     
    return 0;
}

