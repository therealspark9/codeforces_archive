//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
}

void solve(){
	string s;
	cin >> s;
	reverse(all(s));
	ll ans = 0, c = 0;
	for(ll i = 0; i < sz(s); i++){ 
		if(i%2== 0)ans++;
		if(s[i] == '1')c++;
	}
	if(sz(s)%2 and s[sz(s) - 1] == '1' and c == 1) ans--;
	if(sz(s) == 1 and s[0] == '0')cout << 0;
	else cout << ans;
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