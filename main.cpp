#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool pierdut;
const int lungime=20;
const int latime=20;
int dx,dy,fructdx,fructdy,scor;
void Harta();
void Initializare ();
void Logica ();
void Intrare();

int main()
{
    Harta();
    Initializare();
}
void Harta()
{
    system("cls");
    for(int i=0;i<latime+2;i++)
        cout<<"$";

      cout<<endl;
    for(int i=0;i<lungime;i++)
    {
        for(int j=0;j<latime;j++)
        {
            if(j==0)
                cout<<"$";

            if(i==dy && j==dx)
                cout<<"@";

            else if(i==fructdy && j==fructdx)
                cout<<"1";
            else
            cout<<" ";


            if(j==latime-1)
                cout<<"$";
        }
        cout<<endl;
    }
    for(int i=0;i<latime+2;i++)
        cout<<"$";

    cout<<endl;

}
void Initializare()
{
     pierdut=false;
    dx=latime/2;
    dy=lungime/2;
    fructdx=rand()%latime;
    fructdy=rand()%lungime;
    scor=0;
}
void Intrare()
{

}
void Logica()
{

}
