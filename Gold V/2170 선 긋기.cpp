#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pii> v;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}

	sort(v.begin(),v.end());

	int start = v[0].first, end = v[0].second;
	ll ans = 0; 
	for(int i=1;i<N;i++){
		if(end >= v[i].first){
			end = max(end,v[i].second);
			start = min(start, v[i].first);
		}else{
			ans += abs(end-start);
			start = v[i].first;
			end = v[i].second;
		}
	}
	ans += abs(end-start);
	cout<<ans;
	return 0;
}