/*May the force be with me*/
#include "bits/stdc++.h"
#define endl "\n"
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

ll a, b;

void input(){
	cin >> a >> b;
}

void solve(){
	set<ll> s;
	mll mp;
	for(ll i = 1; i*i <= a; i++){
		if(a%i == 0){
			mp[i] = 1;
			if(i != a/i)mp[a/i]=1;
		}
	}
	for(ll i = 1; i*i <= b; i++){
		if(b%i == 0){
			mp[i]++;
			if(i != b/i)mp[b/i]++;
		}
	}
	for(auto it:mp)if(it.s == 2)s.insert(it.f);
	ll t;
	cin >> t;
	for(ll i = 0; i < t; i++){
		ll l, r;
		cin >> l >> r;
		auto it = s.upper_bound(r);
		it--;
		if(*it <= r and *it >= l)cout << *it << endl;
		else cout << -1 << endl;
	}
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