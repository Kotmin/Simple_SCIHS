#include "studentcatalog.h"




//bool StudentCatalog::export_catalog(QString path)
//{
//    QFile fileout(path);

//    if(fileout.open(QFile::ReadWrite | QFile::Text)){
//        QTextStream stream(&fileout);
//        for(QVector<Student>::const_iterator it = catalog.begin(); it != catalog.end(); ++it){
//            stream << *it;
//        }
//        fileout.close();
//    }

//}

//void StudentCatalog::add(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num, std::vector<float> grades)
//{
//    catalog.insert({name,surname,address_street_house_nr_ap_nr_p_code_city,pesel,index,email,phone_num,grades});
//}

void StudentCatalog::add(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num, std::vector<float> grades)
{
    name=Validator::rtrim(name);
    surname=Validator::rtrim(surname);
    phone_num = Validator::trim(phone_num);


    try {
        Validator::validate_name(name);
        Validator::validate_surname(surname);
        Validator::validate_pesel(pesel);
        Validator::validate_index(index);
        Validator::validate_email(email);
        Validator::validate_phone_number(phone_num);

        catalog.insert({name,surname,address_street_house_nr_ap_nr_p_code_city,pesel,index,email,phone_num,grades});

    }  catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

}

void StudentCatalog::add_Student(Student s)
{
    catalog.insert({s.name(),s.surname(),s.address(),s.pesel(),s.index(),s.email(),s.ph_number(),s.grades()});
}

void StudentCatalog::remove_Student_by_index(std::string index)
{
    auto &it = catalog.get<4>();
    it.erase(index);
}

int StudentCatalog::count_double_barreleed_surname()
{
    surname_type &surname_index = catalog.get<1>();
    std::regex re("[ -]+");
    int how_many = boost::range::count_if(surname_index, [re](auto student){
       return std::regex_match(student.surname(), re);
    });
    std::cout<<"Mamy "<< std::to_string(how_many)<<" nazwisk dwuczlonowych"<<std::endl;
    return how_many;
}

void StudentCatalog::show()
{
    for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
    {
        it->show();
        std::cout<<"num\n";
    }

//    for(auto i=0; i != catalog.size();i++)
//    {
//        catalog.get<0>()[i].show();
//    }
//    boost::fusion::for_each(catalog,show());

}

template<typename T>
int StudentCatalog::count_students_with_avr_above_4_0()
{
    return 1;

}
