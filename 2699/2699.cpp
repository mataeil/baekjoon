#include <cstdio>
#include <algorithm>
#define MAXN 51
using namespace std;
 
 
int T;
int n;
 
struct temp{
    int x,y;
}maxP;
 
int ccw (int x1, int y1, int x2, int y2, int x3, int y3){
    long long temp = x1*y2 + x2*y3 + x3*y1 - (y1*x2 + y2*x3 + y3*x1);
    if(temp > 0) return 1;
    if(temp < 0) return -1;
    return 0;
}
 
struct Point{
    int x,y;
    bool operator < (const Point& other) const{
        int clock = ccw(maxP.x, maxP.y, x, y, other.x, other.y);
        if(clock < 0) return 1;
        if(clock > 0) return 0;
        if(y == other.y) return x < other.x;
        return y > other.y;
    }
}p[MAXN];
 
int stk[MAXN], s_top;
 
int main(){
    //freopen("test/convex.txt","r",stdin);
    scanf("%d",&T);
    while(T--){     
        scanf("%d",&n);
        int k=0;
        for(int i=0; i<n; i++){
            scanf("%d %d",&p[i].x,&p[i].y);
            if(p[i].y > p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))          
                k = i;
        }
         
        maxP.x = p[k].x;
        maxP.y = p[k].y;
        swap(p[k],p[0]);
        sort(p+1, p+n);
         
        stk[0] = 0;
        s_top = 0;
         
        //convex hull
        for(int i=1; i<n; i++){
            while(s_top > 0 && ccw(p[stk[s_top-1]].x, p[stk[s_top-1]].y, p[stk[s_top]].x, p[stk[s_top]].y, p[i].x, p[i].y) >= 0 ) 
                stk[s_top--] = 0;
            stk[++s_top] = i;
        }
         
        printf("%d\n",s_top+1);
        for(int i=0; i<=s_top; i++){
            printf("%d %d\n",p[stk[i]].x,p[stk[i]].y);
        }
    }
    return 0;
}
