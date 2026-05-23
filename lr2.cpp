#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

// ==================== ПУБЛИЧНЫЙ КЛАСС ====================
class AbiturientPublic {
private:
    static int count;
public:
    string lastName;
    string firstName;
    string patronymic;
    string address;
    int mathScore;
    int rusScore;
    int infScore;

    AbiturientPublic() : lastName(""), firstName(""), patronymic(""), address(""),
        mathScore(0), rusScore(0), infScore(0) {
        count++;
    }
    AbiturientPublic(string ln, string fn, string pn, string addr,
        int math, int rus, int inf) :
        lastName(ln), firstName(fn), patronymic(pn), address(addr),
        mathScore(math), rusScore(rus), infScore(inf) {
        count++;
    }
    AbiturientPublic(const AbiturientPublic& other) :
        lastName(other.lastName), firstName(other.firstName),
        patronymic(other.patronymic), address(other.address),
        mathScore(other.mathScore), rusScore(other.rusScore),
        infScore(other.infScore) {
        count++;
    }
    ~AbiturientPublic() { count--; }
    static int getCount() { return count; }
    int sum() const { return mathScore + rusScore + infScore; }
    void show() const {
        cout << lastName << " " << firstName << " " << patronymic
            << ", адрес: " << address
            << ", баллы: мат=" << mathScore << ", рус=" << rusScore << ", инф=" << infScore
            << ", сумма=" << sum() << endl;
    }
};
int AbiturientPublic::count = 0;

// ==================== ПРИВАТНЫЙ КЛАСС ====================
class AbiturientPrivate {
private:
    static int count;
    string lastName;
    string firstName;
    string patronymic;
    string address;
    int mathScore;
    int rusScore;
    int infScore;
public:
    AbiturientPrivate() : lastName(""), firstName(""), patronymic(""), address(""),
        mathScore(0), rusScore(0), infScore(0) {
        count++;
    }
    AbiturientPrivate(string ln, string fn, string pn, string addr,
        int math, int rus, int inf) :
        lastName(ln), firstName(fn), patronymic(pn), address(addr),
        mathScore(math), rusScore(rus), infScore(inf) {
        count++;
    }
    AbiturientPrivate(const AbiturientPrivate& other) :
        lastName(other.lastName), firstName(other.firstName),
        patronymic(other.patronymic), address(other.address),
        mathScore(other.mathScore), rusScore(other.rusScore),
        infScore(other.infScore) {
        count++;
    }
    ~AbiturientPrivate() { count--; }
    static int getCount() { return count; }

    void setLastName(string val) { lastName = val; }
    void setFirstName(string val) { firstName = val; }
    void setPatronymic(string val) { patronymic = val; }
    void setAddress(string val) { address = val; }
    void setMathScore(int val) { mathScore = val; }
    void setRusScore(int val) { rusScore = val; }
    void setInfScore(int val) { infScore = val; }

    string getLastName()   const { return lastName; }
    string getFirstName()  const { return firstName; }
    string getPatronymic() const { return patronymic; }
    string getAddress()    const { return address; }
    int getMathScore()     const { return mathScore; }
    int getRusScore()      const { return rusScore; }
    int getInfScore()      const { return infScore; }

    int sum() const { return mathScore + rusScore + infScore; }
    void show() const {
        cout << getLastName() << " " << getFirstName() << " " << getPatronymic()
            << ", адрес: " << getAddress()
            << ", баллы: мат=" << getMathScore() << ", рус=" << getRusScore()
            << ", инф=" << getInfScore()
            << ", сумма=" << sum() << endl;
    }
};
int AbiturientPrivate::count = 0;

// ==================== modify функции ====================
void modify_object(AbiturientPublic& x, int newMath, int newRus, int newInf) {
    x.mathScore = newMath;
    x.rusScore = newRus;
    x.infScore = newInf;
}
void try_to_modify_object(AbiturientPublic x, int newMath, int newRus, int newInf) {
    x.mathScore = newMath;
    x.rusScore = newRus;
    x.infScore = newInf;
    x.show();
}
void modify_object(AbiturientPrivate& x, int newMath, int newRus, int newInf) {
    x.setMathScore(newMath);
    x.setRusScore(newRus);
    x.setInfScore(newInf);
}
void try_to_modify_object(AbiturientPrivate x, int newMath, int newRus, int newInf) {
    x.setMathScore(newMath);
    x.setRusScore(newRus);
    x.setInfScore(newInf);
    x.show();
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================
int main() {
    setlocale(LC_ALL,"");
    // Часть 1: конструкторы и счётчик
    cout << " PART 1: CONSTRUCTORS " << endl;
    AbiturientPublic* a = new AbiturientPublic();                                    // по умолчанию
    AbiturientPublic* b = new AbiturientPublic("Иванов", "Иван", "Иванович", "Москва", 85, 78, 92);
    AbiturientPublic* c = new AbiturientPublic(*b);                                 // копия b
    AbiturientPublic* d = new AbiturientPublic("Петров", "Петр", "Петрович", "СПб", 70, 65, 88);
    AbiturientPublic* e = new AbiturientPublic(*d);                                 // копия d
    cout << "Count Public: " << AbiturientPublic::getCount() << endl;

    AbiturientPrivate* pr1 = new AbiturientPrivate();                               // по умолчанию
    AbiturientPrivate* pr2 = new AbiturientPrivate("Сидоров", "Сидор", "Сидорович", "Казань", 70, 65, 88);
    AbiturientPrivate* pr3 = new AbiturientPrivate(*pr2);                           // копия pr2
    cout << "Count Private: " << AbiturientPrivate::getCount() << endl;

    // Часть 2: modify функции
    cout << "\n PART 2: MODIFY FUNCTIONS " << endl;
    AbiturientPublic* testPub = new AbiturientPublic("Тестов", "Тест", "Тестович", "Город", 50, 60, 70);
    cout << "Original Public: "; testPub->show();
    try_to_modify_object(*testPub, 100, 100, 100);
    cout << "After try_to_modify_object (original unchanged): "; testPub->show();
    modify_object(*testPub, 90, 85, 95);
    cout << "After modify_object (original changed): "; testPub->show();

    AbiturientPrivate* testPriv = new AbiturientPrivate("Приват", "Прив", "Привович", "Город", 55, 65, 75);
    cout << "\nOriginal Private: "; testPriv->show();
    try_to_modify_object(*testPriv, 99, 99, 99);
    cout << "After try_to_modify_object (original unchanged): "; testPriv->show();
    modify_object(*testPriv, 88, 77, 66);
    cout << "After modify_object (original changed): "; testPriv->show();

    // Часть 3: файл и массивы
    cout << "\n PART 3: FILE AND ARRAY " << endl;
    ifstream f("abiturients.txt");
    if (!f.is_open()) {
        ofstream f2("abiturients.txt");
        f2 << "Иванов,Иван,Иванович,Москва,85,78,92\n"
            << "Петров,Петр,Петрович,СПб,45,60,30\n"
            << "Сидорова,Анна,Сергеевна,Казань,70,65,88\n"
            << "Козлов,Дмитрий,Алексеевич,Новосибирск,39,55,70\n"
            << "Смирнова,Елена,Владимировна,Екатеринбург,95,90,100\n"
            << "Васильев,Алексей,Андреевич,НижнийНовгород,50,42,35\n"
            << "Кузнецова,Мария,Петровна,Ростов,88,79,91\n"
            << "Новиков,Артем,Игоревич,Самара,60,55,48\n";
        f2.close();
        f.open("abiturients.txt");
    }

    vector<AbiturientPublic*> pubArray;
    vector<AbiturientPrivate*> privArray;
    string line;
    while (getline(f, line)) {
        int p1 = line.find(',');
        int p2 = line.find(',', p1 + 1);
        int p3 = line.find(',', p2 + 1);
        int p4 = line.find(',', p3 + 1);
        int p5 = line.find(',', p4 + 1);
        int p6 = line.find(',', p5 + 1);

        string ln = line.substr(0, p1);
        string fn = line.substr(p1 + 1, p2 - p1 - 1);
        string pn = line.substr(p2 + 1, p3 - p2 - 1);
        string addr = line.substr(p3 + 1, p4 - p3 - 1);
        int math = atoi(line.substr(p4 + 1, p5 - p4 - 1).c_str());
        int rus = atoi(line.substr(p5 + 1, p6 - p5 - 1).c_str());
        int inf = atoi(line.substr(p6 + 1).c_str());

        pubArray.push_back(new AbiturientPublic(ln, fn, pn, addr, math, rus, inf));
        privArray.push_back(new AbiturientPrivate(ln, fn, pn, addr, math, rus, inf));
    }
    f.close();

    cout << "Loaded public: " << pubArray.size() << endl;
    cout << "Public count after loading: " << AbiturientPublic::getCount() << endl;
    cout << "Loaded private: " << privArray.size() << endl;
    cout << "Private count after loading: " << AbiturientPrivate::getCount() << endl;

    // Ввод критериев
    int minMath, minRus, minInf, requiredSum;
    cout << "\npublic" << endl;
    cout << "Min math score: "; cin >> minMath;
    cout << "Min russian score: "; cin >> minRus;
    cout << "Min informatics score: "; cin >> minInf;
    cout << "Required sum: "; cin >> requiredSum;

    // ---- ВЫВОД ДЛЯ PUBLIC (All: включает конструкторские объекты) ----
    cout << "\n========== PUBLIC ==========" << endl;
    cout << "\nAll:" << endl;
    // Сначала выводим объекты, созданные в PART 1
    cout << "--- Objects from constructors (PART 1) ---" << endl;
    a->show();  // по умолчанию (пустой)
    b->show();  // Иванов
    c->show();  // копия Иванова
    d->show();  // Петров
    e->show();  // копия Петрова
    // Затем объекты из файла
    cout << "--- Objects from file ---" << endl;
    for (auto* p : pubArray) p->show();

    // Фильтрация для public
    cout << "\na) Scores below threshold:" << endl;
    for (auto* p : pubArray)
        if (p->mathScore < minMath || p->rusScore < minRus || p->infScore < minInf)
            p->show();

    cout << "\nb) Sum >= " << requiredSum << ":" << endl;
    for (auto* p : pubArray)
        if (p->sum() >= requiredSum) p->show();

    cout << "\nc) Top 5 by sum (from file only):" << endl;
    vector<AbiturientPublic*> sortedPub = pubArray;
    sort(sortedPub.begin(), sortedPub.end(),
        [](AbiturientPublic* a, AbiturientPublic* b) { return a->sum() > b->sum(); });
    int cnt = min(5, (int)sortedPub.size());
    for (int i = 0; i < cnt; i++)
        cout << i + 1 << ". ", sortedPub[i]->show();

    // ---- ВЫВОД ДЛЯ PRIVATE (All: включает конструкторские объекты) ----
    cout << "\n========== PRIVATE ==========" << endl;
    cout << "\nAll:" << endl;
    cout << "--- Objects from constructors (PART 1) ---" << endl;
    pr1->show();
    pr2->show();
    pr3->show();
    cout << "--- Objects from file ---" << endl;
    for (auto* p : privArray) p->show();

    // Фильтрация для private
    cout << "\na) Scores below threshold:" << endl;
    for (auto* p : privArray)
        if (p->getMathScore() < minMath || p->getRusScore() < minRus || p->getInfScore() < minInf)
            p->show();

    cout << "\nb) Sum >= " << requiredSum << ":" << endl;
    for (auto* p : privArray)
        if (p->sum() >= requiredSum) p->show();

    cout << "\nc) Top 5 by sum (from file only):" << endl;
    vector<AbiturientPrivate*> sortedPriv = privArray;
    sort(sortedPriv.begin(), sortedPriv.end(),
        [](AbiturientPrivate* a, AbiturientPrivate* b) { return a->sum() > b->sum(); });
    cnt = min(5, (int)sortedPriv.size());
    for (int i = 0; i < cnt; i++)
        cout << i + 1 << ". ", sortedPriv[i]->show();

    // Часть 4: очистка памяти
    cout << "\n PART 4: CLEANUP " << endl;
    for (auto* p : pubArray) delete p;
    for (auto* p : privArray) delete p;
    delete testPub;
    delete testPriv;
    delete d; delete e; delete a; delete b; delete c;
    delete pr1; delete pr2; delete pr3;

    cout << "Final Public count: " << AbiturientPublic::getCount() << endl;
    cout << "Final Private count: " << AbiturientPrivate::getCount() << endl;

    return 0;
}