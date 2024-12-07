#include<stdio.h>
#define MAX 2501
int max(int a,int b){
    if(a<b) return b;
    else return a;
}
int main()
{
    int arr[MAX+1]={0,},dp[MAX+1]={0,};
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }


    for(int i=0;i<N;i++){
        
        if(i!=0) dp[i] = max(dp[i-1],dp[i]);
        
        int temp = arr[i];
        for(int j=i+1;j<N;j++){
            temp = arr[j] - temp;
            if(temp < 0) break;
            if(temp == 0){
                dp[j] = dp[i-1]+1;
                break;
            }
        }
    }

    printf("%d",N-dp[N-1]);
    return 0;
}