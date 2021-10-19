#include <iostream>
#include <vector>

using namespace std;

struct Kick {
    char symbol;
    int turn;
};

string board;
int boardFields;

vector<Kick> kicks;

void loadBoard(int n) {
    for (int i = 0; i < n; i++) { cin >> board[i]; }                                            // prvy riadok = prvych n pozicii
    for (int i = 0; i < n - 2; i++) { cin >> board[boardFields - 1 - i]; cin >> board[n + i]; } // n-2 riadkov dvojic i-ty od konca a i-ty od n teho
    for (int i = 0; i < n; i++) { cin >> board[boardFields - n - i + 1]; }                      // posledny riadok = prostrednych n pozicii
}

void printBoard(int n) {
    for (int i = 0; i < n; i++) { cout << board[i]; } cout << endl;
    for (int i = 0; i < n - 2; i++) { cout << board[boardFields - 1 - i] << string(n - 2, ' ') << board[n + i] << endl; }
    for (int i = 0; i < n; i++) { cout << board[boardFields - n - i + 1]; } cout << endl;
}

void play(int k) {
    int pos = board.find('R');                      // najdem svoju figurku
    board[pos] = '.';                               // odstranim svoju figurku z plochy
    int turn = 0;                                   // pocitadlo vykonanych tahov
    while (k != 0) {
        int moves = min(6, k);                      // robim bud 6 tahov, alebo k (ak je k < 6)
        turn += moves;
        k -= moves;
        pos = (pos + moves) % boardFields;          // % pocet_policok zabezpeci, aby sme sa pohybovali v kruhu
        if (board[pos] != '.') {                    // vyhodenie figurky !!!
            kicks.push_back({board[pos], turn});    // ulozim si, aku figurku som vyhodil
            board[pos] = '.';                       // vyhodim figurku z hracej plochy
        }
    }
    board[pos] = 'R';                               // svoju figurku vratim spat na hracu plochu
}

void printKicks() {
    if (!kicks.empty()) cout << endl;
    for (auto kick : kicks) {
        switch (kick.symbol) {
            case 'B': cout << "modry"; break;
            case 'G': cout << "zeleny"; break;
            default : cout << "zlty"; break;
        }
        cout << " " << kick.turn << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();

    boardFields = (n - 1) * 4;
    board = string(boardFields, ' ');

    loadBoard(n);
    play(k);
    printBoard(n);
    printKicks();

    return 0;
}