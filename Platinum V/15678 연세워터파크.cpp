#include<iostream>
#include<vector>
#define INF INT64_MAX
#define MAX 100000
using namespace std;
using ll = long long;
class SegTree{
public:
    SegTree() {tree_.resize(4*MAX, 0);}
    ll top() {return tree_[1];}
    void update(int node, int start, int end, int index, ll gap);
    ll search(int node, int start, int end, int left, int right);
private:
    vector<ll> tree_;
};

void SegTree::update(int node, int start, int end, int index, ll gap){
    if(start > index || end < index) return;
    if(start == end){
        tree_[node] += gap;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, index, gap);
    update(node*2+1, mid+1, end, index, gap);
    tree_[node] = max(tree_[node*2], tree_[node*2+1]);
}

ll SegTree::search(int node, int start, int end, int left, int right){
    if(left > end || right < start) return -INF;
    if(left <= start && end <= right) return tree_[node];
    int mid = (start + end) / 2;
    return max(search(2*node, start, mid, left, right), search(2*node+1, mid+1, end, left, right)); 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SegTree tree;
    int N,D;
    cin>>N>>D;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        tree.update(1, 0, N-1, i, a);
    }
    for(int i=1;i<N;i++){
        ll temp = max(0LL, tree.search(1, 0, N-1, (i-D >= 0 ? i-D : 0), i-1));
        tree.update(1, 0, N-1, i, temp);
    }

    cout<<tree.top();

    return 0;
}