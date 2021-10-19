## Zadanie - Dobré štatistiky [> url <](https://zenit.ksp.sk/task/zenit21skd)

_Počet bodov: 25_

Jožko je paranoidný. Neverí žiadnym štatistikám ktoré pochádzajú z jedného zdroja.
Chcel by vás teda poprosiť, aby ste pre neho porátali nejaké štatistiky. Ak vás bude
dosť veľa, možno im aj uverí. Najviac by ho zaujímalo, ako to vyzerá s koronou tak celkovo.
Koľko dní sa situácia zlepšovala, koľko sa zhoršovala a koľko vôbec bolo tých vĺn.

### Úloha

Ak v niektorý deň pribudne menej prípadov ako predošlí, situácia sa v daný deň zlepšuje a
naopak, ak pribudne viac ako predošlí deň, situácia sa zhoršuje. Za vrchol vlny považujeme
taký deň, kedy sa situácia zhoršila, a nasledujúci deň sa zlepšila. Počet vĺn je rovnaký ako
počet vrcholov vĺn.

Zistite, koľko dní sa za celý čas situácia zlepšovala, koľko dní sa zhoršovala, a koľko bolo vĺn.

### Vstup a výstup

V prvom riadku je číslo _n_ – počet dní za ktoré máme záznamy. Platí (2 ≤ _n_ ≤ 1000).
Nasleduje _n_ riadkov. V _i_-tom z nich je číslo n<sub>i</sub>, počet nových prípadov za _i_-ty deň.

Vypíšte jeden riadok a v ňom tri medzerou oddelené čísla: počet dní kedy sa situácia zlepšovala, počet dní kedy sa situácia zhoršovala a počet vĺn.

### Príklad

##### Input:

```
10
1
2
4
8
2
15
18
18
16
6
```

##### Output:

```
3 5 1
```

### Riešenie

Pre určenie toho, či sa situácia zlepšovala, alebo nie, nám stačia posledné 2 záznamy
(ak mám iba jeden záznam, neviem určiť aktuálnu situáciu). Pre určenie vrchola potrebujem vedieť
aspoň posledné 3 záznamy (z posledných dvoch neviem určiť, či som vo vrchole).

Najjednoduchší spôsob je pamätať si posledné 3 položky a po každom načítaní ďalšieho záznamu si
ich poposúvať (pre praktické využitie pozri [sliding window technique](https://levelup.gitconnected.com/understanding-the-sliding-window-technique-in-algorithms-c6c3bf8226da))
```
predvcerom = vcera;
vcera = dnes;
cin >> dnes;
```
Ak mám 2 záznamy, tak viem určiť, či sa situácia zlepšovala (_dnes_ < _vcera_) alebo zhoršovala (_dnes_ > _vcera_)

Ak mám 3 záznamy, tak viem určiť, či som narazil na vrchol (_dnes_ < _vcera_ && _vcera_ > _predvcerom_)

```
if (dnes > vcera) zhorsenia++;
if (dnes < vcera) zlepsenia++;
if (dnes < vcera && vcera > predvcerom) vlny++;
```

[Riešenie v jazyku C++ nájdete tu](zenit21skd.cpp).