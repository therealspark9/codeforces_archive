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

vll f(20);
map<string, ll> mp;

ll cnt(vll a){
	string num="";
	for(ll i = 0; i < 10; i++){
		ll it = a[i];
		while(it--)num+='0'+ i;
	}
	if(mp.count(num))return 0;
	mp[num]=1;
	ll mul = 0, res = 0, n = 0, tmul = 0;
	for(ll i = 0; i < 10; i++){
		n += a[i];
		if(a[i] <= 1)continue;
		a[i]--;
		res += cnt(a);
		a[i]++;
	}
	mul = f[n];
	for(auto it:a)mul/=f[it];
	if(a[0]){
		tmul = f[n-1];
		a[0]--;
		for(auto it:a)tmul/=f[it];
	}
	return mul + res - tmul;
}

void solve(){
	f[0] = 1;
	for(ll i = 1; i < 20; i++)f[i]=i*f[i-1];
	ll n;
	cin >> n;
	vll a(10,0);
	while(n){
		a[n%10]++;
		n/=10;
	}
	cout << cnt(a);
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