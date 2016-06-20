#include <cstdio>
 
int d[2][10001];
int arr[101];
 
int main(){
    //freopen("test/3442.txt","r",stdin);
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1; i<n+1; i++){
        scanf("%d",&arr[i]);
    }   
 
    d[0][0] = d[1][0] = 1;
    for(int i=1; i<k+1; i++){                        
        if(i%arr[1] == 0) d[1][i]=1;
    }
    for(int i=2; i<n+1; i++){        
        for(int j=1; j<k+1; j++){                                                
            int x = arr[i];
            d[i%2][j] = d[(i%2+1)%2][j];
            while(x <= j){
                d[i%2][j] += d[(i%2+1)%2][j-x];
                x+=arr[i];
            }           
        }
    }
    printf("%d\n",d[n%2][k]);
    return 0;
}
