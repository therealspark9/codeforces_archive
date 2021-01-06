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
	cin >> n >> m;
	string s[n];
	for(ll i = 0; i < n; i++)cin>>s[i];
	string t = s[0];
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < 26; j++){
			string nt = t;
			nt[i] = 'a'+j;
			bool f = true;
			for(ll k = 0; k < n; k++){
				ll g = 0;
				for(ll l = 0; l < m; l++)if(nt[l] != s[k][l])g++;
				if(g > 1)f = false;
			}
			if(f){
				cout << nt;
				return;
			}
		}
	}
	cout << -1;
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