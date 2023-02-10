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



};



#endif // VALIDATOR_H
