#include <stdio.h>
#include <deque>
#define MAX 100000
using namespace std;
 
static int arr[MAX+1];
int size,cur;
long long maxV;
 
long long gMAX(long long a, long long b){
    if(a>b) return a;
    return b;
}
 
deque <int> q;
deque <long long> aq;
int main(){
     
    while(1){
        q.clear();
        maxV = cur = 0;         
        scanf("%d",&size);
        if(size == 0) break;
        for(int i=0; i<size; i++){
            scanf("%d",&arr[i]);    
        }   
        arr[size++]=-1;         
     
        while(cur < size){
            if(q.size()==0){
                q.push_back(cur);
            }
            else if(arr[q.back()] <= arr[cur]){
                    q.push_back(cur);
            }
            else{
                while(arr[q.back()] > arr[cur]){                 
                    if(q.size()==1){
                        maxV = gMAX(maxV, (long long)(cur-0)*arr[q.back()]);                                        
                    }                       
                    else{                   
                        int temp = q.back();                        
                        q.pop_back();
                        maxV = gMAX(maxV, (long long)(cur-(q.back()+1))*arr[temp]);                                                     
                        q.push_back(temp);
                    }   
                    q.pop_back();
                    if(q.size() == 0) break;
                }
                q.push_back(cur);               
            }           
            cur++;
        }
        aq.push_back(maxV);     
    }
     
    while(!aq.empty()){
        printf("%lld\n",aq.front());
        aq.pop_front();
    }
     
    return 0;
}
