#include <cstdio>
#include <cstring>
using namespace std;
 
int main(){
    char arr[33];
    int jin;
    scanf("%s %d",arr,&jin);
    int len = strlen(arr);
     
    int sum = 0;
    int k = 1;
    while(len--){
        int temp=0;
        if(arr[len] >= '1' && arr[len] <= '9')
            temp = arr[len]-'1'+1;
        else if(arr[len] >= 'A' && arr[len] <= 'Z')
            temp = arr[len]-'A'+10;
 
        sum += temp*k;
        //printf("temp=%d, k=%d, sum=%d\n",temp,k,sum);     
        k*=jin;
    }
    printf("%d\n",sum);
     
    return 0;
}
