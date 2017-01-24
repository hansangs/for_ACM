#include <iostream>

using namespace std;
int cover(int x, int y);

int H; //높이 ; 1<=H<=20
int W; //넓이 ; 1<=W<=20
char board[22][22];

int main(void)
{
	int t; //t= 테스트케이스수 최대 30
	
	int count=0; //흰블록의 개수
	int result[30];
	
	cin>>t;

	for(int i=0; i<t;i++)
	{	
		count=0;
		
		for(int x=0;x<22;x++)
			for(int y=0;y<22;y++)
				board[x][y]='6';

		cin>>H>>W;

		for(int x=1;x<=H;x++)
			for(int y=1;y<=W;y++){
				cin>>board[x][y];

				if(board[x][y]=='.')
					count++;

			}

		if(count%3!=0)
			result[i]=0;
		else
		{	
			result[i]=cover(1,1);
		}  

	}

	for(int i=0;i<t;i++)
		cout<<result[i]<<endl;
}

int cover(int x, int y)
{
	int count=0;
	int count2=0;
	int result=0;
	
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
			if(board[i][j]=='.')
				count2++;

	if(count2==0)
		return 1;		

			if(board[y][x]=='.')
			{	
				if(board[y][x+1]=='.' && board[y+1][x]=='.') //r
				{
					board[y][x]='#';
					board[y][x+1]='#';
					board[y+1][x]='#';
					count++;

					result=result+cover(x+2,y);

					board[y][x]='.';
					board[y][x+1]='.';
					board[y+1][x]='.';
				}
				if(board[y][x+1]=='.' && board[y+1][x+1]=='.') //ㄱ
				{
					board[y][x]='#';
					board[y][x+1]='#';
					board[y+1][x+1]='#';
					count++;

					result=result+cover(x+2,y);

					board[y][x]='.';
					board[y][x+1]='.';
					board[y+1][x+1]='.';
				}
				if(board[y+1][x]=='.' && board[y+1][x+1]=='.') //ㄴ
				{
					board[y][x]='#';
					board[y+1][x]='#';
					board[y+1][x+1]='#';
					count++;

					result=result+cover(x+1,y);

					board[y][x]='.';
					board[y+1][x]='.';
					board[y+1][x+1]='.';
				}
				if(board[y+1][x]=='.' && board[y+1][x-1]=='.')//J
				{
					board[y][x]='#';
					board[y+1][x]='#';
					board[y+1][x-1]='#';
					count++;

					result=result+cover(x+1,y);

					board[y][x]='.';
					board[y+1][x]='.';
					board[y+1][x-1]='.';

				}
				if(count==0)
					return 0;
			
			
			}
			else if(board[y][x]=='6'&&y!=H)
				result=result+cover(1,y+1);
			else if(y==H)
				return 0;
			else
				result=result+cover(x+1,y);



		return result;
}





