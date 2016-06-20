#include<cstdio>
#include<deque>
#include<vector>
#define MAX 500000
using namespace std;
 
static int arr[MAX+1];
typedef pair<int,int> pi;
deque<pi> dq;
int main(){
    int size,cur=0,cnt;
    long long answer=0LL;
    pi push,pop;
    scanf("%d",&size);
    for(int i=0; i<size; i++) scanf("%d",&arr[i]);
         
    while(cur < size){   
        cnt = 1;
        if(dq.size()==0){
            push.first = arr[cur++];
            push.second = cnt;
            dq.push_back(push);
            continue;
        }
         
        while(!dq.empty()){
            pop = dq.back();
            if(pop.first == arr[cur]){
                answer += (long long)pop.second;
                cnt = pop.second + 1;
                dq.pop_back();  
            }else if(pop.first < arr[cur]){
                answer += (long long)pop.second;
                dq.pop_back();  
            }else{
                answer++;
                break;
            }
        }
                 
        push.first = arr[cur++];
        push.second = cnt;  
        dq.push_back(push);
    }
    printf("%lld\n",answer);
    return 0;
}
