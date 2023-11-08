#include "khaibao.h"

int main() {
    ListSach listSach;
    ListSV listSV;
    int choice = 1;
    int maxChoice = 10; // Tổng số lựa chọn trong menu (đã sửa thành 10)
    static string tenSach, tacGia, mssv;
    static int namXuatBan, maSach;

    while (true) {
        if (menu(listSach, listSV, tenSach, tacGia, mssv, namXuatBan, maSach, choice, maxChoice) == 0) return 0;
    }

    return 0;
}
