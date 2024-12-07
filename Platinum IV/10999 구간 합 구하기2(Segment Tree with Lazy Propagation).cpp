/*
Segment Tree with Lazy Propagation
    https://book.acmicpc.net/ds/segment-tree-lazy-propagation
다시 공부하기
*/
#include<iostream>
#define MAX 1000000
using namespace std;
using ll = long long;
ll tree[4*MAX]={0,};
ll arr[MAX+1]={0,};
ll lazy[4*MAX]={0,};
ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = init(node*2,start,mid) + init(node*2+1,mid+1,end);
}

void updata_lazy(int node, int start, int end){
    if(lazy[node] == 0) return;
    tree[node] += (end-start+1)*lazy[node];
    if(start != end){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, ll diff){
    updata_lazy(node,start,end);
    if(left > end || start > right) return;
    if(left <= start && end <= right){
        tree[node] += (end-start+1)*diff;    
        if(start != end){
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (start + end)/2;
    update(node*2, start, mid, left, right, diff);
    update(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1]; 
}

ll search(int node, int start, int end, int left, int right){
    updata_lazy(node,start,end);
    if(left > end || start > right) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return search(node*2, start, mid, left, right) + search(node*2+1, mid+1, end, left, right);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M,K;
    cin>>N>>M>>K;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    init(1,0,N-1);

    for(int i=0;i<M+K;i++){
        int a;
        cin>>a;
        if(a==1){
            int b, c;
            ll d;
            cin>>b>>c>>d;
            update(1,0,N-1,b-1,c-1,d);
        }else{
            int b,c;
            cin>>b>>c;
            cout<<search(1,0,N-1,b-1,c-1)<<"\n";
        }
    }
    return 0;
}