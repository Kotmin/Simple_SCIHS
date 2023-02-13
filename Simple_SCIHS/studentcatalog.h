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


namespace bmi = boost::multi_index ;

//typedef bmi::multi_index_container<Student,bmi::indexed_by<
//bmi::hashed_non_unique<bmi::const_mem_fun<Student,std::string,&Student::name>>,
//bmi::hashed_non_unique<bmi::const_mem_fun<Student,std::string, &Student::surname>>,
//bmi::hashed_non_unique<bmi::const_mem_fun<Student,std::string,&Student::name>>, //placeholder for address
//bmi::hashed_unique<bmi::const_mem_fun<Student,std::string, &Student::pesel>>,
//bmi::hashed_unique<bmi::const_mem_fun<Student,std::string, &Student::index>>,
//bmi::hashed_unique<bmi::const_mem_fun<Student,std::string, &Student::email>>,
//bmi::hashed_unique<bmi::const_mem_fun<Student,std::string, &Student::ph_number>>,
//bmi::random_access<>
//>> students_multi

typedef bmi::multi_index_container<Student,bmi::indexed_by<
bmi::hashed_non_unique<Student,std::string, &Student::name>>

//typedef students_multi::nth_index<0>::type name_type;
//typedef students_multi::nth_index<1>::type surname_type;
//typedef students_multi::nth_index<2>::type name_type;
//typedef students_multi::nth_index<3>::type pesel_type;
//typedef students_multi::nth_index<4>::type index_type;
//typedef students_multi::nth_index<5>::type email_type;
//typedef students_multi::nth_index<6>::type ph_number_type;



class StudentCatalog
{
private:


    //read only access vector.at(index), shall be faster
    // qSort(vec.begin(),vec.end(), Func()_; // works on org
    // let's concider separate container named query to hold result of spefic function.
    // what about QHash<QString,Student>? that would take care of unique indexes, but own Class as sec param can be troublesome

    // going into boost lib and MultiIndex Container seems like wiser choice than playing with qt vector and searching
    //how to make accesors / gain acces into class.
//    students_multi students;
public:
    StudentCatalog();
    QVector<Student> catalog;

    bool add_Student(Student s);
    bool export_catalog(QString path);
};

#endif // STUDENTCATALOG_H
