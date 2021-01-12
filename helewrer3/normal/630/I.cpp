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

ll binpow(ll a, ll b){
	if(b < 0)return 0;
	ll rs = 1;
	while(b){
		if(b&1)rs=rs*a;
		a=a*a;
		b>>=1;
	}
	return rs;
}

void solve(){
	ll n;
	cin >> n;
	ll ans = 0, tans = 0;
	ans = 2*4*3*binpow(4,2*n-2-(n+1));
	tans = ((2*n-2-(n-1))-2)*4*3*3*binpow(4,2*n-2-(n+2));
	cout<<ans+tans;
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