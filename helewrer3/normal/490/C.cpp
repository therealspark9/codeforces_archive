//May the force be with me
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
#define endl "\n"
using namespace std;

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

void solve(){
	string s;
	cin >> s;
	ll a, b;
	cin >> a >> b;
	vll c(sz(s),0);
	ll x = 0, cr = 1;
	for(ll i = sz(s)-1; i >= 0; i--){
		ll y = s[i]-'0';
		y = (y*cr)%b;
		x = (x+y)%b;
		cr = (cr*10)%b;
		if(!x)c[i] = 1;
	}
	x = 0;
	for(ll i = 0; i < sz(s); i++){
		x = ((x*10)%a + (s[i] - '0'))%a;
		if(!x)c[i] = -1;
	}
	for(ll i = 0; i < sz(s); i++){
		if(c[i] == -1 and c[i+1] == 1){
			cout<<"YES\n";
			for(ll j = 0; j <= i; j++)cout<<s[j];
			cout<<endl;
			for(ll j = i+1; j < sz(s); j++)cout<<s[j];
			return;
		}
	}
	cout<<"NO";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi