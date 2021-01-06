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
	string s;
	cin >> s;
	string t = s;
	for(ll i = 0; i < n; i++){
		if(i+k >= n)break;
		s[i+k] = s[i];
	}
	if(t > s){
		ll id = 0;
		for(ll i = 0; i < k; i++) if(s[i] != '9')id = i;
		s[id]++;
		for(ll i = id+1; i < k; i++)s[i] = '0';
		for(ll i = 0; i < n; i++){
			if(i+k >= n)break;
			s[i+k] = s[i];
		}
	}
	cout << sz(s) << endl;
	cout << s;
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