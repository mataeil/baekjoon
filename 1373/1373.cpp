#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
 
stack<int> st;
int main(){
    char arr[1000001];
    gets(arr);
    int len = strlen(arr);
     
    int k=0,sum=0;
    while(len--){
        if(arr[len]=='1') sum += (1<<k);
        if(k == 2){
            st.push(sum);
            sum = 0;
        }
        k=(k+1)%3;
    }
     
    if(k>0) st.push(sum);
         
    while(!st.empty()){
        printf("%d",st.top());
        st.pop();
    }
    printf("\n");
    return 0;
}
