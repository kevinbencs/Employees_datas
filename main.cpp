#include <iostream>
#include "employees.h"
#include <fstream>
#include <vector>

void enter_the_datas(std::vector<employees> datas);

int main()
{
    std::vector<employees> datas;
    enter_the_datas(datas);







    return 0;
}


void enter_the_datas(std::vector<employees> datas)
{
    std::stirng name,position;
    int age,code,experince;

    std::ifstream fin("Employees_data.txt");

    while(!fin.eof())
    {
       fin>>code>>age>>name>>experince>>position;
       datas.push_back(code,age,name,experince,position);
    }

    fin.close();
}
