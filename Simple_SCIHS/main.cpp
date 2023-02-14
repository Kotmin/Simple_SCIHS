#include <QCoreApplication>
#include<iostream>
#include "Student.h"
#include "studentcatalog.h"

#include<tuple> //just for tests


int main()
{
//    QCoreApplication a(argc, argv);
    std::cout<<"Hello\n";std::cout<<"Hello2\n";


//    Student(std::string name,std::string surname,
//            std::tuple<std::string,std::string,std::string,std::string,std::string> address_street_house_nr_ap_nr_p_code_city
//            ,std::string pesel,std::string index, std::string email,std::string phone_num);

    std::tuple<std::string,std::string,std::string,std::string,std::string> tup1;
    tup1 = std::make_tuple("Downing st.","3a","14","20-508","Lubdyn");

    std::tuple<std::string,std::string,std::string,std::string,std::string> tup2;
    tup2 = std::make_tuple("Downing st.","3a","14","20-508","Alzacja");

    std::tuple<std::string,std::string,std::string,std::string,std::string> tup3;
    tup3 = std::make_tuple("Downing st.","3a","14","20-508","Bemowo");

    std::tuple<std::string,std::string,std::string,std::string,std::string> tup4;
    tup4 = std::make_tuple("Downing st.","3a","14","20-508","Cajlon");

    Student s1("Adam","Wielysz - Abroam",tup4,"02251305359","554429","mymail@mejl.pl","+48 124873556");

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

    Student s4("Wilhelm","Zdobywca Radom",tup1,"92121505349","554521","hb@mejl.pl","+48 124876556");
    StudentCatalog cat;

    cat.add_Student(s1);
    cat.add_Student(s3);
    cat.add_Student(s4);
    cat.add("Wieso","Szabrownik",tup2,"81121305359","564521","bemowo@mejl.pl","+48 124873555",ocenki);
    cat.add("Janko","Muzykant - Wierszolleta",tup3,"82121335359","564522","flet@mejl.pl","+48 224873555",ocenki);

    cat.show();
    cat.count_double_barreleed_surname();
//    cat.remove_Student_by_index("554429");
    cat.show();
//    cat.sort_by_age();
    cat.show();
    cat.export_to_file("plik.txt");

    cat.sort_by_age();
    cat.sort_by_surname();
    cat.sort_by_city_name(); // error


    std::cout<<s4.address_to_str()<<std::endl;

    // został cały segment z wyświetlaniem

    // 10% studentow z najwyzsza sredniaa

    // zaimplementowac import

    //not czajen dlaczego f szablonowa z count

    return 0;
}
