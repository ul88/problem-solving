//dp풀이 
#include<iostream>
using namespace std;
int main()
{
	int N,arr[1001]={0,},dp[1001]={0,},cnt=0;
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	for(int i=0;i<N;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		cnt=max(cnt,dp[i]);
	}
	cout<<cnt<<endl;
	return 0;
} 
//dfs,dp풀이 
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int cnt=0,N,arr[1001]={0,},dp[1001][1001]={0,};
//int dfs(int n,int ans){
//	if(n>=N);
//	else if(dp[ans][n]!=0);
//	else{
//		if(arr[ans]<arr[n]){
//			dp[ans][n]=max(dp[ans][n],dfs(n+1,n))+1;
//		}
//		dp[ans][n]=max(dp[ans][n],dfs(n+1,ans));
//	}
//	return dp[ans][n];
//}
//int main()
//{
//	cin>>N;
//	for(int i=0;i<N;i++){
//		cin>>arr[i];
//	}
//	for(int i=0;i<N;i++){
//		cnt=max(cnt,dfs(i+1,i));
//	}
//	cout<<cnt+1;
//	return 0;
//} 
