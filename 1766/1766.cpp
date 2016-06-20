#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
#define V_MAX 32000
#define E_MAX 100000
using namespace std;
static int in[V_MAX+1] = {0};
//struct comp{
//  bool operator()(const int& A, const int& B){
//      return A > B;
//  }
//};
//priority_queue<int, vector<int>, comp> pq;
priority_queue<int> pq;
vector< vector<int> > v(V_MAX+1);
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
            pq.push(-i);            
    }
     
    while(!pq.empty()){
        int x = -pq.top();      
        pq.pop();
        printf("%d ",x);
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            in[y]--;
            if(in[y]==0)
                pq.push(-y);                
        }
    }
 
    return 0;
}
