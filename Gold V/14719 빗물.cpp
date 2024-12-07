#include<iostream>
using namespace std;
int main()
{
	int H,W;
	int arr[501][501]={0,};
	cin>>H>>W;
	for(int i=0,tmp;i<W;i++){
		cin>>tmp;
		for(int j=0;j<tmp;j++){
			arr[j][i]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(arr[i][j]==1){
				int tmp=0;
				for(int k=j+1;k<W;k++){ //1로 둘러쌓인 부분의 끝점 체크 
					if(arr[i][k]==1){
						tmp=k;
						break;
					}
				}
				
				for(int k=j+1;k<tmp;k++){ //1로 둘러쌓인 첫부분 부터 끝부분까지 개수채크
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
