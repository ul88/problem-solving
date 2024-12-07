#include<iostream>
#include<vector>
#define MAX 4000001
using namespace std;
/*
 segment tree size 구하기
 배열의 원소의 개수를 N이라고 했을 때, N이 2의 제곱꼴인 경우에는
 Full Binary Tree가 되므로 필요한 노드의 개수는 2*N - 1개이다. 
 N이 2의 제곱꼴이 아닌 경우에는 세그먼트 트리의 높이 H = |lgN|이 되고, 
 필요한 배열의 크기는 2^(H+1) - 1이다.
 이게 귀찮다면 메모리는 좀 낭비하게 되겠지만 그냥 N에 4를 곱하는 것도 한 방법이다. 
 4*N은 모든 경우에 우리가 필요로 하는 배열의 크기보다 크기 때문이다. 
*/
typedef long long ll;
ll tree[MAX]={0,};
ll arr[MAX]={0,};
ll segmentTree(int node,int start,int end){ //segment tree 초기화 
	if(start==end) return tree[node] = arr[start]; 
	int mid = (start+end)/2;
	return tree[node] = segmentTree(node*2,start,mid) + segmentTree(node*2+1,mid+1,end);
}
ll sum(int node,int start,int end,int left,int right){ //합 구하기 
	//만약 2~4까지의 값을 구하고자 할때 
	//left는 2 right는 4 
	if(left>end || right<start) return 0;
	if(left<=start && end <= right) return tree[node];
	int mid = (start+end)/2;
	return sum(node*2,start,mid,left,right) + sum(node*2+1,mid+1,end,left,right);
}
void update(int node,int start,int end,int index,long long gap){ //값 업데이트
	//index는 바꾸고자 하는 위치
	//gap은 바꾸기 전 값과 바꾼 후의 값의 차 
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
	segmentTree(1,0,N-1); //node는 1에서부터 시작, 시작점은 0, 끝점은 N-1 
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
