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
	vll a(n);
	for(auto &it:a)cin>>it;
	sort(all(a));
	mll mp;
	for(ll i = 1; i < n; i++)mp[a[i]-a[i-1]]++;
	if(n == 1) cout << -1;
	else if(sz(mp) == 1){
		if(a[1] == a[0]){
			cout << 1 << endl;
			cout << a[0];
		}
		else if(n > 2 or (n <= 2 and (a[1]-a[0])%2)){
			cout << 2 << endl;
			cout << a[0] - (a[1]-a[0]) << " " << a[n-1] + (a[1]-a[0]);
		}
		else if((a[1]-a[0])%2 == 0){
			cout << 3 << endl;
			cout << a[0] - (a[1]-a[0]) << " " << a[0] + (a[1]-a[0])/2  << " "<< a[n-1] + (a[1]-a[0]);
		}
	}
	else if(sz(mp) == 2){
		ll b[2];
		ll t = 0;
		for(auto it:mp){
			b[t] = it.f;
			t++;
		}
		if(b[1] == 2*b[0] and mp[b[1]] == 1){
			cout << 1 << endl;
			for(ll i = 1; i < n; i++){
				if(a[i]-a[i-1] == b[1]){
					cout << a[i-1]+b[0];
					break;
				}
			}
		}
		else cout << 0;
	}
	else cout << 0;
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