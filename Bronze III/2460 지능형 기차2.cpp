#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int cnt=0,cntMax=0;
	for(int i=0,a,b;i<10;i++){
		cin>>a>>b;
		cnt+=(b-a);
		cntMax=max(cnt,cntMax);
	}
	cout<<cntMax;
	return 0;
}
