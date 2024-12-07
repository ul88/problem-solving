#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int N,K;
	long long ans=0;
	vector <pair<int,int> > v;
	vector <int> bag;
	priority_queue <int> pq;
	cin>>N>>K;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	for(int i=0,a;i<K;i++){
		cin>>a;
		bag.push_back(a);
	}
	sort(v.begin(),v.end());
	sort(bag.begin(),bag.end());
	
	int idx=0;
	
	for(int i=0;i<bag.size();i++){
		while(bag[i] >= v[idx].first && idx<v.size()){
			pq.push(v[idx++].second);
		}
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	cout<<ans;
	return 0;
}
