#include "validator.h"



bool Validator::validate_name(std::string name)
{   name=Validator::rtrim(name);

    std::regex reg_ex_name("^[A-Z][a-z]{1,20}$");

    if(regex_match(name,reg_ex_name))
        return true;

    throw "Wprowadzono niepoprawne imie";
}

bool Validator::validate_surname(std::string surname)
{
    std::regex reg_ex_sname("^([ \u00c0-\u01ffa-zA-Z'-])+{1,40}$"); //oparte na unicode puszcza tez francuskie nazwiska typu D'Arc

    if(regex_match(surname,reg_ex_sname)){
        return true;
    }
    throw "Podano niepoprawne nazwisko";
}

bool Validator::validate_pesel(std::string pesel)
{
    std::regex reg_ex_pesel("[0-9]{11}$");
    // sprawdzam dlugosc, bez sprawdzanie tego algorytmem Luhna i ogólnie spodziewanych wartosci

    int decade = std::stoi(pesel.substr(0,2));
    int month = std::stoi(pesel.substr(2,2));
    int day = std::stoi(pesel.substr(4,2));

    //zakladamy ze wszystkie miesiace moga miec 31 dni i system bedzie dzialal dla ludzi ur w latach 1900-2099

    if(regex_match(pesel,reg_ex_pesel) && (month < 33) && (day<32)) return true;

    throw "\n Wprowadzono niepoprawny PESEL";
}

bool Validator::validate_index(std::string index)
{
    std::regex reg_ex_index("[0-9]{6}$");

    if(regex_match(index,reg_ex_index)) return true;

    throw "\n Wprowadzono niepoprawny PESEL\n";
}

bool Validator::validate_email(std::string email)
{
    std::regex reg_ex_email("[a-zA-Z0-9.-_]{1,}@[a-zA-Z.-]{2,}[.]{1}[a-zA-Z]{2,}");
    // uwzglednienie tez podwojnych koncowej ...@we.es.ro

    if(regex_match(email,reg_ex_email)) return true;

    throw "\n Wprowadzono niepoprawny email\n";
}

bool Validator::validate_phone_number(std::string phone_num)
{

    std::regex reg_ex_ph_number("[\\+]{0,1}[0-9]{9,16}$");
    // tutaj mamy mocna odskocznie od wymagan projektowych, 9 + prefiks ktory technicznie moze byc dluzszy i opcjonalnym zdaniem
    //+ ktory z duza dola prawdopodobienstwa czasami mozna pominac (przynajmniej od strony ui)
    phone_num = Validator::trim(phone_num);

    if(regex_match(phone_num,reg_ex_ph_number)) return true;
    throw "\n Wprowadzono niepoprawny numer telefonu \n";
}

std::string Validator::extract_date_from_pesel(std::string pesel)
{ //02251305359
    std::string output ="";
    int decade = std::stoi(pesel.substr(0,2));
    int month = std::stoi(pesel.substr(2,2));
    int day = std::stoi(pesel.substr(4,2));
    int century = 19;
    if(day<10)
        output+="0";
    output+=std::to_string(day);
    output+=".";
//    std::cout<<"After day "<<output<<std::endl;
    if(month>12){
        month-=20;
        century=20;
    }
    if(month<12)
        output+="0";
    output+=std::to_string(month);
    output+=".";
//    std::cout<<"After month "<<output<<std::endl;
    output+=std::to_string(century);
    if(decade<10)
        output+="0";
    output+=std::to_string(decade);


    return output; //"dd.mm.yyyy"
}
