#include<iostream>
#define MAX 100
using namespace std;
int parent[MAX + 1] = { 0, };
int Find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = Find(parent[n]);
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
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0,a,b; i < M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 2; i <= N; i++) {
		if (Find(i) == 1) ans++;
	}

	cout << ans;
	return 0;
}