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
	string s;
	cin >> s;
	ll o = 0, z = 0;
	queue<ll> q;
	for(ll i = 0; i < sz(s); i++){
		if(s[i] == '1'){
			o++;
			if(z){
				q.push(z);
				z = 0;
			}
		}
		else{
			z++;
			if(o){
				q.push(o);
				o = 0;
			}
		}
	}
	if(o){
		q.push(o);
		o = 0;
	}
	if(z){
		q.push(z);
		z = 0;
	}
	
	ll ans = 0, ones = 0;
	while(!q.empty()){
		while(!q.empty() and q.front() == 1){
			q.pop();
			ones++;
		}
		if(q.empty())break;
		ll v = q.front();
		ll d = min(ones, v-1);
		ones -= d, ans += d, v -= d;
		q.pop();
		if(v == 1) ones++;
		else ans++;
	}
	ans += (ones+1)/2;
	cout<<ans;
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