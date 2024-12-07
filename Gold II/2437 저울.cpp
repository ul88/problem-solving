#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N,arr[1001]={0,};
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	int sum=0;
	for(int i=0;i<N;i++){  
		if(sum+1<arr[i]) break;
		sum+=arr[i];
	}
	cout<<sum+1<<endl;
	return 0;
} 
/*1 1 3 7 8   
sum=0 1>1 가능 
sum=1 2>1 가능 
sum=2 3>3 가능 
sum=5 6>7 불가능 
sum=12 13>8 가능
1 1 2 3 6 7 30
sum=0 1>1 가능
sum=1 2>1 가능
sum=2 3>2 가능
sum=4 5>3 가능
sum=7 8>6 가능
sum=13 14>7 가능
sum20 21>30 불가능 */
