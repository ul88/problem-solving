#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long long N,S,arr[100001]={0,};
	cin>>N>>S;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	int left=0,right=0,cnt=0;
	long long hap=arr[0];
	while(right<N){
		if(hap>=S){
			if(cnt==0) cnt=right-left+1;
			else cnt=min(cnt,right-left+1);
			hap-=arr[left];
			left++;
		}
		else{
			right++;
			hap+=arr[right];
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
