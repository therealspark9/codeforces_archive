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

vll fib(1ll*1e5+5,0);

void solve(){
	fib[0] = fib[1] = 1;
	for(ll i = 2; i < sz(fib); i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
	ll n, m;
	cin >> n >> m;
	cout << 2*(fib[n]+fib[m]-1)%mod;
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