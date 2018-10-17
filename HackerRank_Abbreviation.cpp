
//..Problem Link:- https://www.hackerrank.com/challenges/abbr/problem
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
#include<functional>
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

#define ms(a,b) memset(a, b, sizeof(a))

using namespace std;

string a,b;
int dp[1010][1010];
int fun(int i, int j){
    if(i == a.size()){
        if(i == a.size() && j >= b.size()-1){
            return 1;
        }
        else
            return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int r1 = 0, r2 = 0;
    if(isupper(a[i])){
        if(a[i] == b[j])
            r1 = fun(i+1, j+1);
    }
    else{
        if(a[i] == tolower(b[j]))
            r1 = fun(i+1, j+1);
        r2 = fun(i+1, j);
    }
    return dp[i][j] = r1 | r2;
}

int main(){
    int t;
    cin>>t;
    getchar();
    while (t--) {
        ms(dp, -1);
        cin>>a>>b;
        b.push_back('#');
        int res = fun(0,0);
        if(res == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
