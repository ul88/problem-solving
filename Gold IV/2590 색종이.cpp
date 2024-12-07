#include<iostream>
#define MAX 6
using namespace std;
int main()
{
	int ans = 0;
	int paper[MAX+1] = { 0, };
	for (int i = 0; i < MAX; i++) {
		cin >> paper[i];
	}

	ans += paper[5];

	while (paper[4] > 0) {
		if (paper[0] > 11) {
			paper[0] -= 11;
		}
		else {
			paper[0] = 0;
		}
		paper[4]--;
		ans++;
	}

	int cnt = 0;

	while (paper[3] > 0) {
		cnt = 20;
		if (paper[1] > 5) {
			paper[1] -= 5;
			cnt = 0;
		}
		else {
			cnt -= paper[1]*4;
			paper[1] = 0;
		}

		if (paper[0] <= cnt) {
			paper[0] = 0;
		}
		else {
			paper[0] -= cnt;
		}
		paper[3]--;
		ans++;
	}


	while (paper[2] > 0) {
		cnt = 36;
		if (paper[2] >= 4) {
			paper[2] -= 4;
			cnt = 0;
		}
		else {
			cnt -= paper[2] * 9;
			if (paper[2] == 1) {
				if (paper[1] > 5) {
					cnt -= 20;
					paper[1] -= 5;
				}
				else {
					cnt -= paper[1] * 4;
					paper[1] = 0;
				}
			}
			if (paper[2] == 2) {
				if (paper[1] > 3) {
					cnt -= 12;
					paper[1] -= 3;
				}
				else {
					cnt -= paper[1] * 4;
					paper[1] = 0;
				}
			}
			if (paper[2] == 3) {
				if (paper[1] > 1) {
					cnt -= 4*paper[1];
					paper[1] = 0;
				}
			}
			if (paper[0] <= cnt) {
				paper[0] = 0;
			}
			else {
				paper[0] -= cnt;
			}
			paper[2] = 0;
		}
		ans++;
	}

	while (paper[1] > 0) {
		cnt = 36;
		if (paper[1] > 9) {
			paper[1] -= 9;
		}
		else {
			cnt -= paper[1] * 4;
			paper[1] = 0;
			if (paper[0] <= cnt) {
				paper[0] = 0;
			}
			else {
				paper[0] -= cnt;
			}
		}
		ans++;
	}

	while (paper[0] > 0) {
		if (paper[0] > 36) {
			paper[0] -= 36;
		}
		else {
			paper[0] = 0;
		}
		ans++;
	}

	cout << ans;
	return 0;
}