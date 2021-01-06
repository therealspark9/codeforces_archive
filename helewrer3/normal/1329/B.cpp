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

vll cnt_arr(60);

ll cnt(ll i, ll n, bool f){
	if(!f)return cnt_arr[i];
	else return n-(1ll<<i)+1;
}

void solve(){
	ll n, m;
	cin >> n >> m;
	cnt_arr[0] = 1;
	for(ll i = 1; i < 60; i++)cnt_arr[i] = 2*cnt_arr[i-1]%m;
	ll d = n;
	ll sz = 0;
	while(d)sz++, d/=2;
	//cout << sz << " ";
	sz--;
	ll ans = 0;
	for(ll i = 0; i <= sz; i++){
		bool f = (i == sz);
		ans = (cnt(i,n,f)*ans%m+ans+cnt(i,n,f))%m;
	}
	cout << ans;
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
  return 0;
}