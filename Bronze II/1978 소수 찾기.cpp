#include<iostream>
using namespace std;
int main()
{
	int sosu[1001]={1,1,};
	for(int i=2;i<=1000;i++){
		if(sosu[i] == 1) continue;
		for(int j=i+i;j<=1000;j+=i){
			sosu[j] = 1;
		}
	}
	int N,cnt=0;
	cin>>N;
	for(int i=0,tmp;i<N;i++){
		cin>>tmp;
		if(sosu[tmp]==0) cnt++;
	}
	cout<<cnt;
	return 0;
}