#include<cstdio>
#include<deque>
#include<vector>
#define MAX 500
using namespace std;
 
struct WORK{
    int in=0,during,end=0;
}w[MAX+1];
 
deque<int> dq;
vector< vector<int> > v(MAX+1);
int main(){
    int size;
    scanf("%d",&size);
    for(int i=0,a; i<size; i++){
        scanf("%d",&a);     
        w[i+1].during = a;
        while(1){
            scanf("%d",&a); 
            if(a == -1){
                break;
            }
            w[i+1].in++;
            v[a].push_back(i+1);
        }                        
    }
     
    for(int i=1; i<size+1; i++){
        if(w[i].in == 0){       
            dq.push_back(i);
            w[i].end = w[i].during;
        }
    }
     
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();     
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
     
    for(int i=1; i<size+1; i++){
        printf("%d\n",w[i].end);
    }
     
    return 0;
}
