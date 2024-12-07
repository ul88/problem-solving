#include<iostream>
using namespace std;
/**가장 큰 증가하는 부분 수열 활용**/ 
int main()
{
	int arr[201]={0,},dp[201]={0,},N,cnt=0;
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	for(int i=0;i<N;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		cnt=max(cnt,dp[i]);
	}
	cout<<N-cnt;
	return 0;
}
