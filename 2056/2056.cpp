#include<cstdio>
#include<deque>
#include<vector>
#define W_MAX 10000
using namespace std;
 
struct WORK{
    int in,during,end=0;
}w[W_MAX+1];
 
deque<int> dq;
vector< vector<int> > v(W_MAX+1);
int main(){
    int w_size,out,max=0;
    scanf("%d",&w_size);
    for(int i=0; i<w_size; i++){
        scanf("%d %d",&w[i+1].during,&w[i+1].in);       
        for(int j=0; j<w[i+1].in; j++){
            scanf("%d",&out);
            v[out].push_back(i+1);
        }        
    }
     
    for(int i=1; i<w_size+1; i++){
        if(w[i].in == 0){       
            dq.push_back(i);
            w[i].end = w[i].during;
        }
    }
     
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();
        if(max < w[x].end)
            max = w[x].end;
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            w[y].in--;
            if(w[y].end < w[x].end + w[y].during)
                w[y].end = w[x].end + w[y].during;
            if(w[y].in == 0){
                dq.push_back(y);
            }
        }
    }
     
    printf("%d\n",max);
     
    return 0;
}
