#include "employees.h"
#include <fstream>

employees::employees()
{
}

employees::employees(int age, std::string name, int experience, std::string position)
{
    std::ifstream fin("Employees_data.txt");
    std::string line;
    while(!fin.eof()){
        fin>>line;
    }
    code=std::stoi(line)+1;
    fin.close();

    this->age=age;
    this->name=name;
    this->experience=experience;
    this->position=position;

    line=std::to_string(code)+' '+std::to_string(this->age)+' '+this->name+' '+std::to_string(this->experience)+' '+this->position;
    std::ofstream fout("Employees_data.txt");

    fout.close();
}


void employees::delete_employees(int code)
{
    std::ofstream fin("Employees_data.txt");
    for(){}
    fin.close();
}

void employees::edit_employees(int code, int age, std::string name, int experience, std::string position)
{
    for()
}

employees::~employees()
{

}
