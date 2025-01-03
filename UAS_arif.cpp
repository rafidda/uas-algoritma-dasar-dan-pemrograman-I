#include <iostream>
#include <iomanip>
using namespace std;

struct Peminjaman {
    float jumlahPinjaman;
    int jangkaWaktu;
    float bungaPinjaman;
    float totalBayar;
    float angsuranPerBulan;
};

struct IO {
    void input(Peminjaman &pinjaman) {
        cout << "Masukkan jumlah pinjaman (1 juta - 200 juta): Rp ";
        cin >> pinjaman.jumlahPinjaman;

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

    void output(Peminjaman pinjaman) {
        cout << fixed << setprecision(2);
        cout << "\nJumlah Pinjaman: Rp " << pinjaman.jumlahPinjaman << endl;
        cout << "Bunga Pinjaman: " << pinjaman.bungaPinjaman << "%" << endl;
        cout << "Total yang harus dibayarkan: Rp " << pinjaman.totalBayar << endl;
        cout << "Angsuran per bulan: Rp " << pinjaman.angsuranPerBulan << endl;
        cout << "Silahkan bayar sebelum tanggal 10 di outlet kami\n";
    }
};

float hitungBunga(float jumlahPinjaman) {
    if (jumlahPinjaman >= 1000000 && jumlahPinjaman <= 3000000) {
        return 8.0;
    } else if (jumlahPinjaman > 3000000 && jumlahPinjaman <= 10000000) {
        return 6.0;
    } else if (jumlahPinjaman > 10000000 && jumlahPinjaman <= 200000000) {
        return 4.0;
    } else {
        return 0.0;
    }
}

float hitungBungaJangkaWaktu(int jangkaWaktu) {
    if (jangkaWaktu == 3) {
        return 3.0;
    } else if (jangkaWaktu == 6) {
        return 7.0;
    } else if (jangkaWaktu == 12) {
        return 10.0;
    } else {
        return 0.0;
    }
}

void hitungTotalBayar(Peminjaman &pinjaman) {
    float bungaPinjaman = hitungBunga(pinjaman.jumlahPinjaman);
    float bungaJangkaWaktu = hitungBungaJangkaWaktu(pinjaman.jangkaWaktu);
    pinjaman.bungaPinjaman = bungaPinjaman + bungaJangkaWaktu;
    pinjaman.totalBayar = pinjaman.jumlahPinjaman + (pinjaman.jumlahPinjaman * pinjaman.bungaPinjaman / 100);
    pinjaman.angsuranPerBulan = pinjaman.totalBayar / pinjaman.jangkaWaktu;
}

int main() {
    Peminjaman pinjaman;
    IO io;

    io.input(pinjaman);
    if (pinjaman.jumlahPinjaman >= 1000000 && pinjaman.jumlahPinjaman <= 200000000 &&
        (pinjaman.jangkaWaktu == 3 || pinjaman.jangkaWaktu == 6 || pinjaman.jangkaWaktu == 12)) {
        hitungTotalBayar(pinjaman);
        io.output(pinjaman);
    }

    return 0;
}
