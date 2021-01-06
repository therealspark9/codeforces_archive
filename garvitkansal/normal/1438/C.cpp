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
	ll n, m;
	cin >> n >> m;
	ll a[n][m], ch[n][m];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin >> a[i][j];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)ch[i][j] = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			bool f = true;
			if(i and a[i-1][j] == a[i][j]){
				if(ch[i-1][j])f = false;
			}
			if(i<n and a[i+1][j] == a[i][j]){
				if(ch[i+1][j])f = false;
			}
			if(j<m and a[i][j+1] == a[i][j]){
				if(ch[i][j+1])f = false;
			}
			if(j and a[i][j-1] == a[i][j]){
				if(ch[i][j-1])f = false;
			}
			if(!f){
				a[i][j]++;
				ch[i][j]++;
				f = true;
				if(i and a[i-1][j] == a[i][j]){
					if(ch[i-1][j])f = false;
				}
				if(i<n and a[i+1][j] == a[i][j]){
					if(ch[i+1][j])f = false;
				}
				if(j<m and a[i][j+1] == a[i][j]){
					if(ch[i][j+1])f = false;
				}
				if(j and a[i][j-1] == a[i][j]){
					if(ch[i][j-1])f = false;
				}
				if(!f)exit(0);
				else{
					if(i and a[i-1][j] == a[i][j]){
					a[i-1][j]++;
					ch[i-1][j]++;
					}
					if(i<n and a[i+1][j] == a[i][j]){
						ch[i+1][j]++;
						a[i+1][j]++;
					}
					if(j<m and a[i][j+1] == a[i][j]){
						ch[i][j+1]++;
						a[i][j+1]++;
					}
					if(j and a[i][j-1] == a[i][j]){
						ch[i][j-1]++;
						a[i][j-1]++;
					}
				}
			}
			else{
				if(i and a[i-1][j] == a[i][j]){
					a[i-1][j]++;
					ch[i-1][j]++;
				}
				if(i<n and a[i+1][j] == a[i][j]){
					ch[i+1][j]++;
					a[i+1][j]++;
				}
				if(j<m and a[i][j+1] == a[i][j]){
					ch[i][j+1]++;
					a[i][j+1]++;
				}
				if(j and a[i][j-1] == a[i][j]){
					ch[i][j-1]++;
					a[i][j-1]++;
				}
			}
		}
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++)cout << a[i][j] << " ";
		cout<<endl;
	}
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