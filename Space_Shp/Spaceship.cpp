#include<iostream>
#include<string>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

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
};

bool Gamestart=true;
int x=100,y=20;
int posx=x/2,posy=18;
int alien[33][2];

int main()
{
    int z;
    for(z=0;z<33;z++)
    {
        alien[z][0]=rand()%96;
        alien[z][1]=0;
    }
    while(Gamestart)
    {
        system("clear");
        int i,j;
        for(i=0;i<=x;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        for(i=0;i<=y;i++)
        {
            for(j=0;j<=x;j++)
            {
                int check=0;
                for(z=0;z<33;z++)
                {
                    if(i==alien[z][1]&&alien[z][0]==j)
                    {
                        cout<<"0";
                        check=1;
                    }
                    if(alien[z][1]==posy&&alien[z][0]==posx)
                    {
                        Gamestart=false;
                    }
                }
                if(posx==j&&posy==i)
                {
                    cout<<"A";
                }
                else if(j==0||j==x)
                {
                    cout<<"|";
                }
                else if(check==0)
                {
                    cout<<" ";
                }
            }
            cout<<"\n";
        }
        for(i=0;i<=x;i++)
        {
            cout<<"-";
        }
        char inpt;
        if(kbhit())
        {
            cin>>inpt;
        }
        if(inpt=='d')
        {
            posx+=4;
        }
        else if(inpt=='a')
        {
            posx-=4;
        }
        inpt='0';
        cout<<"\n";
        for(z=0;z<33;z++)
        {
            alien[z][1]=alien[z][1]+rand()%2;
            if(alien[z][1]==y)
            {
                alien[z][1]=0;
            }
        }
        usleep(100000); 
    }
}