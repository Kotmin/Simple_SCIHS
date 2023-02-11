#ifndef VALIDATOR_H
#define VALIDATOR_H


#include<iostream>
#include<iterator>
#include<string>
#include<regex>
#include<vector>

class Validator
{
private:
    Validator() {};

    std::regex regex_name;

public:
//    template< typename T>
//    static bool validateName(T name);
    static std::string ltrim(const std::string &s) {
        return std::regex_replace(s, std::regex("\\s+"),std::string(""));
    }

    static std::string rtrim(const std::string &s){
        return std::regex_replace(s, std::regex("\\s+$"),std::string(""));
    }

    static std::string trim(const std::string &s){
        return ltrim(rtrim(s));
    }

    static bool validate_name(std::string name);
    static bool validate_surname(std::string surname);
    //placeholder for validate_address
    static bool validate_pesel(std::string pesel);
    static bool validate_index(std::string index);
    static bool validate_email(std::string email);
    static bool validate_phone_number(std::string phone_num);
    //placeholder for validate_grades

    template<typename T>
    static bool validate_grade(T grade);

    template<typename T>
    static bool validate_grades(std::vector<T> const &container);



};

template<typename T>
bool Validator::validate_grades(const std::vector<T> &container)
{
    typename std::vector<T>::const_iterator it;
    for(it = container.begin();it!=container.end();it++)
        if(!Validator::validate_grade(*it))
            throw "Podany kontener nie posiada wartosci zgodnych ze zdefiniowana skala\n";
    return true;

}

template<typename T>
bool Validator::validate_grade(T grade) // to jest delikatnie naciagane
{
    if ((grade==2.0f)||(grade==3.0f)||(grade==3.5f)||(grade==4.0f)||(grade==4.5f)||(grade==5.0f))
        return true;
    throw "\nProba wprowadzenia oceny spoza zdefiniowanych [2.0,3.0,3.5,4.0,4.5,5.0]\n";
}



#endif // VALIDATOR_H
