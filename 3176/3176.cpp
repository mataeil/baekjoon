#include<cstdio>
#include<vector>
#include<deque>
#define MAX 100000
using namespace std;
 
typedef pair<int,int> pi;
 
static int depth[MAX+1];
static int chk[MAX+1];
static int parent[MAX+1];
static int p[MAX+1][20][3];
 
vector< vector < pair <int, int> > > v(MAX+1);
deque <int> dq;
 
int getMAX(int a,int b){
    if(a>b) return a;
    return b;
}
 
int getMIN(int a,int b){
    if(a>b) return b;
    return a;
}
 
pi findLCA(int a, int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    int log,max=0,min=1000001;
    for(log=1; (1<<log)<=depth[a]; log++);
    log-=1;
    for(int i=log; i>=0; i--){
        if(depth[a]-(1<<i)>=depth[b]){         
            max = getMAX(max,p[a][i][1]);
            min = getMIN(min,p[a][i][2]);       
            a = p[a][i][0];         
        }
    }   
    if(a==b){
        return make_pair(min,max);
    }
    for(int i=log; i>=0; i--){
        if(p[a][i][0] != 0 && p[a][i][0] != p[b][i][0]){        
            max = getMAX(getMAX(max,p[a][i][1]),p[b][i][1]);
            min = getMIN(getMIN(min,p[a][i][2]),p[b][i][2]);                            
            a = p[a][i][0];
            b = p[b][i][0];
        }
    }
    max = getMAX(getMAX(max,p[a][0][1]),p[b][0][1]);
    min = getMIN(getMIN(min,p[a][0][2]),p[b][0][2]);                            
     
    return make_pair(min,max);
}
 
int main(){
    //freopen("test/3176.txt","r",stdin);
    int size,a,b,c;
    scanf("%d",&size);
    for(int i=0; i<size-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
     
    depth[1]=0;
    p[1][0][0]=0;
    p[1][0][1]=0;
    p[1][0][2]=1000001;
    chk[1] = 1;
    dq.push_back(1);
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].first;
            int cost = v[x][i].second;
            if(chk[y] == 0) {
                chk[y] = 1;
                depth[y] = depth[x] +1;
                p[y][0][0]=x;
                p[y][0][1]=cost;
                p[y][0][2]=cost;
                dq.push_back(y);
            }
        }
    }
     
    //[0]=parent, [1] = max , [2] = min
    for(int i=1; (1<<i)<size; i++){
        for(int j=1; j<size+1; j++){
            int prt = p[j][i-1][0];         
            p[j][i][0] = p[prt][i-1][0];                        
            p[j][i][1] = getMAX(p[prt][i-1][1], p[j][i-1][1]);
            p[j][i][2] = getMIN(p[prt][i-1][2], p[j][i-1][2]);
        }
    }
     
    pi p;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        scanf("%d %d",&a,&b);
        p = findLCA(a,b);
        printf("%d %d\n",p.first,p.second);
    }
             
    return 0;
}
