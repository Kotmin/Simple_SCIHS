#include <QCoreApplication>
#include<iostream>
#include "Student.h"
#include "studentcatalog.h"

#include<tuple> //just for tests

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    std::cout<<"Hello\n";std::cout<<"Hello2\n";


//    Student(std::string name,std::string surname,
//            std::tuple<std::string,std::string,std::string,std::string,std::string> address_street_house_nr_ap_nr_p_code_city
//            ,std::string pesel,std::string index, std::string email,std::string phone_num);

    std::tuple<std::string,std::string,std::string,std::string,std::string> tup1;
    tup1 = std::make_tuple("Downing st.","3a","14","20-508","Lubdyn");
    Student s1("Adam2","Wielysz - Abroam",tup1,"02251305359","554421","mymail@mejl.pl","+48 124873556");

    std::vector<float> ocenki;
    ocenki.push_back(5.0);
    ocenki.push_back(4.0);
    ocenki.push_back(2.0);
    ocenki.push_back(3.5);
//    Student s2("Tadeusz","Ramen",tup1,"02251305359","554421","mymail@mejl.pl","+48 124873556",ocenki);
    s1.show_grades(ocenki);

//    std::cout<<"\n"<<Validator::validate_grades(ocenki)<<std::endl;
//    ocenki.push_back(3.51);
//    std::cout<<"\n"<<Validator::validate_grades(ocenki)<<std::endl;
//    ocenki.push_back(3.6);
//    std::cout<<"\n"<<Validator::validate_grades(ocenki)<<std::endl;

    // dokladnie bedzie trzeba lab6 przejrzec i skrypcik

    Student s3("Tobiasz","Kanoe",tup1,"04311305359","554421","mymail@mejl.pl","+48 124873556");
    s3.add_grade(5);
    s3.add_grade(4.5);
    s3.add_grade(3);
    s3.add_grade(3.7);
    s3.show_grades();

    std::cout<<Validator::extract_date_from_pesel("02251305359")<<std::endl;

    StudentCatalog ca1();


    return 1;
}
