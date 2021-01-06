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
	vll a(n);
	ll ans = 0;
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < n-1; i++){
		if(a[i] > a[i+1]){
			for(ll j = 0; j <= i; j++) if(a[j] > x)swap(a[j], x), ans++;
			if(a[i] > a[i+1] and a[i+1] > x)swap(x, a[i]), ans++;
			else if(a[i] > a[i+1]){
				cout << -1;
				return;
			}
		}
	}
	cout<<ans;
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