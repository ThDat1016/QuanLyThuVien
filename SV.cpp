#include "khaibao.h"

void ListSV::addSv(const string& tenSV, const string& lop, const string& mssv) {
    SV sv(tenSV, lop, mssv);

    NodeSv* newNode = new NodeSv(sv);

    if (!father) {
        father = newNode;
        tailSv = newNode;
    }
    else {
        tailSv->next = newNode;
        tailSv = newNode;
    }
}

void ListSV::DeleteSV(const string& mssv) {
    NodeSv* crr = father;
    NodeSv* prev = nullptr;

    if (crr == nullptr) {
        cout << endl << "Danh sach trong!";
        return;
    }
    while (crr != nullptr && crr->ThongTinSV.GetMSSV() != mssv) {
        prev = crr;
        crr = crr->next;
    }

    if (crr == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
    }
    else {
        if (crr->sizeUse == 0) {
            prev->next = prev->next->next;
            delete crr;
            cout << "Xoa sinh vien thanh cong!" << endl;
        }
        else {
            cout << "Sinh vien chua tra het sach, khong the xoa!" << endl;
        }
    }
}

void ListSV::ShowSV() {
    NodeSv* crr = father;

    if (crr == nullptr) {
        cout << endl << "Danh sach trong!";
        return;
    }
    else {
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "| " << setw(6) << left << "MSSV" << " | " << setw(30) << left << "Ten sinh vien" << " | " << setw(20) << left << "Lop" << " | " << setw(20) << left << "So Luong Sach Muon" << " | " <<endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;

        while (crr != nullptr) {
            cout << "| " << setw(6) << left << crr->ThongTinSV.GetMSSV() << " | " << setw(30) << left << crr->ThongTinSV.GetTenSv() << " | " << setw(20) << left << crr->ThongTinSV.GetLop() << " | " << setw(20) << left << crr->sizeUse << " | " <<endl;
            crr = crr->next;
        }

        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
} 

void DanhSachSachMuon(NodeSv* sv) {
    cout << "Ten\t\tTacGia\t\tNam Xuat Ban\t\tMa Sach" << endl;
    for (int i = 0; i < sv->sizeUse; i++) {
        cout << sv->thong_tin_sm[i].ten << "\t\t" << sv->thong_tin_sm[i].tacgia << "\t\t" << sv->thong_tin_sm[i].nxb << "\t\t" << sv->thong_tin_sm[i].id << endl;
    }
}
void ListSV::quickSort(NodeSv* low, NodeSv* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        NodeSv* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->next, high);
    }
}

NodeSv* ListSV::partition(NodeSv* low, NodeSv* high) {
    string pivot = high->ThongTinSV.GetTenSv();
    NodeSv* i = low;
    for (NodeSv* j = low; j != high; j = j->next) {
        if (j->ThongTinSV.GetTenSv() < pivot) {
            swapSV(i, j);
            i = i->next;
        }
    }
    swapSV(i, high);
    return i;
}

void ListSV::swapSV(NodeSv* a, NodeSv* b) {
    SV temp = a->ThongTinSV;
    a->ThongTinSV = b->ThongTinSV;
    b->ThongTinSV = temp;
}

NodeSv* ListSV::getTail(NodeSv* current) {
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void ListSV::SortByName() {
    NodeSv* tail = getTail(father);
    quickSort(father, tail);
    tailSv = tail;
}