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
				for(int k=j+1;k<W;k++){ //1�� �ѷ����� �κ��� ���� üũ 
					if(arr[i][k]==1){
						tmp=k;
						break;
					}
				}
				
				for(int k=j+1;k<tmp;k++){ //1�� �ѷ����� ù�κ� ���� ���κб��� ����äũ
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
