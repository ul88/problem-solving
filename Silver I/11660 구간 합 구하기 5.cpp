#include<iostream>
#include<vector>
using namespace std;
int arr[1025][1025]={0,},hap[1025][1025]={0,},N,M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			if(j==0) hap[i][j]=arr[i][j];
			else hap[i][j] += hap[i][j-1]+arr[i][j];
		}
	}
	for(int i=0,a,b,c,d;i<M;i++){
		cin>>a>>b>>c>>d;
		if(a==c && b==d){
			cout<<arr[c-1][d-1]<<"\n";
		}
		else{
			int tmp=0;
			for(int i=a-1;i<c;i++){
				tmp+=hap[i][d-1]-(b-1<0 ? 0 : hap[i][b-2]);
			}
			cout<<tmp<<'\n';
		}
	}
	return 0;
}
