#include<iostream>
using namespace std;
int main()
{
	int arr[101]={0,},loc[101]={0,};
	int N,K,cnt=0;
	cin>>N>>K;
	for(int i=0;i<K;i++){
		cin>>arr[i];
	}
	if(N<K){	
		for(int i=0;i<K;i++){
			int p=0;
			//�÷��װ� �̹� �����ִٸ� 
			for(int j=0;j<N;j++){
				if(loc[j]==arr[i]){
					p=1;
					break;
				}
			}
			if(p==1) continue;
			//����ִ� ���� �÷��׸� ���� 
			for(int j=0;j<N;j++){
				if(loc[j]==0){
					loc[j]=arr[i];
					p=1;
					break;
				}
			}
			if(p==1) continue;
			//���� ���� ����Ǵ� �÷��״� �����ϰ� �ٸ� �÷��׸� ���� 
			int idx=0,ansComp=0;
			for(int j=0;j<N;j++){
				int ans=0; 
				for(int k=i+1;k<K;k++){
					if(loc[j]==arr[k]) break;
					ans++;
				}
				if(ansComp<ans){
					ansComp=ans;
					idx=j;
				}
			}
			cnt++;
			loc[idx]=arr[i];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
