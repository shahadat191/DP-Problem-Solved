/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<bits/stdc++.h>
using namespace std;

int cas = 1;
int l, r, k;
vector<int> ar, br;
int dp[100][100][10][2][2];

int fun(int last, int digit, int pos, bool f1, bool f2){
    if(pos == ar.size()){
        if(last == 0 && digit == 0) return 1;
        return 0;
    }
    
    if(dp[last][digit][pos][f1][f2] != -1) return dp[last][digit][pos][f1][f2];
    
    int left = f2 == 1 ? br[pos] : 0;
    int right = f1 == 1 ? ar[pos] : 9;
    
    int res = 0;
    
    for(int i = left; i <= right; i++){
        int temp = last * 10 + i;
        int temp2 = digit + i;
        temp %= k;
        temp2 %= k;
        
        res += fun(temp, temp2, pos + 1, f1 && ar[pos] == i, f2 && br[pos] == i);
    }
    return dp[last][digit][pos][f1][f2] = res;
}
void solve(){
    scanf("%d %d %d", &l, &r, &k);
    
    if(k > 99){
        printf("Case %d: %d\n", cas++, 0);
        return;
    }
    
    while(r){
        ar.push_back(r % 10);
        r /= 10;
    }
    reverse(all(ar));
    
    while(l){
        br.push_back(l % 10);
        l /= 10;
    }
    while(br.size() != ar.size())
        br.push_back(0);
    reverse(all(br));
    
    
    printf("Case %d: %d\n", cas++, fun(0, 0, 0, 1, 1));
}

int32_t main(){
    int t;
    scanf("%d", &t);
    while(t--){
        ar.clear();
        br.clear();
        ms(dp, -1);
        
        solve();
    }
}
