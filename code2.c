#include "area.h"
#include "volume.h"
#include <stdio.h>

void menu(int *a)
{
    printf("1. kwadrat\n");
    printf("2. szescian\n");
    printf("3. wyjscie z programu\n");
    scanf("%d",&*a);
}

void loadData(float *a)
{
    printf("Wprowadz dlugosc boku:\n");
    scanf("%f",&*a);
}

void loadDataCube(float *a)
{
    printf("Wprowadz dlugosc krawedzi:\n");
    scanf("%f",&*a);
}

void printData(float area)
{
    printf("Pole kwadratu: %f\n",area);
}

void printDataCube(float areaCube, float volume)
{
    printf("Pole powierzchni szescianu: %f , Objetosc: %f \n",areaCube,volume);
}
int main()
{

    int choice;
    float a;
    menu(&choice);
    while(choice != 3)
    {
        switch(choice)
        {
        case 1:
            loadData(&a);
            printData(area(a));

            break;
        case 2:
            loadDataCube(&a);
            printDataCube(cubeArea(a),volume(a));
            break;
        case 3:
            return(0);
        default:
            printf("zly numer zadania");
        }
        menu(&choice);
    }
    return 0;
}
