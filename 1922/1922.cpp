#include<cstdio>
#include<queue>
#include<vector>
#define V_MAX 1000
using namespace std;
 
static int chk[V_MAX+1];
typedef pair<int,int> pi;
struct comp{
    bool operator()(const pi& A, const pi& B){
        return A.second > B.second;
    }
};
 
priority_queue <pi, vector<pi>, comp> pq;
vector< vector<pi> > v(V_MAX+1);
 
int main(){
    int v_size, e_size,cnt=0,sum=0;
    scanf("%d %d",&v_size,&e_size); 
    int a,b,c;
    for(int i=0; i<e_size; i++){
        scanf("%d %d %d",&a,&b,&c);     
        v[a].push_back(make_pair(b,c));     
        v[b].push_back(make_pair(a,c));
    }
         
    pq.push(make_pair(1,0));    
    while(cnt < v_size){
        pi x = pq.top();        
        pq.pop();
        if(chk[x.first]==1){        
            continue;
        }           
        chk[x.first]=1;
        sum += x.second;
        cnt++;      
        for(int i=0; i<v[x.first].size(); i++){
            int to = v[x.first][i].first;       
            if(chk[to]==0){         
                pq.push(v[x.first][i]);
            }
        }
    }
     
    printf("%d\n",sum);
     
    return 0;
}
