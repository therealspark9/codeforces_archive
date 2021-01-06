//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, m, k;

void input(){
	cin >> n >> m >> k;
}

void solve(){
	if(n == 1 and m == 1){cout << 0;return;}
	string s = "";
	for(ll i = 0; i < k; i++){ll d; cin >> d >> d;}
	for(ll i = 0; i < k; i++){ll d; cin >> d >> d;}
	if(n != 1)for(ll i = 1; i < n; i++)s+="U";
	if(m != 1)for(ll i = 1; i < m; i++)s+="L";
	for(ll i = 0; i < n; i++){
		if(i%2 == 0) for(ll j = 1; j < m; j++)s+="R";
		else if(i%2) for(ll j = 1; j < m; j++)s+="L";
		if(i != n-1)s+="D";
	}
	cout << sz(s) << endl << s;
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
	}
	cout << endl;
	cin.get();
	return 0;
}