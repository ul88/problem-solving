#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> v,dp;
    int N,M;
    cin>>N>>M;
    v.resize(N+1);
    dp.resize(N+1);

    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        v[a]=1;
    }

    dp[0] = dp[1] = 1;
    for(int i=2;i<=N;i++){
        if(v[i] == 1 || v[i-1] == 1) dp[i] = dp[i-1];
        else dp[i] = dp[i-2] + dp[i-1];
    }

    cout<<dp[N];
    return 0;
}