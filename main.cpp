#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// JOB:
// Kau harus menentukan apakah matriks yang dimasukkan itu dapat di-inverskan atau tidak menggunakan OBE
// Kau harus membuat algoritma untuk menentukan determinan terlebih dahulu

/*
Dokumentasi:

Deklarasi fungsi yang dibutuhkan:
> Semua OBE (lihat sendiri di bagian bawah dokumentasi)
> Print matriks (biar ga ribet print ulang pake for(for()){{}} O
> Garis pembatas (memudahkan melihat setiap bagian OBE di terminal)
> Print matriks setiap OBE (lihat semi-output)

Alur I/O
Input: banyak baris, banyak kolom, matriks utama awal
Semi-Output: setiap proses dari OBE (yakali langsung dikeluarin hasil akhir, nanti dikira ngawur)
Output: matriks sekunder akhir (invers dari matriks utama awal)

1)  Bagian awal:
Input:
Harusnya input m dan n sama agar tidak bisa dilakukan invers 
-> Banyaknya baris (m)
-> Banyaknya kolom (n)
-> Matriks utama awal

Deklarasi lainnya
matriks identitas (patokan agar proses logika berhenti)
matriks sekunder awal = matriks identitas

2)  Bagian proses:
Deklarasi nilai awal proses:
matriks utama proses = matriks utama awal
matriks sekunder proses = matriks sekunder awal

Menentukan determinan dari matriks:
(ribet kalau di dokumentasikan)

Jika determinan == 0, maka operasi batal 
//(syarat dilakukannya invers adalah determinan tidak sama dengan nol)
Jika determinan != 0, maka lanjut

Logika:
Buat ntar waktu udah ada pencerahan
3)  Bagian akhir:
*/

/*-----------------------------Operasi Baris Elementer-------------------------------------*/
// Tukar Baris (Rij)
std::vector<std::vector<double>> tukarBaris(int m,
                                            int n,
                                            int baris_i,
                                            int baris_j,
                                            std::vector<std::vector<double>> matriksAwal)
{
  // Deklarasi matriks hasil
  std::vector<std::vector<double>> matriksAkhir(m, std::vector<double>(n));

  // Operasi Matriks
  for (int i = 0; i < m; i++)
  {
    if (i == baris_i - 1)
    {
      matriksAkhir[baris_i - 1] = matriksAwal[baris_j - 1];
    }
    else if (i == baris_j - 1)
    {
      matriksAkhir[baris_j - 1] = matriksAwal[baris_i - 1];
    }
    else
    {
      matriksAkhir[i] = matriksAwal[i];
    }
  }

  // Hasil Fungsi
  return matriksAkhir;
}
// Kali Konstanta (Rik)
std::vector<std::vector<double>> kaliKonstanta(int m,
                                               int n,
                                               int baris_i,
                                               double k,
                                               std::vector<std::vector<double>> matriksAwal)
{
  // Deklarasi matriks hasil
  std::vector<std::vector<double>> matriksAkhir(m, std::vector<double>(n));

  // Operasi Matriks
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == baris_i - 1)
      {
        matriksAkhir[i][j] = matriksAwal[i][j] * k;
      }
      else
      {
        matriksAkhir[i][j] = matriksAwal[i][j];
      }
    }
  }

  // Hasil Fungsi
  return matriksAkhir;
}
// Bagi Konstanta (Ri(1/k))
std::vector<std::vector<double>> bagiKonstanta(int m,
                                               int n,
                                               int baris_i,
                                               double k,
                                               std::vector<std::vector<double>> matriksAwal)
{
  // Deklarasi matriks hasil
  std::vector<std::vector<double>> matriksAkhir(m, std::vector<double>(n));

  // Operasi Matriks
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == baris_i - 1)
      {
        matriksAkhir[i][j] = matriksAwal[i][j] / k;
      }
      else
      {
        matriksAkhir[i][j] = matriksAwal[i][j];
      }
    }
  }

  // Hasil Fungsi
  return matriksAkhir;
}
// Jumlah Kelipatan (Rij(k))
std::vector<std::vector<double>> jumlahKelipatan(int m,
                                                 int n,
                                                 int baris_i,
                                                 int baris_j,
                                                 double k,
                                                 std::vector<std::vector<double>> matriksAwal)
{
  // Deklarasi matriks hasil
  std::vector<std::vector<double>> matriksAkhir(m, std::vector<double>(n));

  // Operasi Matriks
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == baris_i - 1)
      {
        matriksAkhir[i][j] = matriksAwal[i][j] + (matriksAwal[baris_j - 1][j] * k);
      }
      else
      {
        matriksAkhir[i][j] = matriksAwal[i][j];
      }
    }
  }

  // Hasil Fungsi
  return matriksAkhir;
}
// Jumlah Pembagian (Rij(1/k))
std::vector<std::vector<double>> jumlahPembagian(int m,
                                                 int n,
                                                 int baris_i,
                                                 int baris_j,
                                                 double k,
                                                 std::vector<std::vector<double>> matriksAwal)
{
  // Deklarasi matriks hasil
  std::vector<std::vector<double>> matriksAkhir(m, std::vector<double>(n));

  // Operasi Matriks
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == baris_i - 1)
      {
        matriksAkhir[i][j] = matriksAwal[i][j] + (matriksAwal[baris_j - 1][j] / k);
      }
      else
      {
        matriksAkhir[i][j] = matriksAwal[i][j];
      }
    }
  }

  // Hasil Fungsi
  return matriksAkhir;
}
/*---------------------------------------------------------------------------------------------------*/

// Menentukan Operasi Determinan
double determinan1(int m,
                  int n,
                  std::vector<std::vector<double>> matriks)
{
  double hasil;
  std::vector<double> elemen <n>
  for (int a = 0; a < matriks.size(); a++)
  {

  }

  for (int a = 0; )
}
// Penghitungan Operasi Determinan
double determinan2(){}

// Print Matriks
void printMatriks(std::vector<std::vector<double>> matriks)
{
  for (int i = 0; i < matriks.size(); i++)
  {
    for (int j = 0; j < matriks[i].size(); j++)
    {
      cout << fixed << setprecision(2) << matriks[i][j] << " ";
    }
    cout << endl;
  }
}
// Garis Pembatas
void garis()
{
  cout << "--------------------" << endl;
}
// Print Matriks OBE
void printOBE(std::vector<std::vector<double>> matriksUtama,
              std::vector<std::vector<double>> matriksSekunder)
{
  cout << "Matriks Utama: " << endl;
  printMatriks(matriksUtama);
  cout << endl;
  cout << "Matriks Sekunder: " << endl;
  printMatriks(matriksSekunder);
  garis();
}

// Alur Utama
int main()
{
  // Deklarasi Variabel dan Matriks
  int m;       // baris
  int n;       // kolom
  int k;       // kelipatan atau konstanta, bisa angka real atau pecahan
  int baris_i; // baris yang dioperasikan baris j
  int baris_j; // baris yang memngoperasikan baris i
  double determinan;

  // Matriks Utama
  vector<vector<double>> matriksUAwal(m, vector<double>(n));   // matriks utama awal
  vector<vector<double>> matriksUAkhir(m, vector<double>(n));  // matriks utama akhir
  vector<vector<double>> matriksUProses(m, vector<double>(n)); // matriks utama proses

  // Matriks Sekunder
  vector<vector<double>> matriksSAwal(m, vector<double>(n));   // matriks sekunder awal
  vector<vector<double>> matriksSAkhir(m, vector<double>(n));  // matriks sekunder akhir
  vector<vector<double>> matriksSProses(m, vector<double>(n)); // matriks sekunder proses

  // Matriks Pembantu
  vector<vector<double>> matriksIdentitas(m, vector<double>(n)); // matriks identitas

  // Input baris dan kolom
  cout << "baris dan kolom harus sama" << endl;
  cout << "input baris: ";
  cin >> m;
  cout << "input kolom: ";
  cin >> n;
  cout << endl;

  // Pembuatan matriks identitas
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        matriksIdentitas[i][j] = 1;
      }
      else
      {
        matriksIdentitas[i][j] = 0;
      }
    }
  }

  // Input data (matriks utama awal)
  cout << "Masukkan nilai: " << endl;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "baris " << i + 1 << " kolom " << j + 1 << " : ";
      cin >> matriksUAwal[i][j];
    }
  }
  cout << endl;

  // Matriks sekunder awal
  matriksSAwal = matriksIdentitas;

  // Deklarasi nilai awal proses
  matriksUProses = matriksUAwal;
  matriksSProses = matriksSAwal;

  // Menentukan determinan

  // Proses (belum selesai--tentuin determinan dahulu)
  if (determinan == 0)
  {
    cout << "Matriks tidak dapat diinverskan menggunakan OBE" << endl;
  }
  else
  {
    while (matriksUProses != matriksIdentitas)
    {
      for (int a = 0; a < matriksUProses.size(); a++) // a menunjukkan baris
      {
        for (int b = 0; b < matriksUProses[a].size(); b++) // b menunjukkan kolom
        {
          if (a == b) // Diagonal utama
          {
            if (matriksUProses[a][b] == 1)
            {
              continue;
            }
            else
            {
              for (int c = a + 1; c < matriksUProses.size(); c++) // c menunjukkan baris setelah a
              {
                if (matriksUProses[c][b] == 1)
                {
                }
              }
            }
          }
          else
          {
            if (matriksUProses == 0)
            {
              continue;
            }
            else
            {
              for (int c = a + 1; c < matriksUProses.size(); c++)
              {
              }
            }
          }
        }
      }
    }
  }

  // Output data
  printOBE(matriksUAkhir, matriksUAwal);
  return 0;
}
