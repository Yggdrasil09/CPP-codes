#include<iostream>
#include <unistd.h>
#include<string>
#include <termios.h>
#include <fcntl.h>

using namespace std;

void setup();

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

int x=100,y=20,fruitx,fruity;
int dir=0,score=0;
bool Gamestart;
int posx,posy;
string snake;

int main()
{
    setup();
    while(Gamestart)
    {
        system("clear");
        int i,j;
        for(i=0;i<x;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        for(i=0;i<y;i++)
        {
            for(j=0;j<x;j++)
            {
                if(j==0||j==99)
                {
                    cout<<"|";
                }
                else if(j==posx&&i==posy)
                {
                    cout<<snake;
                }
                else if(j==fruitx&&i==fruity)
                {
                    cout<<"F";
                }
                else
                {
                    cout<<" ";
                }
                if(posx==fruitx&&posy==fruity)
                {
                    score+=10;
                    fruitx=rand()%x;
                    fruity=rand()%y;
                    snake+='o';
                }
                if(posx==x||posx==0||posy==0||posy==y)
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
        char inpt;
        if(kbhit())
        {
            cin>>inpt;
        }
        switch(dir)
            {
                case 0:posx++;
                        break;
                case 1:posy--;
                        break;
                case 2:posx--;
                        break;
                case 3:posy++;
                        break;
            }
        switch(inpt)
        {
            case 'w':
                    dir=1;
                    break;
            case 'a':
                    dir=2;
                    break;
            case 's':
                    dir=3;
                    break;
            case 'd':
                    dir=0;
                    break;
        }
        cout<<"\n";
        cout<<" SCORE: "<<score<<"\n";
        usleep(100000);                     //To sleep for a duration 
    }
}

void setup()
{
    Gamestart=true;
    fruitx=rand()%x;
    fruity=rand()%y;
    posx=x/2;
    posy=y/2;
    snake="O";
}

