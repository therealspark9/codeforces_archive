//May the force be with me
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


void solve(){
	ll n;
	cin >> n;
	if(n <= 2)cout<<"No";
	else{
		cout<<"Yes\n";
		vll a, b;
		for(ll i = 1; i <= n; i++)if(i%2)a.pb(i);
		for(ll i = 1; i <= n; i++)if(i%2 == 0)b.pb(i);
		cout << sz(a) << " ";
		for(auto it:a)cout << it << " ";
		cout << endl;
		cout << sz(b) << " ";
		for(auto it:b)cout << it << " ";
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