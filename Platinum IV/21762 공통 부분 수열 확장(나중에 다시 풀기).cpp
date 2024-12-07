#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string X, Y, W;
        cin >> X >> Y >> W;

        bool ans = 0;

        int xAlpha[26] = { 0, }, yAlpha[26] = { 0, };

        //1. 부분 수열이 될 수 있는 w[i]에 해당하는 알파벳의 최소와 최대를 각각 구한다.
        //2. 슬라이딩 윈도우으로 범위 내의 알파벳 개수를 센다. -> 슬라이딩 윈도우를 사용하기 때문에 문자열 X를 전부 탐색하면 O(|X|)만큼만 걸린다.

        deque <int> x_start, x_end, y_start, y_end;

        x_start.push_back(-1);
        x_end.push_front(X.length());
        int left = 0, right = X.length() - 1;
        for (int i = 0; i < W.length(); i++) {
            while (X[left] != W[i]) left++;
            while (X[right] != W[W.length() - 1 - i]) right--;

            x_start.push_back(left++);
            x_end.push_front(right--);
        }

        y_start.push_back(-1);
        y_end.push_front(Y.length());
        left = 0, right = Y.length() - 1;
        for (int i = 0; i < W.length(); i++) {
            while (Y[left] != W[i]) left++;
            while (Y[right] != W[W.length() - 1 - i]) right--;

            y_start.push_back(left++);
            y_end.push_front(right--);
        }

        int x_left = 0, x_right = 0, y_left = 0, y_right = 0;
        for (int i = 0; i <= W.length(); i++) {
            while (x_left <= x_start[i]) {
                --xAlpha[X[x_left++] - 'a'];
            }
            while (y_left <= y_start[i]) {
                --yAlpha[Y[y_left++] - 'a'];
            }

            while (x_right < x_end[i]) {
                xAlpha[X[x_right] - 'a']++;
                if (xAlpha[X[x_right] - 'a'] > 0 && yAlpha[X[x_right] - 'a'] > 0) ans = 1;
                x_right++;
            }
            while (y_right < y_end[i]) {
                yAlpha[Y[y_right] - 'a']++;
                if (xAlpha[Y[y_right] - 'a'] > 0 && yAlpha[Y[y_right] - 'a'] > 0) ans = 1;
                y_right++;
            }
            if (ans) break;
        }

        cout << ans << "\n";
    }
    return 0;
}