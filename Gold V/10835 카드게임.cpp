#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 2000
using namespace std;
vector<int> A,B;
int dp[MAX+1][MAX+1]={0,};
int dfs(int a, int b){
    if(a >= A.size() || b >=B.size()) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    if(A[a] > B[b]) return dp[a][b] = max(dp[a][b] , dfs(a,b+1)+B[b]);
    return dp[a][b] = max(dp[a][b], max(dfs(a+1,b),dfs(a+1,b+1)));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    for(int i=0,a;i<N;i++){
        cin>>a;
        A.push_back(a);
    }

    for(int i=0,a;i<N;i++){
        cin>>a;
        B.push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    cout<<dfs(0,0);

    return 0;
}