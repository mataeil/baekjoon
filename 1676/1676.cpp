#include <cstdio>
 
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=5; i<=n; i*=5){
        int k = i;
        while(k<=n){
            cnt++;
            k+=i;
        }
    }
    printf("%d\n",cnt);
    return 0;   
}
