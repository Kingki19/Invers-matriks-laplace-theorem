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
    return 
  Else
    
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
    
    EndFor
  EndFor
EndIf
```
