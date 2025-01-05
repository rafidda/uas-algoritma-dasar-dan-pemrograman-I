#include <iostream>
#include <iomanip>
using namespace std;

// Structure data untuk menyimpan informasi peminjaman
struct Peminjaman {
    float jumlahPinjaman;
    int jangkaWaktu;
    float bungaPinjaman;
    float totalBayar;
    float angsuranPerBulan;
    float nominalBunga;
};

// Structure data untuk input dan output
struct IO {
    // Fungsi untuk input data peminjaman
    void input(Peminjaman &pinjaman) {
        cout << "Masukkan jumlah pinjaman (1 juta - 200 juta): Rp ";
        cin >> pinjaman.jumlahPinjaman;

        // Nested if untuk validasi jumlah pinjaman
        if (pinjaman.jumlahPinjaman < 1000000 || pinjaman.jumlahPinjaman > 200000000) {
            cout << "Input pinjaman anda tidak bisa diproses, silahkan input (1 juta - 200 juta)\n";
            return;
        }

        cout << "Masukkan jangka waktu pinjaman:\n";
        cout << "1. 3 bulan\n";
        cout << "2. 6 bulan\n";
        cout << "3. 12 bulan\n";
        cout << "Masukkan pilihan Anda: ";
        int pilihanWaktu;
        cin >> pilihanWaktu;

        // Switch untuk menentukan jangka waktu pinjaman
        switch (pilihanWaktu) {
            case 1:
                pinjaman.jangkaWaktu = 3;
                break;
            case 2:
                pinjaman.jangkaWaktu = 6;
                break;
            case 3:
                pinjaman.jangkaWaktu = 12;
                break;
            default:
                cout << "Input jangka waktu tidak valid, silahkan input (3, 6, 12 bulan)\n";
                return;
        }
    }

    // Fungsi untuk output data peminjaman
    void output(Peminjaman pinjaman) {
        cout << fixed << setprecision(2);
        cout << "\nJumlah Pinjaman: Rp " << pinjaman.jumlahPinjaman << endl;
        cout << "Jangka Waktu Pinjaman: " << pinjaman.jangkaWaktu << " bulan" << endl;
        cout << "Bunga Pinjaman: " << pinjaman.bungaPinjaman << "%" << endl;
        cout << "Nominal Bunga: Rp " << pinjaman.nominalBunga << endl;
        cout << "Total yang harus dibayarkan: Rp " << pinjaman.totalBayar << endl;
        cout << "Angsuran per bulan: Rp " << pinjaman.angsuranPerBulan << " sebanyak " << pinjaman.jangkaWaktu << " kali angsuran " << endl;
        cout << "Ini adalah perhitungan pinjaman yang sesuai, notifikasi tagihan akan kami kirimkan, silahkan lakukan pembayaran sebelum tanggal 10 di setiap bulannya, terimakasih\n\n\n";
    }
};

// Fungsi untuk menghitung bunga berdasarkan jumlah pinjaman
float hitungBunga(float jumlahPinjaman) {
    if (jumlahPinjaman >= 1000000 && jumlahPinjaman <= 3000000) {
        return 8.0;
    } else if (jumlahPinjaman > 3000000 && jumlahPinjaman <= 10000000) {
        return 6.0;
    } else if (jumlahPinjaman > 10000000 && jumlahPinjaman <= 200000000) {
        return 5.0;
    } else {
        return 0.0;
    }
}

// Fungsi untuk menghitung bunga berdasarkan jangka waktu
float hitungBungaJangkaWaktu(int jangkaWaktu) {
    if (jangkaWaktu == 3) {
        return 3.0;
    } else if (jangkaWaktu == 6) {
        return 9.0;
    } else if (jangkaWaktu == 12) {
        return 12.0;
    } else {
        return 0.0;
    }
}

// Fungsi untuk menghitung total yang harus dibayarkan
void hitungTotalBayar(Peminjaman &pinjaman) {
    float bungaPinjaman = hitungBunga(pinjaman.jumlahPinjaman);
    float bungaJangkaWaktu = hitungBungaJangkaWaktu(pinjaman.jangkaWaktu);
    pinjaman.bungaPinjaman = bungaPinjaman + bungaJangkaWaktu;
    pinjaman.nominalBunga = pinjaman.jumlahPinjaman * pinjaman.bungaPinjaman / 100;
    pinjaman.totalBayar = pinjaman.jumlahPinjaman + pinjaman.nominalBunga;
    pinjaman.angsuranPerBulan = pinjaman.totalBayar / pinjaman.jangkaWaktu;
}

int main() {
    cout << "=========================================\n";
    cout << "NAMA       : ARIF RAFIDA RAHMAN\n";
    cout << "NIM        : 241011700826\n";
    cout << "MATA KULIAH: ALGORITMA DAN PEMROGRAMAN I\n";
    cout << "=========================================\n\n";

    char lagi;
    IO io;

    // Array untuk menyimpan riwayat pinjaman
    Peminjaman riwayatPinjaman[10];
    int jumlahRiwayat = 0;

    // Do-while loop untuk mengulang perhitungan
    do {
        Peminjaman pinjaman;
        io.input(pinjaman);
        if (pinjaman.jumlahPinjaman >= 1000000 && pinjaman.jumlahPinjaman <= 200000000 &&
            (pinjaman.jangkaWaktu == 3 || pinjaman.jangkaWaktu == 6 || pinjaman.jangkaWaktu == 12)) {
            hitungTotalBayar(pinjaman);
            io.output(pinjaman);

            // Simpan riwayat pinjaman ke array
            if (jumlahRiwayat < 10) {
                riwayatPinjaman[jumlahRiwayat++] = pinjaman;
            }
        }

        cout << "Apakah Anda ingin menghitung kembali? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    // Perulangan for untuk menampilkan riwayat pinjaman
    cout << "\nRiwayat Pinjaman:\n";
    for (int i = 0; i < jumlahRiwayat; i++) {
        io.output(riwayatPinjaman[i]);
    }

    cout << "Terimakasih telah menggunakan program perhitungan pinjaman ini.\n";

    // Tampilkan opsi untuk menutup program
    cout << "Tekan apapun untuk mengakhiri program...\n";
    cin.ignore();
    cin.get();

    return 0;
}