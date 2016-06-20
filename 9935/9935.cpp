#include<cstdio>
#include<cstring>
#include<deque>
#define MAX_T 1000000
#define MAX_A 36
using namespace std;
 
static char T[MAX_T+1];
static char A[MAX_A+1];
static int answer[MAX_T+1];
int t_size, a_size, cur;
 
deque <int> q; 
 
int chkBomb(){  
    deque <int> tq; 
    for(int i=a_size-1; i>=0; i--){
        if(T[q.back()] != A[i])
            break;
        answer[q.back()] = 1;
        tq.push_back(q.back());
        q.pop_back();
        if(q.size()==0) break;
    }       
    if(tq.size() == a_size){        
        return 1;       
    }       
    else{
        while(!tq.empty()){
            answer[tq.back()] = 0;
            q.push_back(tq.back());
            tq.pop_back();
        }
    }
    return 0;
}
 
int main(){
    gets(T);
    gets(A);
    t_size = strlen(T);
    a_size = strlen(A);
     
    cur=0;
    while(cur < t_size){
        q.push_back(cur++);
        while(T[q.back()] == A[a_size-1]){
            if(chkBomb() == 0) break;
            else if (q.size() == 0) break;
        }
    }
     
    int FRULA = 0;
    for(int i=0; i<t_size; i++){
        if(answer[i] == 0) {
            printf("%c",T[i]);
            FRULA = 1;
        }
    }
    if(FRULA==0)
        printf("FRULA");
    printf("\n");
     
     
    return 0;
}

