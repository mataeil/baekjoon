#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int d[501][501];
int arr[501][501];
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};
 
int go(int i, int j){
   if(d[i][j] != 0) return d[i][j];
   d[i][j] = 1;
   for(int k=0; k<4; k++){
        int ii = i + di[k];
        int jj = j + dj[k];     
        if( 0 <= ii && ii < n && 0 <= jj && jj < n){        
            if(arr[i][j] < arr[ii][jj]){
                d[i][j] = max(d[i][j], go(ii,jj)+1);                                
            } 
        }  
    }
    return d[i][j];
}
 
int main(){
//  freopen("test/panda.txt","r",stdin);    
    scanf("%d",&n);
 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);     
        }
    }       
     
    int ans=0;
    for(int i=0; i<n; i++){      
        for(int j=0; j<n; j++){      
            ans = max(ans,go(i,j)); 
        }       
    }
     
    printf("%d\n",ans);
 
    return 0;
}
