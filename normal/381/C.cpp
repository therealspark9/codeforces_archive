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
	ll n, m;
	cin >> n;
	mll mp, mp2;
	set<ll> s;
	vll a;
	ll idx = 0;
	for(ll i = 0; i < n; i++){
		ll type;
		cin >> type;
		if(type == 1){
			ll x;
			cin >> x;
			mp[idx] = x;
			a.pb(x);
			idx++;
		}
		else{
			ll l, c, t = 0;
			cin >> l >> c;
			s.insert(idx);
			mp2[idx] = l;
			idx += l*c;
			while(sz(a) <= 1ll*1e5+5 and c){
				a.pb(a[t]);
				t++;
				t%=l;
				if(!t)c--;
			}
		}
	}
	cin >> m;
	vll b(m);
	for(auto &it:b)cin>>it;
	for(auto jt:b){
		ll it = jt-1;
		if(mp.count(it))cout << mp[it] << " ";
		else if(it < sz(a))cout << a[it] << " ";
		else{
			auto kt = s.upper_bound(it);
			kt--;
			ll rem = (it - *kt + mp2[*kt])%mp2[*kt];
			cout << a[rem] << " ";
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
  return 0;
}