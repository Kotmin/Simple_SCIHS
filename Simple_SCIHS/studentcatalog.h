#ifndef STUDENTCATALOG_H
#define STUDENTCATALOG_H

#include<QVector>
#include "Student.h"

#include<boost/multi_index/hashed_index.hpp>
#include<boost/multi_index/ordered_index.hpp>
#include<boost/multi_index_container.hpp>
#include<boost/multi_index/mem_fun.hpp>
#include<boost/multi_index/random_access_index.hpp>
#include<boost/bind.hpp>
#include<boost/range/algorithm.hpp>


#include<boost/fusion/algorithm/iteration/for_each.hpp>
#include<boost/fusion/include/for_each.hpp>

typedef std::tuple<std::string,std::string,std::string,std::string,std::string> krotka;

namespace bmi = boost::multi_index;

typedef bmi::multi_index_container<Student, bmi::indexed_by<
    bmi::hashed_non_unique<bmi::const_mem_fun<Student, std::string, &Student::name>>,
    bmi::hashed_non_unique<bmi::const_mem_fun<Student, std::string, &Student::surname>>,
    bmi::hashed_non_unique<bmi::const_mem_fun<Student, krotka, &Student::address>>,
    bmi::hashed_unique<bmi::const_mem_fun<Student, std::string, &Student::pesel>>,
    bmi::hashed_unique<bmi::const_mem_fun<Student, std::string, &Student::index>>,
    bmi::hashed_unique<bmi::const_mem_fun<Student, std::string, &Student::email>>,
    bmi::hashed_unique<bmi::const_mem_fun<Student, std::string, &Student::ph_number>>,
    bmi::random_access<>
>> students_multi;

typedef students_multi::nth_index<0>::type name_type;
typedef students_multi::nth_index<1>::type surname_type;
typedef students_multi::nth_index<2>::type address_type;
typedef students_multi::nth_index<3>::type pesel_type;
typedef students_multi::nth_index<4>::type index_type;
typedef students_multi::nth_index<5>::type email_type;
typedef students_multi::nth_index<6>::type ph_number_type;
typedef students_multi::nth_index<7>::type random_type;



class StudentCatalog
{
private:

    students_multi catalog;
    //read only access vector.at(index), shall be faster
    // qSort(vec.begin(),vec.end(), Func()_; // works on org
    // let's concider separate container named query to hold result of spefic function.
    // what about QHash<QString,Student>? that would take care of unique indexes, but own Class as sec param can be troublesome

    // going into boost lib and MultiIndex Container seems like wiser choice than playing with qt vector and searching
    //how to make accesors / gain acces into class.
//    students_multi students;
public:
    StudentCatalog(){};
//    QVector<Student> catalog;
    void add(std::string name,std::string surname,
             std::tuple<std::string,std::string,std::string,std::string,std::string> address_street_house_nr_ap_nr_p_code_city
             ,std::string pesel,std::string index, std::string email,std::string phone_num,std::vector<float> grades);
    void add_Student(Student s); // to check

    void remove_Student_by_index(std:: string index); // to check
//    bool export_catalog(QString path);

    void show();
    void show_all_ppl_from_speficic_town(); //empty
    void show_all_students_btw_24_and_26_yor(); //empty

// przydalaby sie funkcja ktora nam na biezaco zrobi slownik index - srednia, ze dynamicznie
    template <typename T>
    int count_students_with_avr_above_4_0(); //empty
     int count_double_barreleed_surname(); //to check
};

#endif // STUDENTCATALOG_H
