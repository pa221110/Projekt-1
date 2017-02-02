
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/********   FUNKCJE   ***************************/
void plansza();
void pole(int x,int y);
void czysc();
void start();
void move(int g);
void rezultat(int win);
void rank();
int rozp();
int spr();
int gracze();
/************************************************/
int tab[3][3];
int wyb, win, g, gstat=0, pkt_g1=0, pkt_g2=0, tmp;
string gracz1, gracz2;
float v=1.5;
/************************************************/
main()
{
      while(1)
      {
          win=0;
          start();
          cout<<"1. Nowa gra\n2. Wprowadz graczy\n0. Koniec\n\n";
          rank();
          cout<<"\n\nTwoj wybor: ";cin>>wyb;
          switch(wyb){
                     case 1:
                          if(gstat!=0)
                          {
                                      start();
                                      g=rozp();
                                      while(1)
                                      {
                                              plansza();
                                              move(g);
                                              plansza();
                                              win=spr();
                                              if(win!=0)break;
                                              g++;
                                      }
                          rezultat(win);
                          getch();
                          break;
                          }
                          else
                          {
                              cout<<"Najpierw prowadz graczy";
                              getch();
                              break;
                          }
                     case 2:
                          gstat=gracze();
                          break;
                     case 0: return 0;
                     default : 
                             cout<<"Brak opcji...";
                             getch();
                     }
      czysc();
      }
}
/**************  �r�d�a  *****************************/
int rozp()
{
    cout<<"Kto rozpoczyna?\n1. "<<gracz1<<"\n2. "<<gracz2<<"\n\nTwoj wybor:";
    cin>>g;
    return g;
}
//**************
//**************
int gracze()
{
    start();
    cout<<"Podaj nazwe gracza X\n\n";
    cin>>gracz1;
    start();
    cout<<"Podaj nazwe gracza O\n\n";
    cin>>gracz2;
    return 1;
}
//**************
void rezultat(int win)
{
     if(win==1)
     {
               if(g%2)
               {
                      cout<<"\nWygrywa gracz: "<<gracz1;
                      pkt_g1++;
               }
               else
               {
                      cout<<"\nWygrywa gracz: "<<gracz2;
                      pkt_g2++;
               }
     }
     else cout<<"Remis";
}
//**************
void move(int g)
{
     int m,x,y,bl;
     do{
     if(g%2)cout<<"\n"<<gracz1<<" wybierz pole: ";
     else cout<<"\n"<<gracz2<<" wybierz pole: ";
     cin>>m;
     if(m>9||m<1)
     {
                 cout<<"\nBrak podanego pola na plaszy u�ytkowniku...";
                 getch();
                 bl=0;
                 plansza();
     }
     else
     {
     /*A*/if(m<4&&m>0){y=(m-1);x=2;bl=1;}
     /*B*/if(m<7&&m>3){y=(m-4);x=1;bl=1;}
     /*C*/if(m<10&&m>6){y=(m-7);x=0;bl=1;}
     if(tab[x][y]!=0)
     {
                     cout<<"\nPole zajete u�ytkowniku...";
                     getch();
                     bl=0;
                     plansza();
     }
     }
     }while(bl!=1);
     if(g%2) tab[x][y]=1;
     else tab[x][y]=2;
}
//**************
void pole(int x,int y){
     if(tab[x][y]==0)cout<<" ";
     if(tab[x][y]==1)cout<<"X";
     if(tab[x][y]==2)cout<<"O";}
//**************
int spr(){
for(int c=0;c<3;c++){
if(((tab[c][0]==1)&&(tab[c][1]==1)&&(tab[c][2]==1))||((tab[c][0]==2)&&(tab[c][1]==2)&&(tab[c][2]==2)))return 1;
if(((tab[0][c]==1)&&(tab[1][c]==1)&&(tab[2][c]==1))||((tab[0][c]==2)&&(tab[1][c]==2)&&(tab[2][c]==2)))return 1;}
if(((tab[0][0]==1)&&(tab[1][1]==1)&&(tab[2][2]==1))||((tab[0][0]==2)&&(tab[1][1]==2)&&(tab[2][2]==2)))return 1;
else{
if(((tab[0][2]==1)&&(tab[1][1]==1)&&(tab[2][0]==1))||((tab[0][2]==2)&&(tab[1][1]==2)&&(tab[2][0]==2)))return 1;
tmp=9;for(int c=0;c<3;c++){for(int d=0;d<3;d++){if((tab[c][d]==1)||(tab[c][d]==2))tmp--;}}if(tmp==0)return 2;
else return 0;}}
//**************
void plansza()
{
     start();
     cout<<"\n\n";
     for(int x=0;x<3;x++)
     {
             cout<<"\t";
             for(int y=0;y<3;y++)
             {
                     //cout<<tab[x][y];
                     pole(x,y);
                     if(y<2)cout<<"|";
             }
             cout<<"\n";
     if(x<2)cout<<"\t-----\n";
     }
     cout<<"\n\n";
     rank();
}
//**************
void rank(){cout<<"\nAktualny ranking:\n\n"<<gracz1<<"\t- "<<pkt_g1<<" pkt\n"<<gracz2<<"\t- "<<pkt_g2<<" pkt\n";}
void start(){system("cls");cout<<"   KOLKO I KRZYZYK v"<<v<<"  \n-------------------------\n";}
void czysc(){for(int a=0;a<3;a++)for(int b=0;b<3;b++)tab[a][b]=0;}
//**************

