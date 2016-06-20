#include <stdio.h>
#define MAX 750
 
int R,C,m_size=0;
char t;
struct Dia{
    int input,left,right;   
}d[MAX+1][MAX+1];
 
int rangeChk(int i, int j){
    if(i >= 0 && i <= R-1 && j >= 0 && j <= C-1) return 1;      
    else return 0;
}
 
int getMin(int a, int b){
    if(a>b) return b;
    return a;
}
 
void searchSize(int i, int j){  
    int c_size = getMin(d[i][j].left,d[i][j].right);    
    while(m_size < c_size){  
        if(d[i+(c_size-1)][j-(c_size-1)].right >= c_size && d[i+(c_size-1)][j+(c_size-1)].left >= c_size)
            m_size = c_size;
        else c_size--;
    }
}
 
int main(){
    scanf("%d",&R);
    scanf("%d",&C);
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            scanf("%c",&t);
            while(t != '1' && t != '0')
                scanf("%c",&t);
            d[i][j].input =  d[i][j].left = d[i][j].right = t - 48;
        }
    }
 
    for(int i=R-2; i>=0; i--){
        for(int j=0; j<C; j++){
            if(d[i][j].input == 1){
                if(j==0) d[i][j].right = d[i+1][j+1].right + 1;
                else if (j==C-1) d[i][j].left = d[i+1][j-1].left + 1;
                else{
                    d[i][j].left = d[i+1][j-1].left + 1;
                    d[i][j].right = d[i+1][j+1].right + 1;
                }                                               
            }           
        }
    } 
 
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(d[i][j].left>m_size && d[i][j].right>m_size)   
                searchSize(i,j);
        }   
    }
     
    printf("%d\n",m_size);
             
    return 0;
}
