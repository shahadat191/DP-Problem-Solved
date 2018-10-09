

/*
 Shahadat Hossain
 I.C.T Department
 Comilla University
 Session: 2013-2014
 */

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

#define sc2(m,n) scanf("%d %d",&m, &n)
#define scl2(m,n) scanf("%lld %lld",&m, &n)

#define sc3(m,n,o) scanf("%d %d %d",&m, &n, &o)
#define scl3(m,n,o) scanf("%lld %lld %lld",&m, &n, &o)

#define input freopen("/Users/shahadat/Desktop/input.txt", "r", stdin)
#define output freopen("/Users/shahadat/Desktop/output.txt", "w", stdout)

#define ms(a,b) memset(a, b, sizeof(a))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scs(n) scanf("%s",&n)
#define prln(n) printf("%d\n",n)
#define prsp(n) printf("%d ",n)
#define pr(n) printf("%d ",n)
#define MAX 100010
#define modulo 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;

vector<int> store[2020];
int dp[2020][2020];
int visit[2020];
vector<int> first, second;
int cow, bull;
bool flag;
int len, nxt;

void dfs(int start){
    
    if(visit[start] == 1)
        cow++;
    else
        bull++;
    for(int i = 0; i<store[start].size(); i++){
        int temp = store[start][i];
        if(visit[temp] == 0){
            visit[temp] = visit[start] == 1 ? 2 : 1;
            dfs(temp);
        }
        else{
            if(visit[temp] == visit[start])
                flag = false;
        }
    }
}

bool fun(int pos, int baki){
    
    if(pos>=len){
        if(baki == 0)
            return 1;
        if(pos == nxt)
            return 0;
    }
    
    if(dp[pos][baki] != -1)
        return dp[pos][baki];
    int re1 = 0, re2 = 0;
    if(first[pos] <= baki)
        re1 = fun(pos+1, baki-first[pos]);
    if(second[pos]<=baki)
        re2 = fun(pos+1, baki-second[pos]);
    return dp[pos][baki] = re1 | re2;
}

void clear(int n){
    ms(dp, -1);
    ms(visit, 0);
    for(int i=0; i<=n; i++)
        store[i].clear();
    first.clear();
    second.clear();
    flag = true;
}

int main(){
    
    int t;
    cin>>t;
    while (t--) {
        int b,c,a;
        cin>>b>>c>>a;
        clear(b+c);
        
        for(int i = 1; i<=a; i++){
            int x, y;
            sc2(x,y);
            store[x].push_back(y);
            store[y].push_back(x);
        }
        
        int sum = 0;
        for(int i = 1; i<=b+c; i++){
            if(store[i].size() > 0 && visit[i] == 0){
                cow = 0, bull = 0;
                visit[i] = 1;
                dfs(i);
                first.push_back(cow);
                second.push_back(bull);
                sum += (cow+bull);
            }
        }
        if(!flag)
            printf("no\n");
        else{
            int baki = b+c-sum;
            len = (int)first.size();
            
            for(int i = 1; i<=baki; i++){
                first.push_back(1);
                second.push_back(1);
            }
            nxt = (int)first.size();
            bool res = fun(0, b);
            if(res)
                printf("yes\n");
            else
                printf("no\n");   
        }   
    }
}

