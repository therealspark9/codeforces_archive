/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
//Snippets: graph, segtree, delta, sieve, fastexp

using namespace std;

ll n;
vector<pll> arr;

void Input() {
	cin >> n, arr.clear();
	for (ll i = 0; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		arr.pb({u, v});
	}
}

void Solve() {
	for (ll i = 0; i < n - 1; i++)
		if (!(arr[i].f <= arr[i + 1].f and arr[i].s <= arr[i + 1].s and arr[i].f >= arr[i].s)) {
			cout << "NO\n";
			return;
		}
	if (!(arr[n - 1].f >= arr[n - 1].s)) cout << "NO\n";
	else cout << "YES\n";
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