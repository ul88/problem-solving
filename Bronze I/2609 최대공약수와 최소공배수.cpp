#include<iostream>
using namespace std;
int GCD(int a,int b){
	return b==0 ? a:GCD(b,a%b);
}
int LCM(int a,int b){
	return a*b/GCD(a,b);
}
int main()
{
	int N,M;
	cin>>N>>M;
	cout<<GCD(N,M)<<" "<<LCM(N,M);
	return 0;
}
