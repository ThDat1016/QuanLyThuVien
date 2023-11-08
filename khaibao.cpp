#include "khaibao.h"

using namespace std;
void pressAnyKey() {
    system("cls");
}
void GoTo(SHORT posX, SHORT posY) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    SetConsoleCursorPosition(hStdout, Position);
}

void printText(const string& text, bool isSelected) {
    if (isSelected) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31); // Set text color to red
        cout << "> " << text << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset text color to default (white)
    }
    else {
        cout << "  " << text << endl;
    }
}

void displayMenuAdmin(int currentOption, int totalOptions) {
    system("cls"); 

    for (int i = 1; i <= totalOptions; i++) {
        GoTo(7 * 10, (10 + i));

        switch (i) {
        case 1:
            printText("Them Sach", i == currentOption);
            break;
        case 2:
            printText("Danh Sach Cac Cuon Sach", i == currentOption);
            break;
        case 3:

            printText("Tim Kiem Theo Ten Sach", i == currentOption);
            break;
        case 4:
            printText("Ghi File", i == currentOption);
            break;
        case 5:
            printText("Danh Sach Sinh Vien", i == currentOption);
            break;
        case 6:
            printText("Muon Sach", i == currentOption);
            break;
        case 7:
            printText("Xoa Sach Muon", i == currentOption);
            break;
        case 8:
            printText("Xoa Sinh vien", i == currentOption);
            break;
        case 9:
            printText("Thoat Chuong Trinh", i == currentOption);
            break;
        }
    }
}

int menu(ListSach& listSach, ListSV& listSV,string& tenSach,string& tacGia,string& mssv, int namXb, int maSach, int& choice, int& maxChoice) {
    displayMenuAdmin(choice, maxChoice);
    char key = _getch();
    if (key == 13) {
        switch (choice) {
        case 1: {
            pressAnyKey();
            cout << "Nhap thong tin sach:" << std::endl;

            cout << "Ten sach: ";
            getline(cin,tenSach);

            cout << "Tac gia: ";
            getline(cin, tacGia);

            cout << "Nam xuat ban: ";
            cin >> namXb;
            cin.ignore();
            listSach.addSach(tenSach, tacGia, namXb);
            cout << "Sach da duoc them vao danh sach." << endl;
            _getch();
            break;
        }
        case 2:
            pressAnyKey();
            listSach.PrintSach();
            _getch();
            break;
        case 3:
        {
            pressAnyKey();
            string tenSach;
            cin.ignore(); // Loại bỏ dấu xuống dòng sau khi đọc lựa chọn.
            cout << "Nhap Ten Sach: ";
            getline(cin, tenSach);
            listSach.searchBook(tenSach);
            _getch();
            break;
        }
        case 4:
            pressAnyKey();
            listSach.saveToFile("ThongTinSach.txt");
            listSV.saveSvToFile("ThongTinSV.txt");
            _getch();
            break;
        case 5:
            pressAnyKey();
            listSV.ShowSV();
            _getch();
            break;
        case 6:
        {
            pressAnyKey();
            cout << endl << "Nhap ma so sinh vien: ";
            getline(cin, mssv);
            cin.ignore();
            listSV.Muon_Sach(mssv, listSach, listSV);
            _getch();
            break;
        }
        case 7:
        {
            pressAnyKey();
            cout << endl << "Nhap Ma So Sinh Vien: ";
            getline(cin, mssv);
            cin.ignore();
            cout << "Nhap Ma Sach De Tra: ";
            cin >> maSach;
            listSV.TraSach(listSV, listSach, mssv, maSach);
            _getch();
            break;
        }
        case 8: {
            pressAnyKey();
            cout << endl << "Nhap ma so sinh vien muon xoa: ";
            getline(cin, mssv);
            listSV.DeleteSV(mssv);
            cin.ignore();
            _getch();
            break;
        }
        case 9:
            return 0;
            pressAnyKey();
        }
    }
    else if (key == 72) { // Mũi tên lên
        if (choice > 1) {
            choice--;
        }
    }
    else if (key == 80) { // Mũi tên xuống
        if (choice < maxChoice) {
            choice++;
        }
    }
}



