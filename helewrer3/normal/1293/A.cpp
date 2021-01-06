#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T, n, s, k, data;
    cin >> T;
    while(T--){
        cin >> n >> s >> k;
        map<ll, ll> mp;

        for(ll i = 0; i < k; i++){
            cin >> data;
            mp[data-1] = 1;
        }

        ll ans = INT_MAX;

        for(ll i = 0; i < n; i++){
            if(mp[i] != 1){
                ans = min(ans, abs(s - 1 - i));
            }
        }

        cout << ans << endl;
    }
    return 0;
}