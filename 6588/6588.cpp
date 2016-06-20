#include <cstdio>
#include <cstring>
using namespace std;
 
bool prime[1000001];
 
void makePrime(){
    prime[1]=false; 
    for(int i=2; i<1000001; i++){
        if(prime[i] == true){
            for(int j=i*2; j<1000001; j+=i){
                prime[j] = false;
            }
        }
    }
}
 
int main(){
    //freopen("test/0612.txt","r",stdin);
    memset(prime,true,sizeof(prime));
    makePrime();
     
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0) return 0;
        for(int i=2; i<n-1; i++){
            if(prime[i] && prime[n-i]){
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
        }       
    }
    return 0;
}
