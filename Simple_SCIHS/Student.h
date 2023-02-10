#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<tuple>
#include<iostream>
#include<vector>
#include<regex>

#include "validator.h"

class Student
{
private:
    std::string _name;
    std::string _surname;
    std::tuple<std::string,std::string,std::string,std::string,std::string> _addres;
    std::string _pesel;
    std::string _index_nr;
    std::string _email;
    std::string _phone_number;
//    std::enum grades {2.0,3.0,3.5}; //to tak ladnie nie zadziala
    std::vector<float> _grades;


    // wyjasniajac dlaczego to wszystko jest typu string, nr_domu, mieszkania miewaja w sobie magiczne literki typu 3a,
    // jedynie postal code mozna by tu rozwazyc jako int. I zasadniczo w takim ulozeniu typ tuple jest troszke zbedny
    // zwazajac na homogenicznosc typow
public:
    Student();
    Student(std::string name,std::string surname,
            std::tuple<std::string,std::string,std::string,std::string,std::string> address_street_house_nr_ap_nr_p_code_city
            ,std::string pesel,std::string index, std::string email,std::string phone_num);

    Student(std::string name,std::string surname,
            std::tuple<std::string,std::string,std::string,std::string,std::string> address_street_house_nr_ap_nr_p_code_city
            ,std::string pesel,std::string index, std::string email,std::string phone_num,std::vector<float> grades);

    template<typename T>
    void show_grades(std::vector<T> const &container);
};

template<typename T>
void Student::show_grades(std::vector<T> const &container)
{
    typename std::vector<T>::const_iterator it;
    for(it = container.begin();it!=container.end();it++)
            std::cout<<*it<<" ";
    std::cout<<std::endl;

}

#endif // STUDENT_H
