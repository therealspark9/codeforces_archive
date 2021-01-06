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
vector<bool> ispr((ll)10e6 + 5, true);
void sieve(ll x){
	ispr[0] = ispr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(ispr[i])for(ll j = i*i; j <= x; j+= i)ispr[j] = 0;
}

void input(){
	cin >> n;
}

void solve(){
	sieve(n);
	vll ans;
	for(ll i = 1; i <= n; i++){
		if(ispr[i]){
			ll t = i;
			while(t <= n){
				ans.pb(t);
				t*=i;
			}
		}
	}
	cout << sz(ans) << endl;
	for(auto it:ans)cout << it << " ";
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