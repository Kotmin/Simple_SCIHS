#include "Student.h"



Student::Student(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num)
{
    name=Validator::rtrim(name);
    surname=Validator::rtrim(surname);
    phone_num = Validator::trim(phone_num);

    try {
        if(Validator::validate_name(name))
            this->_name= name;
        if(Validator::validate_surname(surname))
            this->_surname = surname;
        if(Validator::validate_pesel(pesel))
            this->_pesel = pesel;
        if(Validator::validate_index(index))
            this->_index_nr = index;
        if(Validator::validate_email(email))
            this->_email = email;
        if(Validator::validate_phone_number(phone_num))
            this->_phone_number = phone_num;



    }  catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    this->_address = address_street_house_nr_ap_nr_p_code_city;


    // miescje na walidacje wnetrza krotki




    //mozna by rozwazyc czy uzywanie asserta nie byloby tutaj wygodniejsze


}

Student::Student(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num, std::vector<float> grades)
{
    name=Validator::rtrim(name);
    surname=Validator::rtrim(surname);
    phone_num = Validator::trim(phone_num);

    try {
        if(Validator::validate_name(name))
            this->_name= name;
        if(Validator::validate_surname(surname))
            this->_surname = surname;
        if(Validator::validate_pesel(pesel))
            this->_pesel = pesel;
        if(Validator::validate_index(index))
            this->_index_nr = index;
        if(Validator::validate_email(email))
            this->_email = email;
        if(Validator::validate_phone_number(phone_num))
            this->_phone_number = phone_num;
        this->_grades = grades;

    }  catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    this->_address = address_street_house_nr_ap_nr_p_code_city;
}

void Student::show() const
{
    std::cout<<this->index()<<" "<<this->name()<<" "<< this->surname()<<" "<<this->email()<<
            " "<<this->pesel()<<std::endl;

}

void Student::show_grades()
{
    for(auto& i: _grades)
        std::cout<<i<<" ";
    std::cout<<std::endl;

}

std::string Student::address_to_str() const
{
    std::string street,house_nr,flat_nr,postal_code,city;

    std::tie(street,house_nr,flat_nr,postal_code,city) = this->address();

    return street+","+house_nr+","+flat_nr+","+postal_code+","+city+",";

}

//std::string Student::address_to_str() const
//{
//    std::string ret="";
//    for(int i =0; i<5;i++)
//        ret+=std::get<i>(this->_address)+",";
//    return ret;
//}
//}

float Student::calculate_the_avg() // without wages, just simple avg value
{   int len_of_vector = this->_grades.size();
    float sum=0.0;
    for(auto& i: _grades)
        sum+=i;
    return sum/len_of_vector;

}

std::string Student::generate_email()
{
    return this->index() +"@pollub.edu.pl";
}

std::string Student::ret_grades() const
{ std::string ret = "";
    for(auto& i: _grades){
        ret+=std::to_string(i).substr(0,3);
        ret+=",";
    }


    return ret;

}
