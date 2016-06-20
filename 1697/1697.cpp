#include <stdio.h>
#include <deque>
#define MAX 100000LL
using namespace std;
 
deque <long long> que;
int check[MAX + 2];
 
long long cvrt(long n, long k){
    return n*(MAX + 2) + k;
}
 
long long getPosition(long long cur){
    return cur / (MAX + 2);
}
 
long long getCnt(long long cur){
    return cur % (MAX + 2);
}
 
int bfs(int n, int k){
    que.push_back(cvrt(n,0));
 
    for (int i = 0; i < MAX+2; i++) check[i] = 0;
 
    long long cur;
    int position, cnt;
    while (!que.empty()){
        cur = que.front();
        que.pop_front();
        position = getPosition(cur);
        cnt = getCnt(cur);  
 
        if (position == k) return cnt;
        if (position + 1 <= MAX && check[position + 1] == 0) que.push_back(cvrt(position + 1, cnt + 1)), check[position+1]++;        
        if (position - 1 >= 0 && check[position - 1] == 0) que.push_back(cvrt(position - 1, cnt + 1)),check[position-1]++;
        if (position * 2 <= MAX && check[position * 2] == 0) que.push_back(cvrt(position * 2, cnt + 1)), check[position*2]++;
 
    }
    return 0;
}
 
int main(){
    long long n, k;
    scanf("%lld %lld", &n, &k);
    printf("%d", bfs(n, k));
    //system("pause");
    return 0;
}
