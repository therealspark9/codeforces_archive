/*May The Force Be With Me*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll N;
vector<ll> arr;

void Input(){
    cin >> N, arr.clear(), arr.resize(N);
    for(auto &z:arr)
        cin >> z;
}

void Solve(){
    if(N <= 2 or N%2 == 0){
        cout << "-1\n";
    }
    else{
        ll ans = 0;
        for(ll i = N-1; i >= 2; i--){
            if(i%2 == 1){
                ans += max(arr[i], max(arr[i-1], arr[(i-1)/2]));
                arr[i] = arr[i-1] = arr[(i-2)/2] = 0;
            }
            else{
                ans += max(arr[i], arr[i/2]);
                arr[i] = arr[i/2] = 0;
            }
        }
        cout << ans << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin >> T;
    while(T--){
        Input();
        Solve();
    }
    return 0;
}