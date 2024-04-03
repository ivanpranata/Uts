#include <iostream>
#include <string>

using namespace std;

// Modifikasi struktur untuk menyimpan data mahasiswa tanpa NIM dan IPK
struct Mahasiswa {
    string nama;
    string makananFavorit;
    string minumanFavorit;
    string tanggalUlangTahun; // Format bisa berupa string sederhana "DD-MM-YYYY"
    Mahasiswa *next;
};

// Fungsi untuk menambahkan data mahasiswa baru ke dalam linked list
void tambahData(Mahasiswa** kepala, string nama, string makananFavorit, string minumanFavorit, string tanggalUlangTahun) {
    Mahasiswa* mahasiswaBaru = new Mahasiswa();
    Mahasiswa* terakhir = *kepala;

    mahasiswaBaru->nama = nama;
    mahasiswaBaru->makananFavorit = makananFavorit;
    mahasiswaBaru->minumanFavorit = minumanFavorit;
    mahasiswaBaru->tanggalUlangTahun = tanggalUlangTahun;
    mahasiswaBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = mahasiswaBaru;
        return;
    }

    while (terakhir->next != NULL) {
        terakhir = terakhir->next;
    }

    terakhir->next = mahasiswaBaru;
}

// Fungsi untuk menampilkan data mahasiswa beserta informasi tambahan
void tampilkanData(Mahasiswa *node) {
    while (node != NULL) {
        cout << "Nama: " << node->nama;
        cout << ", Makanan Favorit: " << node->makananFavorit;
        cout << ", Minuman Favorit: " << node->minumanFavorit;
        cout << ", Tanggal Ulang Tahun: " << node->tanggalUlangTahun << endl;
        node = node->next;
    }
}

int main() {
    Mahasiswa* kepala = NULL;

    // Menambahkan data mahasiswa
    tambahData(&kepala, "Budi", "Nasi Goreng", "Teh Manis", "01-01-2000");
    tambahData(&kepala, "Ani", "Sate", "Kopi", "02-02-2001");
    tambahData(&kepala, "Wati", "Bakso", "Soda", "03-03-2002");

    // Menampilkan data mahasiswa
    cout << "Data Mahasiswa:" << endl;
    tampilkanData(kepala);

    return 0;
}
