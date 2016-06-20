#include <cstdio>
 
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    int a,b,g1,g2;
    scanf("%d %d",&a,&b);
    g1 = gcd(a,b);
    printf("%d\n",g1);
    g2 = a/g1*b;        
    printf("%d\n",g2);
     
    return 0;
}
