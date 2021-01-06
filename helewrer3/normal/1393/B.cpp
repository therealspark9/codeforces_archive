#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long)(x).size())
#define mll map<long long, long long>
#define pll pair<long long, long long>
using namespace std;

ll n, q, x, y;
char ch;
vll a(1e5+5, 0);

void input(){
	cin >> n;
	for(ll i = 0; i < n; i++){
		ll d;
		cin >> d;
		x -= a[d]/2, y -= a[d]/4;
		a[d]++;
		x += a[d]/2, y += a[d]/4;
	}
	cin >> q;
}

void solve(){
	for(ll i = 0; i < q; i++){
		ll d;
		cin >> ch >> d;
		x -= a[d]/2, y -= a[d]/4;
		if(ch == '+')a[d]++;
		else a[d]--;
		x += a[d]/2, y += a[d]/4;
		if(y >= 1 and x >= 4)cout<<"YES\n";
		else cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cout << endl;
	return 0;
}