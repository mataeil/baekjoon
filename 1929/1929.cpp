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
     
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=n; i<=m; i++){
        if(prime[i] == true)    
            printf("%d\n",i);
    }   
    return 0;
}
