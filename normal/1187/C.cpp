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
	ll n, k;
	cin >> n >> k;
	vll a(n, 0), c(n), d(n, 0);
	for(auto &it:c)it=2000;
	vector<pll> b;
	ll vis = 1;
	for(ll i = 0; i < k; i++){
		ll t;
		cin >> t;
		if(t == 1){
			ll l, r;
			cin >> l >> r;
			l--, r--;
			vll prev;
			for(ll j = l; j <= r; j++)if(a[j])prev.pb(a[j]);
			if(sz(prev)){
				for(ll j = l; j <= r; j++)a[j] = prev[0];
				for(ll j = 0; j < n; j++)if(a[j] == prev[sz(prev)-1])a[j] = prev[0];
			}
			else{
				for(ll j = l; j <= r; j++) a[j] = vis;
				vis++;
			}
		}
		else{
			ll l, r;
			cin >> l >> r;
			l--, r--;
			b.pb({l, r});
		}
	}
	for(auto it:b){
		vll s, cnt(n+1, 0);
		for(ll i = it.f; i <= it.s; i++)if(!cnt[a[i]])s.pb(a[i]), cnt[a[i]]=1;
		if(sz(s) == 1){
			if(s[0] == 0){
				bool g = true;
				for(ll i = it.s; i >= it.f; i--){
					if(d[i] != -1){
						if(i == it.s)c[it.s] = c[it.s-1]-1;
						else c[i] = c[i+1]+1;
						g = false;
						break;
					}
				}
				if(g){
					ll del = c[it.f+1]+1-c[it.f];
					for(ll i = it.f; i >= 0; i--){
						if(d[i] == -1)c[i]+=del;
						else break;
					}
				}
			}
			else{
				cout<<"NO";
				return;
			}
		}
		else{
			if(s[sz(s)-1]){
				for(ll i = it.f; i <= it.s; i++)if(a[i] == s[sz(s)-1]){
					c[i] = c[i-1]-1;
					break;
				}
			}
			else{
				s.pop_back();
				for(ll i = it.s; i >= it.f; i--)if(a[i] == s[sz(s)-1]){
					c[i] = max(c[i-1], c[i+1])+1;
					break;
				}
			}
		}
		for(ll i = it.f; i <= it.s; i++)d[i] = -1;
	}
	cout<<"YES\n";
	for(auto it:c)cout<<it<<" ";
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