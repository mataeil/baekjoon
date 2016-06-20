#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> v;
int main(){
    int n,a,size,cur,ans=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        if(v.size()==0){
            v.push_back(a);
        }else{
            cur = lower_bound(v.begin(), v.end(), a)-v.begin();
            if(cur == v.size()) v.push_back(a);         
            else v[cur] = a;                
        }
        size = v.size();
        ans = max(ans,size);
    }
    printf("%d\n",ans);
    return 0;
}
