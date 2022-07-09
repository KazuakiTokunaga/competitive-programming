#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: set に対して色々な操作を行う（1 個目は "End"、2 個目は "46" と出力される）
    set<int> Set;
    Set.insert(37); 
    Set.insert(15); 
    Set.insert(37); // この時点での Set の要素は {15, 37}
    auto itr1 = Set.lower_bound(40);

    if (itr1 == Set.end()) cout << "End" << endl;
    else cout << (*itr1) << endl;
 
    Set.insert(23); Set.insert(32); Set.insert(46); // その時点での Set の要素は {15, 23, 32, 46}
    auto itr2 = Set.lower_bound(20); //20以上の最小の要素を指すイテレータ
    if (itr2 == Set.end()) cout << "End" << endl;
    else cout << (*itr2) << endl;

    auto iter1 = Set.lower_bound(20);
    auto iter2 = Set.lower_bound(35);
    Set.erase(iter1, iter2); // 20以上の最小の要素から、35以上の最小の要素の1つ前の値までを消去する
    for (auto i: Set) {cout << i << ' ';} cout << endl;
    

    // 例 2: a[1],a[2],...,a[N] を小さい順に出力する（同じ要素が複数ある場合 1 回だけ出力する）
    set<int> b;
    vector<int> a = {10,5,3,3,10,2,6,0,8};
    for (int i: a) b.insert(i);
    auto itr = b.begin();
    while (itr != b.end()) {
        cout << (*itr) << " ";
        itr++;
    }
    cout << endl;
    
    // 例 3: multiset
    multiset<int> c = {1,2,3,6,12,3,4,5,12,2};
    c.insert(20); c.insert(8);
    c.erase(2);
    cout << *--c.end() << endl; // cの最大値を出力
}