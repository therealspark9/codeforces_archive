/*May The Force Be With Me*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 10000
#define mem(a,val) memset(a,val,sizeof(a))
//Snippets: bigint, bsearch, graph, splitstring, segtree, delta

using namespace std;

ll N;
ll x, y, x_1, y_1, x_2, y_2;
ll arr[size_1d];

void Input() {
	N = 4;
	for (ll i = 0; i < N; i++)
		cin >> arr[i];
	cin >> x >> y >> x_1 >> y_1 >> x_2 >> y_2;
}

void Solve() {
	x_1 -= x, x_2 -= x;
	y_2 -= y, y_1 -= y;

	if (max(arr[0], arr[1]) == 0 and max(arr[2], arr[3]) == 0) {
		cout << "Yes\n";
	}
	else if ((max(arr[0], arr[1]) != 0 and x_1 == x_2) or (max(arr[2], arr[3]) != 0 and y_1 == y_2)) {
		cout << "No\n";
	}
	else if ((arr[1] - arr[0]) >= x_1 and (arr[1] - arr[0]) <= x_2 and ((arr[3] - arr[2]) >= y_1) and (arr[3] - arr[2] <= y_2)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll T = 1;
	cin >> T;
	//ll t = 1;
	while (T--) {
		Input();
		//cout << "Case " << t << ": ";
		Solve();
		//t++;
	}
	return 0;
}