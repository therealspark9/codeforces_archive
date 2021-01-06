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

ll n, d;

void input(){
	cin >> n >> d;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(all(a));
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		ll l = i+1, r = n-1, midd = i;
		while(l <= r){
			ll mid = l + (r-l)/2;
			if(a[i] + d >= a[mid]){
				midd = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans += (midd - i)*(midd - i - 1)/2;
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