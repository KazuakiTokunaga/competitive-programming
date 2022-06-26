// パケット分割

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int B = 1000;
string S = "abcdefghijklmnopqrstuvwxyz";
vector<vector<int>> batch(500000/B+1, vector<int>(26,0));
int toInt(char c){
    
    rep(i, 0, S.size()){
        if (S[i] == c) return i;
    }
    return -1;
}

int main() {
    int n, Q; string s;
    cin >> n >> s >> Q;

    rep(i, 0, n){
        int b = i / B;
        char c = s[i];
        batch[b][toInt(c)]++;
    }

    rep(i, 0, Q){
        int q; cin >> q;
        if (q==1){
            int iq; char cq;
            cin >> iq >> cq;
            if (s[iq-1] == cq) continue;
            else {
                int b = iq / B;

                batch[b][toInt(s[iq-1])]--;
                batch[b][toInt(cq)]++;
                s[iq-1] = cq;

                // cout << "update: ";
                // for (auto i: batch[b]) {cout << i << ' ';} cout << endl;
                
            }
        } else {
            int l, r;
            cin >> l >> r; l--;
            
            int cnt = 0;
            while (l % B != 0 and l < r){
                cnt |= (1 << toInt(s[l]));
                l++;
            }
            while (r % B != 0 and l < r){
                r--;
                // cout << r << " " << s[r] << endl;
                cnt |= (1 << toInt(s[r]));
            }
            while (l < r){
                int b = l / B;
                rep(j, 0, 26){
                    if (batch[b][j] > 0){
                        cnt |= 1 << j;
                    }
                }
                l += B;
            }

            // cout << "query: " << cnt << " " << l << " " << r << endl; 
            int res = 0;
            rep(j, 0, 26){
                if (cnt & (1<<j)) res++;
            }
            cout << res << endl;
        }
    }
}