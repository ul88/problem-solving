#include<iostream>
using namespace std;
int dp[4000000]={0,};
int arr[4000000]={0,},l=-1;
void sosu(int n){
	for(int i=2;i<=n;i++){
		int tmp=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				tmp=1;
				break;
			}
		}
		if(tmp==0){
			arr[++l]=i;
		}
	}
}
int main()
{
	int N,cnt=0;
	cin>>N;
	sosu(N);
	int left=0,right=1;
	int	hap=arr[left];
	if(arr[l]==N) cnt++;
	while(left<l){
		if(hap==N) cnt++;
		if(hap<=N){
			hap+=arr[right];
			right++;
		}else{
			hap-=arr[left];
			left++;
		}
	}	
	cout<<cnt<<endl;
	return 0;
}

