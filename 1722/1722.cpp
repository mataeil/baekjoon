#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,k; //max = 20;
int ans[20];
bool chk[20];
vector<int> v;
 
long long getFactorial(int num){
    if(num <= 1) return 1;
    return num*getFactorial(num-1);
}
 
int main(){
     
    scanf("%d %d",&n,&k);   
     
    if(k==1){
        long long x;
        scanf("%lld",&x);       
        for(int i=0; i<n; i++){  
            ans[i] = x/getFactorial(n-1-i);     
            x = x%getFactorial(n-1-i);
        }       
         
        for(int i=0; i<n; i++){
            int cnt = ans[i];
            int chkCnt=0;
            for(int j=0; j<n; j++){
                if(chk[j] == false){                    
                    if(cnt == chkCnt){                      
                        v.push_back(j+1);
                        chk[j] = true;
                        break;  
                    }
                    chkCnt++;
                }               
            }           
        }
        prev_permutation(v.begin(),v.end());
        if(v.size() != n) printf("%d ",n);
        for(int i=0; i<v.size(); i++){
            printf("%d ",v[i]);
        }       
    }else{      
        long long sum=0;
        for(int i=0; i<n; i++){
            int temp;
            scanf("%d",&temp);
            v.push_back(temp-1);
        }       
        for(int i=0; i<n; i++){
            int h = 0;
            for(int j=0; j<n; j++){              
                if(v[i] == j){
                    chk[j]=true;
                    break;                  
                }                                           
                if(chk[j] == false){
                    h++;    
                }               
            }
            sum += h*getFactorial(n-1-i);
        }
        printf("%lld",sum+1);
    }
    printf("\n");
    return 0;
}
