#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> v;
	vector <int> presum;
	presum.push_back(0);
	int N;
	cin>>N;
	for(int i=0,a;i<N;i++){
		cin>>a;
		v.push_back(a);
		presum.push_back(presum[i]+v[i]);
	}
	int ans=presum[1];
	int Min=presum[1];
	for(int i=2;i<=N;i++){
		ans=max(ans,presum[i]-Min);
		ans=max(ans,presum[i]);
		Min=min(presum[i],Min);
	}
	cout<<ans;
	return 0;
}
