#include <cstdio>
 
int arr[101];
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    //freopen("test/0612.txt","r",stdin);
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        int sum = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                sum += gcd(arr[i],arr[j]);
            }
        }
        printf("%d\n",sum); 
    }
     
    return 0;
}
