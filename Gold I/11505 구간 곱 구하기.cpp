#include<iostream>
#define MAX 1000000
#define MOD 1000000007
using namespace std;
using ll = long long;
ll arr[MAX+1]={0,};
ll tree[4*MAX]={0,};
ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = (init(node*2,start,mid) * init(node*2+1,mid+1,end))%MOD;
}

void update(int node, int start, int end, int idx, int data){
    if(start == end){
        tree[node] = data;
        return;
    }
    int mid = (start + end)/2;
    if(start <= idx && idx <= mid){
        update(node*2,start,mid,idx,data);
    }
    else if(mid+1 <= idx && idx <= end){
        update(node*2+1,mid+1,end,idx,data);
    }
    tree[node] = (tree[node*2] * tree[node*2+1])%MOD;
}

ll search(int node, int start, int end, int left, int right){
    if(left > end || right < start ) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    return (search(node*2,start,mid,left,right) * search(node*2+1,mid+1,end,left,right))%MOD;
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
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(1,0,N-1,b-1,c);
        }else{
            cout<<search(1,0,N-1,b-1,c-1)<<"\n";
        }
    }
    return 0;
}