## Flowchart
<p> sedikit ribet emang </p>
<p> link syntax flowchart </p>

```
https://mermaid.js.org/syntax/flowchart.html
```
<h3> Flowchart Utama </h3>

```mermaid
flowchart LR
  y 
  a([Start]) --> b[/Matriks/]
  b --> c[[determinan]] --> e[/Determinan/]
  e -- determinan == 0 --> d[/"matriks is uninvertible"/]
  e -- determinan != 0 --> f[[invers matriks]]
  f --> g[/Invers/] --> h([End])
  d --> h
  b --> f
```
<h3> Sub-Flowchart Determinan </h3>
<p> buat ntar aja, cukup ribet buat kofaktor dengan LU decomposition </p>
<p> kemungkinan cari repositi orang lain </p>
<h3> Sub-Flowchart Invers Matriks </h3>
<p> dua matriks, matriks utama dan matriks sekunder memiliki 3 posisi, diantaranya: </p>

```mermaid
flowchart TB
  a([start])
  b([end])
  c[/matriks/]
  d{{matriks sekunder}}
  a --> b
```
