// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <Task1.h>
#include <Task2.h>
#include <Task3.h>


// Ваші файли загловки 
//
#include "Lab6Example.h"
int main()
{
    std::cout << " Lab #6  !\n";
    std::cout << "1. Task 1\n";
    std::cout << "2. Task 2\n";
    std::cout << "3. Task 3\n";

    int choise = 0;
    std::cin >> choise;
    if (choise == 1)
        task1();
    else if (choise == 2)
        task2();
    else if (choise == 3)
        task3();

    return 0;

}