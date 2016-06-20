#include <cstdio>
#include <vector>
using namespace std;
 
long long get(long long n, long long k){
    long long cnt=0;
    for(long long i=k; i<=n; i*=k){
        cnt += n/i;
    }
    return cnt;
}
 
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
     
    if(n<m) swap(n,m);
 
    long long a = get(n,5LL) - get(m,5LL) - get(n-m,5LL);
    long long b = get(n,2LL) - get(m,2LL) - get(n-m,2LL);;
     
    if(a>b) a=b;
     
    printf("%lld\n",a);
    return 0;   
}
