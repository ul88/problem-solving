#include<iostream>
#include<algorithm>
#include<vector>
#define INF INT32_MAX
using namespace std;
typedef long long ll;
int main()
{
	vector <int> v;
	int n;
	cin>>n;
	for(int i=0,a;i<n;i++){
		cin>>a;
		v.push_back(a);
	}

	sort(v.begin(),v.end());
	
	int ans=INF;
	for(int i=0;i<=100;i++){
		int tmp = 0;
		int left = upper_bound(v.begin(),v.end(),i)-v.begin()-1;
		int right = upper_bound(v.begin(),v.end(),i+17)-v.begin();
		for(int j=0;j<=left;j++){
			tmp += ((i-v[j])*(i-v[j]));
		}
		for(int j=right;j<n;j++){
			tmp += ((v[j]-(i+17))*(v[j]-(i+17)));
		}

		ans = min(ans,tmp);
	}
	cout<<ans;
	return 0;
}