#include <iostream>
using namespace std;

// Function to count consecutive characters
int countChar(const string& s, int& i, char ch) {
    int count = 0;
    while (i < s.length() && s[i] == ch) {
        count++;
        i++;
    }
    return count;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int i = 0;
    int a_count = countChar(s, i, 'a');
    int b_count = countChar(s, i, 'b');
    int c_count = countChar(s, i, 'c');
    int d_count = countChar(s, i, 'd');


    if (i != s.length() || a_count != b_count || c_count != d_count || b_count != c_count + 2) {
        cout << "Rejected" << endl;
    } else {
        cout << "Accepted" << endl;
    }

    return 0;
}
