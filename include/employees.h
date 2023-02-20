#include <string>
#ifndef EMPLOYES_H
#define EMPLOYES_H


class employees
{
    public:
        employees();


        virtual ~employees();



    private:
         int age;
         std::string name;
         int experience;
         std:: string position;
         int code;

};

#endif // EMPLOYES_H
