//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, m, d;

void input(){
	cin >> n >> m >> d;
}

void solve(){
	vector<pll> a(n);
	for(ll i = 0; i < n; i++)cin >> a[i].f, a[i].s = i;
	sort(all(a));
	ll t = 0;
	vll ans(n, -1);
	for(ll i = 0; i < n; i++){
		if(ans[a[i].s] == -1)t++, ans[a[i].s] = t;
		ll st = i, ed = n-1, midd = n, key = d+a[i].f+1;
		while(st <= ed){
			ll mid = st + (ed-st)/2;
			if(a[mid].f >= key and ans[a[mid].s] == -1)midd = min(midd, mid), ed = mid - 1;
			else st = mid + 1;
		}
		if(midd != n)ans[a[midd].s]	 = ans[a[i].s];
	}
	cout << t << endl;
	for(auto it:ans)cout << it << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}