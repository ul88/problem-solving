#include<iostream>
#include<algorithm>
#define INF 0xFFFFFF
using namespace std;
int main()
{
	int sosu[10001]={0,};
	for(int i=2;i<=10000;i++){
		int tmp=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				tmp=1;
				break;	
			} 
		}
		if(tmp==0) sosu[i]=1;
	}
	int N,M,sosuMin=INF,hap=0;
	bool flag=false;
	cin>>N>>M;
	for(int i=N;i<=M;i++){
		if(sosu[i]==1){
			hap+=i;
			flag=true;
			sosuMin=min(sosuMin,i);
		}
	}
	if(flag==true) cout<<hap<<"\n"<<sosuMin;
	else cout<<-1;
	return 0;
}