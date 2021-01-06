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
  vector<pair<ll, string>> a(n), b;
  for(auto &it:a)cin >> it.s >> it.f;
  sort(all(a));
  set<pair<ll, string>> s;
  for(ll i = 0; i < n; i++){
	if(a[i].f > sz(s)){
		cout << -1;
		return;
	}
	if(sz(s) == 0)s.insert({5000, a[i].s});
	else if(a[i].f == sz(s)) s.insert({(*s.begin()).f-1, a[i].s});
	else{
		auto it = s.rbegin();
		ll t = a[i].f;
		vector<pair<ll, string>> vs;
		while(t){
			vs.pb(*it);
			it++, t--;
		}
		pair<ll, string> p = {(*it).f+1, a[i].s};
		if(it != s.rbegin()){
			for(auto jt:vs){
				s.erase(jt);
				jt.f++;
				s.insert(jt);
			}
		}
		s.insert(p);
	}
  }
  for(ll i = 0; i < n; i++){
	cout << a[i].s << " ";
	for(auto it:s)if(it.s == a[i].s){cout << it.f;break;}
	cout<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  //cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi