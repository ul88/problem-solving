#include<iostream>
#include<vector>
#define MAX 250000
using namespace std;
int main()
{
    int dp[2][MAX+1]={};
    vector<int> v;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    v.push_back(v[0]);
    dp[0][1] = v[0];
    dp[1][0] = 1;
    for(int i=1;i<N;i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]) + v[i];
        dp[1][i] = dp[0][i-1] + 1;  
    }

    cout<<max(dp[0][N-1], dp[1][N-1]);
    return 0;
}