#include<iostream>
#define MAX 10000
using namespace std;
int main()
{
	int N,ans=0;
	bool flag[MAX+1]={0,};
	cin>>N;
	for(int i=0,a,b;i<N;i++){
		cin>>a>>b;
		for(int j=a;j<b;j++){
			if(flag[j]) continue;
			flag[j]=1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}