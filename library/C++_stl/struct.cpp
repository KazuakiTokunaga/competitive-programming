// https://noshi91.hatenablog.com/entry/2020/03/22/231032
// https://atcoder.jp/contests/apg4b/tasks/APG4b_ab?lang=ja

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// コンストラクタでメンバ変数を代入
struct Test {
    int t1;
    int t2;
    int t3;

    Test(int a, int b, int c){
        t1 = a * 2; // この書き方の場合は変数名を変えないといけない
        t2 = b * 3;
        t3 = c * 5;
    }
};

// コンストラクタでメンバ変数を初期化
struct Test1 {
    int t1;
    int t2;
    int t3;
    vector<int> vec;

    Test1(int t1, int t2, int size): t1(t1), t2(t2), t3(t1 + t2), vec(size, 0) {}

    int multiply(){
        return t1 * t2;
    }

    int multiply_add(int v){
        return t1 * t2 + v;
    }
};

int main() {
    Test t = Test(1, 2, 3);
    cout << t.t1 << " " << t.t2 << " " << t.t3 << endl;

    Test1 t1 = Test1(50, 70, 5);
    t1.vec[2] = 5;
    cout << t1.t3 << endl;
    for (auto i: t1.vec) {cout << i << ' ';} cout << endl;
    cout << t1.multiply() << endl; // 50 * 70 = 3500;
    cout << t1.multiply_add(10) << endl; // 50 * 70 + 10 = 3500;
}