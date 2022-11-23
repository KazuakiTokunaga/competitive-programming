#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int H, W;
int H2, W2;
vector<int> cur;
vector<vector<int>> A, B;
vector<vector<int>> idxVec;

void getIdx(int h, int w, int cnt){
    if (cnt == W2) {
        idxVec.push_back(cur);
        return;
    }
    if (w == W) return;
    
    if (A[h][w] == B[0][cnt]) {
        cur.push_back(w);
        getIdx(h, w+1, cnt+1);
        cur.pop_back();
    } 
    
    getIdx(h, w+1, cnt);
}

int main() {
    cin >> H >> W;
    A.assign(H, vector<int>(W, 0));
    rep(i, 0, H) rep(j, 0, W) cin >> A[i][j];

    cin >> H2 >> W2;
    B.assign(H2, vector<int>(W2, 0));
    rep(i, 0, H2) rep(j, 0, W2) cin >> B[i][j];

    if (H2 > H or W2 > W) {cout << "No" << endl; return 0;}

    rep(i, 0, H){
        idxVec.clear();
        cur.clear();
        getIdx(i, 0, 0);

        // cout << i << ": " << idxVec.size() << endl;
        // rep(j, 0, idxVec.size()) {for (auto k: idxVec[j]) {cout << k << ' ';} cout << endl;}
        
        for (vector<int> vec: idxVec) {
            if (vec.empty()) break;
            if (H2 == 1) { cout << "Yes" << endl; return 0;}

            int h2 = 1;
            rep(j, i+1, H){
                bool check = true;
                rep(k, 0, W2){
                    // cout << j << " " << k << ": " << B[h2][k] << " " << A[j][vec[k]] << endl;
                    if (B[h2][k] != A[j][vec[k]]) check = false;
                }
                if (check) h2++;
                if (h2 == H2) {cout << "Yes" << endl; return 0;}
            }
        }
    }

    cout << "No" << endl;
}