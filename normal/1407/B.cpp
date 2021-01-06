//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
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
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(rall(a));
	vll b(n), c(n, 0);
	c[0] = 1;
	b[0] = a[0];
	ll t = b[0];
	for(ll i = 1; i < n; i++){
		ll tmp = -1;
		for(ll j = 0; j < n; j++){
			if(c[j]) continue;
			if(tmp == -1) tmp = __gcd(t, a[j]);
			else tmp = max(tmp, __gcd(t, a[j]));
		}
		for(ll j = 0; j < n; j++){
			if(c[j]) continue;
			if(tmp == __gcd(t, a[j])){
				c[j] = 1;
				b[i] = a[j];
				t = tmp;
				break;
			}
		}
	}
	for(auto it:b)cout << it << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}