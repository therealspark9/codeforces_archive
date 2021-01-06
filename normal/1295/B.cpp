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
	ll n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	ll diff[n] = {0};
	if(s[0] == '0')diff[0]++;
	else diff[0]--;
	for(ll i = 1; i < n; i++){
		diff[i] = diff[i-1];
		if(s[i] == '0')diff[i]++;
		else diff[i]--;
	}
	ll cnt = 0, tx = x;
	bool f = false;
	for(ll i = 0; i < n; i++){
		if(diff[n-1] == 0)f |= (diff[i] == x);
		else if(abs(tx)%abs(diff[n-1]) == 0 and tx*diff[n-1] >= 0)cnt++;
		tx = x - diff[i];
	}
	if(f) cout << -1;
	else cout << cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi