#include <QCoreApplication>
#include<iostream>
#include "Student.h"
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
    Student s1("Adam Karol","Wielysz - Abroam",tup1,"02251305359","554421","mymail@mejl.pl","+48 124873556");

    return 1;
//    return a.exec();
}
