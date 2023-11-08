#include "khaibao.h"

void ListSach::saveToFile(const string& fileName) {
	ofstream outFile(fileName); // Mở tệp tin để ghi thông tin

	if (!outFile.is_open()) {
		cerr << "Khong the mo file " << fileName << " de ghi." << endl;
		return; // Thoát nếu không thể mở tệp tin
	}

	Node* crr = this->GetHead();
	outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
	outFile << "| " << setw(6) << left << "ID" << " | " << setw(30) << left << "Ten sach" << " | " << setw(20) << left << "Tac gia" << " | "
		<< setw(15) << left << "Nam xuat ban" << " | " << setw(10) << left << "So Luong" << " |" << endl;
	outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;

	while (crr != nullptr) {
		outFile << "| " << setw(5) << left << crr->ThongTinSach.ID << " | "
			 << setw(30) << left  << crr->ThongTinSach.TenSach << " | "
			<< setw(20) << left  << crr->ThongTinSach.TacGia<<  " | "
			<< setw(15) << left << crr->ThongTinSach.NamXuatBan<<  " | "
			<< setw(10) << left <<crr->ThongTinSach.SoLuong<<  " |" << endl;
		outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
		crr = crr->next;
	}

	outFile.close(); // Đóng tệp tin sau khi ghi xong
	cout << "Thong tin sach da duoc luu vao file! " << fileName << endl;
}

void ListSV::saveSvToFile(const string& fileName) {
	ofstream outFile(fileName); // Mở tệp tin để ghi thông tin

	if (!outFile.is_open()) {
		cerr << "Khong the mo file " << fileName << " de ghi." << endl;
		return; // Thoát nếu không thể mở tệp tin
	}

	NodeSv* crr = this->GetFather();
	outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
	outFile << "| " << setw(6) << left << "MSSV" << " | " << setw(30) << left << "Ho Va Ten" << " | " << setw(20) << left << "Lop" << " | " << setw(10) << left << "So Luong Sach Da Muon" << " |" << endl;
	outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;

	while (crr != nullptr) {
		outFile << "| " << setw(5) << left << crr->ThongTinSV.GetMSSV() << " | "
			<< setw(30) << left << crr->ThongTinSV.GetTenSv() << " | "
			<< setw(20) << left << crr->ThongTinSV.GetLop() << " | "
			<< setw(10) << left << crr->sizeUse << " | " << endl;
			
		outFile << "-------------------------------------------------------------------------------------------------------------------" << endl;
		crr = crr->next;
	}

	outFile.close(); // Đóng tệp tin sau khi ghi xong
	cout << "Thong tin sach da duoc luu vao file! " << fileName << endl;
}