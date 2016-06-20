#include<cstdio>
int d[100002][3];
 
int main(){
    int n;
    scanf("%d",&n);
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
     
    for(int i=2; i<=n+1; i++){
        for(int j=0; j<3; j++){
            if(j==0)
                d[i][j]=d[i-1][0]+d[i-1][1]+d[i-1][2];
            if(j==1)
                d[i][j]=d[i-1][0]+d[i-1][2];
            if(j==2)
                d[i][j]=d[i-1][0]+d[i-1][1];
            d[i][j]%=9901;
        }
    }
    printf("%d\n",d[n+1][0]);
}
