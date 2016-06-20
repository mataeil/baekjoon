#include <cstdio>
#include <cstring>
using namespace std;
char arr[51];
 
int main(){
    //freopen("case.txt","r",stdin);
    int T;
    scanf("%d ",&T);
    for(int i=0;i<T; i++){
        gets(arr);
        int len = strlen(arr);
 
        int state = 0;
        for(int j=0; j<len; j++){
            if(arr[j] == '(')
                state+=1;
            else
                state-=1;
 
            if(state < 0 ) break;
        }
 
        if(state == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

