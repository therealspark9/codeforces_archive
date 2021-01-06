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
	string s;
	cin >> s;
	vll a(n, 0), b(n, 0);
	ll mn = 0, mx = 0;
	for(ll i = 0; i < n-1; i++){
		if(s[i] == '>')a[i+1] = mn-1, mn--;
		else a[i+1] = mx+1, mx++;
	}
	for(ll i = n-2; i >= 0; i--){
		ll t = b[i+1];
		if(s[i] == '>')b[i] = t+1;
		else b[i] = t-1;
	}
	ll inc = 1;
	for(auto it:b)if(it<0)inc = max(inc, abs(it)+1);
	for(auto it:b)cout<<it+inc<<" ";
	cout<<endl;
	inc = 1;
	for(auto it:a)if(it<0)inc = max(inc, abs(it)+1);
	for(auto it:a)cout<<it+inc<<" ";
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