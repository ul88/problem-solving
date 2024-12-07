#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> coin;
	int dp[100001]={0,};
	int n,k;
	cin>>n>>k;
	for(int i=0,a;i<n;i++){
		cin>>a;
		coin.push_back(a);
	}
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=coin[i];j<=k;j++){
			dp[j] += dp[j-coin[i]];
		}
	}
	cout<<dp[k];
	return 0;
}