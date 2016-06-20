#include<cstdio>
#include<vector>
#include<deque>
#define V_MAX 10000
#define E_MAX 100000
using namespace std;
 
static int eChk[E_MAX];
struct CITY{
    int in=0,max=0,chk=0;
}ct[V_MAX+1];
typedef pair<int,int> pi;
vector< vector<pi> > v(V_MAX+1);
vector< vector<pi> > v2(V_MAX+1);
deque<int> dq;
int main(){
    int v_size,e_size,max=0,strtCity,endCity,cnt=0;
    scanf("%d %d",&v_size, &e_size);
    int a,b,c;
    for(int i=0; i<e_size; i++){
        scanf("%d %d %d",&a,&b,&c); 
        ct[b].in++;     
        v[a].push_back(make_pair(b,c));
        v2[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&strtCity,&endCity);
         
    dq.push_back(strtCity); 
    while(!dq.empty()){
        int x= dq.front();
        dq.pop_front();
        if(max < ct[x].max)
            max = ct[x].max;            
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].first;
            int cost = v[x][i].second;
            ct[y].in--;
            if(ct[y].max < ct[x].max + cost)
                ct[y].max = ct[x].max + cost;
            if(ct[y].in==0){                
                dq.push_back(y);
            }
        }
    }
     
    dq.clear(); 
    dq.push_back(endCity);
    while(!dq.empty()){
        int x = dq.front();     
        dq.pop_front();             
        for(int i=0; i<v2[x].size(); i++){           
            int y = v2[x][i].first;
            int cost = v2[x][i].second;         
            if(ct[x].max-cost == ct[y].max){                
                cnt++;
                if(ct[y].chk==0){
                    ct[y].chk = 1;
                    dq.push_back(y);                                        
                }                           
            }           
        }
    }
     
    printf("%d\n",max);
    printf("%d\n",cnt);
     
    return 0;
}
