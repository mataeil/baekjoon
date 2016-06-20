#include <cstdio>
#include <cstring>
using namespace std;
 
bool prime[1001];
 
void makePrime(){
    prime[1]=false; 
    for(int i=2; i<1001; i++){
        if(prime[i] == true){
            for(int j=i*2; j<1001; j+=i){
                prime[j] = false;
            }
        }
    }
}
 
int main(){
    //freopen("test/0612.txt","r",stdin);
    memset(prime,true,sizeof(prime));
    makePrime();
     
    int n,a;
    scanf("%d",&n);
    int cnt = 0;
    while(n--)  {
        scanf("%d",&a);
        if(prime[a] == true) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
