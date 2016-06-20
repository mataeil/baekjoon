#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int d[15][15][32769];
int n,m;
 
int go(int i, int j, int bmk){      
    if(i > n && bmk == 0) return 1;  
    if(i > n && bmk != 0) return 0;          
    if(j == m+1) return go(i+1,1,bmk); 
    if(j == m+2) return 0;      
     
    if(d[i][j][bmk] >= 0) {      
        return d[i][j][bmk];    
    }
     
    d[i][j][bmk] = 0;   
    if(((1<<j) & bmk) > 0){        
        d[i][j][bmk] = go(i,j+1,bmk-(1<<j));                                  
    }else{
        if(i<n)d[i][j][bmk] = go(i,j+1,bmk+(1<<j));        
        if(((1<<(j+1)) & bmk) < 1) 
            d[i][j][bmk] += go(i,j+2,bmk);          
    }               
    d[i][j][bmk]%=9901;
    return d[i][j][bmk];
}
 
int main(){     
    memset(d,-1,sizeof(d)); 
    scanf("%d %d",&n,&m);
    printf("%d\n",go(1,1,0));
    return 0;
}
