//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

string s;
ll n;

void input(){
	cin >> s;
	n = sz(s);
}

void solve(){
	ll su = 0, z = 0;
	for(auto it:s)su += (it - '0');
	if(su%3 == 0) cout << s;
	else{
		vll a, b;
		for(ll i = 0; i < n; i++) if((s[i] - '0')%3 == 1)a.pb(i);
		for(ll i = 0; i < n; i++) if((s[i] - '0')%3 == 2)b.pb(i);
		for(ll i = 0; i < n; i++) if((s[i] == '0'))z++;
		if(sz(a))reverse(all(a));
		if(sz(b))reverse(all(b));
		if(su%3 == 1){
			string ans1 = "", ans2 = "";
			ll l = 0, r = 0;
			if(sz(a)){
				for(ll i = 0; i < n; i++)if(i != a[0])ans1+=s[i];
				for(ll i = 0; i < sz(ans1); i++){
					if(ans1[i] == '0' and sz(ans1) > 1)ans1[i] = 'x';
					else break;
				}
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')l++;
			}
			if(sz(b) >= 1){
				for(ll i = 0; i < n; i++)if(i != b[0] and i != b[1])ans2+=s[i];
				for(ll i = 0; i < sz(ans2); i++){
					if(ans2[i] == '0' and sz(ans2) > 1)ans2[i] = 'x';
					else break;
				}
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')r++;
			}
			if(!sz(a) and sz(b) < 1) {
				if(z)cout<<0;
				else cout << -1;
			}
			else if(!l and !r) {
				if(z)cout<<0;
				else cout << -1;
			}
			else if(!sz(a)) {
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')cout<<ans2[i];
			}
			else if(sz(b) < 1){
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')cout<<ans1[i];
			}
			else if(r < l){
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')cout<<ans1[i];
			}
			else {
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')cout<<ans2[i];
			}
		}
		else{
			string ans1 = "", ans2 = "";
			ll l = 0, r = 0;
			if(sz(b)){
				for(ll i = 0; i < n; i++)if(i != b[0])ans2+=s[i];
				for(ll i = 0; i < sz(ans2); i++){
					if(ans2[i] == '0' and sz(ans2) > 1)ans2[i] = 'x';
					else break;
				}
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')r++;
			}
			if(sz(a) >= 1){
				for(ll i = 0; i < n; i++)if(i != a[0] and i != a[1])ans1+=s[i];
				for(ll i = 0; i < sz(ans1); i++){
					if(ans1[i] == '0' and sz(ans1) > 1)ans1[i] = 'x';
					else break;
				}
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')l++;
			}
			if(!sz(b) and sz(a) < 1) {
				if(z)cout<<0;
				else cout << -1;
			}
			else if(!l and !r){
				if(z)cout<<0;
				else cout << -1;
			}
			else if(!sz(b)) {
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')cout<<ans1[i];
			}
			else if(sz(a) < 1) {
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')cout<<ans2[i];
			}
			else if(r < l){
				for(ll i = 0; i < sz(ans1); i++)if(ans1[i] != 'x')cout<<ans1[i];
			}
			else {
				for(ll i = 0; i < sz(ans2); i++)if(ans2[i] != 'x')cout<<ans2[i];
			}
		}
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