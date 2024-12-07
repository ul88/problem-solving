#include<iostream>
#include<vector>
#define MAX 10000
using namespace std;
int dp[MAX+1][101]={0,};
vector <pair<int,int>> v;
int T,k;
int dfs(int sum,int n){
    if(sum == 0) return 1;
    if(n>=v.size()) return 0;
    if(sum < 0) return 0;
    if(dp[sum][n] != -1) return dp[sum][n];
    int result = 0;
    for(int i=0;i<=v[n].second;i++){
        if(sum - (v[n].first*i) < 0) continue;
        result += dfs(sum-(v[n].first*i),n+1);
    }
    return dp[sum][n] = result;
}

int main()
{
    cin>>T>>k;
    for(int i=0,a,b;i<k;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    for(int i=0;i<=MAX;i++){
        for(int j=0;j<=100;j++){
            dp[i][j] = -1;
        }
    }

    cout<<dfs(T,0);

    return 0;
}