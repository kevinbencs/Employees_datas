#include <iostream>
#include "employees.h"
#include <fstream>
#include <vector>

void enter_the_datas(std::vector<employees> datas);

void write_to_file(std::vector<employees> datas);

int main()
{
    std::vector<employees> datas;
    enter_the_datas(datas);
    int option;

    std::cout<<<<std::endl;
    std::cout<<"Mit szeretn�l csin�lni (add meg a sz�mot)?"<<std::endl;
    std::cout<<<<std::endl;
    std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
    std::cout<<<<std::endl;
    std::cout<<"1. �j alkalmazott adatainak megad�sa."<<std::endl;
    std::cout<<"2. Alkalmazott t�rl�se."<<std::endl;
    std::cout<<"3. Alkalmazott adatainak megv�ltoztat�sa."<<std::endl;







    return 0;
}


void enter_the_datas(std::vector<employees> datas)
{
    std::string name_1,name_2,position;
    int age,code,experince;

    std::ifstream fin("Employees_data.txt");

    while(fin)
    {
       fin>>code>>age>>name_1>>name_2>>experince>>position;
       employees v(code,age,name_1+' '+name_2,experince,position);
       datas.push_back(v);
    }

    fin.close();
}


void write_to_file(std::vector<employees> datas)
{
    std::ofstream fout("Employees_data.txt");

    for(int i=0;i<datas.size();i++)
    {
        fout<<datas[i].get_code()<<' '<<datas[i].get_age()<<' '<<datas[i].get_name()<<' '<<datas[i].get_experience()<<' '<<datas[i].get_position();
    }

    fout.close();
}
