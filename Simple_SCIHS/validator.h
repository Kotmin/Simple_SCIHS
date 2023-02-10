#ifndef VALIDATOR_H
#define VALIDATOR_H


#include<iostream>
#include<iterator>
#include<string>
#include<regex>
#include<iostream>

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

};



#endif // VALIDATOR_H
