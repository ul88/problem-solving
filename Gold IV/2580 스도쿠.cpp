#include<iostream>
#include<vector>
#define MAX 9
using namespace std;
int sdoku[MAX + 1][MAX + 1] = { 0, };
vector <pair<int,int> > v;
bool isAnswer = false;
bool checkSquare(int n,int m) {
	// (0 1 2) / 3 == 0 * 3 = 0
	// (3 4 5) / 3 == 1 * 3 = 3
	// (6 7 8) / 3 == 2 * 3 = 6
	bool visit[MAX + 1] = { 0, };
	for (int i = (n / 3) * 3; i < (n / 3 + 1) * 3; i++) {
		for (int j = (m / 3) * 3; j < (m / 3 + 1) * 3; j++) {
			if (sdoku[i][j] == 0) continue;
			if (visit[sdoku[i][j]]) {
				return false;
			}
			visit[sdoku[i][j]] = 1;
		}
	}
	return true;
}

bool checkRow(int n, int m) {
	bool visit[MAX + 1] = { 0, };
	for (int i = 0; i < MAX; i++) {
		if (sdoku[i][m] == 0) continue;
		if (visit[sdoku[i][m]]) {
			return false;
		}
		visit[sdoku[i][m]] = 1;
	}
	return true;
}

bool checkCol(int n, int m) {
	bool visit[MAX + 1] = { 0, };
	for (int i = 0; i < MAX; i++) {
		if (sdoku[n][i] == 0) continue;
		if (visit[sdoku[n][i]]) {
			return false;
		}
		visit[sdoku[n][i]] = 1;
	}
	return true;
}

bool isCheck(int n, int m) {
	if (checkSquare(n,m) && checkRow(n, m) && checkCol(n, m)) return true;
	else return false;
}

void dfs(int n) {
	if (n == v.size()) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << sdoku[i][j] << " ";
			}
			cout << "\n";
		}
		isAnswer = true;
		return;
	}
	if (isAnswer) return;
	for (int i = 1; i <= MAX; i++) {
		sdoku[v[n].first][v[n].second] = i;
		if (isCheck(v[n].first, v[n].second)) {
			dfs(n + 1);
		}
	}
	sdoku[v[n].first][v[n].second] = 0;
}

int main()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> sdoku[i][j];
			if (sdoku[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}

	dfs(0);

	return 0;
}