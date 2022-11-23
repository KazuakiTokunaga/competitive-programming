// セグメント木の応用。かなり難しい

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int n, c;
vector<int> L, S, A;
vector<double> prv;

struct Arm{
    int vx;
    int vy;
    double angle;
    Arm(int x, int y, double a): vx(x), vy(y), angle(a) {}
};

struct SegTree {
    int n;
    vector<Arm> dat;
    SegTree(int n_){
        n = n_;
        dat.assign(4*n_, Arm(0,0,0));
        init(0, 0, n_);
    }

    int init(int k, int l, int r){
        Arm arm(0, 0, 0);
        if ((r-l) == 1) {
            arm.vy = L[l];
        } else {
            int chl = k * 2 + 1;
            int chr = k * 2 + 2;
            int y_left = init(chl, l, (l+r)/2);
            int y_right = init(chr, (l+r)/2, r);
            arm.vy = y_left + y_right;
        }
        dat[k] = arm;
        return arm.vy;
    }

    Arm get_vector(Arm l, Arm r, double a){
        double si = sin(a), co = cos(a);
        double x = l.vx + co * r.vx - si * r.vy;
        double y = l.vy + si * r.vx + co * r.vy;
        return Arm(x, y, a);
    }

    void update(int s, double a, int v, int l, int r) {
        if (s <= l) return;
        else if (s < r){
            int chl = v * 2 + 1, chr = v * 2 + 2;
            int m = (l+r)/2;
            update(s, a, chl, l, m);
            update(s, a, chr, m, r);
            if (s <= m) dat[v].angle += a;

            dat[v] = get_vector(dat[chl], dat[chr], dat[v].angle);
        }
    }

};


int main() {
    cin >> n >> c;

    L.assign(n, 0); S.assign(c, 0); A.assign(c, 0); 
    rep(i, 0, n) cin >> L[i];
    rep(i, 0, c) cin >> S[i];
    rep(i, 0, c) cin >> A[i];
    
    prv.assign(n, M_PI);
    SegTree t(n);
    cout << "created tree" << endl;
    rep(i, 0, c){
        int s = S[i];
        double a = A[i] / 360.0 * 2 * M_PI;
        
        t.update(S[i], a - prv[s], 0, 0, n);
        prv[s] = a;

        cout << t.dat[0].vx << " " << t.dat[0].vy << endl;
    }
}

/*
2 1
10 5
1
90

3 2
5 5 5
1 2
270 90
*/