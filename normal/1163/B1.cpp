//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, mx = -inf, mxfr = -inf;
const ll nax = 10e5+5;
multiset<ll> s;
ll fr[nax] = {0};
mll frfr;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	ll ans = 0;
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < n; i++){
		fr[a[i]]++;
		frfr[fr[a[i]]]++;
		if(frfr.count(fr[a[i]] - 1))frfr[fr[a[i]] - 1]--;
		if(mx <= frfr[fr[a[i]]]) mxfr = fr[a[i]];
		mx = max(mx, frfr[fr[a[i]]]);
		if(s.find(fr[a[i]] - 1) != s.end())s.erase(s.find(fr[a[i]] - 1));
		s.insert(fr[a[i]]);
		auto l = s.lower_bound(mxfr), r = s.upper_bound(mxfr);
		if(r == s.end()){
			if(l != s.begin()){
				l--;
				if(l == s.begin()) if((*l) == 1) ans = max(ans, i+1);
				
			}
			else if((*l) == 1) ans = max(ans, i+1);
		}
		else{
			if(l == s.begin()){
				if(r != s.end()){
					r++;
					if(r == s.end()){
						r--;
						if((*r) - 1 == mxfr) ans = max(ans, i+1);
					}
				}
			}
		}
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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