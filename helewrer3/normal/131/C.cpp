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

ll n, m, t;

ll C(ll N, ll k) {
    double res = 1;
    for (ll i = 1; i <= k; ++i) res = res * (N - k + i) / i;
    return (ll)(res + 0.01);
}

void input(){
	cin >> n >> m >> t;
}

void solve(){
	ll ans = 0;
	for(ll i = 4; i <= n; i++){
		ll d = t - i;
		if(d < 1) break;
		ans += C(n, i)*C(m, d);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> t;
	while(T--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}