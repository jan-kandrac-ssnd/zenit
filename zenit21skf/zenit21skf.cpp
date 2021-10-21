#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    double p;
    cin >> n >> k >> p;
    cout << fixed << ((p <= 0.5) ? n : n * pow(2.0 * p, k)) << endl;
    return 0;
}