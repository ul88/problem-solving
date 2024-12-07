#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10000001
using namespace std;
typedef long long ll;
vector <ll> xidx,yidx,x,y;
ll psum[MAX]={0,};
int main()
{
	int N,M;
	ll a=0,b=0,ans=0;
	cin>>N;
	for(int i=0;i<N;i++){
		ll idx,tmp;
		cin>>idx>>tmp;
		xidx.push_back(idx);
		x.push_back(tmp);
	}
	cin>>M;
	for(int i=0;i<M;i++){
		ll idx,tmp;
		cin>>idx>>tmp;
		yidx.push_back(idx);
		y.push_back(tmp);
		psum[i+1] = psum[i]+tmp;
	}
	cin>>a>>b;
	for(int i=0;i<N;i++){
		ll low = lower_bound(yidx.begin(),yidx.end(),xidx[i]+a)-yidx.begin();
		ll high = lower_bound(yidx.begin(),yidx.end(),xidx[i]+b+1)-yidx.begin();
		ans += x[i] * (psum[high]-psum[low]);
	}
	cout<<ans;
	return 0;
}