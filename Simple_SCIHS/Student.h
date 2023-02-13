#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<tuple>
#include<iostream>
#include<vector>
#include<regex>

#include<QDataStream>
#include<QTextStream>

#include<QFile>

#include "validator.h"

typedef std::tuple<std::string,std::string,std::string,std::string,std::string> krotka;

class Student
{
private:
    std::string _name;
    std::string _surname;
    krotka _address;
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
    void show_grades();
    template<typename T>
    void show_grades(std::vector<T> const &container);

    template<typename T>
    bool add_grade(const T grade);


    std::string name() const {return this->_name;}


    std::string surname() const {return this->_surname;}


//    std::string address() const {return "";}//_addres;} to do


    std::string pesel() const {return this->_pesel;}



    std::string index() const {return this->_index_nr;}; // to do
    QString sindex(){return QString::fromStdString(index());};


    std::string email() const {return this->_email;};


    std::string ph_number() const {return this->_phone_number;}


    krotka address() const {return this->_address;}


//    friend QDataStream& operator<<(QDataStream &stream, Student &student){
//        stream << student.sindex();

//        return stream;
//    }

};

template<typename T>
bool Student::add_grade(const T grade)
{
    try {
        if(Validator::validate_grade(grade))
            this->_grades.push_back(grade);
        return true;

    }  catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return false;
}

template<typename T>
void Student::show_grades(std::vector<T> const &container)
{
    typename std::vector<T>::const_iterator it;
    for(it = container.begin();it!=container.end();it++)
            std::cout<<*it<<" ";
    std::cout<<std::endl;

}

#endif // STUDENT_H
