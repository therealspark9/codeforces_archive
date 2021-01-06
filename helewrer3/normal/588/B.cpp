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
unordered_map<ll, ll> mp;

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

void input(){
	cin >> n;
}

void solve(){
	ll ans = 1;
	if(n%2 == 0) mp[2]=1;
	while(n%2 == 0) n/=2;
	for(ll i = 3; i*i <= n; i+=2){
		if(n%i == 0)mp[i] = 1;
		while(n%i == 0) n /= i;
	}
	if(n > 1) mp[n]=1;
	for(auto it:mp) ans *= it.f;
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