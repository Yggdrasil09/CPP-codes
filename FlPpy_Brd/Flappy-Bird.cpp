#include<iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

using namespace std;

int kbhit(void);

bool Gamestart=true;
int x=100,y=25;
int posx=20,posy=12;
int score=0;

float blocks[7][2];

int main()
{
    int z;
    for(z=0;z<7;z++)
    {
        blocks[z][0]=rand()%70;
        blocks[z][1]=15-rand()%8;
    }
    int gap=rand()%5;
    while(Gamestart)
    {
        int g=0;
        system("clear");
        int i,j;
        for(i=0;i<x;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        for(i=0;i<=y;i++)
        {
            for(j=0;j<=x;j++)
            {
                int check=0;
                for(z=0;z<7;z++)
                {
                    if(x-blocks[z][0]==j&&(i<blocks[z][1]-gap||i>blocks[z][1]+gap)&&check==0)
                    {
                        cout<<"0";
                        check=1;
                    }
                    if(x-blocks[z][0]==posx&&(posy<blocks[z][1]-gap||posy>blocks[z][1]+gap))
                    {
                        Gamestart=false;
                    }
                    if((posy>blocks[z][1]-gap||posy<blocks[z][1]+gap)&&posx==blocks[z][0]&&g==0)
                    {
                        score+=10;
                        g=1;
                    }
                }
                if(i==posy&&j==posx)
                {
                    cout<<"B";   
                }
                else if(j==0||j==x)
                {
                    cout<<"|";
                }
                else if(check==0)
                {
                    cout<<" ";
                }
                if(posy==y||posy==0)
                {
                    Gamestart=false;
                }
            }
            cout<<"\n";
        }
        for(i=0;i<x;i++)
        {
            cout<<"-";
        }
        for(i=0;i<7;i++)
        {
            blocks[i][0]+=1;
            if(blocks[i][0]==x)
            {
                blocks[i][0]=rand()%30;
            }
        }
        cout<<"\n";
        cout<<"SCORE: "<<score<<"\n";
        char hit;
        if(kbhit())
        {
            cin>>hit;
        }
        if(hit=='w')
        {
            posy-=(rand()%3)+7;
        }
        hit='a';
        posy++;

        usleep(155000);
    }
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}