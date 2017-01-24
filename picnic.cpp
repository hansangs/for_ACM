#include <iostream>

using namespace std;


int makefriends(int n, int m);

int friends[45][2];
int ox[10];

int main(void)
{	
	
	int test; //test 케이스 수
	int n; //학생수
	int m; //친구 쌍의 수
	int total[50];

	cin>>test;
	
	for(int i=0;i<test;i++)
	{	
		total[i]=0;
		cin>>n>>m;

		

		for(int j=0; j<m; j++)
			cin>>friends[j][0]>>friends[j][1];

		for(int y=m; y>0;y--)
		{
			for(int j=0; j<10; j++)
				ox[j]=0;

		}

		total[i]=total[i]+makefriends(n,m);
	}
	for(int i=0;i<test;i++)
		cout<<total[i]<<endl;


	return 0;
}

int makefriends(int n, int m)
{	
	int count=0;
	int a=0;
	
	if(m==0)
	{
		for(int i=0; i<n ;i++)
			{
				if(ox[i]==0)
				{	
					count=-1;
					break;
				}
			}
	
		if(count==0)
			{
				a++;
				return a;
			}

		return 0;
	}
	//인자 사용 안했을경우
	if(ox[friends[m-1][0]] == 0 && ox[friends[m-1][1]] == 0)
	{
			//선택o
			ox[friends[m-1][0]] = 1;
			ox[friends[m-1][1]] = 1;

			a=a+makefriends(n,m-1);
			//선택x
			ox[friends[m-1][0]] = 0;
			ox[friends[m-1][1]] = 0;

			a=a+makefriends(n,m-1);

	}//둘중 하나라도 사용했을경우
	else
	{
		a=a+makefriends(n,m-1);
	}

	

	return a;
}


