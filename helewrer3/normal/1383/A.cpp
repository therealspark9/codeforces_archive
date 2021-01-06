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


void solve(){
	ll n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vll a[26];
	for(ll i = 0; i < 26; i++)a[i].resize(26, 0);
	for(ll i = 0; i < n; i++) if(s[i] != t[i])a[s[i] - 'a'][t[i]-'a']++;
	ll ans = 0;
	for(ll i = 0; i < 26; i++){
		bool f = false;
		char ch;
		for(ll j = 0; j < 26; j++){
			if(a[i][j]){
				if(j+'a' < i+'a'){
					cout<<-1;
					return;
				}
				else if(j+'a' > i+'a'){
					if(!f){
						ans++;
						f = true;
						ch = j+'a';
					}
					else a[ch-'a'][j] = a[i][j];
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi