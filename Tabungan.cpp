#include "Tabungan.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Tabungan::menuawal()
{
logulang:
	system("cls");
	int menu;
	cout << "\n=====================================================\n";
	cout << "|                                                   |" << endl;
	cout << "|                   ATMI XXPRESS                    |" << endl;
	cout << "|                                                   |" << endl;
	cout << "=====================================================" << endl;
	cout << "| 1. Login                                          |\n";
	cout << "| 2. Keluar                                         |\n";
	cout << "=====================================================" << endl;
	cout << "Pilih menu: ";
	cin >> menu;
	if (menu == 1) {
		system("cls");
		login();
		goto logulang;
	}

	else if (menu == 2) {
		system("cls");
		cout << "\nTerima kasih telah menggunakan layanan kami." << endl;
		return;
	}

	else {
		cout << "Pilihan tidak valid, silakan coba lagi." << endl;
		system("pause");
		goto logulang;
	}
}

void Tabungan::login()
{
	string username, pw;

loginulang:
	system("cls");
	cout << "----------------------------------------\n";
	cout << "                ATMI EXPRESS            \n";
	cout << "----------------------------------------\n";
	cout << "                                        \n";
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	pw.clear();

	char ch;
	while (true) {
		ch = _getch(); 

		if (ch == '\r') {
			break;
		}
		else if (ch == '\b') {
			if (!pw.empty()) {
				pw.pop_back();
				cout << "\b \b";
			}
		}
		else {
			pw += ch;
			cout << '*';
		}
	}

	if (username == "admin" && pw == "123") {
		cout << "\nLogin berhasil!\n";
		cout << "----------------------------------------\n\n";
		system("pause");
		menuadmin();
		menuawal();
	}
	else if (username == "user" && pw == "456") {
		cout << "\nLogin berhasil!\n";
		cout << "----------------------------------------\n\n";
		system("pause");
		menuuser();
		menuawal();
	}
	else {
		cout << "\n\nUsername/Password Salah, Silahkan Input Ulang\n\n";
		cout << "----------------------------------------\n\n";
		system("pause");
		goto loginulang;
	}
}

void Tabungan::menuadmin(){
	menu:
		char menus;
		system("cls");
		cout << "-----------------------------------------\n";
		cout << "|         KOPERASI SEJAHTERA JAYA       |\n";
		cout << "-----------------------------------------\n";
		cout << "|1. Tambah Peserta                      |\n";
		cout << "|2. Tampilkan Data Peserta              |\n";
		cout << "|3. Ubah Data Peserta                   |\n";
		cout << "|4. Input Tabungan (Semester)           |\n";
		cout << "|5. Total Tabungan                      |\n";
		cout << "|6. Export Data                         |\n";
		cout << "|7. Hapus data                          |\n";
		cout << "|8. Keluar                              |\n";
		cout << "-----------------------------------------\n\n";
		cout << "Pilih Menu : ";
		cin >> menus;
		if (menus == '1') { peserta(); goto menu; }
		if (menus == '2') { tampilandata(); system("pause"); goto menu; }
		if (menus == '3') { ubahdata(); goto menu; }
		if (menus == '4') { inputtabungan(); goto menu; }
		if (menus == '5') { totaltabungan(); goto menu; }
		if (menus == '6') { exportdata("Tampilan Data Koperasi.txt"); goto menu; }
		if (menus == '7') { hapusdata(); goto menu; }
		if (menus == '8') { system("cls"); cout << "\nBye Bye\n\n"; }
		else { cout << "\nEror terjadi permasalahan pada input menu, coba ulang\n\n"; system("pause"); goto menu; }
}

void Tabungan::peserta() {
	char yt;
	do {
		tampilandata(); 
		pengguna p;
		cout << "-----------------------------------------\n";
		cout << "|               Input Data              |\n";
		cout << "-----------------------------------------\n";
		cout << "\nNama : ";
		cin >> ws; getline(cin, p.mahasiswa);
		cout << "NIM : ";
		cin >> p.nim;
		p.januari = 0;
		p.februari = 0;
		p.maret = 0;
		p.april = 0;
		p.mei = 0;
		p.juni = 0;
		user.push_back(p);
		cout << "\nData berhasil ditambahkan.\n";
		cout << "\nInput Lagi(y/t) : ";
		cin >> yt;
	} while (yt == 'y' || yt == 'Y');
}

void Tabungan::tampilandata() {
	pengguna p;
	system("cls");
	cout << "-----------------------------------------------------------------------------------------------------------\n";
	cout << "|             |              |                                   TABUNGAN                                 |\n";
	cout << "|     NIM     |     NAMA     |----------------------------------------------------------------------------|\n";
	cout << "|             |              |   JANUARI  |  FEBRUARI  |    MARET   |    APRIL   |     MEI    |   JUNI    |\n";
	cout << "-----------------------------------------------------------------------------------------------------------\n";
	if (user.empty()) {
		cout << "|                                  Tidak ada data peserta yang tersedia.                                  |\n";
		cout << "-----------------------------------------------------------------------------------------------------------\n";
		return;
	}
	for (const auto& p : user) {
		cout << "| " << setw(12) << left << p.nim
			<< "| " << setw(13) << left << p.mahasiswa
			<< "| " << setw(11) << left << p.januari
			<< "| " << setw(11) << left << p.februari
			<< "| " << setw(11) << left << p.maret
			<< "| " << setw(11) << left << p.april
			<< "| " << setw(11) << left << p.mei
			<< "| " << setw(10) << left << p.juni
			<< "| \n";
	}
	cout << "-----------------------------------------------------------------------------------------------------------\n";
}

void Tabungan::ubahdata() {
	string cariNIM;
	tampilandata();
	cout << "-----------------------------------------\n";
	cout << "             Ubah Data Peserta           \n";
	cout << "-----------------------------------------\n";
	cout << "Masukkan NIM yang ingin diubah: ";
	cin >> cariNIM;

	bool ditemukan = false;
	for (auto& p : user) {
		if (p.nim == cariNIM) {
			ditemukan = true;
			cout << "\nData ditemukan. Silakan masukkan data baru:\n";
			cout << "Nama Baru : ";
			cin >> ws; getline(cin, p.mahasiswa);
			cout << "NIM Baru : ";
			cin >> p.nim;
			p.januari = 0;
			p.februari = 0;
			p.maret = 0;
			p.april = 0;
			p.mei = 0;
			p.juni = 0;
			cout << "\nData berhasil diubah.\n";
			break;
		}
	}

	if (!ditemukan) { cout << "\nData dengan NIM " << cariNIM << " tidak ditemukan.\n"; }
	system("pause");
}

void Tabungan::inputtabungan() {
	string cariNIM;
	tampilandata();
	cout << "-----------------------------------------\n";
	cout << "|                 TABUNGAN              |\n";
	cout << "-----------------------------------------\n";
	cout << "Masukkan NIM yang ingin diinput: ";
	cin >> cariNIM;
	bool ditemukan = false;
	for (auto& p : user) {
		if (p.nim == cariNIM) {
			ditemukan = true;
			cout << "\nData ditemukan. Silakan Menginput Tabungan :\n";
			cout << "Januari    : ";
			cin >> p.januari;
			cout << "Februari   : ";
			cin >> p.februari;
			cout << "Maret      : ";
			cin >> p.maret;
			cout << "April      : ";
			cin >> p.april;
			cout << "Mei        : ";
			cin >> p.mei;
			cout << "Juni       : ";
			cin >> p.juni;
			cout << "\nData berhasil Diinput.\n";
			break;
		}
	}

	if (!ditemukan) { cout << "\nData dengan NIM " << cariNIM << " tidak ditemukan.\n"; }
	system("pause");
}

void Tabungan::totaltabungan() {
	string cariNIM;
	system("cls");
	cout << "-----------------------------------------------------\n";
	cout << "|                       TABUNGAN                    |\n";
	cout << "-----------------------------------------------------\n";
	cout << "|     NIM     |     NAMA     |     TOTAL TABUNGAN   |\n";
	cout << "-----------------------------------------------------\n";
	for (const auto& p : user) {
		int ttabungan = p.januari + p.februari + p.maret + p.april + p.mei + p.juni;
		cout << "| " << setw(13) << left << p.nim
			<< "| " << setw(12) << left << p.mahasiswa
			<< "| " << setw(21) << left << ttabungan
			<< "| \n";
	}
	cout << "-----------------------------------------------------\n";
system("pause");
}


void Tabungan::exportdata(const string& filename) {
	ofstream tampilkan(filename);
	system("cls");
	tampilkan << "--------------------------------------------------------------------------------------------------------------------------------\n";
	tampilkan << "|             |              |                                   TABUNGAN                                 |                    |\n";
	tampilkan << "|     NIM     |     NAMA     |----------------------------------------------------------------------------|         TOTAL      |\n";
	tampilkan << "|             |              |   JANUARI  |  FEBRUARI  |    MARET   |    APRIL   |     MEI    |   JUNI    |                    |\n";
	tampilkan << "--------------------------------------------------------------------------------------------------------------------------------\n";
	for (const auto& p : user) {
		int ttabungan = p.januari + p.februari + p.maret + p.april + p.mei + p.juni;
		tampilkan << "| " << setw(12) << left << p.nim
			<< "| " << setw(13) << left << p.mahasiswa
			<< "| " << setw(11) << left << p.januari
			<< "| " << setw(11) << left << p.februari
			<< "| " << setw(11) << left << p.maret
			<< "| " << setw(11) << left << p.april
			<< "| " << setw(11) << left << p.mei
			<< "| " << setw(10) << left << p.juni
			<< "| " << setw(19) << left << ttabungan
			<< "| \n";
	}
	tampilkan << "--------------------------------------------------------------------------------------------------------------------------------\n";
	tampilkan.close();
	cout << "\nData berhasil diekspor ke file.\n";
	system("pause");
}

void Tabungan::hapusdata() {
	tampilandata();
	string cariNIM;
	tampilandata();
	cout << "-----------------------------------------\n";
	cout << "                Delete Data              \n";
	cout << "-----------------------------------------\n";
	cout << "Input NIM yang ingin dihapus : ";
	cin >> cariNIM;

	bool ditemukan = false;
	for (auto hapus = user.begin(); hapus != user.end(); ++hapus) {
		if (hapus->nim == cariNIM) {
			ditemukan = true;
			user.erase(hapus);
			cout << "\nData telah dihapus.\n";
			break;
		}
	}
	if (!ditemukan) { cout << "\nData dengan NIM " << cariNIM << " tidak ditemukan.\n"; }
	system("pause");
}

void Tabungan::menuuser() {
	menu:
		char menus;
		system("cls");
		cout << "-----------------------------------------\n";
		cout << "|         KOPERASI SEJAHTERA JAYA       |\n";
		cout << "-----------------------------------------\n";
		cout << "|1. Tampilkan Tabungan                  |\n";
		cout << "|2. Total Tabungan                      |\n";
		cout << "|3. Tarik Tabungan                      |\n";
		cout << "|4. Keluar                              |\n";
		cout << "-----------------------------------------\n\n";
		cout << "Pilih Menu : ";
		cin >> menus;
		if (menus == '1') { tampilandata(); system("pause"); goto menu; }
		if (menus == '2') { totaltabungan(); goto menu; }
		if (menus == '3') { tariktabungan(); goto menu; }
		if (menus == '4') { system("cls"); cout << "\nBye Bye\n\n"; }
		else { cout << "\nEror terjadi permasalahan pada input menu, coba ulang\n\n"; system("pause"); goto menu; }
}

void Tabungan::tariktabungan() {
    tampilandata();
    string cariNIM;
    cout << "-----------------------------------------\n";
    cout << "|             TARIK TABUNGAN            |\n";
    cout << "-----------------------------------------\n";
    cout << "Masukkan NIM yang ingin ditarik tabungannya: ";
    cin >> cariNIM;

    bool ditemukan = false;
    for (auto& p : user) {
        if (p.nim == cariNIM) {
            ditemukan = true;
            int totalTabungan = p.januari + p.februari + p.maret + p.april + p.mei + p.juni;
            cout << "\nTotal tabungan: " << totalTabungan << endl;
            int tarik;
            cout << "Masukkan jumlah yang ingin ditarik: ";
            cin >> tarik;

            if (tarik > totalTabungan) {
                cout << "\nJumlah yang ingin ditarik melebihi total tabungan!\n";
            } else {
                int sisaTarik = tarik;
                int* bulan[] = { &p.januari, &p.februari, &p.maret, &p.april, &p.mei, &p.juni };
                for (int i = 0; i < 6 && sisaTarik > 0; ++i) {
                    if (*bulan[i] >= sisaTarik) {
                        *bulan[i] -= sisaTarik;
                        sisaTarik = 0;
                    } else {
                        sisaTarik -= *bulan[i];
                        *bulan[i] = 0;
                    }
                }
                cout << "\nPenarikan berhasil. Sisa tabungan:\n";
                cout << "Januari: " << p.januari << "\n";
                cout << "Februari: " << p.februari << "\n";
                cout << "Maret: " << p.maret << "\n";
                cout << "April: " << p.april << "\n";
                cout << "Mei: " << p.mei << "\n";
                cout << "Juni: " << p.juni << "\n";
            }
            break;
        }
    }
    if (!ditemukan) {
        cout << "\nData dengan NIM " << cariNIM << " tidak ditemukan.\n";
    }
    system("pause");
}