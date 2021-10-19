#include <iostream>

using namespace std;

int main() {
    int t;
    string input;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> input;
        char small = '9' + 1;
        for (char j : input) { if (j < small) { small = j; } }
        cout << small << endl;
    }
    return 0;
}