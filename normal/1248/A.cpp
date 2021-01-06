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

ll n, m;
ll arr[size_1d], brr[size_1d];

void Input() {
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	for (ll i = 0; i < m; i++)
		cin >> brr[i];
}

void Solve() {
	ll o_1, e_1, o_2, e_2;
	o_2 = o_1 = e_1 = e_2 = 0;
	for (ll i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) e_1++;
		else o_1++;
	}
	for (ll i = 0; i < m; i++) {
		if (brr[i] % 2 == 0) e_2++;
		else o_2++;
	}


	cout << o_2*o_1 + e_2*e_1 << endl;
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