#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define MAX 200000
using namespace std;
using pii = pair<int, int>;
vector <int> graph[MAX+1];
vector <int> unGraph[MAX+1];
vector<vector<int>> cycleGroup;
vector<int> visit;
set<pii> s;

void cycle(int n) {
	if (visit[n]) return;
	visit[n] = 1;
	cycleGroup.back().push_back(n);
	for (int i = 0;i < unGraph[n].size();i++) {
		cycle(unGraph[n][i]);
	}
}

int main()
{
	int cnt = 0;
	int ans = 0;
	int N;
	cin >> N;
	visit.resize(N + 1);
	for (int i = 0;i < N;i++) {
		int a, b;
		cin >> a >> b;
		if(a==b) continue;
		graph[b].push_back(a);
		unGraph[a].push_back(b);
		unGraph[b].push_back(a);
	}

	for (int i = 1;i <= N;i++) {
		if (visit[i]) continue;
		cycleGroup.push_back(vector<int>());
		cycle(i);
	}

	for (int i = 1;i <= N;i++) visit[i] = 0;
	for (int t = 0;t < cycleGroup.size();t++) {
		int cnt = 0;
		for(auto i : cycleGroup[t]){
			if(graph[i].size() > 1) cnt++;
		}
		if(cnt >= 2){
			cout<<-1;
			return 0;
		}
		else if(cnt != 0)
			ans += cycleGroup[t].size()+1;
	}

	cout << ans;
	return 0;
}