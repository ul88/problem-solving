#include<iostream>
#include<algorithm>
#define MAX 20
using namespace std;
int N,ans=0;
int board[MAX + 1][MAX + 1] = { 0, };

void move(int dir) {
	if (dir == 0) { // 상
		for (int i = 0; i < N; i++) { // col
			for (int j = 0; j < N; j++) { // row
				if (board[j][i]) {
					for (int k = j+1; k < N; k++) {
						if (board[k][i] == board[j][i]) {
							board[j][i] *= 2;
							board[k][i] = 0;
							break;
						}
						if (board[k][i]) break;
					}
				}
				else {
					for (int k = j + 1; k < N; k++) {
						if (board[k][i]) {
							board[j][i] = board[k][i];
							board[k][i] = 0;
							j--;
							break;
						}
					}
				}
			}
		}
	}
	else if (dir == 1) { // 하
		for (int i = 0; i < N; i++) { // col
			for (int j = N-1; j >= 0; j--) { // row
				if (board[j][i]) {
					for (int k = j-1; k >= 0; k--) {
						if (board[k][i] == board[j][i]) {
							board[j][i] *= 2;
							board[k][i] = 0;
							break;
						}
						if (board[k][i]) break;
					}
				}
				else {
					for (int k = j - 1; k >= 0; k--) {
						if (board[k][i]) {
							board[j][i] = board[k][i];
							board[k][i] = 0;
							j++;
							break;
						}
					}
				}
			}
		}
	}
	else if (dir == 2) { // 좌
		for (int i = 0; i < N; i++) { // row
			for (int j = 0; j < N; j++) { // col
				if (board[i][j]) {
					for (int k = j+1; k < N; k++) {
						if (board[i][k] == board[i][j]) {
							board[i][j] *= 2;
							board[i][k] = 0;
							break;
						}
						if (board[i][k]) break;
					}
				}
				else {
					for (int k = j + 1; k < N; k++) {
						if (board[i][k]) {
							board[i][j] = board[i][k];
							board[i][k] = 0;
							j--;
							break;
						}
					}
				}
			}
		}
	}
	else { // 우
		for (int i = 0; i < N; i++) { // row
			for (int j = N - 1; j >= 0; j--) { // col
				if (board[i][j]) {
					for (int k = j - 1; k >= 0; k--) {
						if (board[i][k] == board[i][j]) {
							board[i][j] *= 2;
							board[i][k] = 0;
							break;
						}
						if (board[i][k]) break;
					}
				}
				else {
					for (int k = j - 1; k >= 0; k--) {
						if (board[i][k]) {
							board[i][j] = board[i][k];
							board[i][k] = 0;
							j++;
							break;
						}
					}
				}
			}
		}
	}
}

void swap(int copyBoard[][MAX+1], int recent[][MAX+1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copyBoard[i][j] = recent[i][j];
		}
	}
}

void dfs(int cnt) {

	int copyBoard[MAX + 1][MAX + 1] = { 0, };

	

	if (cnt == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, board[i][j]);
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		swap(copyBoard,board);
		move(i);
		dfs(cnt - 1);
		swap(board,copyBoard);
	}

}
int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(5);

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << board[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << ans;

	return 0;
}