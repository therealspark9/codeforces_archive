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

ll n, m;

void input(){
	cin >> n >> m;
}

void solve(){
	char a[n][m];
	bool is[n];
	for(ll i = 0; i < n; i++)is[i] = 0;
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++)cin >> a[i][j];
	ll ans = 0;
	for(ll j = 0; j < m; j++){
		bool tis[n];
		for(ll k = 0; k < n; k++) tis[k] = 0;
		for(ll i = 1; i < n; i++){
			if(a[i][j] > a[i-1][j])tis[i] = 1;
			if(a[i][j] < a[i-1][j] and is[i] == 0){
				for(ll k = 0; k < n; k++)tis[k] = 0;
				ans++;
				break;
			}
		}
		for(ll k = 0; k < n; k++)is[k] |= tis[k];
	}
	cout<<ans;

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