#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
 
deque<int> dq;
int main(){
    //freopen("case.txt","r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }
 
    printf("<");
    while(dq.size()>1){
        for(int i=0; i<m-1; i++){
            dq.push_back(dq.front());
            dq.pop_front(); 
        }
        printf("%d, ",dq.front());
        dq.pop_front();
    }
    printf("%d>\n",dq.front());
     
    return 0;
}
