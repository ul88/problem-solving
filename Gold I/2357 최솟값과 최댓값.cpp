#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
#define INF INT32_MAX
using namespace std;
vector<int> v;
int maxBT[MAX*4]={0,};
int minBT[MAX*4]={0,};

int minSegmentTree(int node,int start, int end){
    if(start == end) return minBT[node] = v[start];
    int mid = (start + end)/2;
    return minBT[node] = min(minSegmentTree(node*2,start,mid), minSegmentTree(node*2+1,mid+1,end));
}

int searchMin(int node, int start, int end, int left, int right){
    if(left > end || right < start) return INF;
    if(left <= start && end <= right) return minBT[node];
    int mid = (start + end)/2;
    return min(searchMin(node*2,start,mid,left,right),searchMin(node*2+1,mid+1,end,left,right));
}

int maxSegmentTree(int node,int start, int end){
    if(start == end) return maxBT[node] = v[start];
    int mid = (start + end)/2;
    return maxBT[node] = max(maxSegmentTree(node*2,start,mid), maxSegmentTree(node*2+1,mid+1,end));
}

int searchMax(int node, int start, int end, int left, int right){
    if(left > end || right < start) return -INF;
    if(left <= start && end <= right) return maxBT[node];
    int mid = (start + end)/2;
    return max(searchMax(node*2,start,mid,left,right),searchMax(node*2+1,mid+1,end,left,right));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    minSegmentTree(1,0,N-1);
    maxSegmentTree(1,0,N-1);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        cout<<searchMin(1,0,N-1,a-1,b-1)<<" "<<searchMax(1,0,N-1,a-1,b-1)<<"\n";
    }
    
    return 0;
}