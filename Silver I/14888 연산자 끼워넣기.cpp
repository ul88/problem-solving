#include<iostream>
#include<algorithm>
#define INF INT64_MAX
using namespace std;
int N,asmd[4]={0,};
long long arr[12]={0,},gapMax=-INF,gapMin=INF;
void dfs(int n,int a,int s,int m,int d,long long hap){
	if(n>=N){
		gapMax=max(gapMax,hap);
		gapMin=min(gapMin,hap);
	}else{
		if(a-1>=0) dfs(n+1,a-1,s,m,d,hap+arr[n]);
		if(s-1>=0) dfs(n+1,a,s-1,m,d,hap-arr[n]);
		if(m-1>=0) dfs(n+1,a,s,m-1,d,hap*arr[n]);
		if(d-1>=0) dfs(n+1,a,s,m,d-1,hap/arr[n]); 
	}
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];		
	}
	cin>>asmd[0]>>asmd[1]>>asmd[2]>>asmd[3];
	dfs(1,asmd[0],asmd[1],asmd[2],asmd[3],arr[0]);
	cout<<gapMax<<"\n"<<gapMin;
	return 0;
}
