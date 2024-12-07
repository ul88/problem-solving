#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 300
using namespace std;
vector <int> v;
int dp[MAX+1][3]={0,};
int dfs(int n, int k){
    if(n < 0) return 0;
    if(k >= 2) return 0;
    if(dp[n][k] != 0) return dp[n][k];
    return dp[n][k] += max(dfs(n-1,k+1),dfs(n-2,0)) + v[n];
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    cout<<dfs(N-1,0);

    return 0;
}