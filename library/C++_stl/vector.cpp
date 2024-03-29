#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    //サブベクトル 
    //https://www.delftstack.com/ja/howto/cpp/how-to-extract-a-subvector-from-vector-in-cpp/
    vector<int> v1 = {1,2,3,4,5};

    vector<int> v_sub = {v1.begin()+1, v1.begin()+3}; // イテレータ
    for (auto i: v_sub) {cout << i << ' ';} cout << endl;

    vector<int> v_sub1 = {&v1[1], &v1[3]}; // ポインタ 
    for (auto i: v_sub1) {cout << i << ' ';} cout << endl;
    
    vector<int> v2 = {-1,0};
    copy(v1.begin(), v1.begin()+3, back_inserter(v2)); // サブベクトルを、既存のベクトルの末尾に加える
    for (auto i: v2) {cout << i << ' ';} cout << endl;

    // lower_boundを降順の配列に用いる
    // 降順を崩さないようにキーを挿入した時のキーのindexが与えられる
    // https://qiita.com/lndclt/items/622f81925e10badf2afe
    cout << "降順のlower_bound: " << endl;
    vector<int> v = {5, 3, 3, 3, 2, 2, 1};
    cout << lower_bound(v.begin(), v.end(), 2, greater<int>()) - v.begin() << endl; // 4
    cout << upper_bound(v.begin(), v.end(), 2, greater<int>()) - v.begin() << endl; // 6
    cout << endl;

    //検索
    // https://qiita.com/e869120/items/518297c6816adb67f9a5#3-22-find
    auto find_result = find(v1.begin(), v1.end(), 4);
    if (find_result != v1.end()){
        int place = find_result - v1.begin();
        cout << "v1 contains 4. Place: " << place << endl;
    }

    
    // accumulate, partial_sum
    // https://www.delftstack.com/ja/howto/cpp/sum-of-array-in-cpp/
    // https://programming-place.net/ppp/contents/cpp/library/024.html#inner_product

    vector<int> a = {1,2,3,4,5};
    int b = accumulate(a.begin(), a.end(), 0); // 3番目の引数は初期値(doubleのときは0.0にする)
    cout << b << endl; // ベクトルの合計

    int d = accumulate(a.begin(), a.end(), 0, [](int a, int b){return a+b+b;});
    cout << d << endl;

    int c = accumulate(a.begin(), a.end(), 1, multiplies<>());
    cout << c << endl;

    vector<int> result(5);
    partial_sum(a.begin(), a.end(), result.begin());
    for (auto i: result) {cout << i << ' ';} cout << endl; // 累積和

    vector<int> result1(5);
    partial_sum(a.begin(), a.end(), result1.begin(), [](int a, int b){return a * b * 2;});
    for (auto i: result1) {cout << i << ' ';} cout << endl << endl;;


    // next_permutation
    // http://vivi.dyndns.org/tech/cpp/permutation
    vector<int> v5 = {2,3,1};
    cout << "順列の列挙：" << endl;
    do {
        for (auto i: v5) {cout << i << ' ';} cout << endl;
    } while(next_permutation(v5.begin(), v5.end()));

    // 要素を検索して削除：Erase-remove idiom
    // https://www.delftstack.com/ja/howto/cpp/remove-element-from-vector-cpp/
    vector<string> str_vec = {"map", "vector", "deque", "list", "set", "map", "stack", "queue", "map", "span"};
    str_vec.erase(remove(str_vec.begin(), str_vec.end(), "map"), str_vec.end());
    for (auto i: str_vec) {cout << i << ' ';} cout << endl;
    
}