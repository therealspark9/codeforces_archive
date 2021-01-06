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
	vll a(n), b(n, 0);
	for(auto &it:a)cin >> it;
	string s;
	cin >> s;
	b[0] = a[0]*(s[0] - '0');
	for(ll i = 1; i < n; i++)b[i] = b[i-1] + (s[i] - '0')*a[i];
	ll ans = b[n-1], t = 0;
	for(ll i = 0; i < n; i++){
		if((s[i] - '0') == 1) ans = max(ans, b[n-1] - b[i] + t);
		t += a[i];
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