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

void StudentCatalog::export_to_file(std::string path)
{
    try{
    std::ofstream fileOf;
    fileOf.open(path);
    if(fileOf.is_open())
    {
        for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
        {
            fileOf<<it->name()<<";";
            fileOf<<it->surname()<<";";
            fileOf<<it->address_to_str()<<";";
            fileOf<<it->pesel()<<";";
            fileOf<<it->email()<<";";
            fileOf<<it->ph_number()<<";";
            fileOf<<"\n";
        }
        fileOf.close();
    }
    else
        std::cerr<<"Blad, zapis nie powidl sie\n";

}  catch (const char* msg) {
    std::cerr << msg << std::endl;
}
}


int StudentCatalog::count_double_barreleed_surname()
{
    surname_type &surname_index = catalog.get<1>();
    std::regex re("[ -]+");
//    int how_many = boost::range::count_if(surname_index, [re](auto student){ // kompilator mi zatrzymal to magicznie
    int how_many = boost::range::count_if(surname_index, [re]( const Student& student){
//       return std::regex_match(student.surname(), re);
        return std::regex_search(student.surname(), re);
    });
    std::cout<<"Mamy "<< std::to_string(how_many)<<" nazwisk dwuczlonowych"<<std::endl;
    return how_many;
}

void StudentCatalog::show()
{
    for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
    {
        it->show();
//        std::cout<<"num\n";
    }

//    for(auto i=0; i != catalog.size();i++)
//    {
//        catalog.get<0>()[i].show();
//    }
//    boost::fusion::for_each(catalog,show());

}

//void StudentCatalog::show_all_ppl_from_speficic_town(std::string town)
//{
//    surname_type &surname_index = catalog.get<1>();
//    std::regex re("[ -]+");
//    int how_many = boost::range::count_if(surname_index, [re]( const Student& student){
//        return std::regex_search(student.surname(), re);
//    });
//    std::cout<<"Mamy "<< std::to_string(how_many)<<" nazwisk dwuczlonowych"<<std::endl;

//}

void StudentCatalog::show_all_students_btw_24_and_26_yor()
{
//    auto
}

void StudentCatalog::sort_by_age()
{ auto ind = &catalog.get<3>();
//    catalog.begin()
//    boost::sort(begin(index),end(index),Older());
//    boost::sort(catalog.begin(),catalog.end(),Older());

//    boost::sort(ind);
//    boost::range::sort(ind,Older());

}

void StudentCatalog::generate_emails()
{
    for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
    {
       std::cout<<it->index()<<" "<<it->index()<<"@pollub.edu.pl";
       std::cout<<std::endl;
    }
}

template<typename T>
int StudentCatalog::count_students_with_avr_above_4_0()
{
//    bool is_greater_than_4_0(T number){return if(number > 4.0f);}

    return 1;

}
