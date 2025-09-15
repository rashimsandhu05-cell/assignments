#include <iostream>
#include<string.h>
#include <vector>
using namespace std;

string concatStrings(const string& s1, const string& s2) {
    return s1 + s2;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string removeVowels(string s) {
    string res = "";
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            res += c;
    }
    return res;
}

vector<string> sortStrings(vector<string> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

string toLowercase(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << "Concatenated: " << concatStrings(s1, s2) << "\n";

    string s3;
    cin >> s3;
    cout << "Reversed: " << reverseString(s3) << "\n";

    string s4;
    cin >> s4;
    cout << "Without vowels: " << removeVowels(s4) << "\n";

    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    arr = sortStrings(arr);
    cout << "Sorted strings: ";
    for (auto &x : arr) cout << x << " ";
    cout << "\n";

    string s5;
    cin >> s5;
    cout << "Lowercase: " << toLowercase(s5) << "\n";

    return 0;
}
