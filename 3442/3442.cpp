#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
 
int n;
 
struct Point{
    int i,j;    
}p1[10001],p2[10001];
 
struct Line{
    Point a,b;
    bool chk=false;
}line[10001];
 
struct Dir{
    int x,y;
    char dir;   
    Dir(int x,int y, char dir):x(x),y(y),dir(dir){
    }
};
 
queue<Dir> q;
 
bool comp1(const Point& A, const Point&B){
    if(A.i == B.i) return A.j < B.j;
    return A.i < B.i;
}
 
bool comp2(const Point& A, const Point&B){
    if(A.j == B.j) return A.i < B.i;
    return A.j < B.j;
}
 
void findLine(int x2,int y2, int& x3, int& y3){
    for(int i=0; i<n; i++){
        if(line[i].chk == false){
            if(line[i].a.i == x2 && line[i].a.j == y2){
                x3 = line[i].b.i;
                y3 = line[i].b.j;
                line[i].chk = true;     
                break;
            }else if(line[i].b.i == x2 && line[i].b.j == y2){
                x3 = line[i].a.i;
                y3 = line[i].a.j;
                line[i].chk = true;             
                break;
            }
        }
    }
}
 
int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp = temp - y1*x2 - y2*x3 - y3*x1;
    if(temp < 0) return -1;
    else if(temp > 0) return 1;
    return 0;
}
 
char getDir(char dir, int ccw){
    if(dir == 'N'){
        if(ccw < 0) return 'W';
        return 'E';
    } 
    if(dir == 'W'){
        if(ccw < 0) return 'S';
        return 'N';
    } 
    if(dir == 'E'){
        if(ccw < 0) return 'N';
        return 'S';
    } 
    if(dir == 'S'){
        if(ccw < 0) return 'E';
        return 'W';
    } 
}
 
int main(){
    int startX, startY;
    //freopen("test/3442.txt","r",stdin);   
         
    while(1){
        scanf(" %d",&n);    
        if(n == 0){
            return 0;
        }
        for(int i=0; i<n; i++){
            scanf("%d %d",&p1[i].j,&p1[i].i);
            p2[i].i = p1[i].i;
            p2[i].j = p1[i].j;      
        }
        startX = p1[0].i;
        startY = p1[0].j;
        sort(p1, p1+n, comp1);
        sort(p2, p2+n, comp2);
         
        //x축과 평행한 직선 연결
        for(int i=0; i<n/2; i++) {
            line[i].a = p1[2*i];
            line[i].b = p1[2*i+1];      
            line[i].chk = false;        
        }
         
        //y축과 평핸한 직선 연결
        for(int i=0; i<n/2; i++) {
            line[i+n/2].a = p2[2*i];
            line[i+n/2].b = p2[2*i+1];
            line[i+n/2].chk = false;        
        } 
         
        int x1,y1,x2,y2,x3,y3;
        //출발점 찾기    
        char dir = 'N';
        x1=p2[0].i;     
        y1=p2[0].j; 
        x2=p2[1].i;
        y2=p2[1].j; 
        line[n/2].chk = true;
        q.push(Dir(x1,y1,dir));             
             
        while(!(p2[0].i==x2 && p2[0].j==y2)){           
            findLine(x2,y2,x3,y3);      
            dir = getDir(dir,ccw(x1,y1,x2,y2,x3,y3));           
            q.push(Dir(x2,y2,dir));
            x1=x2, y1=y2;
            x2=x3, y2=y3;       
        }       
     
        while(!(q.front().x==startX && q.front().y==startY)){
            q.push(q.front());
            q.pop();
        }
         
        while(!q.empty()){
            printf("%c",q.front().dir);
            q.pop();
        }           
        printf("\n");   
    }
     
    return 0;
}
