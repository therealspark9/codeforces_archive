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
	ll n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	ll a[26] = {0}, b[26] = {0};
	for(ll i = 0; i < n; i++)a[s[i]-'a']++, b[t[i]-'a']++;
	for(ll i = 0; i < 26; i++){
		if(a[i] == b[i])continue;
		if(a[i] < b[i]){
			cout << "No";
			return;
		}
		if((a[i]-b[i])%k == 0) a[i+1] += (a[i]-b[i]);
		else{
			cout << "No";
			return;
		}
	}
	cout<<"Yes";
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