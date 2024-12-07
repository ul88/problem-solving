#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;
using ll = long long;
class SegTree{
public:
    SegTree() { m_tree.resize(4*MAX); }

    void init(int node, int start, int end, vector<int>& v);
    ll search(int node, int start, int end, int left, int right);
    void update(int node, int start, int end, int index, int data);
private:
    vector<ll> m_tree;
};

void SegTree::init(int node, int start, int end, vector<int>& v){
    if(start == end) {
        m_tree[node] = v[start];
        return;
    }

    int mid = (start + end)/2;
    init(node*2, start, mid, v);
    init(node*2+1, mid+1, end, v);
    m_tree[node] = m_tree[node*2] + m_tree[node*2+1];
}

ll SegTree::search(int node, int start, int end, int left, int right){
    if(start > right || end < left) return 0;
    if(start >= left && end <= right) return m_tree[node];
    int mid = (start + end) / 2;
    return search(node*2, start, mid, left, right) + search(node*2+1, mid+1, end, left, right);
}

void SegTree::update(int node, int start, int end, int index, int data){
    if(start > index || end < index) return;
    if(start == end){
        m_tree[node] = data;
        return;
    }
    int mid = (start + end)/2;
    update(node*2, start, mid, index, data);
    update(node*2+1, mid+1, end, index, data);
    m_tree[node] = m_tree[node*2] + m_tree[node*2+1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int N,Q;
    cin>>N>>Q;
    v.reserve(N);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    SegTree tree;
    tree.init(1, 0, N-1, v);

    for(int i=0;i<Q;i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        cout<<tree.search(1,0,N-1, x-1, y-1)<<"\n";
        tree.update(1, 0, N-1, a-1, b);
    }
    return 0;
}