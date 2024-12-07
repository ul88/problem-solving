#include<iostream>
#define MAX 100
using namespace std;
int main()
{
	int arr[MAX+1][MAX+1]={0,},cnt=0;
	for(int i=0,a,b,c,d;i<4;i++){
		cin>>a>>b>>c>>d;
		for(int i=a;i<c;i++){
			for(int j=b;j<d;j++){
				if(arr[i][j]>=1);
				else{
					arr[i][j]++;
					cnt++;
				}
			}
		}
	}
    cout<<cnt;
	return 0;
}