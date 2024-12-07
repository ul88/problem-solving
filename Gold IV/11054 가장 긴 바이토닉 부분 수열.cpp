#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,arr[1001]={0,},dp[1001]={0,},cnt=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		dp[i]=1;
	}
	for(int i=0;i<N;i++){ //증가 수열 체크 
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	for(int i=0;i<N;i++){ //감소 수열 체크 
		for(int j=0;j<i;j++){
			if(arr[i]<arr[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		cnt=max(dp[i],cnt);
	}
	cout<<cnt;
	return 0;
}
