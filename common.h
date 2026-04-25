#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>

using namespace std;

// Modül 1: Ana kayıt yapısı
struct Record {
    int id;
    string title;          // Dosya adı / başlık
    string category;       // belge, görsel, video, yedek, log vb.
    double sizeKB;         // KB cinsinden boyut
    string createdDate;    // YYYY-MM-DD
    string priority;       // dusuk / orta / yuksek
    string status;         // aktif / islemde / arsiv
    double averageScore;   // 0.0 - 5.0 arası değerlendirilebilir
    string criticalNote;   // boş olabilir
};

// Modül 2: Operasyon günlüğü
struct LogEntry {
    string operationType;  // Ekle / Sil / Guncelle / Dequeue
    int recordID;
    string dateTime;       // YYYY-MM-DD HH:MM
    string oldValue;
    string newValue;
};

// Modül 3: Undo işlemleri
struct UndoAction {
    string operationType;  // Ekle / Sil / Guncelle / Dequeue
    Record beforeState;
    Record afterState;
};

// Modül 4: Talep kuyruğu
struct Request {
    int requestID;
    string title;          // yüklenecek dosya adı
    string category;
    double sizeKB;
    string priority;       // dusuk / orta / yuksek
    string requestTime;    // YYYY-MM-DD HH:MM
};

// Modül 8: Performans kayıtları
struct PerformanceEntry {
    string moduleName;
    string operationName;
    double durationMs;
};

// Ortak örnek veri üretim fonksiyonları
vector<Record> getSampleRecords();
vector<Request> getSampleRequests();

#endif
