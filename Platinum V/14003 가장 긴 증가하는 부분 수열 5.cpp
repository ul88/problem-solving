#include<iostream>
#include<vector>
#include<stack>
#define MAX 1000001
#define INF 0xFFFFFFF
using namespace std;
vector <int> v; 
vector <int> LIS;
int dp[MAX]={0,};
stack <int> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,idx=0,tmp=0;
	cin>>N;
	for(int i=0,a=0;i<N;i++){
		cin>>a;
		v.push_back(a);
	}

	LIS.push_back(v[0]);
	dp[0]=0;
	for(int i=1;i<N;i++){
		if(v[i]>LIS.back()){
			LIS.push_back(v[i]);
			dp[i]=LIS.size()-1;
		}else{
			int pos = lower_bound(LIS.begin(),LIS.end(),v[i])-LIS.begin();
			LIS[pos] = v[i];
			dp[i]=pos;
		}
	}
	idx=LIS.size()-1;
	cout<<LIS.size()<<'\n';
	for(int i=N-1;i>=0;i--){
		if(idx==dp[i]){
			idx--;
			s.push(v[i]);
		}
	}
	while(!s.empty(	)){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
