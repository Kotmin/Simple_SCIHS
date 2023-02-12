#ifndef STUDENTCATALOG_H
#define STUDENTCATALOG_H

#include<QVector>
#include "Student.h"

class StudentCatalog
{
private:


    //read only access vector.at(index), shall be faster
    // qSort(vec.begin(),vec.end(), Func()_; // works on org
    // let's concider separate container named query to hold result of spefic function.
    // what about QHash<QString,Student>? that would take care of unique indexes, but own Class as sec param can be troublesome
public:
    StudentCatalog();
    QVector<Student> catalog;
};

#endif // STUDENTCATALOG_H
