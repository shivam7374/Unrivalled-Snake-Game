#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int gameover =0; 
int width=20,heigth=20;
int x=(width/2),y=(heigth/2);
int score=0;	
int fx=(rand() % width),fy=(rand() % heigth);
int tailX[100], tailY[100];
int nTail;


void draw()
{	system("cls");
	cout<<"press any 5 to exit "<<endl;
	for(int i=0;i<width;i++)
		{
			for(int j=0;j<heigth;j++)
				{
					if(i==0 || i==(width-1) || j==0 || j==(heigth-1))
					{
						cout<<"#";
					}
					else if (i==x && j==y)
					{
						cout<<"X";
					}

					else if (i==fx && j==fy)
					{
						cout<<"o";
					}
					else
					{
						bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == i && tailY[k] == j)
                    {
                        cout << "x";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
					}
					
				}
				cout<<endl;
		}
		cout<<endl<<"SCORE="<<score<<endl;
}
void input()
{
	if(kbhit())
	{
	switch(getch())
	{
		case '8':
		x--;
		break;

		case '2':
		x++;
		break;
		
		case '6':
		y++;
		break;
		
		case '4':
		y--;
		break;
		
		case '5':
		gameover=1;
		break;
	}
}
	int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
	
	if((x==width) || (y==heigth) || (x==0) || (y==0))
	{
		gameover=1;
	}

	// if (x >= width) x = 0; else if (x < 0) x = width - 1;
    // if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
	
	if(x==fx && y==fy)
	{
		score=score+10;
		fx=rand() % (width-1);
		fy=rand() % (heigth-1);
		nTail++;
	}
}
int main()
{	cout<<"press 5 to exit ";

	while(!gameover)
	{	
		draw();
		input();
	}
	cout<<"gameover";
	return 0;
}