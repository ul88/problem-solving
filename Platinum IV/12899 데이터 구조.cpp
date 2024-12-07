#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2000000
using namespace std;
class SegTree{
public:
    SegTree() {m_tree.resize(4*MAX, 0);};
    void add(int node, int start, int end, int data);
    int search(int node, int start, int end, int data);
    void del(int node, int start, int end, int data);
private:
    vector<int> m_tree;
};

void SegTree::add(int node, int start, int end, int data){
    if(start > data || end < data) return;
    if(start == end){
        m_tree[node]+=1;
        return;
    }
    int mid = (start+end)/2;
    add(node*2,start,mid,data);
    add(node*2+1,mid+1,end,data);
    m_tree[node] = m_tree[node*2] + m_tree[node*2+1];
}

int SegTree::search(int node, int start, int end, int data){
    if(start == end) return start;
    int mid = (start+end)/2;
    if(data <= m_tree[2*node]) return search(2*node, start, mid, data);
    else return search(2*node+1, mid+1, end, data-m_tree[2*node]);
}

void SegTree::del(int node, int start, int end, int data){
    if(start > data || end < data) return;
    if(start == end){
        m_tree[node]-=1;
        return;
    }
    int mid = (start+end)/2;
    del(node*2,start,mid,data);
    del(node*2+1,mid+1,end,data);
    m_tree[node] = m_tree[node*2] + m_tree[node*2+1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SegTree tree;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if(a == 1){
            tree.add(1, 1, MAX+1, b);
        }else{
            int ans = tree.search(1, 1, MAX+1, b);
            cout<<ans<<"\n";
            tree.del(1, 1, MAX+1, ans);
        }
    }
    return 0;
}