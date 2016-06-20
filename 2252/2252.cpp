#include<cstdio>
#include<vector>
#include<deque>
#define V_MAX 32000
#define E_MAX 100000
using namespace std;
 
static int in[V_MAX+1];
 
vector< vector<int> > v(V_MAX+1);
deque<int> dq;
int main(){
    int v_size, e_size,a,b;
    scanf("%d %d",&v_size,&e_size);
    for(int i=0; i<e_size; i++){
        scanf("%d %d",&a,&b);
        in[b]++;
        v[a].push_back(b);
    }
     
    for(int i=1; i<v_size+1; i++){
        if(in[i] == 0)
            dq.push_back(i);
    }
     
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();
        printf("%d ",x);
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            in[y]--;
            if(in[y]==0)
                dq.push_back(y);
        }
    }
 
    return 0;
}
