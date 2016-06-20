#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#define MAX 25
using namespace std;
 
static char arr[MAX][MAX];
static int answer[MAX*MAX];
deque<int> que;
int size;
static char inputStr[MAX+1];
 
int getHomeCnt(int i, int j){
    que.push_back(i*100+j);
    arr[i][j]=0;
    int homeCnt = 1;
     
    while(!que.empty()){
        int pop = que.front();
        int pop_i = pop/100;
        int pop_j = pop%100;
        que.pop_front();
         
        if(pop_j+1 < size){
            if(arr[pop_i][pop_j+1] == '1'){
                que.push_back(pop_i*100+pop_j+1);
                arr[pop_i][pop_j+1]='0';
                homeCnt++;
            }
        }
        if(pop_i+1 <size){
            if(arr[pop_i+1][pop_j] == '1'){
                que.push_back((pop_i+1)*100+pop_j);
                arr[pop_i+1][pop_j]='0';
                homeCnt++;
            }
        }
        if(pop_j-1 >= 0){
            if(arr[pop_i][pop_j-1] == '1'){
                que.push_back((pop_i)*100+pop_j-1);
                arr[pop_i][pop_j-1]='0';
                homeCnt++;
            }
        }
        if(pop_i-1 >= 0){
            if(arr[pop_i-1][pop_j] == '1'){
                que.push_back((pop_i-1)*100+pop_j);
                arr[pop_i-1][pop_j]='0';
                homeCnt++;
            }
        }       
    }   
    return homeCnt;
}
 
int main(){
    scanf("%d",&size);
    for(int i=0; i<size; i++){
        scanf("%s",&inputStr);      
        for(int j=0; j<size; j++){   
            arr[i][j] = inputStr[j];                
        }
    }
     
    int index = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i][j] == '1') answer[index++] = getHomeCnt(i,j);                     
        }
    }   
    sort(answer, answer+index);
     
    printf("%d\n",index);
    for(int i=0; i<index; i++)
        printf("%d\n",answer[i]);
    return 0;
}
