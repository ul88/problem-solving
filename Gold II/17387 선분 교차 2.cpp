#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef struct Line {
	ll x1, y1;
	ll x2, y2;
}line_t;

int ccw(pii p1, pii p2, pii p3) {
	ll s = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
		- (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
	if (s < 0) return -1;
	else if (s > 0) return 1;
	else return 0;
}

bool isIntersect(line_t a, line_t b) {
	pii p1 = { a.x1, a.y1 };
	pii p2 = { a.x2,a.y2 };
	pii p3 = { b.x1,b.y1 };
	pii p4 = { b.x2,b.y2 };

	if (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0) {
		if (ccw(p1, p2, p3) * ccw(p1, p2, p4) == 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) == 0) {
			if (p1 > p2) swap(p1, p2);
			if (p3 > p4) swap(p3, p4);

			return p3 <= p2 && p1 <= p4;
		}
		return true;
	}
	return false;
}

int main()
{
	vector <line_t> v;

	for (int i = 0; i < 2; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1,y1,x2,y2 });
	}

	cout << isIntersect(v[0], v[1]);

	return 0;
}