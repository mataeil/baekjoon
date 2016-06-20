#include<cstdio>
#define MAX 50
using namespace std;
 
struct Body{
    int kg, height, seq,rank;
}bd[MAX+1];
 
int main(){
    //freopen("7568.txt","r",stdin);
    int size;
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        scanf("%d %d",&bd[i].kg, &bd[i].height);
        bd[i].seq = i;
    }
    for(int i=0; i<size; i++){
        int cnt=1;
        for(int j=0; j<size; j++){
            if(i==j) continue;
            if(bd[i].kg < bd[j].kg && bd[i].height < bd[j].height){
                cnt++;
            }
        }
        bd[i].rank = cnt;
    }
    for(int i=0; i<size; i++){
        printf("%d\n",bd[i].rank);
    }
    return 0;   
}
