#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		vector <int> v[2];
		int dp[2][100001]={0,};
		int N,ans=0;
		cin>>N; 
		for(int i=0;i<2;i++){
			for(int j=0,a;j<N;j++){
				cin>>a;
				v[i].push_back(a);
			}
		}
		dp[0][0]=v[0][0];
		dp[1][0]=v[1][0];
		ans=max(dp[0][0],dp[1][0]);
		for(int i=1;i<N;i++){
			dp[0][i] = max(dp[0][i-1],dp[1][i-1]+v[0][i]);
			dp[1][i] = max(dp[1][i-1],dp[0][i-1]+v[1][i]);
			ans=max(ans,dp[0][i]);
			ans=max(ans,dp[1][i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
