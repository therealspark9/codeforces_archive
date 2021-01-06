/*May the force be with me*/
#include "bits/stdc++.h"
#define endl "\n"
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

ll p(vll a, ll m){
	sort(all(a));
	ll t1 = 0, t2 = 0;
	for(auto it:a)t1 += abs(it-a[sz(a)/2]);
	for(auto it:a)t2 += abs(it-a[max(0ll, sz(a)/2-1)]);
	return min(t1, t2);
}

void solve(){
	ll n, m, ans = 0;
	cin >> n >> m;
	ll a[n][m];
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> a[i][j];
	for(ll i = 0; i < n/2; i++) for(ll j = 0; j < m/2; j++)ans += p({a[i][j],a[n-1-i][j],a[i][m-1-j],a[n-1-i][m-1-j]}, 4);
	if(n%2) for(ll i = 0; i < m/2; i++)ans += p({a[n/2][i], a[n/2][m-1-i]}, 2);
	if(m%2) for(ll i = 0; i < n/2; i++)ans += p({a[i][m/2], a[n-1-i][m/2]}, 2);
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}