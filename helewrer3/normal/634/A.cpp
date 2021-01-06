/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
//Snippets: delta, sieve, fastexp, dfs, bfs, dijkstra, floodfill

using namespace std;

ll n;

void Input() {
	cin >> n;
}

void Solve() {
	vll a(n), b(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	if (a == b)cout << "YES";
	else {
		ll N = n;
		ll u = 0;
		for (ll i = 0; i < n; i++)if (!a[i]) {u = i; break;}
		vll c = a;
		ll U = u;
		while (N--) {
			ll i = u;
			i--;
			if (i < 0)i = n - 1;
			swap(a[u], a[i]);
			u = i;
			if (a == b) {cout << "YES"; return;}
		}
		N = n;
		u = U, a = c;
		while (N--) {
			ll i = u; i++; i %= n;
			swap(a[u], a[i]);
			u = i;
			if (a == b) {cout << "YES"; return;}
		}
		cout << "NO";
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
	//cin >> T;
	//ll t = 1;
	while (T--) {
		Input();
		//cout << "Case " << t << ": ";
		Solve();
		//t++;
	}
	return 0;
}