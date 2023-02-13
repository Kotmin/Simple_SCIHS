#ifndef OLDER_H
#define OLDER_H

#include "validator.h"
#include<iostream>
#include<stdlib.h>

class Older
{
public:
//    Older();
    bool operator()(std::string pesel_1,std::string pesel_2);
};

#endif // OLDER_H
