#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector <int> v;
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		if(N%i==0){ 
			v.push_back(i);
		}
	}
	if(v.size()>=K){
		cout<<v[K-1];
	}else cout<<0;
	return 0;
}
