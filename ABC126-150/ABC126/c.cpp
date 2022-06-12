#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, k;
    cin >> n >> k;
    
    long double res = 0;
    rep(i, 1, n+1){
        int count = 0;
        double current = k;
        while (current > i){
            current /= 2;
            count++;
        }

        res += pow((long double)0.5, count) * ((long double)1/n);
    }
    cout << setprecision(12) << res << endl;
}