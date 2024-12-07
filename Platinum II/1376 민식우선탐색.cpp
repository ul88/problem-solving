#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100000
using namespace std;

class SegTree {
public:
    void addEdge(int e);
    void init() {
        if(m_graph.size() == 0) return;
        m_tree.resize(4*m_graph.size());
        sort(m_graph.begin(), m_graph.end());
        m_graph.erase(unique(m_graph.begin(),m_graph.end()),m_graph.end());
        init(1, 1, m_graph.size());
    }
    // 그래프에 들어가있는 정점의 번호가 아닌 정점의 인덱스를 기준으로 세그트리를 생성
    void init(int node, int start, int end);

    void update(int data, int gap) {
        update(1, 1, m_graph.size(), data, gap);
    }
    void update(int node, int start, int end, int data, int gap);

    int search(int data) {
        return search(1, 1, m_graph.size(), data);
    }
    int search(int node, int start, int end, int data);

    vector<int>& getGraph() {return m_graph;}
    int getGraphData(int idx) { return m_graph[idx-1]; }
    int getGraphIndex(int data) { return lower_bound(m_graph.begin(), m_graph.end(), data) - m_graph.begin() + 1; }
    int count();
private:
    vector<int> m_tree;
    vector<int> m_graph;
};

void SegTree::addEdge(int e) {
    m_graph.emplace_back(e);
}

void SegTree::init(int node, int start, int end) {
    if (start == end) {
        m_tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    m_tree[node] = m_tree[node * 2] + m_tree[node * 2 + 1];
}

void SegTree::update(int node, int start, int end, int data, int gap) {
    if (start > data || end < data) return;
    if (start == end) {
        m_tree[node] += gap;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, data, gap);
    update(node * 2 + 1, mid + 1, end, data, gap);
    m_tree[node] = m_tree[node * 2] + m_tree[node * 2 + 1];
}

int SegTree::search(int node, int start, int end, int data) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (data <= m_tree[2 * node]) return search(node * 2, start, mid, data);
    else return search(node * 2 + 1, mid + 1, end, data - m_tree[2 * node]);
}

int SegTree::count() {
    return m_tree[1];
}

vector<SegTree> tree;
int visit[MAX + 1];

void mst(int n) {
    if (visit[n]) return;
    visit[n] = 1;
    cout << n << " ";
    for(auto iter : tree[n].getGraph()){
        int idx = tree[iter].getGraphIndex(n);
        tree[iter].update(idx, -1);
    }

    while(tree[n].count() > 0){
        int now;
        if(tree[n].count()%2 == 1){
            now = tree[n].search((tree[n].count()+1)/2);
        }else{
            now = tree[n].search(1);
        }
        if(!visit[tree[n].getGraphData(now)])
            mst(tree[n].getGraphData(now));
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    tree.resize(N + 1);
    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        tree[a].addEdge(b);
        tree[b].addEdge(a);
    }

    for (int i = 1;i <= N;i++) {
        tree[i].init();
    }

    mst(1);

    return 0;
}