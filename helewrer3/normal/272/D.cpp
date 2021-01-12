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

mll mp, mps;

void solve(){
	ll n,m;
	cin >> n;
	vll a(n), b(n), f(2*n+1,0), p(2*n+1,0), cnt(2*n+1,0);
	for(auto &it:a)cin>>it,mp[it]++;
	for(auto &it:b)cin>>it,mp[it]++;
	cin >> m;
	f[0]=p[0]=1;
	for(ll i = 0; i < n; i++)if(a[i] == b[i])mps[a[i]]++;
	for(ll i = 1; i < sz(f); i++){
		cnt[i]=cnt[i-1];
		if(i%2)f[i]=i*f[i-1]%m;
		else{
			f[i]=f[i-1];
			ll ti = i;
			while(ti%2==0)cnt[i]++,ti/=2;
		}
	}
	for(ll i = 1; i < sz(p); i++)p[i]=2ll*p[i-1]%m;
	ll ans = 1;
	for(auto it:mp){
		ans=ans*f[it.s]%m;
		ll d = cnt[it.s]-mps[it.f];
		ans=ans*p[d]%m;
	}
	cout<<ans;
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