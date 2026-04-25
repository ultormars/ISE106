#include <iostream>
#include <windows.h>
#include "module5_tree.h"
#include "module6_hash.h"

using namespace std;

int main() {
	
	system("color 8A")
	
    // Class obj.
    ;TreeModule myTree;
    HashModule myHash;

    // Örnek 3 kayýt
    Record r1 = {10, "Proje_Sunumu", "Sunum", 1024, "2026-04-25", "yuksek", "aktif", 4.5, ""};
    Record r2 = {5, "Ders_Notlari", "Belge", 512, "2026-04-24", "orta", "aktif", 4.0, ""};
    Record r3 = {15, "Yedek_Dosya", "Yedek", 2048, "2026-04-23", "dusuk", "aktif", 3.5, ""};
    
    // --- TREE MODÜLÜ ---
    myTree.insert(r1);
    myTree.insert(r2);
    myTree.insert(r3);
    
    cout << "--- Agactaki Kayitlar (Sirali) ---" << endl;
    myTree.printTree();
    
    // ---HASH MODÜLÜ---
    myHash.insert(r1);
    myHash.insert(r2);
    myHash.insert(r3);
    
    cout << "\nModuller basariyla baglandi ve calisiyor!" << endl;
    
    // ---MENÜ(testing)---
    int secim;
    while (true) {
        cout << "\n--- BULUT DEPOLAMA YONETIM SISTEMI ---" << endl;
        cout << "1. Ana Kayit Yonetimi" << endl;
        cout << "5. Tree Analizi (Modul 5)" << endl;
        cout << "6. Hash Analizi (Modul 6)" << endl;
        cout << "0. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 0) break;

        switch (secim) {
            case 1: 
                cout << "Ana kayit yonetimi modulu burada olacak." << endl; 
                break;
            case 5: 
                cout << "\n--- Agactaki Kayitlar ---" << endl;
                myTree.printTree(); 
                system("pause"); // Tuþa basana kadar bekletme
                system("cls"); // Ekran temizlik
                break;
            case 6: 
                cout << "Hash analizi: Kayitlar zaten yuklendi." << endl; 
                break;
            default: 
            	cout << "" << endl;
                cout << "-------------------------" << endl;
				cout << "Bu modul henuz eklenmedi!" << endl;
				cout << "-------------------------" << endl;
				cout << "" << endl;
        }
    }
    
    return 0;
}
