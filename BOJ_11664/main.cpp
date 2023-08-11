#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vd = vector<double>;
using vvd = vector<vd>;

auto pts = vvd(3, vd(3));

double dist(const vd& p, const vd& q) {
	auto ret = double{ 0 };
	for (auto i = 0; i < 3; ++i) {
		const auto& d = p[i] - q[i];
		ret += d * d;
	}

	return sqrt(ret);
}

vd getM1(const vd& p, const vd& q) {
	auto ret = vd(3);

	for (auto i = 0; i < 3; ++i) {
		ret[i] = (2 * p[i] + q[i]) / 3;
	}

	return ret;
}

vd getM2(const vd& p, const vd& q) {
	auto ret = vd(3);

	for (auto i = 0; i < 3; ++i) {
		ret[i] = (p[i] + 2 * q[i]) / 3;
	}

	return ret;
}

vd search(vd l, vd r) {
	if (dist(l, r) < 1E-8) {
		return l;
	}

	const auto m1 = getM1(l, r);
	const auto m2 = getM2(l, r);

	const auto d1 = dist(m1, pts[2]);
	const auto d2 = dist(m2, pts[2]);

	if (d1 < d2) {
		return search(l, m2);
	}
	else {
		return search(m1, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (auto i = 0; i < 3; ++i) {
		for (auto j = 0; j < 3; ++j) {
			cin >> pts[i][j];
		}
	}

	const auto ans = search(pts[0], pts[1]);
	cout << fixed << setprecision(7) << dist(pts[2], ans);

	return 0;
}