//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
#define endl "\n"
using namespace std;

ll const nax = 1e5+5;
vll a;
pll seg[4*nax], ans;

pll combine(pll l, pll r){
	ll x = __gcd(l.f, r.f), y = 0;
	if(x == l.f)y+=l.s;
	if(x == r.f)y+=r.s;
	pll p = {x,y};
	return p;
}

void build(ll i, ll tl, ll tr){
	if(tl == tr){
		seg[i].f = a[tl];
		seg[i].s = 1;
	}
	else{
		ll tm = tl + (tr-tl)/2;
		build(2*i, tl, tm);
		build(2*i+1, tm+1, tr);
		seg[i] = combine(seg[2*i], seg[2*i+1]);
	}
}

void query(ll i, ll tl, ll tr, ll l, ll r){
	if(l > r) return;
	if(l == tl and r == tr){
		if(ans.f == -1)ans.f = seg[i].f;
		ans = combine(ans, seg[i]);
	}
	else{
		ll tm = tl + (tr-tl)/2;
		query(2*i, tl, tm, l, min(r, tm));
		query(2*i+1, tm+1, tr, max(l, tm+1), r);
	}
}

void solve(){
	ll n;
	cin >> n;
	a.resize(n);
	for(auto &it:a)cin >> it;
	ll q;
	cin >> q;
	build(1, 0, n-1);
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--, r--;
		ans.f = -1, ans.s = 0;
		query(1, 0, n-1, l, r);
		cout << (r-l+1)-ans.s<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi