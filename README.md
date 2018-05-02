# Vertinimas

- Sutvarkyti README pagal reikalavimus
- Sukurti cmake (CMakeList.txt) arba make (MAKEFILE)


# Kaip naudotis programa

Programa naudotis paprasta:
* Atsisiųsti naujausią realeas'ą
* Atidaryti Paleisti.cpp failą 
* norint generuoti ir skaityti failus spausti 2, įvesti pačiam - 1.
* sekti tolimesnes programoje nurodytas instrukcijas

Pirmoji programa
# [v0.1](https://github.com/mrchezz/test/releases/tag/v0.100001)
* Pradėta programa
 * Apskaičiuoja mokinių rezultatus pagal įvestus duomenis
 * Galimas random skaičių generavimas
# [v0.2](https://github.com/mrchezz/test/releases/tag/v0.200)
* Programa skaito iš failo
* Pradėtos naudoti struktūros
# [v0.3](https://github.com/mrchezz/test/releases/tag/v0.31)
* Pridėti .h (header) failai
* Pradėti naudoti vektoriai
# [v0.4](https://github.com/mrchezz/test/releases/tag/v0.4)
* Pradėti grupuoti studentai
# [v1.0](https://github.com/mrchezz/test/releases/tag/v1.0)
* Trys konteinerių tipai
* Naudojamos abi strategijos
* Tiksliai išmatuotas funkcijų veikimo laikas
* Pridėtas readme failas
# [v1.0](https://github.com/mrchezz/test/releases/tag/v1.010)
* Pridėtas README.md failas
* Ištrinti nereikalingi failai
## Ataskaita
Failo generavimas

0.922672s

Naudojant 2 konteinerius

Vektorius:

|failų skaičius | laikas |
|---------------|--------|
| 10 | 0.004008s |
| 100 | 0.012017s |
| 1000 |0.063363s |
| 10000 | 0.597255s |
| 100000 | 5.53383 s |

Deque:

|failų skaičius | laikas |
|---------------|--------|
| 10        | 0s |
| 100  |0       s |
| 1000 | 0.062546s |
| 10000 |0.577504s |
| 100000 | 5.79763 s |

List:

|failų skaičius | laikas |
|---------------|--------|
| 10  | 0.015628s |
| 100 | 0       s |
| 1000   | 0.055098s |
| 10000    | 0.503515s |
| 100000   | 4.81017 s |

Naudojant 3 konteinerius

Vektorius:

|failų skaičius | laikas |
|---------------|--------|
| 10  |0       s |
| 100   | 0       s |
| 1000   | 0.062539s |
| 10000   | 0.552101s |
| 100000 |  5.53861 s |

Deque:

|failų skaičius | laikas |
|---------------|--------|
| 10    | 0.004029s |
| 100   | 0.004096s |
| 1000  | 0.062544s |
| 10000   | 0.594409s |
| 100000  | 5.89093 s |

List:

|failų skaičius | laikas |
|---------------|--------|
| 10  | 0       s |
| 100     | 0.015628s |
| 1000   | 0.062545s |
| 10000   | 0.497908s |
| 100000  | 4.96985 s |

Naudojant optimizavimo flag'us:

|lygis | laikas | būdas|konteineriai| 
|---------------|--------|---|----|
| O1 | 5.77476 | Vector | 2 |
| O1 | 6.10345 | List | 2 |
| O1 | 5.12426 | Deque | 2 |
| O1 | 5.74883 | Vector | 3 |
| O1 | 5.74883 | List | 3 |
| O1 | 5.9939 | Deque | 3 |

|lygis | laikas | būdas|konteineriai| 
|---------------|--------|---|----|
| O2 | 6.32502 | Vector | 2 |
| O2 | 6.16982 | List | 2 |
| O2 | 5.61493 | Deque | 2 |
| O2 | 6.00598 | Vector | 3 |
| O2 | 6.45116 | List | 3 |
| O2 | 5.56283 | Deque | 3 |

|lygis | laikas | būdas|konteineriai| 
|---------------|--------|---|----|
| O3 | 6.05209 | Vector | 2 |
| O3 | 6.16038 | List | 2 |
| O3 | 4.94215 | Deque | 2 |
| O3 | 5.8482 | Vector | 3 |
| O3 | 6.40604 | List | 3 |
| O3 | 5.06884 | Deque | 3 |


