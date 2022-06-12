#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int end_count = 0;
    int face_count = 0;
    int unhappy = 0;
    if (s[0] == 'L') {
        end_count +=1;
        unhappy += 1;
    }
    if (s[n-1] == 'R') {
        end_count += 1;
        unhappy += 1;
    }

    for (int i = 1; i < n; i++) {
        if (s[i-1] == 'R' and s[i] == 'L') {
            face_count += 1;
            unhappy += 2;
        }
    }

    for (int i = 0; i < k; i++) {
        if (face_count > 1) {
            face_count--;
            unhappy -= 2;
            continue;
        } else if (face_count == 1 and end_count > 0){
            face_count--;
            unhappy -= 2;
            continue;
        } else if (face_count == 1 and end_count == 0){
            end_count++;
            face_count--;
            unhappy--;
            continue;
        } else if (face_count == 0 and end_count > 1){
            end_count--;
            unhappy--;
            continue;
        }
    }

    cout << n - unhappy << endl;
}