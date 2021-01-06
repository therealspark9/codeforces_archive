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
	a %= mod;
	ll res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

void solve(){
	string s;
	cin >> s;
	ll cnt = 0, sze = 0;
	for(auto it:s){
		ll num = 0;
		if(it >= '0' and it <= '9')num = it-'0';
		else if(it >= 'a' and it <= 'z') num = 36 + (it-'a');
		else if(it >= 'A' and it <= 'Z') num = 10 + (it-'A');
		else if(it == '-') num = 62;
		else num = 63;
		while(num){
			if((num&1) == 0)cnt++;
			sze++;
			num >>= 1;
		}
	}
	cout << binpow(3, cnt+(6*sz(s)-sze));
	
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
  return 0;
}