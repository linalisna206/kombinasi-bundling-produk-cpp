#include <iostream>
using namespace std;

// struct untuk menyimpan data produk
struct Produk {
    string nama;
    int modal;
    int harga;
};

int jumlahKombinasi = 0;
int maxProfit = -1;

string bestBundle[100];
int bestSize = 0;

// fungsi kombinasi bundling (menggunakan algoritma rekursif)
void kombinasi(Produk data[], Produk temp[], int start, int n, int r, int index) {

    // kondisi berhenti (base case)
    // jika jumlah produk dalam paket sudah sesuai (r)
    if (index == r) {
        jumlahKombinasi++;

        int totalModal = 0, totalHarga = 0;

        cout << jumlahKombinasi << ". Paket: ";
        for (int i = 0; i < r; i++) {
            cout << temp[i].nama;
            if (i < r - 1) cout << " + ";
            totalModal += temp[i].modal;
            totalHarga += temp[i].harga;
        }

        // menghitung profit
        int profit = totalHarga - totalModal;

        cout << "| Profit: " << profit << endl;

        // cek apakah profit ini terbesar atau bukan   
        if (profit > maxProfit) 
        {
            maxProfit = profit;
            bestSize = r;
            for (int i = 0; i < r; i++) {
                bestBundle[i] = temp[i].nama;
            }
        }

        return;
    }

    // proses pembentukan kombinasi
    for (int i = start; i < n; i++) 
    {
        temp[index] = data[i];
        // pemanggilan algoritma rekursif untuk kombinasi berikutnya
        kombinasi(data, temp, i + 1, n, r, index + 1);
    }
}

// fungsi faktorial untuk menghitung C(n,r)
int faktorial(int x) 
{
    int hasil = 1;
    for (int i = 1; i <= x; i++) 
    {
        hasil *= i;
    }
    return hasil;
}

int main() 
{
    int n, r;

    cout << "=== Program Kombinasi bundling produk ===" << endl;
    cout << "Jumlah produk: ";
    cin >> n;

    Produk data[100];

    for (int i = 0; i < n; i++) 
    {
        cout << "\nProduk ke-" << i+1 << endl;
        cout << "Nama: ";
        cin.ignore(); // membersihkan buffer sebelum input string
        getline(cin, data[i].nama);

        cout << "Modal: ";
        cin >> data[i].modal;

        cout << "Harga jual: ";
        cin >> data[i].harga;
    }

    cout << "\nJumlah produk dalam bundling: ";
    cin >> r;

    Produk temp[100];

    cout << "\n=== Semua Kombinasi Bundling ===\n";
    kombinasi(data, temp, 0, n, r, 0);

    // menghitung jumlah kombinasi dengan rumus c(n,r)
    int hasilRumus = faktorial(n) / (faktorial(r) * faktorial(n - r));

    cout << "\nTotal kombinasi (program): " << jumlahKombinasi << endl;
    cout << "Total kombinasi (rumus C(n,r)): " << hasilRumus << endl;

    cout << "\n=== Bundling Paling Menguntungkan ===\n";
    cout << "Paket: ";
    for (int i = 0; i < bestSize; i++) 
    {
        cout << bestBundle[i];
        if (i < bestSize - 1) cout << " + ";
    }
    cout << "\nProfit Maksimum: " << maxProfit << endl;

    return 0;
}
