#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
char arr[600001];
 
deque<char> dq1;
deque<char> dq2;
int main(){
    //freopen("case.txt","r",stdin);
    gets(arr);
    int len = strlen(arr);
    for(int i=0; i<len; i++){
        dq1.push_back(arr[i]);
    }
    int size;
    scanf("%d",&size);
 
    for(int i=0; i<size; i++){
        char a,b;
        scanf(" %c",&a);
        if(a == 'L'){
            if(dq1.size() == 0) continue;
            dq2.push_back(dq1.back());
            dq1.pop_back();
        }else if(a == 'D'){
            if(dq2.size() == 0) continue;
            dq1.push_back(dq2.back());
            dq2.pop_back();
        }else if(a == 'B'){
            if(dq1.size() == 0)  continue;
            dq1.pop_back();
        }else{
            scanf(" %c",&b);
            dq1.push_back(b);
        }
    }
 
    while(!dq1.empty()){
        printf("%c",dq1.front());
        dq1.pop_front();
    }
    while(!dq2.empty()){
        printf("%c",dq2.back());
        dq2.pop_back();
    }
    printf("\n");
    return 0;
}
