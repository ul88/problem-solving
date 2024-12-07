#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 50
using namespace std;
char map[MAX + 1][MAX + 1] = { 0, };
int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };
int N, M;

int bfs(int n, int m) {
	int visit[MAX + 1][MAX + 1] = { 0, }, cnt = 0;
	queue <pair<pair<int,int> , int> > q;
	q.push({ {n, m}, 0});
    visit[n][m] = 1;
	while (!q.empty()) {
		int nowN = q.front().first.first;
		int nowM = q.front().first.second;
		int cost = q.front().second;
		q.pop();
		cnt = max(cnt, cost);
		for (int i = 0; i < 4; i++) {
			if (nowN + dx[i] < 0 || nowN + dx[i] >= N || nowM + dy[i] < 0 || nowM + dy[i] >= M) continue;
			if (map[nowN + dx[i]][nowM + dy[i]] == 'W') continue;
            if(visit[nowN + dx[i]][nowM + dy[i]]) continue;
			visit[nowN + dx[i]][nowM + dy[i]] = 1;
			q.push({ {nowN + dx[i], nowM + dy[i]}, cost + 1 });
		}
	}

	return cnt;
}

int main()
{
	int ans = 0, idx = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'W') continue;
			ans = max(ans, bfs(i,j));
		}
	}

	cout << ans;
	return 0;
}