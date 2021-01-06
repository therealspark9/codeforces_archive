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

ll const nax = 1e5 + 5;
string s;
ll seg[4*nax][26] = {0}, galp[26] = {0};

void combine(ll m, ll l, ll r){
	for(ll i = 0; i < 26; i++)seg[m][i] = seg[l][i]+seg[r][i];
}

void build(ll i, ll tl, ll tr){
	if(tl == tr){
		for(ll j = 0; j < 26; j++)seg[i][j]=0;
		seg[i][s[tl]-'a']++;
	}
	else{
		int m = tl + (tr-tl)/2;
		build(2*i, tl, m);
		build(2*i+1, m+1, tr);
		combine(i, 2*i, 2*i+1);
	}
}

void update(ll i, ll v, ll tl, ll tr, char ch){
	if(tl == tr){
		s[tl] = ch;
		for(ll j = 0; j < 26; j++)seg[i][j]=0;
		seg[i][ch-'a']++;
	}
	else{
		int m = tl + (tr-tl)/2;
		if(v <= m)update(2*i, v, tl, m, ch);
		else update(2*i+1, v, m+1, tr, ch);
		combine(i, 2*i, 2*i+1);
	}
}

void query(ll i, ll l, ll r, ll tl, ll tr){
	if(l > r)return;
	if(l == tl and r == tr) for(ll j = 0; j < 26; j++)galp[j] += seg[i][j];
	else{
		ll m = tl + (tr-tl)/2;
		query(2*i, l, min(r, m), tl, m);
		query(2*i+1, max(l, m+1), r, m+1, tr);
	}
}

void solve(){
	cin >> s;
	ll n;
	cin >> n;
	build(1, 0, sz(s)-1);
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < 26; j++)galp[j] = 0;
		ll t;
		cin >> t;
		if(t == 1){
			ll pos;
			char c;
			cin >> pos >> c;
			pos--;
			s[pos] = c;
			// build(1,0,sz(s)-1);
			update(1, pos, 0, sz(s)-1, c);
			// for(ll j = 0; j < 26; j++)cout << seg[1][j] << " ";
			// cout << s;
			// cout << endl;
		}
		else{
			ll l, r;
			cin >> l >> r;
			l--, r--;
			query(1, l, r, 0, sz(s)-1);
			ll ans = 0;
			for(ll j = 0; j < 26; j++)if(galp[j])ans++;
			cout << ans << endl;
		}
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