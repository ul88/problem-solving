#include<iostream>
#include<algorithm>
#define INF 0xFFFFFF
using namespace std;
int main()
{
	int A,B,N,cnt=INF;
	cin>>A>>B;
	cin>>N;
	cnt=min(cnt,(A<B?B-A:A-B));
	for(int i=0,tmp;i<N;i++){
		cin>>tmp;
		cnt=min(cnt,(tmp<B?B-tmp:tmp-B)+1);
	}
	cout<<cnt;
	return 0;
}
