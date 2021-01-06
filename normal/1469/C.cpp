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
	vll a(n);
	for(auto &it:a)cin>>it;
	ll mx = a[0], mn = a[0];
	for(ll i = 1; i < n; i++){
		mn = max(a[i], mn-(k-1));
		mx = min(a[i]+(k-1), mx+(k-1));
		if(mn > mx){
			cout<<"NO";
			return;
		}
	}
	if(a[n-1] >= mn and a[n-1] <= mx)cout<<"YES";
	else cout<<"NO";
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
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi