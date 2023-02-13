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



    // miescje na walidacje wnetrza krotki




    //mozna by rozwazyc czy uzywanie asserta nie byloby tutaj wygodniejsze


}

void Student::show() const
{
    std::cout<<this->index()<<" "<<this->name()<<" "<< this->surname()<<" "<<this->email()<<std::endl;

}

void Student::show_grades()
{
    for(auto& i: _grades)
        std::cout<<i<<" ";
    std::cout<<std::endl;

}

float Student::calculate_the_avg() // without wages, just simple avr value
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
