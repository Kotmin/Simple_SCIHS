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

void StudentCatalog::add(std::string name, std::string surname, std::tuple<std::string, std::string, std::string, std::string, std::string> address_street_house_nr_ap_nr_p_code_city, std::string pesel, std::string index, std::string email, std::string phone_num)
{
    std::vector<float> grades;
    this->add(name,surname,address_street_house_nr_ap_nr_p_code_city,pesel,index,email,phone_num,grades);

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
            fileOf<<it->index()<<";";
            fileOf<<it->email()<<";";
            fileOf<<it->ph_number()<<";";
            fileOf<<it->ret_grades()<<";";
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

void StudentCatalog::import_from_file(std::string path)
{
    std::ifstream fileIf;
    fileIf.open(path);
    std::string line,tmp;
    size_t pos =0;

    std::vector<std::string> temp;
    std::vector<std::string> temp_address;
    std::vector<float> temp_grades;
    std::string delimiter =";";

    try {

    while (getline(fileIf,line)) {
        delimiter=";";

        while((pos = line.find(delimiter)) != std::string::npos){
            temp.push_back(line.substr(0,pos));
            line.erase(0,pos + delimiter.length());
        }
        //
        for(auto& i: temp) //just for testing
            std::cout<<i<<" ";

        //

        //addres part
        delimiter=",";
        while((pos = temp[2].find(delimiter)) != std::string::npos){
            temp_address.push_back(temp[2].substr(0,pos));
            temp[2].erase(0,pos + delimiter.length());
        }

//                for(auto& i: temp_address) //just for testing
//                    std::cout<<i<<" ";
//           std::cout<<std::endl;

        krotka hook = std::make_tuple(temp_address[0],temp_address[1],temp_address[2],temp_address[3],
                temp_address[4]);
        std::cout<<std::endl<<" Size :"<< temp.size()<<std::endl;
//        std::cout<<std::endl<<" Size :"<< temp[8]<<std::endl;
        if(temp.size()==8) //if line contains grades
        {
            delimiter=",";
            while((pos = temp[7].find(delimiter)) != std::string::npos){
                temp_grades.push_back(std::stof(temp[7].substr(0,pos)));
                temp[7].erase(0,pos + delimiter.length());
            }
            Validator::validate_grades(temp_grades);
        }

        this->add(temp[0],temp[1],hook,temp[3],temp[4],temp[5],temp[6],temp_grades);
        for(auto& i: temp) //just for testing
            std::cout<<i<<" ";

        std::cout<<std::endl;

        temp.clear();
        temp_grades.clear();
        temp_address.clear();


//        std::cout<<line<<std::endl;
    }

}  catch (const char* msg) {
    std::cerr << msg << std::endl;
}
    fileIf.close();
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
    }

//    for(auto i=0; i != catalog.size();i++)
//    {
//        catalog.get<0>()[i].show();
//    }
//    boost::fusion::for_each(catalog,show());

}

bool isFromSpecificTown(const Student &s1,std::string town){
    krotka adress = s1.address();

    std::string town_to_compare = std::get<4>(adress);
    return !(town.compare(town_to_compare));
}

void StudentCatalog::show_all_ppl_from_speficic_town(std::string town)
{
    for(address_type::iterator it=catalog.get<2>().begin(); it !=catalog.get<2>().end();++it)
        if(isFromSpecificTown(*it,town))
            it->show();
}

bool isForeignNumber(const Student &s1){
    std::string number = s1.ph_number();

    if(number.length()==9)
        return false;
    if(number.length()==10 && number.substr(0,0)=="0")
        return false;
    if(number.length()==13 && number.substr(0,4)=="0048")
        return false;
    std::regex re(".48[0-9]{9}");
    if(regex_match(number,re))
        return false;
    return true;
}

void StudentCatalog::show_all_pll_with_foreign_ph_numbers()
{
    for(ph_number_type::iterator it=catalog.get<6>().begin(); it !=catalog.get<6>().end();++it)
        if(isForeignNumber(*it))
            it->show();
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

bool isInRange24_26(const Student &s1){ // to year precision
//    std::cout<<"My pesel is"<< s1.pesel()<<std::endl; // for testing
    int actual_year = 2023;
    std::string students_date_of_birth = Validator::extract_date_from_pesel(s1.pesel());
    int year_of_students_birth = std::stoi(students_date_of_birth.substr(6,4));
    int diff = (actual_year-year_of_students_birth);
//    std::cout<<"diff: "<<std::to_string(diff)<<std::endl;
    return (24 <= diff) && (diff <= 26);
}
void StudentCatalog::show_all_students_btw_24_and_26_yor()
{
//    auto
//    auto ind = &catalog.get<3>();

//        std::vector<boost::reference_wrapper<Student const> > temporary(ind->begin(),ind->end());
//    auto start = temporary.begin();

//    for(auto it=start;it!=temporary.end();it++)
//    {
////        it = std::find_if(start,temporary.end(),isInRange24_26);
////        *it->show();
////         std::cout<<"Last obj is behind"<< *it<<std::endl;
//    }
//    auto find_first = boost::range::adjacent_find(ind,isInRange24_26);

//    auto &pesel_index = catalog.get<3>();
//    auto it = pesel_index.find(isInRange24_26);

//    std::cout<<"znaleziono "<< it->show();
//    it->show();

//        std::sort(temporary.begin(),temporary.end(),myOldSort);

//        for(Student const& e: temporary)
//            e.show();


    for(pesel_type::iterator it=catalog.get<3>().begin(); it !=catalog.get<3>().end();++it)
        if(isInRange24_26(*it))
            it->show();

}

void StudentCatalog::show_students_with_their_grades()
{
    for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
    {
        std::cout<<it->index()<<"\t";
        it->show_grades();
        std::cout<<std::endl;
    }

}

void StudentCatalog::show_students_with_their_avr()
{
    for(auto it = catalog.get<0>().begin(); it != catalog.get<0>().end();++it)
    {
        std::cout<<it->index()<<"\t"<<std::to_string(it->calculate_the_avg())<<std::endl;
    }
}

bool myOldSort(const Student &s1, const Student &s2)
{
    std::string pesel_1 = s1.pesel();
    std::string pesel_2 = s2.pesel();
    std::string date_1 = Validator::extract_date_from_pesel(pesel_1);
    std::string date_2 = Validator::extract_date_from_pesel(pesel_2);
    std::cout<<"date 1 "<< date_1 << " vs "<< "date 2 "<< date_2 << std::endl;
//    int decade = std::stoi(pesel.substr(0,2));
//    int month = std::stoi(pesel.substr(2,2));
//    int day = std::stoi(pesel.substr(4,2));

    int year_1 = std::stoi(date_1.substr(6,4));
    int year_2 = std::stoi(date_2.substr(6,4));

//    std::cout<<date_1.substr(6,4)<<" vs "<< date_2.substr(6,4) << std::endl;

    int month_1 = std::stoi(date_1.substr(3,2));
    int month_2 = std::stoi(date_2.substr(3,2));

    int day_1 = std::stoi(date_1.substr(0,2));
    int day_2 = std::stoi(date_2.substr(0,2));

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

    return false;

}




void StudentCatalog::sort_by_age()
{ auto ind = &catalog.get<3>();

    std::vector<boost::reference_wrapper<Student const> > temporary(ind->begin(),ind->end());

    std::sort(temporary.begin(),temporary.end(),myOldSort);

    for(Student const& e: temporary)
        e.show();
//    catalog.begin()
//    boost::sort(begin(index),end(index),Older());
//    boost::sort(catalog.begin(),catalog.end(),Older());

//    boost::sort(ind);
//    boost::range::sort(ind,Older());

}

bool surnameSort(const Student &s1, const Student &s2){
    std::string surname_1 = s1.surname();
    std::string surname_2 = s2.surname();

    return surname_1 < surname_2;

}

void StudentCatalog::sort_by_surname()
{
    auto ind = &catalog.get<1>();

        std::vector<boost::reference_wrapper<Student const> > temporary(ind->begin(),ind->end());

        std::sort(temporary.begin(),temporary.end(),surnameSort);

        for(Student const& e: temporary)
            e.show();
}


bool city_name_Sort(const Student &s1, const Student &s2)
{
    krotka t1= s1.address();
    krotka t2= s2.address();

//    std::get<0>(t1);
//    std::cout<<std::endl<<std::get<4>(s1.address())<<std::endl;

    return std::get<4>(t1) < std::get<4>(t2);

}
void StudentCatalog::sort_by_city_name()
{
    auto ind = &catalog.get<2>();

        std::vector<boost::reference_wrapper<Student const> > temporary(ind->begin(),ind->end());

        std::sort(temporary.begin(),temporary.end(),city_name_Sort);

        for(Student const& e: temporary)
            e.show();
//            std::cout<<e.index()<<" "<<e.address()
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
    random_type &grades_index = catalog.get<7>();

    int how_many = boost::range::count_if(grades_index, []( const Student& student){
        return (student.calculate_the_avg() > 4.0f);
    });

    std::cout<<"Mamy "<<how_many<<" studentow ze srednia powyzej 4.0"<<std::endl;
    return how_many;

}
