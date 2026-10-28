#include "Singlylist.h"

void createList(List &L) {
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = first(L);
    while (P != Nil) {
        cout << info(P) << " ";
        P = next(P);
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    next(P) = first(L);
    first(L) = P;
}