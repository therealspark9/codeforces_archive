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

ll m;
string s;

void Input() {
	cin >> s >> m;
}


void Solve() {
	vll a(m);
	for (ll i = 0; i < m; i++)cin >> a[i];
	vector<vll> grp;
	while (1) {
		vll pos;
		for (ll i = 0; i < m; i++)if (!a[i])pos.pb(i);
		if (pos.empty())break;
		grp.pb(pos);
		for (ll i = 0; i < m; i++) {
			if (!a[i])a[i] = inf;
			else for (auto it : pos)a[i] -= abs(it - i);
		}
	}
	string osf(m, '.');
	map<char, ll> mp;
	for (auto it : s)mp[it]++;
	auto it = mp.rbegin();
	for (auto g : grp) {
		while (it->s < g.size())it++;
		for (auto jt : g) osf[jt] = it->f;
		it++;
	}
	cout << osf << endl;
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