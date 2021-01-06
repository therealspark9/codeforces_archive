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
	vll a(n), b(n+1, 0), c(n+1,0);
	for(ll i = 0; i < n; i++){
		cin>>a[i];
		b[a[i]]++;
	}
	ll t = 0;
	if(b[1])c[n]=1, t = 1;
	ll l = 0, r = n-1;
	for(ll i = n-1; i >= 1; i--){
		if((a[l] == t or a[r] == t) and b[t]==1 and b[t+1]){
			c[i]=1;
			if(a[l]==t)l++;
			else r--;
			t++;
		}
		else break;
	}
	bool f = true;
	for(ll i = 1; i <= n; i++)if(b[i] != 1)f=false;
	if(f)c[1]=1;
	for(ll i = 1; i <= n; i++)cout<<c[i];
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