#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    ll res = 0;
    rep(n, 1, N+1){
        string s = to_string(n);
        int len = s.size();
        int first = int(s[0]-'0'), last = int(s[s.size()-1]-'0');
        if (last == 0) continue;
        if (len == 1) {res++; continue;}

        // (11, 1)のようなパターンを先に回収する
        if (last == first) res += 2;

        rep(i, 2, s.size()+1){ // 桁数    

            int free_digit = i - 2; // 自由な桁数
            if (i == s.size()){
                if (last > first) continue;
                else if (last == first) {
                    int n2 = (n - last * pow(10, s.size()-1) - first) / 10;
                    res += max(n2, 0) * 2 + 1;
                } else {
                    res += pow(10, free_digit) * 2;
                }
            } else {
                res += pow(10, free_digit) * 2;
            }
        }
    }

    cout << res << endl;
}