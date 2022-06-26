// 貪欲解
// https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2019-02-16abc-155#toc4

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> digits;
    reverse(all(s));
    rep(i, 0, n){
        int d = (int)(s[i]-'0');
        digits.push_back(d);
    }
    
    int res = 0;
    digits.push_back(0);
    rep(i, 0, n){
        int c = digits[i];
        if (c <= 4){
            res += c;
        } else if (c >= 6){
            res += (10-c);
            digits[i+1]++;
        } else {
            if (digits[i+1] >= 5){
                digits[i+1]++;
                res += (10-c);
            } else {
                res += c;
            }
        }
    }

    cout << res + digits[n] << endl;
}