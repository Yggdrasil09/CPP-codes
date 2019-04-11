#include<iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int gridx=100,gridy=42;
bool StartLoop=true;

using namespace std;

int main()
{
    int i,j;
    int grid[gridy][gridx];
    for(i=0;i<gridy;i++)
    {
        for(j=0;j<gridx;j++)
        {
            grid[i][j]=0;
        }
    }
    grid[gridy/2][gridx/2]=600;
    while(StartLoop)
    {
        int check=0;
        system("clear");
        for(i=0;i<gridx;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        for(i=0;i<gridy;i++)
        {
            for(j=0;j<gridx;j++)
            {
                if(j==0||j==gridx-1)
                {
                    cout<<"|";
                }
                else if(grid[i][j]==0)
                {
                    cout<<" ";
                }
                else
                {
                    cout<<grid[i][j];
                    if(grid[i][j]>=4)
                    {
                        grid[i][j]-=4;
                        grid[i][j-1]+=1;
                        grid[i][j+1]+=1;
                        grid[i-1][j]+=1;
                        grid[i+1][j]+=1;
                        check=1;
                    }
                }
            }
            cout<<"\n";
        }
        for(i=0;i<gridx;i++)
        {
            cout<<"-";
        }
        cout<<"\n";
        if(check==0)
        {
            StartLoop=false;
        }
    }
}