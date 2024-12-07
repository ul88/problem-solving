#include<iostream>
using namespace std;
int arr[1025][1025]={0,};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,M;
	cin>>N>>M; 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			arr[i][j] += arr[i-1][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			arr[i][j] += arr[i][j-1];
		}
	}
	for(int i=0,a,b,c,d;i<M;i++){
		cin>>a>>b>>c>>d;
		cout<<arr[c][d] - arr[c][b-1] - arr[a-1][d] + arr[a-1][b-1]<<"\n";
	}
	return 0;
}
