#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	long long A,B,C,tmp=1;
	cin>>A>>B>>C;
	while(B!=1){
		if(B%2==1){
			tmp=tmp%C*A%C%C;
		}
		A=A%C*A%C%C;
		B/=2;
	}
	cout<<A*tmp%C;
	return 0;
}
