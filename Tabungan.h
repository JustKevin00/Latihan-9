#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <conio.h>
using namespace std;

class Tabungan
{
	public:
		struct pengguna
		{
			string mahasiswa, nim;
			int januari, februari, maret, april, mei, juni;
		};
		vector<pengguna> user;

		void peserta();
		void tampilandata();
		void ubahdata();
		void inputtabungan();
		void totaltabungan();
		void exportdata(const string& filename);
		void hapusdata();
		void menuadmin();
		void login();
		void menuawal();
		void menuuser();
		void tariktabungan(); 
};

