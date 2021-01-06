/*May the force be with me*/
#include "bits/stdc++.h"
#define endl "\n"
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
using namespace std;

ll n;
mll mp;

void bc(ll i){
	while(n%i == 0){
		n/=i;
		mp[i]++;
	}
}

void input(){
	cin >> n;
}

void solve(){
	ll N = n;
	bc(2);
	for(ll i = 3; i * i <= n; i++)bc(i);
	if(n != 1)mp[n]++;
	if(mp.empty())cout << "1\n0";
	else if(mp.size() == 1){
		for(auto it:mp){
			if(it.s == 2)cout << 2;
			else if(it.s == 1) cout << "1\n0";
			else cout << "1\n" << it.f*it.f;
		}
	}
	else{
		ll a = -1, b = -1;
		for(auto it:mp){
			if(a == -1)a = it.f;
			else if(b == -1)b = it.f;
		}
		if(a*b == N)cout << 2;
		else cout << "1\n" << a*b;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}