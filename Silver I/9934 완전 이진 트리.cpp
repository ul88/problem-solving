#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int arr[1024]={0,};
vector <int> tree[1024];
void inorder(int height,int left,int right){
	if(left==right) return;
	int mid = (left+right)/2;
	tree[height].push_back(arr[mid]);
	inorder(height+1,left,mid);
	inorder(height+1,mid+1,right);
}
int main()
{
	int K;
	cin>>K;
	for(int i=0;i<pow(2,K)-1;i++) cin>>arr[i];
	inorder(0,0,pow(2,K)-1);
	for(int i=0;i<K;i++){
		for(int j=0;j<tree[i].size();j++){
			cout<<tree[i][j]<<" ";
		} cout<<"\n";
	}
	return 0;
}
