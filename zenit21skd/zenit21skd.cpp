#include <iostream>

using namespace std;

int main() {
    int n, zlepsenia = 0, zhorsenia = 0, vlny = 0;
    int dnes = 0, vcera = 0, predvcerom = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        predvcerom = vcera;
        vcera = dnes;
        cin >> dnes;
        if (i == 0) continue;           // z jedineho dna neviem urcit zlepsenie/zhorsenie/vlnu
        if (dnes > vcera) zhorsenia++;  // zhorsenie - dnes je viac pripadov ako vcera
        if (dnes < vcera) zlepsenia++;  // zlepsenie - dnes je menej pripadov ako vcera
        if (i == 1) continue;           // z dvoch dni neviem urcit vlnu
        if (dnes < vcera && vcera > predvcerom) vlny++;    // vlna - dnes je menej pripadov ako vcera a vcera bolo viac pripadov ako predvcerom
    }
    cout << zlepsenia << " " << zhorsenia << " " << vlny << endl;
    return 0;
}