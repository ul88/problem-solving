#include<iostream>
#include<algorithm>
#define INF 0xFFFFFF
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	long long M=-INF,m=INF;
	cin>>N;
	for(int i=0;i<N;i++){
		long long tmp=0;
		cin>>tmp;
		M=max(M,tmp);
		m=min(m,tmp);
	}
	cout<<m<<" "<<M;
	return 0;
}
