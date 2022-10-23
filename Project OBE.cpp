#include <iomanip>
#include <iostream>
using namespace std;
/*
Catatan ada di bagian bawah
jangan sembarangan di edit dan copas gan, koreksi dipersilahkan
Koreksi:
  ->
  ->
*/
int main() {
  int baris, kolom, i, j, obe, baris_i, baris_j;
  float matriks[10][10], x, matriksTemp[10][10], k;
  float matriksIdentitas[10][10], matriksIdentitasTemp[10][10];
  char pilihan, BaLi;
  cout << "Invers matriks menggunakan OBE" << endl;
  cout << endl;
  cout << "Max baris: 10 & Max kolom: 10" << endl;
  cout << endl;
  // Input baris dan kolom
  do {
    cout << "Masukkan banyaknya baris: ";
    cin >> baris;
    cout << "Masukkan banyaknya kolom: ";
    cin >> kolom;
    cout << endl;
    if (baris <= 10 && kolom <= 10 && baris > 0 && kolom > 0) {
      break;
    } else {
      cout << "Input salah!" << endl;
      cout << endl;
    }
  } while (baris > 10 || kolom > 10 || baris < 1 || kolom < 1);
  // Input elemen di dalam matriks
  for (i = 0; i < baris; i++) {
    for (j = 0; j < kolom; j++) {
      cout << "Input baris " << i + 1 << " dan kolom " << j + 1 << " : ";
      cin >> x;
      matriks[i][j] = x;
    }
  }
  // Matriks Identitas
  for (i = 0; i < baris; i++) {
    for (j = 0; j < kolom; j++) {
      if (i == j) {
        matriksIdentitas[i][j] = 1;
      } else {
        matriksIdentitas[i][j] = 0;
      }
    }
  }
  cout << endl;
  // Output matriks
  cout << "Matriks: " << endl;
  cout << endl;
  for (i = 0; i < baris; i++) {
    for (j = 0; j < kolom; j++) {
      if (matriks[i][j] == -0) {
        matriks[i][j] = 0;
      }
      cout << " " << matriks[i][j];
    }
    cout << endl;
    cout << endl; // double spasi
  }
  cout << endl;
  // Pilih invers ga nih?
  do {
    cout << "Apakah anda ingin melakukan Invers matriks? (y/n) ";
    cin >> pilihan;
    if (pilihan != 'y' && pilihan != 'n') {
      cout << "Input salah!" << endl;
    }
  } while (pilihan != 'y' && pilihan != 'n');
  cout << endl;

  switch (pilihan) { // OBE atau nggak?
  case 'y':
    // Output matriks awal dan matriks identitas
    cout << "Matriks Awal" << endl;
    cout << endl;
    for (i = 0; i < baris; i++) { // matriks awal
      for (j = 0; j < kolom; j++) {
        if (matriks[i][j] == -0) {
          matriks[i][j] = 0;
        }
        cout << " " << matriks[i][j];
      }
      cout << endl;
      cout << endl;
    }
    cout << "-------------------------" << endl;
    cout << endl;
    for (i = 0; i < baris; i++) { // Matriks identitas
      for (j = 0; j < kolom; j++) {
        cout << " " << matriksIdentitas[i][j];
      }
      cout << endl;
      cout << endl;
    }
    // Pilihan operasi OBE
    do { // Jangan ditutup
      cout << "Pilihan Operasi Baris Elementer" << endl;
      cout
          << "1 --------- Operasi menukar baris i dengan baris j ---------- Rij"
          << endl;
      cout << "2 ------ Operasi mengalikan baris i dengan bilangan k ------- "
              "Ri(k)"
           << endl;
      cout << "3 -- Operasi menjumlahkan baris i dengan kelipatan baris j -- "
              "Rij(k)"
           << endl;
      // Input pilihan OBE
      do {
        cout << endl;
        cout << "Input angka pilihan: ";
        cin >> obe;
      } while (obe < 1 || obe > 3);
      cout << endl;
      // OBE
      switch (obe) {
        // Pilihan operasi Rij
      case 1:
        cout << "Baris mana yang ingin ditukar?" << endl;
        do { // Input baris i
          cout << "Baris i: ";
          cin >> baris_i;
          if (baris_i > baris || baris_i <= 0) {
            cout << "Input salah!" << endl;
          }
        } while (baris_i > baris || baris_i <= 0);
        do { // Input baris j
          cout << "Baris j: ";
          cin >> baris_j;
          if (baris_j > baris || baris_j <= 0) {
            cout << "Input salah!" << endl;
          }
        } while (baris_j > baris || baris_j <= 0);
        // Operasi Rij
        for (i = 0; i < kolom; i++) {
          matriksTemp[baris_i - 1][i] = matriks[baris_i - 1][i];
          matriks[baris_i - 1][i] = matriks[baris_j - 1][i];
          matriks[baris_j - 1][i] = matriksTemp[baris_i - 1][i];
          matriksIdentitasTemp[baris_i - 1][i] =
              matriksIdentitas[baris_i - 1][i];
          matriksIdentitas[baris_i - 1][i] = matriksIdentitas[baris_j - 1][i];
          matriksIdentitas[baris_j - 1][i] =
              matriksIdentitasTemp[baris_i - 1][i];
        }
        cout << endl;
        cout << "R" << baris_i << baris_j << endl;
        break;
        // Pilihan operasi Ri(k)
      case 2:
        cout << "Baris mana yang ingin dikali dengan bilangan k?" << endl;
        do { // Input baris i
          cout << "Baris i: ";
          cin >> baris_i;
          if (baris_i > baris || baris_i <= 0) {
            cout << "Input salah!" << endl;
          }
        } while (baris_i > baris || baris_i <= 0);
        // Input k
        do {
          cout << "Ingin dikali atau dibagi? (* atau /) ";
          cin >> BaLi;
          if (BaLi != '*' && BaLi != '/') {
            cout << "input salah!";
          }
        } while (BaLi != '*' && BaLi != '/');
        cout << "K: ";
        cin >> k;
        // Operasi Ri(k)
        if (BaLi == '*') {
          for (i = 0; i < baris; i++) {
            matriks[baris_i - 1][i] = matriks[baris_i - 1][i] * k;
            matriksIdentitas[baris_i - 1][i] =
                matriksIdentitas[baris_i - 1][i] * k;
          }
          cout << endl;
          cout << "R" << baris_i << "(" << k << ")" << endl;
        } else if (BaLi == '/') {
          for (i = 0; i < baris; i++) {
            matriks[baris_i - 1][i] = matriks[baris_i - 1][i] / k;
            matriksIdentitas[baris_i - 1][i] =
                matriksIdentitas[baris_i - 1][i] / k;
          }
          cout << endl;
          cout << "R" << baris_i << "(1/" << k << ")" << endl;
        }
        break;
        // Pilihan operasi Rij(k)
      case 3:
        cout << "Baris mana yang ingin dijumlahkan dengan kelipatan baris lain?"
             << endl;
        do { // Input baris i
          cout << "Baris i: ";
          cin >> baris_i;
          if (baris_i > baris || baris_i <= 0) {
            cout << "Input salah!" << endl;
          }
        } while (baris_i > baris || baris_i <= 0);
        do { // Input baris j
          cout << "Baris j: ";
          cin >> baris_j;
          if (baris_j > baris || baris_j <= 0) {
            cout << "Input salah!" << endl;
          }
        } while (baris_j > baris || baris_j <= 0);
        // Input k
        cout << "K: ";
        cin >> k;
        // Operasi Rij(k)
        for (i = 0; i < baris; i++) {
          matriks[baris_i - 1][i] =
              matriks[baris_i - 1][i] + (matriks[baris_j - 1][i] * k);
          matriksIdentitas[baris_i - 1][i] =
              matriksIdentitas[baris_i - 1][i] +
              (matriksIdentitas[baris_j - 1][i] * k);
        }
        cout << endl;
        cout << "R" << baris_i << baris_j << "(" << k << ")" << endl;
        break;
      }
      cout << endl;
      // Output matriks hasil operasi
      for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
          if (matriks[i][j] == -0) {
            matriks[i][j] = 0;
          }
          cout << fixed;
          cout << setprecision(0);
          cout << " " << matriks[i][j];
        }
        cout << endl;
        cout << endl;
      }
      cout << "-------------------------" << endl;
      cout << endl;
      for (i = 0; i < baris; i++) {
        for (j = 0; j < kolom; j++) {
          if (matriksIdentitas[i][j] == -0) {
            matriksIdentitas[i][j] = 0;
          }
          cout << fixed;
          cout << setprecision(0);
          cout << " " << matriksIdentitas[i][j];
        }
        cout << endl;
        cout << endl;
      }
      cout << endl;
      // OBE lagi ga nih?
      do {
        cout << "Apakah anda ingin melakukan OBE lagi?(y/n) ";
        cin >> pilihan;
        if (pilihan == 'n') {
          cout << "Selesai";
          break;
        }
      } while (pilihan != 'y' && pilihan != 'n');
      cout << endl;
    } while (pilihan == 'y');
    break;
  case 'n':
    cout << "Terima kasih" << endl;
    break;
  }
}
/*
CATATAN PERMASALAHAN:
- Tidak bisa menginput pecahan dalam "k" pada operasi ke-2 dan ke-3
    -> Bisa tapi harus menggunakan bentuk desimal (0.x)
        - Jika angka di belakang koma ada banyak, misal 0.3333333333 (solved)

CATATAN IDE:
- Pada bagian akhir operasi, setelah bentuk matriks awal itu sama dengan matriks
identitas.
    -> langsung print invers matriks
    -> Semua OBE yang digunakan untuk mencapai invers matriks

UI masih jelek, tidak bisa secara otomatis menampilkan hasil. Setiap OBE harus
dibuat sendiri. (kalau ga konsen harus ngulang dari awal kalau salah input,
wkwkwk)
*/
