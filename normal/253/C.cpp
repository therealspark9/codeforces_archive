//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	ll r, c, r2, c2;
	cin >> r >> c >> r2 >> c2;
	ll ans = abs(r - r2);
	if(r > r2){
		r--, r2--;
		for(ll i = r; i > r2; i--) if(a[i-1] < c)c = a[i-1]+1;
		ll t = abs(c - c2);
		ll X = c;
		for(ll i = r; i < n; i++){ 
			if(a[i] < c){
				c = a[i]+1;
				t = min(t, 2*abs(i-r) + abs(c2-c));
			}
		}
		c = X;
		for(ll i = r2; i >= 0; i--){ 
			if(a[i] < c){
				c = a[i]+1;
				t = min(t, 2*abs(i-r2) + abs(c2-c));
			}
		}
		ans += t;
	}
	else{
		r--, r2--;
		for(ll i = r; i < r2; i++) if(a[i+1] < c)c = a[i+1]+1;
		ll t = abs(c - c2);
		ll X = c;
		for(ll i = r2; i < n; i++) {
			if(a[i] < c){
				c = a[i]+1;
				t = min(t, 2*abs(i-r2) + abs(c2-c));
			}
		}
		c = X;
		for(ll i = r; i >= 0; i--) {
			if(a[i] < c){
				c = a[i]+1;
				t = min(t, 2*abs(i-r) + abs(c2-c));
			}
		}
		ans += t;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}