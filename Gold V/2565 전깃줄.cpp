#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector <pair<int,int> > v;
	int N,dp[501]={0,},ans=0;
	cin>>N;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		dp[i]=1;
		for(int j=0;j<v.size();j++){
			if(v[i].second > v[j].second){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans,dp[i]);
	}
	cout<<N-ans;
	return 0;
}
