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

ll n, k;

void input(){
	cin >> n >> k;
	k = n - k;
}

void solve(){
	string a, b, c = "";
	vll vis(n, 0);
	cin >> a >> b;
	for(ll i = 0; i < n; i++)c += "x";
	for(ll i = 0; i < n; i++){
		if(a[i] == b[i] and k){
			c[i] = a[i];
			k--;
			vis[i] = 1;
		}
	}
	k *= 2;
	for(ll i = 0; i < n; i++){
		if(a[i] != b[i] and k){
			if(k%2)c[i] = a[i];
			else c[i] = b[i];
			k--;
		}
		else if(!k and !vis[i]){
			for(ll j = 0; j < 25; j++){
				char ch = 'a' + j;
				if(ch != a[i] and ch != b[i])c[i] = ch;
			}
		}
	}
	if(!k)cout << c;
	else cout << -1;
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