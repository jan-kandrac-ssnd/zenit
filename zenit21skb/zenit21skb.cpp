#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int input[5];
    for (int &i: input) { cin >> i; }
    sort(input, input + 5, greater<>());

    int sum = 0;
    int index = 0;
    do {
        sum += input[index++];
    } while (input[index] > 0);

    cout << sum << endl;
    return 0;
}
