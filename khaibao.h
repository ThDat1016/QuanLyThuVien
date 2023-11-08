#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <functional>
#include<random>
#include<set>
#include<Windows.h>
#include<conio.h>
// Định nghĩa màu sắc cho chữ (đỏ)
#define RED_TEXT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

// Đặt lại màu sắc chữ về mặc định
#define RESET_TEXT SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

using namespace std;


class Sach {
public:
	string TenSach, TacGia, TinhTrang, SinhVienMuon;
	int NamXuatBan, SoLuong, ID;
	Sach() {};
	Sach(const string& TenSach, const string& TacGia, int NamXuatBan) {
		this->NamXuatBan = NamXuatBan;
		SoLuong = 0;
		this->TacGia = TacGia;
		this->TenSach = TenSach;
		ID = randomId();
		SinhVienMuon = "";// neu co sv muon thi gan mssv vao bien nay, tra sach thi quay ve = 0
		TinhTrang = "0";
	}
	int randomId() const {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(100000, 999999);
		return dis(gen);
	}
};
class Node {
public:
	Sach ThongTinSach;
	Node* next;
	Node(Sach& ThongTinSach) : ThongTinSach(ThongTinSach), next(nullptr) {}
};
class ListSach {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
public:
	void addSach(const string& TenSach, const string& TacGia, int NamXuatBan);
	Node* GetHead() const {
		return head;
	}
	void SetHead(Node* crr) {
		head = crr;
	}

	void PrintSachTQ();
	void PrintSach();
	void searchBook(const string& TenSach);
	void GetSachID(const string& TenSach, const string& TacGia, int NamXuatBan);
	void deleteBook(const string& id);
	void saveToFile(const string& filename);
	void SoLuong();

};

class NodeSv;
class SV {
private:
	string MSSV;
	string TenSv, Lop;
public:
	SV(const string& TenSv, const string& Lop, const string& MSSV) {
		this->Lop = Lop;
		this->MSSV = MSSV;
		this->TenSv = TenSv;
	}
	string GetMSSV() const {
		return MSSV;
	}
	void SetMSSV(const string& newMSSV) { 
		MSSV = newMSSV;
	}
	string GetTenSv() const {
		return TenSv;
	}
	void SetTenSv(const string& ten) {
		TenSv = ten;
	}
	string GetLop() const {
		return Lop;
	}
	void SetLop(const string& lop){
		Lop = lop;
	}
};
struct TTSach {
	string ten,tacgia;
	int nxb, id;
};

class NodeSv {
public:
    SV ThongTinSV;
	TTSach* thong_tin_sm;
	int size, sizeUse;
    NodeSv* next;
	NodeSv(SV& ThongTinSV) : ThongTinSV(ThongTinSV), thong_tin_sm(nullptr), next(nullptr), size(20), sizeUse(0) { thong_tin_sm = new TTSach[20]; }
	~NodeSv() { delete []thong_tin_sm; }
};

class ListSV {
private:
	NodeSv* father;
	NodeSv* tailSv;
public:
	ListSV() { father = tailSv = nullptr; }
	NodeSv* GetFather() {
		return father;
	}
	void SetFaTher(NodeSv* head) {
		father = head;
	}
	void addSv(const string& tenSV, const string& lop, const string& mssv);
	void DeleteSV(const string& mssv);
	void ShowSV();
	void swapSV(NodeSv* a, NodeSv* b);
	NodeSv* partition(NodeSv* low, NodeSv* high);
	void quickSort(NodeSv* low, NodeSv* high);
	void saveSvToFile(const string& fileName);
	void SortByName();
	NodeSv* getTail(NodeSv* current);
	void addSM(NodeSv* sv, ListSach& bookList, const string& ten, const string& tacgia, int nxb);
	void Muon_Sach(const string& mssv, ListSach& listSach, ListSV& list);
	void TraSach(ListSV& listSv, ListSach& bookList, const string& mssv, int maSach);
};

void pressAnyKey();
void saveToFile(const string & fileName); 
void printRedText(const std::string& text);
void highlightOption(int currentOption, int totalOptions);
void displayMenuAdmin(int currentOption, int totalOptions);

int menu(ListSach& listSach, ListSV& listSV, string& tenSach, string& tacGia, string& mssv, int namXb, int maSach, int& choice, int& maxChoice);
void GoTo(SHORT posX, SHORT posY);
void DanhSachSachMuon(NodeSv* sv);