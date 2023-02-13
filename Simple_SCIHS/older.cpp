#include "older.h"

bool Older::operator()(std::string pesel_1, std::string pesel_2) //format "dd.mm.yyyy" from Validator::extract_date_from_PESEL
{
    std::string date_1 = Validator::extract_date_from_pesel(pesel_1);
    std::string date_2 = Validator::extract_date_from_pesel(pesel_2);

//    int decade = std::stoi(pesel.substr(0,2));
//    int month = std::stoi(pesel.substr(2,2));
//    int day = std::stoi(pesel.substr(4,2));

    int year_1 = std::stoi(pesel_1.substr(6,4));
    int year_2 = std::stoi(pesel_2.substr(6,4));

    std::cout<<pesel_1.substr(6,4)<<" vs "<< pesel_2.substr(6,4) << std::endl;

    int month_1 = std::stoi(pesel_1.substr(3,2));
    int month_2 = std::stoi(pesel_2.substr(3,2));

    int day_1 = std::stoi(pesel_1.substr(0,2));
    int day_2 = std::stoi(pesel_2.substr(0,2));

    if(year_1 < year_2)
        return true;

    if(year_1 > year_2)
        return false;

    if(month_1<month_2)
        return true;

    if(month_1>month_2)
        return false;

    if(day_1<day_2)
        return true;

    if(day_1>day_2)
        return false;

}
