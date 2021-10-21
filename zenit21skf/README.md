## Zadanie - Ferdinant stávkuje [> url <](https://zenit.ksp.sk/task/zenit21skf)

_Počet bodov: 50_

“A dosť!” povedal si Ferdinant, keď jedol už 4. vifonku tento týždeň. Je to veľký labužník a občas by si dal aj oveľa honosnejšie jedlo. Taký rezeň by napríklad vôbec nebol zlý. Problém je v tom, že Ferdinant nie je práve najlepší kuchár. Zachrániť ho síce môžu reštaurácie a donáškové služby, no to pre chudobného študenta tiež nie je udržateľná alternatíva. Po dlhom uvažovaní dospel k záveru, že táto zapeklitá situácia sa dá riešiť 3 spôsobmi. Môže sa naučiť variť, môže si nájsť prácu alebo sa môže vydať cestou hazardu. Keď sa na to človek pozrie prakticky, učiť sa variť prináša mnohé riziká. Ferdinant by si ešte podpálil kuchyňu a už by si nemal kde zaliať ani tú vifonku. V takej práci zas treba pracovať, a kto by mal na to všetko čas? Ferdinant teda nie. Vyraďovacou metódou teda zisťujeme, že pre Ferdinanta je najlepšie začať stávkovať. Berie teda všetky svoje úspory, _N_ mincí a navštevuje miestnu stávkovú kanceláriu KSP. Tam mu povedia, že stávkovať môže v _K_ kolách a každé vyhrá s pravdepodobnosťou _P_. Ak dané kolo vyhrá, dostane dvojnásobok vstavených peňazí. Ak prehrá, všetky ich stratí.

Ferdinant by si rád vypočítal, koľko najviac peňazí bude mať v očakávanom prípade, ak bude stávkovať optimálne. No to je veľa počítania a kto by mal na to všetko čas? Ferdinant teda nie. Viete mu s tým pomôcť?

### Vstup a výstup

Na jednom riadku vstupu sa nachádzajú 3 čísla _N_, _K_ a _P_. _N_ predstavuje množstvo mincí, ktoré máme na začiatku, _K_ je počet kôl, ktoré budeme hrať, a _P_ je pravdepodobnosť, s akou stávku vyhráme.

Platí 0 ≤ _P_ ≤ 1, s presnosťou na 2 desatinné miesta.

V prvej sade platí 1 ≤ _K_ ≤ 5 a 1 ≤ _N_ ≤ 100. V druhej sade, 1 ≤ _K_ ≤ 50 a 1 ≤ _N_ ≤ 1000.

Vo výstupe vypíšte, koľko najviac mincí budeme mať v očakávanom prípade, ak stávkujeme optimálne. Odpoveď bude akceptovaná, ak relatívna alebo absolútna odchýlka neprevyšuje 10<sup>−6</sup>.

### Príklad

##### Input:

```
10 1 0.7
```

##### Output:

```
14
```
_Pri jednom kole sa nám oplatí staviť všetky mince. S pravdepodobnosťou 0.7 vyhráme a skončíme
s 20 mincami, a s pravdepodobnosťou 0.3 všetko stratíme. V očakávanom prípade teda máme
0.7 ⋅ 20 + 0.3 ⋅ 0 = 14 mincí._

##### Input:

```
150 30 0.2 
```

##### Output:

```
150
```
_V tomto prípade každú stávku pravdepodobne prehráme, a teda sa rozhodneme nestavit žiadne mince._

### Riešenie

Ak vieme, že pravdepodobnosť výhry je menšia ako 50% staviť si nechceme, pretože pri každej hre pôjdeme viac a viac do
mínusu. Akonáhle je pravdepodobnosť vyššia, náš počet mincí vynásobíme potenciálnym ziskom z každej hry.

Teda pre každé kolo násobíme výhru dvoma a pravdepodobnosťou. Teda výsledok bude _n × (2p)<sup>k</sup>_

[Riešenie v jazyku C++ nájdete tu](zenit21skf.cpp).