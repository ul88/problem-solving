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
sum=0 1>1 ���� 
sum=1 2>1 ���� 
sum=2 3>3 ���� 
sum=5 6>7 �Ұ��� 
sum=12 13>8 ����
1 1 2 3 6 7 30
sum=0 1>1 ����
sum=1 2>1 ����
sum=2 3>2 ����
sum=4 5>3 ����
sum=7 8>6 ����
sum=13 14>7 ����
sum20 21>30 �Ұ��� */
