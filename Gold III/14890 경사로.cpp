#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 100
using namespace std;
int arr[MAX + 1][MAX + 1] = {0, };
int N, L;
int solve1(int row) {
	for(int i=0;i<N-1;i++){
        if(arr[row][i] == arr[row][i+1]) continue;
        if(abs(arr[row][i] - arr[row][i+1]) >= 2) return 0;
        
        for(int j=1;j<=L;j++){
            if(i+j >= N) return 0;
            if(abs(arr[row][i] - arr[row][i+j]) != 1) return 0;
        }
        i+=L-1;
    }
	
	return 1;
}

int solve2(int col) {
	for(int i=0;i<N-1;i++){
        if(arr[i][col] == arr[i+1][col]) continue;
        if(abs(arr[i][col] - arr[i+1][col]) >= 2) return 0;
        for(int j=1;j<=L;j++){
            if(i+j >= N-1) return 0;
            if(abs(arr[i][col] - arr[i+j][col]) != 1) return 0;
        }
        i+=L-1;
    }
	
	return 1;
}

int main()
{
	int ans = 0;
	
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	

	//행 검사
	for (int i = 0;i < N;i++) {
		if(solve1(i)) cout << "row: " << i << " " << solve1(i)<<"\n";
		if (solve2(i)) cout << "col: " << i << " " << solve2(i) << "\n";
		ans += solve1(i) + solve2(i);

	}

	cout << ans;

	return 0;

}