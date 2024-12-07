#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int,int> > v;
int N,K;
int dp[1001][100001]={0,};
int main()
{
	ios::sync_with_stdio(0);
	cin>>N>>K;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			if(j-v[i-1].first>=0)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1].first]+v[i-1].second);
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[N][K];
	return 0;
}
