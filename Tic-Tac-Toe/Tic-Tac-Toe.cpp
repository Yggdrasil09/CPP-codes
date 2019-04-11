#include<iostream>
#include<string>

using namespace std;
void print(char x[]);
int Winner(char x[]);

int main()
{
    cout<<"\t\tEnter the name of Player 1: ";
    string player1,player2;
    cin>>player1;
    cout<<"\t\tEnter the name of Player 2: ";
    cin>>player2;
    cout<<"\t\tMark of Player1 is \'X\'\n";
    cout<<"\t\tMark of Player2 is \'O\'\n\n\n\n";
    char x[9];
    char z[9];
    int y;
    for(y=0;y<9;y++)
    {
        x[y]=49+y;
        z[y]='A';
    }
    int g=0;
    int check=0;
    int pos;
    print(x);
    int count=0;
    while(g==0&&count<9)
    {
        count++;
        if(check==0)
        {
            label:
            cout<<"\t\t"<<"Player1's Turn:\n\n"<<"\t\tEnter the position of the mark: ";
            std::cin>>pos;
            if(z[pos-1]=='A')
            {
                x[pos-1]='X';
                z[pos-1]='B';
            }
            else
            {
                cout<<"Invalid Position\n";
                goto label;
            }
            check=1;
            cout << "\033[H\033[2J";  //To clear the screen
            print(x);
        }
        else
        {
            label1:
            cout<<"\t\t"<<"Player2's Turn:\n\n"<<"\t\tEnter the position of the mark: ";
            std::cin>>pos;
            if(z[pos-1]=='A')
            {
                x[pos-1]='O';
                z[pos-1]='B';
            }
            else
            {
                cout<<"Invalid Position\n";
                goto label1;
            }
            check=0;
            cout << "\033[H\033[2J";
            print(x);
        }
        g=Winner(x);
    }
    if(g==1)
    {
        cout<<"\t\t"<<player1<<" is the Winner of the Game"<<"\n\t\tCongratulations!!!";
        cout<<"\n\n\t\t"<<player2<<" ,Better Luck next Time!\n";    
    }
    else if(g==2)
    {
        cout<<"\t\t"<<player2<<" is the Winner of the Game"<<"\n\t\tCongratulations!!!";
        cout<<"\n\n\t\t"<<player1<<" ,Better Luck next Time!\n";
    }
    else
    {
        cout<<"\t\tIt's A Tie!!!\n";
    }
}

void print(char x[9])
{
    std::cout<<"\t\t"<<"  "<<x[0]<<"  |  "<<x[1]<<"  | "<<x[2]<<"\n";
    std::cout<<"\t\t"<<"-----|-----|-----\n";
    std::cout<<"\t\t"<<"  "<<x[3]<<"  |  "<<x[4]<<"  | "<<x[5]<<"\n";
    std::cout<<"\t\t"<<"-----|-----|-----\n";
    std::cout<<"\t\t"<<"  "<<x[6]<<"  |  "<<x[7]<<"  | "<<x[8]<<"\n\n\n\n";
}

int Winner(char x[9])
{
    int y;
    for(y=0;y<9;y+=3)
    {
        if(x[y]==x[y+1]&&x[y+1]==x[y+2])
        {
            if(x[y]=='X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    for(y=0;y<3;y++)
    {
        if(x[y]==x[y+3]&&x[y+3]==x[y+6])
        {
            if(x[y]=='X')
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    if(x[0]==x[4]&&x[4]==x[8])
    {
        if(x[y]=='X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if(x[2]==x[4]&&x[4]==x[6])
    {
        if(x[y]=='X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    return 0;
}
