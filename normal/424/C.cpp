/*May the force be with me*/
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
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n), b(n+1, 0);
	ll ans;
	for(ll i = 1; i <= n; i++)b[i] = b[i-1]^i;
	for(auto &it:a)cin >> it;
	ans = a[0];
	for(ll i = 1; i < n; i++)ans^=a[i];
	for(ll i = 1; i <= n; i++){
		if((n/i)%2) ans ^= b[i-1];
		if(n%i) ans ^= b[n%i];
	}
	cout << ans;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}