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
	string s;
	cin >> s;
	ll ans = 1;
	for(auto it:s)ans *= (it - '0');
	for(ll i = 0; i < sz(s); i++){
		ll tans = 1;
		if(!i){
			if(s[i] != '1')tans = (s[i] - '1');
		}
		else tans = (s[i] - '1');
		for(ll j = 0; j < i; j++)tans *= (s[j] - '0');
		for(ll j = i+1; j < sz(s); j++) tans *= 9;
		// cout << tans << " ";
		ans = max(ans, tans);
	}
	cout<<ans;
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