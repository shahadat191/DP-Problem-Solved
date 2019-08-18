/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */
 
#include<bits/stdc++.h>
using namespace std;
 
ll dp[100][10][2][2];
vector<int> ar, br;
ll fun(int digit, int pos, bool lmit, bool rmit){
    
    if(pos == ar.size())
        return digit;
    int left = lmit ? ar[pos] : 0;
    int right = rmit ? br[pos] : 9;
    
    if(dp[digit][pos][lmit][rmit] != -1) return dp[digit][pos][lmit][rmit];
    ll res = 0;
    for(int i = left; i <= right; i++){
        res += fun(digit + i, pos + 1, lmit && ar[pos] == i, rmit && br[pos] == i);
    }
    return dp[digit][pos][lmit][rmit] = res;
}
 
 
int l, r;
void solve(){
    while(r){
        br.pb(r % 10);
        r /= 10;
    }
    while(ar.size() != br.size()){
        ar.pb(l % 10);
        l /= 10;
    }
    reverse(all(ar));
    reverse(all(br));
    
    printf("%lld\n", fun(0, 0, 1, 1));
}
 
int32_t main(){
    while(scanf("%d %d", &l, &r)){
        ar.clear();
        br.clear();
        ms(dp, -1);
        if(l == -1 && r == -1) break;
        solve();
    }
}
