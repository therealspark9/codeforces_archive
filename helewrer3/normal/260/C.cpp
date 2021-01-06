//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;


void solve(){
	ll n, x;
	bool f = true;
	cin >> n >> x;
	x--;
	vll a(n);
	for(auto &it:a)cin >> it;
	for(ll i = 1; i < n; i++)f &= (a[i]==a[i-1]);
	ll mn = inf, idx = -1;
	vll b;
	for(ll i = 0; i < n; i++){
		if(mn > a[i]){
			b.clear();
			b.pb(i);
		}
		else if(mn == a[i])b.pb(i);
		mn = min(mn, a[i]);
	}
	for(auto it:b) if(it <= x)idx = it;
	if(idx == -1)idx = b.back();
	for(ll i = 0; i < n; i++)a[i] -= mn;
	a[idx] = n*mn;
	ll i = idx;
	while(idx != x){
		a[i]++;
		a[idx]--;
		idx++;
		idx%=n;
	}
	a[i]++;
	a[idx]--;
	for(auto it:a)cout << it << " ";
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