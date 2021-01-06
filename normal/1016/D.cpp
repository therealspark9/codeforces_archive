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
	vll a(n), b(m);
	ll c[n][m];
	for(auto &it:a)cin>>it;
	for(auto &it:b)cin>>it;
	ll bx = 0, ax = 0;
	for(auto it:a)ax ^= it;
	for(auto it:b)bx ^= it;
	if(ax!=bx){
		cout<<"NO";
		return;
	}
	for(ll i = 0; i < n-1; i++) for(ll j = 0; j < m-1; j++) c[i][j] = 0;
	for(ll i = 0; i < n-1; i++)c[i][m-1] = a[i];
	for(ll j = 0; j < m-1; j++)c[n-1][j] = b[j];
	c[n-1][m-1] = a[n-1]^bx^b[m-1];
	cout << "YES" << endl;
	for(ll i = 0; i < n; i++) {
		for(ll j = 0; j < m; j++) cout << c[i][j] << " ";
		cout<<endl;
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