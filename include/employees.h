#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <string>

class employees
{
    public:
        employees();

        employees(int age, std::string name, int experience, std::string position);

        void edit_code(int code);

        void edit_name(std::string name);

        void edit_experience(int experience);

        void edit_position(std::string position);

        int get_code();

        virtual ~employees();



    private:
         int age;
         std::string name;
         int experience;
         std:: string position;
         int code;

};

#endif // EMPLOYES_H
