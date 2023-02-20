#include "employees.h"


employees::employees()
{
}

employees::employees(int age, std::string name, int experience, std::string position)
{
    this->age=age;
    this->name=name;
    this->experience=experience;
    this->position=position;

}

employees::employees(int code,int age, std::string name, int experience, std::string position)
{
    this->code=code;
    this->age=age;
    this->name=name;
    this->experience=experience;
    this->position=position;

}

void employees::edit_code(int code)
{
    this->code=code;
}

void employees::edit_age(int age)
{
    this->age=age;
}

void employees::edit_experience(int experience)
{
    this->experience=experience;
}

int employees::get_code()
{
    return code;
}

void employees::edit_name(std::string name)
{
    this->name=name;
}

void employees::edit_position(std::string position)
{
    this->position=position;
}

int employees::get_age()
{
    return age;
}

int employees::get_experience()
{
    return experience;
}

std::string employees::get_name()
{
    return name;
}

std::string employees::get_position()
{
    return position;
}

employees::~employees()
{

}
