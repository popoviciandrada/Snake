#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool pierdut;
const int lungime=20;
const int latime=20;
int dx,dy,fructdx,fructdy,scor,coadaX[100],coadaY[100],coadaLG,specialaX,specialaY,aparSpeciala;
enum directie {STOP=0,STANGA,DREAPTA,SUS,JOS};
directie dir;
void Initializare();
void Harta();
void Intrare();
void LogicaTrece();
void LogicaNuTrece();
int main()
{
     int k;
    cout<<"Pentru modul in care sarpele trece prin perete introdu 1";
    cout<<endl;
    cout<<"Pentru modul in care sarpele nu trece prin perete introdu 2";
    cout<<endl;
    cin>>k;
    Initializare();
    while(!pierdut)
    {
        Harta();
        Intrare();
        if (k==2)
        LogicaNuTrece();
        Sleep(200);
    }
    return 0;
}

void Initializare ()
{
    pierdut=false;
    dx=latime/2;
    dy=lungime/2;
    fructdx=rand()%latime;
    fructdy=rand()%lungime;
    scor=0;
}
void Harta ()
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
            {    bool marireCoada=false;
                for(int k=0;k<coadaLG;k++)
                {
                    if(coadaX[k]==j &&  coadaY[k]==i)
                    {
                        cout<<"s";
                        marireCoada=true;

                    }

                }
                if(!marireCoada)
                  cout<<" ";
            }


            if(j==latime-1)
                cout<<"$";
        }
        cout<<endl;
    }
    for(int i=0;i<latime+2;i++)
        cout<<"$";

    cout<<endl;

    cout<<"Scor:"<<scor<<endl;
}
void Intrare()
{
   if(_kbhit())
   {
       switch(_getch())
       {
           case 'w':
            dir=SUS;
            break;
           case 's':
            dir=JOS;
            break;
           case 'a':
            dir=STANGA;
            break;
           case 'd':
            dir=DREAPTA;
            break;
           case 'k':
            pierdut=true;
            break;
       }
   }


}
void LogicaNuTrece()
{ int Xanterior=coadaX[0];
  int Yanterior=coadaY[0];
  int X2anterior,Y2anterior;
  coadaX[0]=dx;
  coadaY[0]=dy;
  for(int i=1;i<coadaLG;i++)
  {
      X2anterior=coadaX[i];
      Y2anterior=coadaY[i];
      coadaX[i]=Xanterior;
      coadaY[i]=Yanterior;
      Xanterior=X2anterior;
      Yanterior=Y2anterior;
  }
  switch(dir)
  {
      case SUS:
          dy--;
          break;
      case JOS:
          dy++;
          break;
      case STANGA:
          dx--;
          break;
      case DREAPTA:
          dx++;
          break;
      default:
        break;

  }
 if(dx>latime || dx<0 || dy>lungime || dy<0 )
    pierdut=true;

  for(int i=0;i<coadaLG;i++)
    if(coadaX[i]==dx && coadaY[i]==dy)
     pierdut = true;
  if(dx==fructdx && dy==fructdy)
  {
      coadaLG++;
      scor++;
      fructdx=rand()%latime;
      fructdy=rand()%lungime;
  }

}
