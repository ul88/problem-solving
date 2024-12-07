#include<iostream>
#include<algorithm>
#define MAX 3000000
#define INF INT32_MAX
using namespace std;
int dp[MAX+1]={0,};
int main()
{
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        dp[i] = INF;
    }
    for(int i=1;i<=N;i++){
        dp[i+1] = min(dp[i+1],dp[i]+1);
        dp[i*2] = min(dp[i*2],dp[i]+1);
        dp[i*3] = min(dp[i*3],dp[i]+1);
    }
    cout<<dp[N];
    return 0;
}