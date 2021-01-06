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
	ll n, m, k, N, M;
	cin >> n >> m >> k;
	N = n, M = m;
	bool f = false;
	if(k%2 == 0)k/=2, f = 1;
	while(k%2 == 0 and (n%2 == 0 or m%2 == 0)){
		k/=2;
		if(n%2 == 0)n/=2;
		else m/=2;
	}
	if(k%2 == 0){
		cout<<"NO";
		return;
	}
	for(ll i = 3; i*i <= k; i+=2){
		while(k%i == 0 and (n%i == 0 or m%i == 0)){
			k/=i;
			if(n%i == 0)n/=i;
			else m/=i;
		}
		if(k%i == 0){
			cout<<"NO";
			return;
		}
	}
	if(k != 1){
		if(n%k == 0 or m%k == 0){
			if(n%k == 0)n/=k;
			else m/=k;
		}
		else{
			cout<<"NO";
			return;
		}
	}
	cout<<"YES"<<endl;
	cout<<"0 0"<<endl;
	if(!f){
		if(2*n <= N)n*=2;
		else if(2*m <= M)m*=2;
	}
	cout<<n<<" 0"<<endl;
	cout<<"0 "<<m<<endl;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi