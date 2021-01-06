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
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
//Snippets: graph, segtree, delta, sieve, fastexp

using namespace std;

ll n;
ll arr[size_1d];

void Input() {
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
}

void Solve() {
	ll su = 0, t = 0, l = 0, r = 0;
	vll L, R;
	for (ll i = 0; i < n; i++) {
		if (t > su) {L.clear(), R.clear(); L.pb(l), R.pb(r);}
		else if (t == su) {L.pb(l), R.pb(r);}
		su = max(t, su);
		if (t + arr[i] <= 0) {t = 0, l = r = i;}
		else {t += arr[i], r = i;}
	}
	if (t > su) {L.clear(), R.clear(); L.pb(l), R.pb(r);}
	else if (t == su) {L.pb(l), R.pb(r);}
	su = max(su, t);
	ll mn = INT_MAX;
	for (ll j = 0; j < L.size(); j++) {
		ll t_mx = 0;
		for (ll i = L[j]; i <= R[j]; i++) t_mx = max(t_mx, arr[i]);
		mn = min(mn, t_mx);
	}
	cout << su - mn << endl;
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