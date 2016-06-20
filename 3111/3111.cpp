#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;
#define MAX_A 25
#define MAX_T 3000000
 
static char A[MAX_A+1];
static char T[MAX_T+1];
static int answer[MAX_T+1];
int A_size=0, T_size=0,cur1,cur2,dir,mrg;
 
deque<int> q1;
deque<int> q2;
 
int match(deque<int>& q, deque<int>& tq, int i){
    if(T[q.back()] != A[i]){
        return 0;
    }   
    answer[q.back()]=1;
    tq.push_back(q.back());
    q.pop_back();
    if(q.size()==0) return 0;
    return 1;
}
 
int getResult(deque<int>& q, deque<int>& tq){
    int tq_size = tq.size();
    if(tq_size == A_size){ 
        return 1;
    }
    else{
        for(int i=0; i<tq_size;i++){         
            answer[tq.back()]=0;
            q.push_back(tq.back());
            tq.pop_back();
        }
        return 0;
    }       
}
 
int searchStr(deque<int>& q){
    deque<int> tq;    
    int i;
             
    if(dir == 0){
        for(i=A_size-1; i>=0; i--){      
            if(match(q,tq,i) < 1) break;
        }
    }else{
        for(i=0; i<=A_size; i++){
            if(match(q,tq,i) < 1) break;
        }
    }
     
    return getResult(q,tq);
}
 
void pushStack(){
    if(dir == 0 && mrg == 0){//left     
        q1.push_back(cur1++);
        if(T[q1.back()] == A[A_size-1]){            
            if(searchStr(q1) > 0)
                dir = 1;
        }
    }else if(dir == 1 && mrg == 0){//right  
        q2.push_back(cur2--);
        if(T[q2.back()] == A[0]){
            if(searchStr(q2) > 0)
                dir = 0;
        }
    }else if(dir == 0 && mrg == 1){
        q1.push_back(q2.back());
        q2.pop_back();
        if(T[q1.back()] == A[A_size-1]){            
            if(searchStr(q1) > 0)
                dir = 1;
        }
    }else{
        q2.push_back(q1.back());
        q1.pop_back();
        if(T[q2.back()] == A[0]){
            if(searchStr(q2) > 0)
                dir = 0;
        }
    }
}
 
int main(){
     
    gets(A);
    gets(T);
    A_size = strlen(A);
    T_size = strlen(T);
     
    cur1 = dir = mrg = 0; //dir=0 left, dir=1 right
    cur2 = T_size-1;    
    while(cur1 <= cur2){ 
        pushStack();
    }   
    mrg = 1;
    while(q1.size()!=0 && q2.size()!=0){
        pushStack();
    }
     
    for(int i=0; i<T_size; i++){
        if(answer[i]==0) 
            printf("%c",T[i]);
    }   
    printf("\n");
    return 0;
}
