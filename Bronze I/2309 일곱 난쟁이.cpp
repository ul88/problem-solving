#include<iostream>
#include<algorithm> 
using namespace std;
void f(int arr[],int hap){
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(hap-(arr[i]+arr[j])==100){
				arr[i]=-1;
				arr[j]=-1;
				return;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int arr[10]={0,},hap=0;
	for(int i=0;i<9;i++){
		cin>>arr[i];
		hap+=arr[i];
	}
	f(arr,hap);
	sort(arr,arr+9);
	for(int i=2;i<9;i++){
		cout<<arr[i]<<"\n";
	}
	return 0;
} 
