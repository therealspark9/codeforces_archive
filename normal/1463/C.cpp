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


void solve(){
	ll n;
	cin >> n;
	vector<pll> a(n);
	for(auto &it:a)cin >> it.f >> it.s;
	a.pb({inf, inf});
	ll cur = 0, trg = 0, edtim = 0, sttim = 0, dir = 0, ans = 0, src = 0;
	for(ll i = 0; i < n; i++){
		cur = src + dir*(min(edtim, a[i].f) - sttim);
		// cout << cur << " ";
		if(cur == trg){
			src = cur;
			trg = a[i].s;
			sttim = a[i].f;
			edtim = sttim + abs(trg - cur);
			if(trg > cur)dir = 1;
			else if(trg < cur)dir = -1;
			else dir = 0;
		}
		if(a[i].s > cur and cur+dir*(min(edtim, a[i+1].f) - a[i].f) >= a[i].s)ans++;
		else if(cur > a[i].s and cur+dir*(min(edtim, a[i+1].f) - a[i].f) <= a[i].s)ans++;
		else if(a[i].s == cur)ans++;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi