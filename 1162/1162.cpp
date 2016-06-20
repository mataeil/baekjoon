#include<cstdio>
#include<vector>
#include<queue>
#define V_MAX 210000
#define INF 2100000000
using namespace std;
  
static bool chk[V_MAX+1];
static int answer[V_MAX+1];
struct VTX{
    int index, val;
    VTX(int index, int val) : index(index), val(val){
    }
    bool operator < (const VTX &other) const{
        return val > other.val;
    }
};
priority_queue<VTX> pq;
vector< vector< pair<int,int> > > v(V_MAX+1); //1~20, 21~40, 41~60 ....
int main(){
    //freopen("test/1162.txt","r",stdin);
    int n,m,k,a,b,c;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&a,&b,&c);
        for(int j=0; j<=k; j++){
            int from = (a-1)*(k+1)+j;
            int to = (b-1)*(k+1)+j;
            v[from].push_back(make_pair(to,c));
            v[to].push_back(make_pair(from,c));
        //  printf("j=%d -> a=%d,b=%d from=%d<->to=%d \n",j,a,b,from,to);
            if(j>0){
                v[from].push_back(make_pair(to-1,0));
            //  printf("j=%d -> a=%d,b=%d from=%d->to=%d \n",j,a,b,from,to-1);
                v[to].push_back(make_pair(from-1,0));
            //  printf("j=%d -> a=%d,b=%d from=%d<-to=%d \n",j,a,b,from-1,to);
            }
             
        }
    }
      
    for(int i=0; i<V_MAX+1; i++)
        answer[i] = INF;
          
    pq.push(VTX(k,0));
    answer[k] = 0;
      
    while(!pq.empty()){   
        VTX x = pq.top();
        pq.pop();
        if(chk[x.index] == true)
            continue;
        answer[x.index] = x.val;
        chk[x.index] = true;       
        for(int i=0; i<v[x.index].size(); i++){
            int y = v[x.index][i].first;
            int cost = v[x.index][i].second;
            if(answer[y] > answer[x.index]+cost){            
                answer[y] = answer[x.index]+cost;
                pq.push(VTX(y,answer[y]));
            }
        }
    }
      
    int min = INF;
    for(int i=0; i<=k; i++){
        if(min > answer[(n-1)*(k+1)+i])
            min = answer[(n-1)*(k+1)+i];
    }
    printf("%d\n",min);
      
    return 0;
}

