#include <iostream>
#include "employees.h"
#include <fstream>
#include <vector>
#include <iterator>


void enter_the_datas(std::vector<employees> &datas); //Call the employee's datas from the .txt file.

void write_to_file(std::vector<employees> &datas); //Write the employee's datas into the .txt file

void new_employee(std::vector<employees> &datas); //Give a new employee's data

void delete_employee(std::vector<employees> &datas);

void edit_data_employee(std::vector<employees> &datas); //Edit an employee's data (age, code, ...)

void show_data_employee(std::vector<employees> &datas); //Show one employee's data's on command line.

void show_data_all_employee(std::vector<employees> &datas);


int main()
{
    setlocale(LC_ALL,"hun");
    std::vector<employees> datas;
    int option;

    enter_the_datas(datas);

    while(option!=0)
    {
        std::cout<<std::endl;
        std::cout<<"Mit szeretne csin�lni (adja meg a megfelel� sz�mot)?"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"1. �j alkalmazott adatainak megad�sa."<<std::endl;
        std::cout<<"2. Alkalmazott t�rl�se."<<std::endl;
        std::cout<<"3. Alkalmazott adatainak megv�ltoztat�sa."<<std::endl;
        std::cout<<"4. Egy alkalmazott adatainak megjelen�t�se k�d alapj�n"<<std::endl;
        std::cout<<"5. �sszes alkalmazott adatainak megjelen�t�se"<<std::endl;
        std::cout<<"0. Kil�p�s."<<std::endl;
        std::cout<<std::endl;
        std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;

        std::cin>>option;
        system("cls");

        switch (option)
        {
            case 1:
                new_employee(datas);
                break;

            case 2:
                delete_employee(datas);
                break;

            case 3:
                edit_data_employee(datas);
                break;

            case 4:
                show_data_employee(datas);
                break;

            case 5:
                show_data_all_employee(datas);
                break;

            case 0:
                break;

            default:
                std::cout<<"Rossz sz�mot adott meg."<<std::endl;
        }

    }


    write_to_file(datas);



    return 0;
}


void enter_the_datas(std::vector<employees> &datas)
{
    std::string name_1,name_2,position;
    int age,code,experince;

    std::ifstream fin("Employees_data.txt");

    while(!fin.eof())
    {
       fin>>code>>age>>name_1>>name_2>>experince>>position;
       employees v(code,age,name_1+' '+name_2,experince,position);
       datas.push_back(v);
    }

    fin.close();
}


void write_to_file(std::vector<employees> &datas)
{
    std::ofstream fout("Employees_data.txt");

    for(int i=0;i<datas.size();i++)
    {

        fout<<datas[i].get_code()<<' '<<datas[i].get_age()<<' '<<datas[i].get_name()<<' '<<datas[i].get_experience()<<' '<<datas[i].get_position();
        if (i<datas.size()-1) {fout<<'\n';}
    }

    fout.close();
}


void new_employee(std::vector<employees> &datas)
{
    std::string name_1,name_2,position;
    int age,code,experince;

    std::cout<<"Add meg az adatokat (k�d �letkor n�v tapasztalat poz�ci�)"<<std::endl;
    std::cin>>code>>age>>name_1>>name_2>>experince>>position;
    employees v(code,age,name_1+' '+name_2,experince,position);
    datas.push_back(v);
}


void delete_employee(std::vector<employees> &datas)
{
    int code;
    std::vector<employees>::iterator iterator_1;

    while(code>0)
    {
        std::cout<<"Kit t�r�lj�nk (alkalmazott k�dj�t adja meg)?"<<std::endl;
        std::cout<<"Visszal�p�shez �rja be a 0-�t."<<std::endl;
        std::cin>>code;
        system("cls");

        for(iterator_1=datas.begin();iterator_1<datas.end();iterator_1++)
        {
            if ((*iterator_1).get_code()==code) {datas.erase(iterator_1); code=0; break;}
        }

        if (iterator_1==datas.end() && code!=0) {std::cout<<"Nincs ilyen k�d."<<std::endl;}
    }


}


void edit_data_employee(std::vector<employees> &datas)
{
    int option,code,age,experience;
    std::string name_1,name_2,position;
    std::vector<employees>::iterator iterator_1;
    system("cls");

    while(code!=0)
    {
        std::cout<<"Kinek az adat�t v�ltoztassuk meg (alkalmazott k�dj�t adja meg)?"<<std::endl;
        std::cout<<"0. Vissza."<<std::endl;
        std::cin>>code;
        option=6;
        system("cls");

        for(iterator_1=datas.begin();iterator_1<datas.end();iterator_1++)
        {
            if ((*iterator_1).get_code()==code) {break;}
        }

        if (iterator_1==datas.end() && code!=0) {std::cout<<"Nincs ilyen k�d."<<std::endl;}
        else {

            while(option!=0 && code!=0)
            {
                std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
                std::cout<<std::endl;
                std::cout<<"1. K�d megv�ltoztat�sa"<<std::endl;
                std::cout<<"2. �letkor megv�ltoztat�sa."<<std::endl;
                std::cout<<"3. N�v megv�ltoztat�sa."<<std::endl;
                std::cout<<"4. Tapasztalat megv�ltoztat�sa."<<std::endl;
                std::cout<<"5. Poz�ci� megv�ltoztat�sa."<<std::endl;
                std::cout<<"0. Vissza."<<std::endl;
                std::cout<<std::endl;
                std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;

                std::cin>>option;
                system("cls");

                switch (option)
                {
                case 1:
                    std::cout<<"�j k�d"<<std::endl;
                    std::cin>>code;
                    (*iterator_1).edit_code(code);
                    code=0;
                    system("cls");
                    break;

                case 2:
                    std::cout<<"�j �letkor"<<std::endl;
                    std::cin>>age;
                    (*iterator_1).edit_age(age);
                    code=0;
                    system("cls");
                    break;

                case 3:
                    std::cout<<"�j n�v"<<std::endl;
                    std::cin>>name_1>>name_2;
                    (*iterator_1).edit_name(name_1+' '+name_2);
                    code=0;
                    system("cls");
                    break;

                case 4:
                    std::cout<<"�j tapasztalat"<<std::endl;
                    std::cin>>experience;
                    (*iterator_1).edit_experience(experience);
                    code=0;
                    system("cls");
                    break;

                case 5:
                    std::cout<<"�j poz�ci�"<<std::endl;
                    std::cin>>position;
                    (*iterator_1).edit_position(position);
                    code=0;
                    system("cls");
                    break;

                case 0:
                    break;

                default:
                    std::cout<<"Nincs ilyen lehet�s�g"<<std::endl;
                }
            }



        }
    }



}


void show_data_employee(std::vector<employees> &datas)
{
    int code;
    std::vector<employees>::iterator iterator_1;

    while(code!=0){
        std::cout<<"Kinek az adat�t jelenits�k meg (alkalmazott k�dj�t adja meg)?"<<std::endl;
        std::cout<<"0. Vissza."<<std::endl;
        std::cin>>code;
        system("cls");

        for(iterator_1=datas.begin();iterator_1<datas.end();iterator_1++)
        {
            if ((*iterator_1).get_code()==code) {break;}
        }

        if (iterator_1==datas.end()) {std::cout<<"Nincs ilyen k�d."<<std::endl;}
        else {std::cout<<(*iterator_1).get_code()<<' '<<(*iterator_1).get_age()<<' '<<(*iterator_1).get_name()<<' '<<(*iterator_1).get_experience()<<' '<<(*iterator_1).get_position()<<std::endl; code=0;}
    }

}


void show_data_all_employee(std::vector<employees> &datas)
{
    for(int i=0;i<datas.size();i++)
    {
        std::cout<<datas[i].get_code()<<' '<<datas[i].get_age()<<' '<<datas[i].get_name()<<' '<<datas[i].get_experience()<<' '<<datas[i].get_position()<<std::endl;;
    }
}



