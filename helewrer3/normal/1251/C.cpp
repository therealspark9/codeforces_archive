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
	vll a[2];
	for(ll i = 0; i < sz(s); i++)a[(s[i]-'0')%2].pb(s[i]-'0');
	ll l = 0, r = 0;
	while(l < sz(a[0]) and r < sz(a[1])){
		if(a[0][l] < a[1][r]) cout<<a[0][l], l++;
		else if(a[0][l] > a[1][r]) cout<<a[1][r], r++;
	}
	while(l < sz(a[0]))cout<<a[0][l],l++;
	while(r < sz(a[1]))cout<<a[1][r],r++;
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