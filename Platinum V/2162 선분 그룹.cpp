#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 3000
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
int parent[MAX + 1] = { 0, }, visit[MAX + 1] = { 0, };
vector < pair<pi, pi> > v;

int ccw(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3) {
	ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool checkSlope(int a, int b) {
	pi p1 = v[a].first;
	pi p2 = v[a].second;
	pi p3 = v[b].first;
	pi p4 = v[b].second;

	ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		// 비교를 일반화하기 위한 점 위치 변경
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int Find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = Find(parent[n]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0, x1, x2, y1, y2; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		parent[i] = i;
		v.push_back({ {x1,y1}, {x2,y2} });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (checkSlope(i, j)) {
				Union(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		visit[Find(i)]++;
	}

	int ans1 = 0, ans2 = 0;

	for (int i = 0; i < N; i++) {
		if (visit[i]) ans1++;
		ans2 = max(ans2, visit[i]);
	}

	cout << ans1 << "\n" << ans2;

	return 0;
}