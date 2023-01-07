<h1> Invers matriks dengan OBE</h1>
<h3> Dokumentasi ada di main.cpp (dibuat di vscode, makanya dokumentasi jadi satu dalam satu file) </h3>
<h4> Masalah di dalam kode yang belum dibuat: </h4>
<ul>
<li> <p> menentukan determinan menggunakan metode kofaktor (lama) atau menggunakan LU decomposition </p> </li>
<li> <p> membuat logika dari program secara otomatis (ada di file logic.md) </p> </li>
<li> <p> mengalokasikan memori secara efektif (di program) </p> </li>
</ul>

<p> Hei diriku di masa depan, kuharap kau dapat menyelasaikan proyek gaje ini </p>
<p> Diriku di masa ini belum bisa menyelesaikannya secara efektif dan efisien </p>
<p> Karena masih banyak hal yang kuketahui soal pemrograman </p>

<h4> Flowchart program </h4>

```mermaid
flowchart TB
  s([start])
  e([end])
  mi[/matriks input/]
  io[/invers output/]
  d[/determinan/]
  mti[/matriks tidak dapat diinverskan/]
  subgraph determinan
    pd(proses mencari determinan matriks)
  end
  subgraph invers
    mumi(matriks utama = matriks input)
    mid{{matriks identitas}}
    msAw{{matriks sekunder}}
    muAw{{matriks utama}}
    msmid(matriks sekunder = matriks identitas)
    
    muAw --> mumi
    msAw --> msmid
    mid --> msmid
    
    muP[/matriks utama/]
    msP[/matriks sekunder/]
    mumi --> muP
    msmid --> msP
    
    muPmid{matriks utama == matriks identitas?}
    muP --> muPmid
    muPmid -- yes -.-> msP --> io 
    muPmid -- no --> pI(proses invers)
  end
  s --> mi
  mi --> determinan
  mi -.-> mumi
  d --determinan != 0--> invers
  d --determinan == 0--> mti --> e
  determinan --> d
  io --> e
```
<p> flowchartnya masih berantakan, benerin lagi! Logikanya udah keliatan </p>
<p> Diedit pada 7 Januari 2023 </p>
