## Zadanie - Extrémne človeče [> url <](https://zenit.ksp.sk/task/zenit21ske)

_Počet bodov: 40_

Keď sa Klaukina sestra Kristína dozvedela o jej Brutálnych kartičkách, rozhodla sa, že si aj ona vytvorí vlastnú hru, ktorá bude na rozdiel od Klaukinej maximálne extrémna.

Kristínina hra je vlastne obyčajné Človeče, nehnevaj sa, z ktorého odstránila všetky nadbytočné pravidlá, ktoré hru robili nedostatočne extrémnou. Zachovala len to najpodstatnejšie – opakované hádzanie kockou a vyhadzovanie figúrok súperov. A aby to bolo naozaj extrémne, rozhodla sa zrušiť obmedzenia na veľkosť hracej plochy a počet figúrok, ktoré môže mať jeden hráč.

Kristína naviac zásadne hrá iba s jedinou červenou figúrkou o ktorej tvrdí, že jej prináša šťastie. Okrem toho hrá vždy nanajvýš s troma ďalšími hráčmi.

### Úloha

Pre zadanú hraciu dosku a súčet čísel, ktoré Kristíne padli na kocke vypíšte stav hracej dosky po tomto ťahu. Okrem toho vypíšte zoznam figuriek, ktoré počas ťahu vyhodila.

Dráha na hracej doske pre Extrémne človeče má tvar štvorca so stranou dlhou presne _n_ políčok. Na každom políčku môže stáť v každom okamihu vždy najviac jedna figúrka.

Na začiatku ťahu Kristína hodí kockou a presunie svoju jedinú figúrku vpred v smere hodinových ručičiek o daný počet políčok. Ak je cieľové poličko obsadené figúrkou inej farby, Kristína ju bez ľútosti hneď vyhodí.

Ak jej naviac padlo na kocke číslo šesť, môže (ale nemusí) Kristína hádzať kockou znovu a zopakovať celý proces. Takto ťah pokračuje až dokým nepadne iné číslo ako šesť, alebo sa sama rozhodne nehádzať.

### Vstup a výstup

V prvom riadku sú dve celé čísla _n_ a _k_ - dĺžka strany dráhy na hracej doske, a súčet čísel ktoré padli na kocke.

Na nasledujúcich _n_ riadkoch je schéma aktuálneho stavu hracej dosky – prázdne políčka dráhy sú označené znakom `.`, Kristínina figúrka znakom `R` a figúrky protihráčov znakmi `G`, `B`, a `Y`. Okrem týchto znakov a medzery sa v schéme nebudú nachádzať žiadne iné znaky.

Na výstup vypíšte stav hracej plochy po danom ťahu v rovnakom tvare aký mal vstup. Ak počas ťahu Kristína vyhodila figúrky svojich súperov, vypíšte navyše prázdny riadok a potom pre každú figúrku do samostatného riadku jej farbu (`zeleny`, `modry`, `zlty`) a krok, v ktorom bola vyhodená. Tieto figúrky vypisujte v poradí, v ktorom boli vyhodené.

Platí _n_ ≥ 2, _k_ > 0.

V prvých dvoch sadách platí _n_ < 50, _k_ ≤ 6.

V tretej až piatej sade platí _n_ < 100, _k_ ≤ 100.

V posledných dvoch sadách platí _n_ < 1000 , _k_ ≤ 10 000.

### Príklad

##### Input:

```
4 5
.R..
.  .
.  .
....
```

##### Output:

```
....
.  .
.  .
...R
```

##### Input:

```
6 7
GB....
.    .
.    .
.    .
.    B
.R....
```

##### Output:

```
.R....
.    .
.    .
.    .
.    B
......

zeleny 6
modry 7
```

### Riešenie

Celú dosku je najvhodnejšie reprezentovať ako jednu líniu políčok, na ktorých sa nachádzajú hráči. Políčok je dokopy
`(n - 1) * 4` (4 strany dosky s prekrývajúcimi sa rohovými políčkami, preto -1). Rozmiestnenie políčok na vstupe je nasledovné:

1. Prvých _n_ políčok je prvý rad a zároveň prvých _n_ pozícií: _i_
2. Ďalších _n_-2 riadkov sú dvojice, ktoré zapisujem na indexy: _pocetpolicok_ - 1 - _i_ a _n_ + _i_
3. Posledných _n_ políčok je posledný rad: _pocetpolicok_ - _n_ - _i_ + 1

Načítanie a vypísanie dosky tak vyzerajú nasledovne:
```
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
```

Pri tejto reprezentácii sa vieme jednoducho pohybovať po doske. Akonáhle aplikujem % _pocetpolicok_, budem sa po doske pohybovať v kruhu.

Nájdem si teda moju pozíciu a odstránim odtiaľ svoju figúrku:
```
int mojapozicia = board.find('R');
board[pos] = '.';
```
a pozíciu posúvam podľa potreby napríklad:
```
pos = (pos + 6) % boardFields;
```

Najťažšie je zvoliť reprezentáciu dát. Spočítať aké figúrky som vyhodil je potom maličkosť.

[Riešenie v jazyku C++ nájdete tu](zenit21ske.cpp).