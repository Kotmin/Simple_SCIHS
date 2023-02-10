#include "Student.h"



Student::Student(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num)
{
    name=Validator::rtrim(name);
    surname=Validator::rtrim(surname);
    std::regex reg_ex_name("^[A-Z][a-z].*{1,20}$");

    if(regex_match(name,reg_ex_name)){
        std::cout<<"imie poprawne :"<<name;
        this->_name = name;
    }
    else{std::cout<<"imie niepoprawne :"<<name;}
    std::regex reg_ex_sname("^([ \u00c0-\u01ffa-zA-Z'-])+{1,40}$"); //oparte na unicode puszcza tez francuskie nazwiska typu D'Arc

    if(regex_match(surname,reg_ex_sname)){
        std::cout<<"nazwisko poprawne : "<<surname<<"\n";
        this->_surname = surname;
    }
    else{std::cout<<"\n nazwisko niepoprawne : "<<surname;}

// miescje na walidacje wnetrza krotki

    //
    std::regex reg_ex_pesel("[0-9]{11}$");
    // sprawdzam dlugosc, bez sprawdzanie tego algorytmem Luhna i ogólnie spodziewanych wartosci
    // tj z wyciagnieciem konkretnej daty urodzenia moglibysmy trzeba rozwazyc zamiane tego na dokladna date
    // znaczy sie tylko wchodzac w to jak bardzo chcemy porownywac studentow pod wzgledem wieku, rok, czy dokladniej

    int decade = std::stoi(pesel.substr(0,2));
    int month = std::stoi(pesel.substr(2,2));
    int day = std::stoi(pesel.substr(4,2));

    //zakladamy ze wszystkie miesiace moga miec 31 dni i system bedzie dzialal dla ludzi ur w latach 1900-2099
    if(regex_match(pesel,reg_ex_pesel) && (month < 33) && (day<32)){
        std::cout<<"PESEL poprawny : "<<pesel<<"\n";
        this->_pesel = pesel;
    }
    else{std::cout<<"\n PESEL niepoprawne : "<<pesel<<"\n";}



    std::regex reg_ex_email("[a-zA-Z0-9.-_]{1,}@[a-zA-Z.-]{2,}[.]{1}[a-zA-Z]{2,}");
    // uwzglednienie tez podwojnych koncowej ...@we.es.ro
    if(regex_match(email,reg_ex_email)){
        std::cout<<"email poprawny : "<<email<<"\n";
        this->_email = email;
    }
    else{std::cout<<"\n email niepoprawne : "<<email;}

    std::regex reg_ex_ph_number("[\\+]{0,1}[0-9]{9,16}$");
    // tutaj mamy mocna odskocznie od wymagan projektowych, 9 + prefiks ktory technicznie moze byc dluzszy i opcjonalnym zdaniem
    //+ ktory z duza dola prawdopodobienstwa czasami mozna pominac (przynajmniej od strony ui)
    phone_num = Validator::trim(phone_num);

    if(regex_match(phone_num,reg_ex_ph_number)){
        std::cout<<"numer tel poprawny : "<<phone_num<<"\n";
        this->_phone_number = phone_num;
    }
    else{std::cout<<"\n numer tel niepoprawne : "<<phone_num;}

}
