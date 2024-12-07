#include<iostream>
#include<vector>
#include<memory.h>
#define MAX 20
#define INF INT32_MAX
using namespace std;
vector<int> v[MAX+1];
int N;
int dp[1<<MAX]={};
int dfs(int n,int m){
    if(m == (1<<N)-1) return 0;
    if(n >= N) return 0;
    if(dp[m] != -1) return dp[m];
    dp[m] = INF;
    for(int i=0;i<N;i++){
        if(m & (1<<i)) continue;
        dp[m] = min(dp[m], dfs(n+1,m|(1<<i)) + v[n][i]); 
    }
    return dp[m];
}
int main()
{   
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0,a;j<N;j++){
            cin>>a;
            v[i].push_back(a);
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,0);
    return 0;
}