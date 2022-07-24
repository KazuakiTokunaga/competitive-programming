#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

struct Student {
    int a;
    int b;
    int s;
    int id;
    Student(int id_, int a_, int b_) {
        id = id_+1;
        a = a_;
        b = b_;
        s = a_+b_;
    }
};

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<int> B(N);
    rep(i, 0, N) cin >> B[i];
    
    vector<Student> students;
    rep(i, 0, N){
        students.push_back(Student(i, A[i], B[i]));
    }

    vector<int> Pass;
    auto math = [](Student s1, Student s2){
        if (s1.a == s2.a) return s1.id > s2.id;
        else return s1.a < s2.a;
    };
    sort(all(students), math);
    rep(i, 0, X){
        Student stu = students.back(); students.pop_back();
        Pass.push_back(stu.id);
    }

    auto english = [](Student s1, Student s2){
        if (s1.b == s2.b) return s1.id > s2.id;
        else return s1.b < s2.b;
    };
    sort(all(students), english);
    rep(i, 0, Y){
        Student stu = students.back(); students.pop_back();
        Pass.push_back(stu.id);
    }
    
    auto total = [](Student s1, Student s2){
        if (s1.s == s2.s) return s1.id > s2.id;
        else return s1.s < s2.s;
    };
    sort(all(students), total);
    rep(i, 0, Z){
        Student stu = students.back(); students.pop_back();
        Pass.push_back(stu.id);
    }

    sort(all(Pass));
    rep(i, 0, Pass.size()){
        cout << Pass[i] << endl;
    }
}