#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#define INF INT32_MAX
using namespace std;

vector <pair<int, int> > v;

int distance(int n, int m) {
	return abs(v[n].first - v[m].first) + abs(v[n].second - v[m].second);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, ans = INF;
	cin >> N >> K;

	for (int i = 0, a, b; i < N; i++) {
		cin >> a >> b;
		v.push_back({a,b});
	}

	if (K == 1) {
		for (int i = 0; i < N; i++) {
			int Max = -INF;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				Max = max(Max, distance(i, j));
			}
			ans = min(ans, Max);
		}
	}
	else if (K == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int Max = -INF;
				for (int k = 0; k < N; k++) {
					if (i == k || j == k) continue;
					Max = max(Max, min(distance(i, k), distance(j, k)));
				}
				ans = min(ans, Max);
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					int Max = -INF;
					for (int h = 0; h < N; h++) {
						if (i == h || j == h || k == h) continue;
						Max = max(Max, min(distance(i, h), min(distance(j, h), distance(k, h))));
					}
					ans = min(ans, Max);
				}
			}
		}
	}
	if (ans == -INF) cout << 0;
	else cout << ans;
	return 0;
}