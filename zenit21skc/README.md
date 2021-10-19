## Zadanie - Cifierky [> url <](https://zenit.ksp.sk/task/zenit21skc)

_Počet bodov: 20_

Danušik jedol polievku s číslovicovými cestovinami. Zjedol najmenšiu číslicu. Čo zjedol?

### Úloha

Zistite, akú cifru zjedol Danušik.

### Vstup a výstup

V prvom riadku je číslo _t_ – počet polievok, z ktorých Danušik povyjedal. Platí (1 ≤ _t_ ≤ 1000).
Nasleduje _t_ riadkov. V _i_-tom z nich je číslo n<sub>i</sub>, ktoré vidí Danušik v _i_-tej polievke.

Vypíšte _t_ riadkov. V _i_-tom riadku vypíšte najmenšiu cifru z čísla, ktoré sa nachádzalo v _i_-tej
polievke.

V prvej sade 0 ≤ n<sub>i</sub> ≤ 100. V druhej sade 
0 ≤ n<sub>i</sub> ≤ 100 000. V ostatných sadách 0 ≤ n<sub>i</sub> ≤ 10<sup>18</sup>.

### Príklad

##### Input:

```
3
75392
13
52
```

##### Output:

```
2
1
2
```

### Riešenie

10<sup>18</sup> je príliš veľké číslo pre uloženie do typu long. Lepšie je prečítať vstup ako
text a písmenko po písmenku zistiť, ktoré z nich má najmenšiu ordinálnu hodnotu pomocou zápisu
_moj_char - '0'_ (napríklad _'2' - '0' = 2_)

[Riešenie v jazyku C++ nájdete tu](zenit21skc.cpp).