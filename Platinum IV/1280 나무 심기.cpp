#include<iostream>
#include<vector>
#include<cmath>
#define MOD 1000000007
#define MAX 200010
using namespace std;
using ll = long long;
class SegTree{
public:
    SegTree(){
        tree_.resize(4*(MAX+1),0);
    }
    void update(int node, int start, int end, int data, int k);
    ll search(int node, int start, int end, int left, int right);
private:
    vector<ll> tree_;
};

void SegTree::update(int node, int start, int end, int data, int k){
    if(start > data || end < data) return;
    if(start == end){
        tree_[node] += k;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, data, k);
    update(node*2+1, mid+1, end, data, k);
    tree_[node] = tree_[node*2] + tree_[node*2+1];
}

ll SegTree::search(int node, int start, int end, int left, int right){
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return tree_[node];
    int mid = (start + end) / 2;
    return search(node*2, start, mid, left, right) + search(node*2+1, mid+1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    SegTree cntTree, sumTree;
    vector<int> v;
    int N;
    ll ans = 1;
    cin>>N;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        if(i==0){
            cntTree.update(1,0,MAX,a,1);
            sumTree.update(1,0,MAX,a,a);
            continue;
        }
        ll left = 0;
        if(a-1 >= 0) left = a*cntTree.search(1,0,MAX,0,a-1) - sumTree.search(1,0,MAX,0,a-1);
        ll right = sumTree.search(1,0,MAX,a+1,MAX) - a*cntTree.search(1,0,MAX,a+1,MAX);
        cntTree.update(1,0,MAX,a,1);
        sumTree.update(1,0,MAX,a,a);
        ans *= (left%MOD + right%MOD) % MOD;
        ans%=MOD;
    }    
    cout<<ans;
    return 0;
}