#include<iostream>
#define MAX 999
using namespace std;
int main()
{
	int N,tmp=0,arr[MAX+1]={0,}	;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i]; 
		if(i==0) tmp=arr[i];
		else{
			if(i%2==0){
				tmp+=arr[i];
			}else tmp-=arr[i];
		}
	}
	tmp/=2;
	cout<<tmp<<endl;
	for(int i=0;i<N-1;i++){
		tmp=arr[i]-tmp;
		cout<<tmp<<endl;
	}
	return 0;
}
