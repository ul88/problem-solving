#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;
class SegTree{
public:
    SegTree() { m_tree.resize(4*MAX); }

    void update(int node, int start, int end, int data, int count);
    int search(int node, int start, int end, int data);
private:
    vector<int> m_tree;
};

void SegTree::update(int node, int start, int end, int data, int count){
    if(start > data || end < data) return;
    if(start == end){
        m_tree[node]+=count;
        return;
    }

    int mid = (start+end)/2;
    update(node*2, start, mid, data, count);
    update(node*2+1, mid+1, end, data, count);
    m_tree[node] = m_tree[node*2] + m_tree[node*2+1];
}

int SegTree::search(int node, int start, int end, int data){
    if(start == end) return start;
    int mid = (start+end)/2;
    if(data <= m_tree[node*2]) return search(node*2, start, mid, data);
    else return search(node*2+1, mid+1, end, data - m_tree[node*2]);
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
        int a,b,c;
        cin>>a;
        if(a==1){
            cin>>b;
            int ans = tree.search(1,1,MAX+1,b);
            cout<<ans<<"\n";
            tree.update(1,1,MAX+1,ans,-1);
        }else{
            cin>>b>>c;
            tree.update(1,1,MAX+1,b,c);
        }
    }

    return 0;
}