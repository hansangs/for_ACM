#include <iostream>
#include <vector>
using namespace std;

//(y,x)= 새로채워질 칸들의 상대 좌표의 목록
const int coverType[4][3][2]={
	{{0,0},{1,0},{0,1}}, 
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(vector< vector<int> >& board, int y, int x, int type, int delta)
{	
	bool ok=true;
	for(int i=0; i<3; i++)
	{
		const int ny = y+coverType[type][i][0];
		const int nx = x+coverType[type][i][1];

		if( ny<0 || ny>= board.size() || nx < 0 || nx >=board[0].size())
			ok=false;
		else if((board[ny][nx] += delta)>1)
			ok = false;
	}

	return ok;
}

int cover(vector<vector<int> >& board)
{
	int y=-1, x=-1;
	//가장 위 가장 왼쪽에 있는 흰블록을 발견하는 코드
	for(int i=0; i<board.size();i++){
		for(int j=0; j<board[i].size(); j++)
		{	
			//cout<<board[i][j]<<" ";
			if(board[i][j]==0)
			{
				y=i;
				x=j;
				break;
			}
		}

		if(y!=-1)break;
	}

			if(y==-1) return 1; // 흰블록이 없을시 1리턴
			int ret=0;

			//총 4개의 타입
			for(int type=0; type < 4; ++type)
			{	
				if(set(board,y,x,type,1)) //참일시
					ret +=cover(board); //재귀호출
				set(board,y,x,type,-1); //거짓일시 걷어내기
			}

			return ret;
}

int main(void)
{	
	int test;
	int h,w;
	int result[30];
	char temp;
	vector<vector<int> > board;
	cin>>test;
	for(int t=0; t<test; t++)
	{
		cin >> h >> w;
		board.assign(h,vector<int>(w,0));

		for(int i=0; i<h;i++)
			for(int j=0; j<w; j++)
			{
				cin >> temp;
				if(temp=='#')
					board[i][j]=1;
			}

			result[t]=cover(board);
	}

	for(int t=0; t<test; t++)
		cout << result[t] <<endl;
	
}





