#include <string>
#ifndef EMPLOYES_H
#define EMPLOYES_H


class employees
{
    public:
        employees();

        employees(int age, std::string name, int experience, std::string position);

        void set_code(int last_code);

        void delete_employees(int code);

        void edit_employees(int code, int age, std::string name, int experience, std::string position);

        virtual ~employees();



    private:
         int age;
         std::string name;
         int experience;
         std:: string position;
         int code;

};

#endif // EMPLOYES_H
