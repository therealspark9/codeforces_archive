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
	vll a(n), b(101, 0);
	for(auto &it:a)cin>>it;
	ll su = 0;
	for(ll i = 0; i < n; i++){
		if(a[i] + su < k)cout<<0<<" ";
		else{
			ll d = (su+a[i]) - k;
			ll ans = 0;
			for(ll j = 100; j >= 0; j--){
				if(d - b[j]*j > 0)d -= b[j]*j, ans += b[j];
				else{
					ans += (d+j-1)/j;
					break;
				}
			}
			cout<<ans<<" ";
		}
		b[a[i]]++;
		su += a[i];
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