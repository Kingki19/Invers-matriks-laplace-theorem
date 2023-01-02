# Logika program

*Belum selesai*

*masih bingung cara ngebuat rekursi pada kofaktor*

```
declaration:
vector<vector<float>> matriks
float                 determinan

# rekursi menggunakan Kofaktor
funct determinan(matriks.size, matriks)
{
  float hasil
  If matriks.size == 2:
    return ???
  Else
    //ribet
    matriks.size -= 1
  EndIf
}

Input(matriks)

# Check the determinan
determinan(matriks)
  Output(determinan)

# Calculation
Input(determinan)
If determinan == 0, then:
  print("Matriks is uninvertible")
Else
  # Check each element of matriks
  For a = 0, a < matriks.size, a++:
    For b = 0, b < matriks.size, b++:
     # Position of elements
     If a == b, then:
      If matriks[a][b] == 1, then:
        continue
      Else:
        // Logika mulai disini
      EndIf
     Else: 
      If matriks[a][b] == 0, then:
        continue
      Else:
        // logika mulai disini
      EndIf
     EndIf
    EndFor
  EndFor
EndIf
```
