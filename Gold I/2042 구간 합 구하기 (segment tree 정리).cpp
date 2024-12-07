#include<iostream>
#include<vector>
#define MAX 4000001
using namespace std;
/*
 segment tree size ���ϱ�
 �迭�� ������ ������ N�̶�� ���� ��, N�� 2�� �������� ��쿡��
 Full Binary Tree�� �ǹǷ� �ʿ��� ����� ������ 2*N - 1���̴�. 
 N�� 2�� �������� �ƴ� ��쿡�� ���׸�Ʈ Ʈ���� ���� H = |lgN|�� �ǰ�, 
 �ʿ��� �迭�� ũ��� 2^(H+1) - 1�̴�.
 �̰� �����ٸ� �޸𸮴� �� �����ϰ� �ǰ����� �׳� N�� 4�� ���ϴ� �͵� �� ����̴�. 
 4*N�� ��� ��쿡 �츮�� �ʿ�� �ϴ� �迭�� ũ�⺸�� ũ�� �����̴�. 
*/
typedef long long ll;
ll tree[MAX]={0,};
ll arr[MAX]={0,};
ll segmentTree(int node,int start,int end){ //segment tree �ʱ�ȭ 
	if(start==end) return tree[node] = arr[start]; 
	int mid = (start+end)/2;
	return tree[node] = segmentTree(node*2,start,mid) + segmentTree(node*2+1,mid+1,end);
}
ll sum(int node,int start,int end,int left,int right){ //�� ���ϱ� 
	//���� 2~4������ ���� ���ϰ��� �Ҷ� 
	//left�� 2 right�� 4 
	if(left>end || right<start) return 0;
	if(left<=start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}
void update(int node,int start,int end,int index,long long gap){ //�� ������Ʈ
	//index�� �ٲٰ��� �ϴ� ��ġ
	//gap�� �ٲٱ� �� ���� �ٲ� ���� ���� �� 
	if(start>index || end<index) return;
 	tree[node]+=gap;
	if(start!=end){
		int mid = (start+end)/2;
		update(node*2,start,mid,index,gap);
		update(node*2+1,mid+1,end,index,gap); 
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	segmentTree(1,0,N-1); //node�� 1�������� ����, �������� 0, ������ N-1 
	for(int i=0;i<M+K;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		if(a==1){
			update(1,0,N-1,b-1,c-arr[b-1]);
			arr[b-1]=c;
		}else{
			cout<<sum(1,0,N-1,b-1,c-1)<<"\n";
		}
	}
	return 0;
}                   
