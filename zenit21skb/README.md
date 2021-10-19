## Zadanie - Brutálne kartičky [> url <](https://zenit.ksp.sk/task/zenit21skb)

_Počet bodov: 20_

V poslednej dobe Klauka trávi svoje prestávky v škole hraním Pokémon kartičiek s kamarátmi. Prestalo ju to však baviť, tak sa rozhodla, že si vyrobí vlastnú kartovú hru, ktorá bude viac brutálna ale aj jednoduchá.

### Úloha

Princíp hry je jednoduchý: každý hráč dostane 5 kartičiek, na ktorých je napísaná sila útoku. Z týchto kartičiek si môže vybrať ľubovoľné (ale aspoň jednu), ktorých sily sa sčítajú a ostatné zahodí. Víťazom hry je ten hráč, ktorý má najväčšiu silu útoku.

Dnes si Klauka musí cez prestávku napísať domácu úlohu z Angličtiny a preto nestíha hrať. Pomôžte jej vybrať najvhodnejšie kartičky.

### Vstup a výstup

Na vstupe je zadaných 5 celých čísel n<sub>1</sub>, n<sub>2</sub>, n<sub>3</sub>, n<sub>4</sub>, n<sub>5</sub> oddelených medzerami.

Vypíšte jedno číslo - najväčší súčet ktorý je možné vytvoriť z kartičiek.

Pre všetky n<sub>i</sub> platí, že −100000 < n < 100000

### Príklad vstupu a výstupu

##### Input:

```2 4 6 3 0```

##### Output:

```15```

##### Input:

```-4 2 0 1 3```

##### Output:

```6```

### Riešenie

Máme získať najvyšší možný súčet z kartičiek. To docielime tým, že sčítame všetky kladné čísla (akékoľvek záporné
číslo totiž vráti výsledok nižší, ako keby sme ho vôbec nezahrnuli).

**Pozor!!!** Musím si vziať aspoň jednu kartu, takže ak sú všetky záporné, musím si vybrať tú, ktorá má
najvyššiu hodnotu (hoci je záporná).

Najľahšie si je všetky položky uložiť do poľa, to zoradiť a sčítavať podľa pravidiel vyššie

[Riešenie v jazyku C++ nájdete tu](zenit21skb.cpp).