#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <string>

class employees
{
    public:
        employees();

        employees(int age, std::string name, int experience, std::string position);

        employees(int code,int age, std::string name, int experience, std::string position);

        void edit_code(int code);

        void edit_name(std::string name);

        void edit_age(int age);

        void edit_experience(int experience);

        void edit_position(std::string position);

        int get_code();

        int get_age();

        int get_experience();

        std::string get_name();

        std::string get_position();

        virtual ~employees();



    private:
         int age;
         std::string name;
         int experience;
         std:: string position;
         int code;

};

#endif // EMPLOYES_H
