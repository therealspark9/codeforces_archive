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
	ll n, K;
	cin >> n >> K;
	string s;
	cin >> s;
	vector<string> a;
	set<string> st;
	a.pb(s), st.insert(s);
	ll ans = 0;
	K--;
	if(!K){
		cout << ans;
		return;
	}
	for(ll i = n-1; i >= 0; i--){
		ll tsz = sz(a);
		for(ll j = 0; j < tsz; j++){
			if(sz(a[j]) != i+1)continue;
			string l = "", r = a[j];
			for(ll k = 0; k < sz(a[j]); k++){
				r.erase(r.begin());
				string t = "";
				t += l;
				t += r;
				l += a[j][k];
				if(st.find(t) == st.end()){
					K--;
					st.insert(t);
					a.pb(t);
					ans += n-i;
				}
				if(!K){
					cout << ans;
					return;
				}
			}
		}
	}
	if(!K) cout << ans;
	else cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi