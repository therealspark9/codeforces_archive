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

ll n, p;

void input(){
	cin >> n >> p;
}

void solve(){
	string s;
	cin >> s;
	ll ans = 0, l = -1, r = -1;
	for(ll i = 0; i < n/2; i++){
		ll c = min(26 - abs(s[i] - s[n - i - 1]), abs(s[i] - s[n - i - 1]));
		ans += c;
		if(c and l == -1)l = i;
		if(c) r = i;
	}
	p--;
	ans += (r-l);
	p = min(p, n - 1 - p);
	if(!ans) cout << 0;
	else{
		ans += min(abs(l-p), abs(r-p));
		cout<<ans;
	}
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