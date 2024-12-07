#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll S,tmp=1,ans=0;
	cin>>S;
	while(S!=0){
		S-=tmp++;
		ans++;
		if(S-tmp<0){
			break;
		}
	}
	cout<<ans;
	return 0;
}
