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
	vll a(n), b(n), c(n+1,0);
	for(auto &it:a)cin>>it, c[it]++;
	for(auto &it:b)cin>>it;
	if(!c[1]){
		ll ans = 0, l = 0;
		while(b[l] != 1){
			if(b[l])c[b[l]]++;
			l++, ans++;
		}
		ll st = 1;
		while(l < n){
			if(b[l] != st) break;
			l++, st++;
		}
		if(l >= n){
			l = 0;
			ll t = b[n-1]+1;
			bool f = true;
			while(b[l] != 1){
				c[b[l]] = 0;
				l++;
			}
			l = 0;
			while(b[l] != 1){
				if(!c[t]){
					f = false;
					break;
				}
				if(b[l])c[b[l]]++;
				l++;
			}
			if(!f)ans+=n+1;
			cout<<ans;
		}
		else{
			ans += l+1;
			ll t = 2, prev = l-1;
			for(ll i = l; i < n; i++){
				if(b[i] == t or c[t])t++, ans++;
				else{
					ans += i-prev;
					prev = i, t = 2;
				}
				if(b[i])c[b[i]]++;
			}
			cout<<ans;
		}
		return;
	}
	ll t = 2, ans = 0, l = -1;
	for(ll i = 0; i < n; i++){
		if(b[i] == t or c[t])t++;
		else{
			ans += i-l;
			t = 2, l = i;
		}
		if(b[i])c[b[i]]++;
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