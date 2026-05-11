#include <iostream>
#include <string>
using namespace std;

class user {
protected:
    static int globalId;

public:
    int id;
    string nama;
    string email;

    user(string pNama, string pEmail) {
        id = generateId();
        nama = pNama;
        email = pEmail;
    }

    static int generateId() {
        return ++globalId;
    }
};

int user::globalId = 0;

class member : public user {
public:
    bool status;

    member(string pNama, string pEmail, bool pStatus)
        : user(pNama, pEmail) {
        status = pStatus;
    }

    void showProfile() {
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : ";

        if (status == true)
            cout << "Aktif\n";
        else
            cout << "Nonaktif\n";

        cout << endl;
    }
};

class admin : public user {
public:
    admin(string pNama, string pEmail)
        : user(pNama, pEmail) {
    }

    void showAllMember(member m[], int jumlah) {
        cout << "\n===== DAFTAR MEMBER =====\n";

        for (int i = 0; i < jumlah; i++) {
            m[i].showProfile();
        }
    }

    void toggleActivationMember(member &m) {
        m.status = !m.status;
    }
};

int main() {

    member m1("Andi", "andi@gmail.com", true);
    member m2("Budi", "budi@gmail.com", false);

    member daftarMember[] = {m1, m2};

    admin a1("Admin", "admin@gmail.com");

    a1.showAllMember(daftarMember, 2);

    cout << "Mengubah status member Budi...\n\n";

    a1.toggleActivationMember(daftarMember[1]);

    a1.showAllMember(daftarMember, 2);

    return 0;
}