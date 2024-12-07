#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T,N;
	cin>>T;
	while(T--){
		int cnt=0;
		vector <int> v;
		cin>>N;
		while(N>0){
			if(N%2==1){
				v.push_back(cnt);
			}
			N/=2;
			cnt++;
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}
