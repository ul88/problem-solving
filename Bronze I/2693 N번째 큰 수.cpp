#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		vector <int> v;
		for(int i=0,tmp;i<10;i++){
			cin>>tmp;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end());
		cout<<v[7]<<"\n";
	}
	return 0;
}
