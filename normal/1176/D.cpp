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

ll const nax = 1.5*1e7+5;
vll pr(nax);
void sieve(ll x){
	for(auto &it:pr)it = 1;
	pr[0] = pr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(pr[i])for(ll j = i*i; j <= x; j+= i)pr[j] = 0;
}

void solve(){
	sieve(nax-1);
	mll prn;
	ll t = 1;
	for(ll i = 0; i < nax; i++){
		if(pr[i]){
			prn[i] = t;
			t++;
		}
	}
	ll n;
	cin >> n;
	vll a(2*n), b;
	for(auto &it:a)cin>>it;
	mll mp;
	for(auto it:a)mp[it]++;
	sort(rall(a));
	for(auto it:a){
		if(mp[it] > 0){
			if(pr[it]){
				b.pb(prn[it]);
				mp[prn[it]]--;
			}
			else{
				ll mx = 0;
				for(ll j = 2; j*j <= it; j++){
					if(it%j == 0)mx = max({mx, j, it/j});
				}
				b.pb(it);
				mp[mx]--;
			}
			mp[it]--;
		}
	}
	for(auto it:b)cout<<it<<" ";
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