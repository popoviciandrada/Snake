#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool pierdut;
const int lungime=20;
const int latime=20;
int dx,dy,fructdx,fructdy,scor,coadaX[100],coadaY[100],coadaLG,specialaX,specialaY,aparSpeciala,capcanaX,capcanaY,zidX,zidY;
int zid1X,zid2X,zid3X,zid4X,zid5X;
int zid1Y,zid2Y,zid3Y,zid4Y,zid5Y;
int vecScor[1000],nrjoc;
int dx1,dy1,coadaX1[100],coadaY1[100],coadaLG1;
enum directie {STOP=0,STANGA,DREAPTA,SUS,JOS};
directie dir;
void Initializare();
void Harta4();
void Harta3();
void Harta2();
void Harta1();
void Intrare();
void LogicaTrece();
void LogicaNuTrece();
void Intrare1();
void LogicaTreceMP();
void Initializare1();
int scormax(int x[],int n);
int main()
{    int k,l,mp,sp,cnrjoc=0;

    cout<<"1.Start";
    cout<<endl;
    cout<<"2.Scor maxim";
    cout<<endl;
    cout<<"Vrei sa inchizi jocul? Introdu 'x' ";
    cout<<endl;
    cin>>sp;
    if(sp==1)
    {
        cout<<"1.Single player";
    cout<<endl;
    cout<<"2.Multiplayer";
    cout<<endl;
    cin>>mp;

    Initializare();
    if(mp==1)
    {
    cout<<"1.Harta normala ";
    cout<<endl;
    cout<<"2.Harta powerup";
    cout<<endl;
    cout<<"3.Harta cu zid";
    cout<<endl;
    cin>>l;
    cout<<"1.Modul in care sarpele nu trece prin perete";
    cout<<endl;
    cout<<"2.Modul in care sarpele trece prin perete ";
    cout<<endl;
    cin>>k;
        while(!pierdut)
    {
         if(l==1)
        Harta1();
        else if(l==2)
            Harta2();
        else if(l==3)
            Harta4();
        Intrare();
        if(k==1)
        LogicaNuTrece();
        else if (k==2)
        LogicaTrece();
        Sleep(200);
        vecScor[nrjoc++]=scor;
    }
    }
    else if (mp==2)
    {
        Initializare1();
    while(!pierdut)
    {   cnrjoc++;
        Harta1();
        Harta3();
        Intrare();
        Intrare1();
        LogicaTreceMP();
        LogicaTrece();
        Sleep(200);
    }
    }
    }
    else if(sp==2)
    {
        int a=scormax(vecScor,cnrjoc);
        cout<<a;
    }


    return 0;
}
void Initializare ()
{
    pierdut=false;
    dx=latime/2;
    dy=lungime/2;
    dx1=latime/4;
    dy1=lungime/4;
    fructdx=rand()%latime;
    fructdy=rand()%lungime;
    specialaX=rand()%latime;
    specialaY=rand()%lungime;
    zidX=rand()%latime;
    zidY=rand()%lungime;
    zid1X=rand()%latime;
    zid1Y=rand()%lungime;
    zid2X=rand()%latime;
    zid2Y=rand()%lungime;
    zid3X=rand()%latime;
    zid3Y=rand()%lungime;
    zid4X=rand()%latime;
    zid4Y=rand()%lungime;
    zid5X=rand()%latime;
    zid5Y=rand()%lungime;
    scor=0;
}
void Initializare1 ()
{
    dx1=(latime/2)+3;;
    dy1=(lungime/2)+3;
    fructdx=rand()%latime;
    fructdy=rand()%lungime;
    specialaX=rand()%latime;
    specialaY=rand()%lungime;
    scor=0;
}
void Harta2 ()
{
    system("cls");
    aparSpeciala=0;
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
                cout<<"O";

            else if(i==fructdy && j==fructdx)
            {
                cout<<"1";
                aparSpeciala++;
            }

            else if(i==specialaY && j==specialaX && aparSpeciala%5==0)
            {
                cout<<"2";

            }
            else if(i==capcanaY && j==capcanaX && aparSpeciala%3==0)
            {
                cout<<"3";
            }



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
           case 'x':
            pierdut=true;
            break;
       }
   }


}
void LogicaNuTrece ()
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
 if(dx==specialaX && dy==specialaY)
    {
        coadaLG--;
        scor+=2;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
        if(dx==capcanaX && dy==capcanaY)
    {
        coadaLG+=2;
        scor=scor-3;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
}
void LogicaTrece ()
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

  if(dx >= latime) dx=0;
  else if (dx<0) dx=latime-1;
  if(dy >= lungime) dy=0;
  else if (dy<0) dy=lungime-1;

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
void Harta3 ()
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

            if(i==dy1 && j==dx1)
                cout<<"@";

            else if(i==fructdy && j==fructdx)
            {
                cout<<"1";

            }



            else
            {    bool marireCoada1=false;
                for(int k=0;k<coadaLG1;k++)
                {
                    if(coadaX1[k]==j &&  coadaY1[k]==i)
                    {
                        cout<<"s";
                        marireCoada1=true;

                    }

                }
                if(!marireCoada1)
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
}

void Harta1 ()
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
                cout<<"O";

            else if(i==fructdy && j==fructdx)
            {
                cout<<"1";

            }



            else
            {    bool marireCoada=false;
                for(int k=0;k<coadaLG;k++)
                {
                    if(coadaX[k]==j &&  coadaY[k]==i)
                    {
                        cout<<"o";
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


    cout<<endl;
}
void LogicaTreceMP ()
{
  int Xanterior1=coadaX1[0];
  int Yanterior1=coadaY1[0];
  int X2anterior1,Y2anterior1;
  coadaX1[0]=dx1;
  coadaY1[0]=dy1;
  for(int i=1;i<coadaLG1;i++)
  {
      X2anterior1=coadaX1[i];
      Y2anterior1=coadaY1[i];
      coadaX1[i]=Xanterior1;
      coadaY1[i]=Yanterior1;
      Xanterior1=X2anterior1;
      Yanterior1=Y2anterior1;
  }
  switch(dir)
  {
      case SUS:
          dy1--;
          break;
      case JOS:
          dy1++;
          break;
      case STANGA:
          dx1--;
          break;
      case DREAPTA:
          dx1++;
          break;
      default:
        break;

  }
    if(dx1 >= latime) dx1=0;
  else if (dx1<0) dx1=latime-1;
  if(dy1 >= lungime) dy1=0;
  else if (dy1<0) dy1=lungime-1;
  for(int i=0;i<coadaLG1;i++)
    if(coadaX1[i]==dx1 && coadaY1[i]==dy1)
     pierdut = true;
 if(dx1==fructdx && dy1==fructdy)
  {
      coadaLG1++;
      scor++;
      fructdx=rand()%latime;
      fructdy=rand()%lungime;
  }

  if(dx1==specialaX && dy1==specialaY)
    {
        coadaLG1--;
        scor+=2;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
    if(dx1==capcanaX && dy1==capcanaY)
    {
        coadaLG1+=2;
        scor=scor-3;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }



}
void Intrare1()
{
   if(_kbhit())
   {
       switch(_getch())
       {
           case 'i':
            dir=SUS;
            break;
           case 'k':
            dir=JOS;
            break;
           case 'j':
            dir=STANGA;
            break;
           case 'l':
            dir=DREAPTA;
            break;
           case 'x':
            pierdut=true;
            break;
       }
   }


}
void Harta4 ()
{
    system("cls");
    aparSpeciala=0;
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
                cout<<"O";

            else if(i==fructdy && j==fructdx)
            {
                cout<<"1";
                aparSpeciala++;
            }

            else if(i==specialaY && j==specialaX && aparSpeciala%5==0)
            {
                cout<<"2";

            }
            else if(i==capcanaY && j==capcanaX && aparSpeciala%3==0)
            {
                cout<<"3";
            }
            else if(i==zidY && j==zidX && aparSpeciala%2==0)
            {
                    cout<<"|";

            }
            else if(i==zid1Y && j==zid1X && aparSpeciala%2==0)
            {
                    cout<<"|";

            }
            else if(i==zid2Y && j==zid2X && aparSpeciala%2==0)
            {
                    cout<<"|";

            }
            else if(i==zid3Y && j==zid3X && aparSpeciala%2==0)
            {
                    cout<<"|";

            }
            else if(i==zid4Y && j==zid4X && aparSpeciala%2==0)
            {
                    cout<<"|";

            }
            else if(i==zid5Y && j==zid5X && aparSpeciala%2==0)
            {
                    cout<<"|";

            }




            else
            {    bool marireCoada=false;
                for(int k=0;k<coadaLG;k++)
                {
                    if(coadaX[k]==j &&  coadaY[k]==i)
                    {
                        cout<<"o";
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
int scormax(int x[],int n)
{    int aux;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(x[i]<x[j])
    {
        aux=x[i];
        x[i]=x[j];
        x[j]=aux;

    }
    return x[0];
}
void LogicaNuTrece ()
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
 if(dx==specialaX && dy==specialaY)
    {
        coadaLG--;
        scor+=2;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
        if(dx==capcanaX && dy==capcanaY)
    {
        coadaLG+=2;
        scor=scor-3;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
}
void LogicaTrecePU ()
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

  if(dx >= latime) dx=0;
  else if (dx<0) dx=latime-1;
  if(dy >= lungime) dy=0;
  else if (dy<0) dy=lungime-1;

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
  if(dx==specialaX && dy==specialaY)
    {
        coadaLG--;
        scor+=2;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }
    if(dx==capcanaX && dy==capcanaY)
    {
        coadaLG+=2;
        scor=scor-3;
        specialaX=rand()%latime;
        specialaY=rand()%lungime;
    }

}
