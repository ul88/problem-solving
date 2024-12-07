#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector <pair<int,int> > v;
	int N,ans=0;
	cin>>N;
	for(int i=0,a;i<N;i++){
		cin>>a;
		v.push_back(make_pair(a,i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++){
		ans=max(ans,v[i].second-i);
	}
	cout<<ans+1;
}
