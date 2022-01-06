#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include "windows.h"

class Hasta
{
private:
    // login for hasta user
    std::string hastaIsmi;
    long long hastaTC;
    bool sigorta;
    std::string randevuSaati;
    std::string randevuTarihi;
    long long telefon;
    int yas;
    std::string bolum;
    int ucret;
    std::vector<long long> medHastalar;
    std::vector<std::string> randevular;
    std::string recete;
public:
    Hasta()
    {
        this->hastaIsmi = "none";
        this->hastaTC = 1;
        this->sigorta = false;
        this->randevuSaati = "none";
        this->randevuTarihi = "none";
        this->telefon = 1;
        this->yas = 1;
        this->bolum = "none";
        this->ucret = 0;
        this->recete = "Henuz Yazilmamis";
    }
    Hasta(std::string hastaIsmi,long long hastaTC,bool sigorta,std::string randevuSaati,std::string randevuTarihi,long long telefon,int yas,std::string bolum,int ucret,std::string recete)
    {
       this->hastaIsmi = hastaIsmi;
       this->hastaTC = hastaTC;
       this->sigorta = sigorta;
       this->randevuSaati = randevuSaati;
       this->randevuTarihi = randevuTarihi;
       this->telefon = telefon;
       this->yas = yas;
       this->bolum = bolum;
       this->ucret = ucret;
       this->recete = recete;
    }
    ~Hasta()
    {
        std::cout << "hasta desct\n";
    }
    //getters
    inline const long long& getHastaTC() const { return this->hastaTC; }
    inline const std::string& getHastaIsmi() const { return this->hastaIsmi; }
    inline const bool& getSigorta() const { return this->sigorta; }
    inline const std::string& getRandevuSaati() const { return this-> randevuSaati; }
    inline const std::string& getRandevuTarihi() const { return this-> randevuTarihi; }
    inline const long long& getTelefon() const { return this-> telefon; }
    inline const int& getYas() const { return this-> yas; }
    inline const std::string& getBolum() const { return this-> bolum; }
    inline const std::string& getRecete() const { return this-> recete; }
    inline const int& getUcret() const { return this-> ucret; }
    inline const std::vector<long long>& getMedHastalar() const { return this-> medHastalar; }
    inline const std::vector<std::string>& getRandevular() const { return this-> randevular; }
    //setters
    inline void setHastaTC(const long long& hastaTC) { this->hastaTC = hastaTC; }
    inline void setHastaIsmi(const std::string& hastaIsmi) { this->hastaIsmi = hastaIsmi; }
    inline void setSigorta(const bool& sigorta) { this->sigorta = sigorta; }
    inline void setRandevuSaati(const std::string& randevuSaati) { this->randevuSaati = randevuSaati; }
    inline void setRandevuTarihi(const std::string& randevuTarihi) { this->randevuTarihi = randevuTarihi; }
    inline void setTelefon(const long long& telefon) { this->telefon = telefon; }
    inline void setYas(const int& yas) { this->yas = yas; }
    inline void setBolum(const std::string& bolum) { this->bolum = bolum; }
    inline void setRecete(const std::string& recete) { this->recete = recete; }
    inline void setUcret(const int& ucret) { this->ucret = ucret; }
    // hasta yapilandirmasi (bloklandirma)
    const std::string blok() const
    {
        std::string sonBlok = "";
        sonBlok = std::string(" | Hasta TC: ") + std::to_string(this->hastaTC) + " | \n"
                + " | Hasta Ismi: " + this->hastaIsmi + "\n"
                + " | Hasta Sigorta: " + std::to_string(this->sigorta) + "\n"
                + " | Hasta Telno: " + "+90" + std::to_string(this->telefon) + "\n"
                + " | Hasta Yas: " + std::to_string(this->yas) + "\n"
                + " | Randevu Alinan Bolum: " + this->bolum + "\n"
                + " | Hasta Randevu Saati: " + this->randevuSaati + "\n"
                + " | Hasta Randevu Tarihi: " + this->randevuTarihi + "\n"
                + " | Randevu Ucreti: " + std::to_string(this->ucret) + "$" + "\n"
                + "---------------------------\n";
        return sonBlok;
    }
    // functions
    void randevuAl (long long hastaTC,std::string randevuSaati,std::string randevuTarihi,std::string bolum)
    {
        std::string randevuString = "";
        std::string bolumler[3] = {"radyoloji","onkoloji","pediatri"};
            if(bolum == bolumler[0] || bolum == bolumler[1] || bolum == bolumler[2])
            {
                std::cout << "Bolum olarak " << bolum << " secildi.\n";
            }
            else
            {
                bolum = "Invalid";
            }
        randevuString = std::string("Randevu Sahibi: ") + std::to_string(hastaTC) + " | Saat: " + randevuSaati + " | Tarih: " + randevuTarihi + " | Bolum: " + bolum;
        std::cout << bolum << " randevunuz saat: " << randevuSaati << " | " << randevuTarihi << " tarihine belirlenmistir.\n";
        randevular.push_back(randevuString);

    }
    void randevuList ()
    {
        for(size_t i = 0; i < randevular.size(); i++)
        {
            std::cout << "Randevu No: " << i+1 << ". [ " << randevular[i] << " ]"<< std::endl;
        }
    }
    void addHasta (long long hastaTC)
    {
        medHastalar.push_back(hastaTC);
    }
    void hastaList ()
    {
        for(size_t i = 0; i < medHastalar.size(); i++)
        {
            std::cout << "Hasta No: " << i+1 << ". [ " << medHastalar[i] << " ]"<< std::endl;
        }
    }


};

class User: public Hasta
{
private:
    // login for user
    std::string login;
    std::string pass;
public:
    User()
    {
        this->login = "user1";
        this->pass = "toor";
    }
    ~User()
    {
        std::cout << "user desct\n";
    }
    bool loginSystemUser (std::string login,std::string pass)
    {
        if (login == "user1" && pass == "toor")
        {
            std::cout << "User olarak erisim saglandi!\n";
            return true;
        }
        else { std::cout << "Erisim reddedildi!\n"; return false; }
    }
    void createHasta (std::string hasta_Ad,long long hasta_TC,bool hasta_Sigorta,std::string randevu_Saati,std::string randevu_Tarihi,long long telefon_no,int hasta_Yas,std::string hastane_Bolum,int islem_Ucret)
    {
        setHastaTC(hasta_TC);
        setHastaIsmi(hasta_Ad);
        setSigorta(hasta_Sigorta);
        setRandevuSaati(randevu_Saati);
        setTelefon(telefon_no);
        setYas(hasta_Yas);
        setBolum(hastane_Bolum);
        addHasta(hasta_TC);
        if (hasta_Sigorta == true)
        {
            setUcret(0);
        }
        else
        {
            setUcret(islem_Ucret);
        }

        std::ofstream myfile (std::to_string(hasta_TC) + ".txt");
        if(myfile.is_open())
        {
            myfile << blok();
            myfile.close();
        }
        else std::cout << "Error!\n";
        std::cout << "Hasta Dosyasi acildi!\n";

    }
    void readHasta (long long tc_kimlik)
    {
        std::string oku;
        std::ifstream myfile (std::to_string(tc_kimlik) + ".txt");
        if(myfile.is_open())
        {
            while(getline(myfile,oku))
            {
                std::cout << oku << "\n";
            }
            myfile.close();
        }
        else std::cout << "Error!\n";
    }
    void deleteHasta (char tc_kimlik[20])
    {
        int stat = 0;
        stat = remove(tc_kimlik);
        if (stat == 0)
        {
            std::cout << tc_kimlik << " TC kimlik numarali hasta veritabanindan silindi!\n";
        }
        else std::cout << "Error!\n";
    }



};

class Doctor: public User
{
private:
    // login for doctor
    std::string login;
    std::string pass;
public:
    Doctor()
    {
        this->login = "doctor1";
        this->pass = "toor";
    }
    ~Doctor()
    {
        std::cout << "doctor desct\n";
    }
    bool loginSystemDoctor (std::string login,std::string pass)
    {
        if (login == "doctor1" && pass == "toor")
        {
            std::cout << "Doktor olarak erisim saglandi!\n";
            return true;
        }
        else { std::cout << "Erisim reddedildi!\n"; return false; }
    }
    void receteYaz (long long hasta_Tc,std::string recete)
    {
       std::string receteString = "";
       setRecete(recete);
       std::cout << "Hastaya Recete Yaziliyor...\n";
       std::ofstream myfile;
       myfile.open(std::to_string(hasta_Tc) + ".txt", std::ios_base::app);
       receteString = std::string(" | Yazilan Recete: ")
                    + recete + "\n"
                    + "---------------------------\n";
       myfile << receteString;
       myfile.close();
    }

};

class BaseMenu
{
public:
    BaseMenu()
    {

    }
    void loginMenu ()
    {
        std::cout << " | Hastane Database Giris | \n"
                  << "----------------------------\n"
                  << "[1] Doktor olarak giris yap:\n"
                  << "[2] Sekreter olarak giris yap:\n"
                  << "[3] Hasta olarak giris yap:\n"
                  << "[4] Cikis:\n";
    }
    void doktorMenu ()
    {
        std::cout << " | Doktor Paneli | \n"
                  << "-------------------\n"
                  << "[1] Hasta kaydi olustur:\n"
                  << "[2] Hastaya recete yaz:\n"
                  << "[3] Hasta Kaydi oku:\n"
                  << "[4] Hasta listesi:\n"
                  << "[5] Randevu listesi:\n"
                  << "[6] Hasta kaydi sil:\n"
                  << "[7] Geri don:\n";
    }
    void userMenu ()
    {
        std::cout << " | Sekreter Paneli | \n"
                  << "-------------------\n"
                  << "[1] Hasta kaydi olustur:\n"
                  << "[2] Hasta Kaydi oku:\n"
                  << "[3] Hasta listesi:\n"
                  << "[4] Randevu listesi:\n"
                  << "[5] Hasta kaydi sil:\n"
                  << "[6] Geri don:\n";
    }
    void hastaMenu ()
    {
        std::cout << " | Hasta Paneli | \n"
                  << "-------------------\n"
                  << "[1] Randevu al:\n"
                  << "[2] Geri don:\n";
    }
};

int main()
{
    BaseMenu menu1;
    Doctor doktor1;
    User sekreter1;

    int firstMenuChoice;
    do
    {
        menu1.loginMenu();
        std::cout << "~: ";
        std::cin >> firstMenuChoice;
        switch(firstMenuChoice)
        {
        case 1:
            {
                std::string log;
                std::cout << "Kullanici adi: ";
                std::cin >> log;
                std::cout << "\n";
                std::string pass;
                std::cout << "Sifre: ";
                std::cin >> pass;
                if (doktor1.loginSystemDoctor(log,pass) == true)
                {
                    int doctorChoice;
                    do
                    {
                        menu1.doktorMenu();
                        std::cout << "~: ";
                        std::cin >> doctorChoice;
                        switch(doctorChoice)
                        {
                        case 1:
                            {
                                std::cout << " | Hasta Kaydi Olusturma | \n"
                                          << "---------------------------\n";
                                std::string ad,randevuSaat,randevuTarih,bolum;
                                long long tc,telno;
                                bool sigorta;
                                int yas,ucret;
                                std::cout << "Hastanin adi: ";
                                std::cout << "~: ";
                                std::cin >> ad;
                                std::cout << "\n";
                                std::cout << "Hastanin TC kimlik numarasi: ";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                std::cout << "Sigorta durumu [1] = var | [0] = yok : ";
                                std::cout << "~: ";
                                std::cin >> sigorta;
                                std::cout << "\n";
                                std::cout << "Randevu saati [ XX:XX ]: ";
                                std::cout << "~: ";
                                std::cin >> randevuSaat;
                                std::cout << "\n";
                                std::cout << "Randevu tarihi [ DD/MM/YYYY ]: ";
                                std::cout << "~: ";
                                std::cin >> randevuTarih;
                                std::cout << "\n";
                                std::cout << "Hastanin telefon numarasi: +90 ";
                                std::cout << "~: ";
                                std::cin >> telno;
                                std::cout << "\n";
                                std::cout << "Hastanin yasi: ";
                                std::cout << "~: ";
                                std::cin >> yas;
                                std::cout << "\n";
                                std::cout << "Muayene yapan bolum [ radyoloji ],[ onkoloji ],[ pediatri ]: ";
                                std::cout << "~: ";
                                std::cin >> bolum;
                                std::cout << "\n";
                                std::cout << "Muayene tutari ( sigortasi var ise 0$ ): ";
                                std::cout << "~: ";
                                std::cin >> ucret;
                                std::cout << "\n";
                                doktor1.createHasta(ad,tc,sigorta,randevuSaat,randevuTarih,telno,yas,bolum,ucret);
                                Sleep(10);
                                system("CLS");
                                doktor1.readHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 2:
                            {
                                std::cout << " | Hastaya Recete Yazma | \n"
                                          << "---------------------------\n";
                                long long tc;
                                std::string recete;
                                std::cout << "Lutfen hastanin TC kimlik numarasini giriniz: ";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                Sleep(10);
                                doktor1.readHasta(tc);
                                std::cout << "Lutfen recetesini yazmak istediginiz ilaci girin: ";
                                std::cout << "~: ";
                                std::cin >> recete;
                                std::cout << "\n";
                                Sleep(10);
                                doktor1.readHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 3:
                            {
                                std::cout << " | Hasta Kaydi Okuma | \n"
                                          << "---------------------------\n";
                                long long tc;
                                std::cout << "Lutfen hastanin TC kimlik numarasini giriniz: ";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                Sleep(10);
                                doktor1.readHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 4:
                            {
                                std::cout << " | Hasta listesi | \n"
                                          << "---------------------------\n";
                                sekreter1.hastaList();
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }

                            }
                        case 5:
                            {
                                std::cout << " | Randevu listesi | \n"
                                          << "---------------------------\n";
                                sekreter1.randevuList();
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 6:
                            {
                                std::cout << " | Hasta Kaydi Silme | \n"
                                          << "---------------------------\n";
                                char tc[20];
                                std::cout << "Lutfen hastanin TC kimlik numarasini giriniz ve sonuna .txt koyunuz: \n";
                                std::cout << "orn: 10224422867.txt\n";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                Sleep(10);
                                doktor1.deleteHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 7:
                            {
                                std::cout << "Geri donuluyor";
                                doctorChoice = 7;
                                system("CLS");
                                break;
                            }
                        default:
                            {
                                std::cout << "Hatali giris!";
                                system("CLS");
                                continue;
                            }
                        }

                    } while (doctorChoice != 7);

                }
                else { system("CLS"); break; }
            }
        case 2:
            {
                std::string log;
                std::cout << "Kullanici adi: ";
                std::cin >> log;
                std::cout << "\n";
                std::string pass;
                std::cout << "Sifre: ";
                std::cin >> pass;
                if (sekreter1.loginSystemUser(log,pass) == true)
                {
                    int sekreterChoice;
                    do
                    {
                        menu1.userMenu();
                        std::cout << "~: ";
                        std::cin >> sekreterChoice;
                        switch(sekreterChoice)
                        {
                        case 1:
                            {
                                std::cout << " | Hasta Kaydi Olusturma | \n"
                                          << "---------------------------\n";
                                std::string ad,randevuSaat,randevuTarih,bolum;
                                long long tc,telno;
                                bool sigorta;
                                int yas,ucret;
                                std::cout << "Hastanin adi: ";
                                std::cout << "~: ";
                                std::cin >> ad;
                                std::cout << "\n";
                                std::cout << "Hastanin TC kimlik numarasi: ";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                std::cout << "Sigorta durumu [1] = var | [0] = yok : ";
                                std::cout << "~: ";
                                std::cin >> sigorta;
                                std::cout << "\n";
                                std::cout << "Randevu saati [ XX:XX ]: ";
                                std::cout << "~: ";
                                std::cin >> randevuSaat;
                                std::cout << "\n";
                                std::cout << "Randevu tarihi [ DD/MM/YYYY ]: ";
                                std::cout << "~: ";
                                std::cin >> randevuTarih;
                                std::cout << "\n";
                                std::cout << "Hastanin telefon numarasi: +90 ";
                                std::cout << "~: ";
                                std::cin >> telno;
                                std::cout << "\n";
                                std::cout << "Hastanin yasi: ";
                                std::cout << "~: ";
                                std::cin >> yas;
                                std::cout << "\n";
                                std::cout << "Muayene yapan bolum [ radyoloji ],[ onkoloji ],[ pediatri ]: ";
                                std::cout << "~: ";
                                std::cin >> bolum;
                                std::cout << "\n";
                                std::cout << "Muayene tutari ( sigortasi var ise 0$ ): ";
                                std::cout << "~: ";
                                std::cin >> ucret;
                                std::cout << "\n";
                                sekreter1.createHasta(ad,tc,sigorta,randevuSaat,randevuTarih,telno,yas,bolum,ucret);
                                Sleep(10);
                                system("CLS");
                                sekreter1.readHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 2:
                            {
                                std::cout << " | Hasta Kaydi Okuma | \n"
                                          << "---------------------------\n";
                                long long tc;
                                std::cout << "Lutfen hastanin TC kimlik numarasini giriniz: ";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                Sleep(10);
                                sekreter1.readHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 3:
                            {
                                std::cout << " | Hasta listesi | \n"
                                          << "---------------------------\n";
                                sekreter1.hastaList();
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 4:
                            {
                                std::cout << " | Randevu listesi | \n"
                                          << "---------------------------\n";
                                sekreter1.randevuList();
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 5:
                            {
                                std::cout << " | Hasta Kaydi Silme | \n"
                                          << "---------------------------\n";
                                char tc[20];
                                std::cout << "Lutfen hastanin TC kimlik numarasini giriniz ve sonuna .txt koyunuz: \n";
                                std::cout << "orn: 10224422867.txt\n";
                                std::cout << "~: ";
                                std::cin >> tc;
                                std::cout << "\n";
                                Sleep(10);
                                sekreter1.deleteHasta(tc);
                                int cikis;
                                std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                                std::cout << "~: ";
                                std::cin >> cikis;
                                if (cikis == 1)
                                {
                                system("CLS");
                                break;
                                }
                            }
                        case 6:
                            {
                                std::cout << "Geri donuluyor";
                                sekreterChoice = 6;
                                system("CLS");
                                break;
                            }
                        default:
                            {
                                std::cout << "Hatali giris!";
                                system("CLS");
                                continue;
                            }

                        }
                    } while (sekreterChoice != 6);

                }
                else { system("CLS"); break; }
            }
        case 3:
            {
                int hastaChoice;
                do
                {
                    menu1.hastaMenu();
                    std::cin >> hastaChoice;
                    std::cout << "~: ";
                    switch(hastaChoice)
                    {
                    case 1:
                        {
                            std::cout << " | Hasta Kaydi Silme | \n"
                                      << "---------------------------\n";
                            long long tc;
                            std::string randevuSaat,randevuTarih,bolum;
                            std::cout << "Lutfen TC kimlik numaranizi giriniz: \n";
                            std::cout << "~: ";
                            std::cin >> tc;
                            std::cout << "\n";
                            std::cout << "Lutfen randevu icin istediginiz saati yaziniz [ XX:XX ]: \n";
                            std::cout << "~: ";
                            std::cin >> randevuSaat;
                            std::cout << "\n";
                            std::cout << "Lutfen randevu icin istediginiz tarihi yaziniz [ DD/MM/YYYY ]: \n";
                            std::cout << "~: ";
                            std::cin >> randevuTarih;
                            std::cout << "\n";
                            std::cout << "Lutfen muayene olmak istediginiz bolumu yaziniz [ radyoloji ],[ onkoloji ],[ pediatri ]: \n";
                            std::cout << "~: ";
                            std::cin >> bolum;
                            std::cout << "\n";
                            Sleep(10);
                            system("CLS");
                            std::cout << "Randevunuz basariyla alinmistir.\n";
                            int cikis;
                            std::cout << "Cikis yapmak icin 1'e basiniz: \n";
                            std::cout << "~: ";
                            std::cin >> cikis;
                            if (cikis == 1)
                            {
                            system("CLS");
                            break;
                            }
                        }
                    case 2:
                        {
                            std::cout << "Geri donuluyor";
                            hastaChoice = 2;
                            system("CLS");
                            break;
                        }
                    default:
                        {
                            std::cout << "Hatali giris!";
                            system("CLS");
                            continue;
                        }
                    }
                } while (hastaChoice != 2);
            }
        case 4:
            {
                std::cout << "Cikis yapiliyor...";
                firstMenuChoice = 4;
                system("CLS");
                break;
            }
        default:
            {
                std::cout << "Yanlis giris!";
                system("CLS");
                continue;
            }

        }
    }while(firstMenuChoice != 4);

    system("CLS");

    std::cout << "Cikis yapildi.";

    system("PAUSE");
    return 0;
}
