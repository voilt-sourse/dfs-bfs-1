/*
小明给你两个容器，分别能装下A升水和B升水，并且可以进行以下操作
FILL(i)        将第i个容器从水龙头里装满(1 ≤ i ≤ 2);
DROP(i)        将第i个容器抽干
POUR(i,j)      将第i个容器里的水倒入第j个容器（这次操作结束后产生两种结果，一是第j个容器倒满并且第i个容器依旧有剩余，二是第i个容器里的水全部倒入j中，第i个容器为空）
现在要求你写一个程序，来找出能使其中任何一个容器里的水恰好有C升，找出最少操作数并给出操作过程
Input
有且只有一行，包含3个数A,B,C（1<=A,B<=100,C<=max(A,B)）
  
Output
第一行包含一个数表示最小操作数K
随后K行每行给出一次具体操作，如果有多种答案符合最小操作数，输出他们中的任意一种操作过程，如果你不能使两个容器中的任意一个满足恰好C升的话，输出“impossible”
Sample Input
3 5 4
Sample Output
6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)

题解：
  一共6种情况，bfs
*/


 ```
 #include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5+100;
int A,B,C;
int head,tail;
int book[120][120];
int as[120][120][120];//a-iL,b-jL,k多少操作
struct node
{
	int x,y;
} a,b;
void print(int i)
{
	if(i==0)cout<<"FILL(1)"<<endl;
	if(i==1)cout<<"FILL(2)"<<endl;
	if(i==2)cout<<"POUR(1,2)"<<endl;
	if(i==3)cout<<"POUR(2,1)"<<endl;
	if(i==4)cout<<"DROP(1)"<<endl;
	if(i==5)cout<<"DROP(2)"<<endl;
}
int main()
{
	memset(book,-1,sizeof book);
	cin>>A>>B>>C;
	if(A<C&&B<C)
	{
		cout<<"impossible"<<endl;
		return 0;
	}
	queue<node> que;
	book[0][0]=0;
	a.x=0;
	a.y=0;
	bool flag =false;
	que.push(a);
	while(!que.empty())
	{
		//cout<<"*";
		a=que.front();
		que.pop();
		if(a.x==C||a.y==C)
		{
			//cout<<"--";
			flag=true;
			break;
		}
		int i;
		for(i=0; i<6; i++)
		{
			if(i==0)//把a倒满
			{
				b.x=A;
				b.y=a.y;
			}
			if(i==1)//把b倒满
			{
				b.x=a.x;
				b.y=B;
			}
			if(i==2)//把a倒入b
			{
				b.y=a.x+a.y;
				if(b.y>=B)
				{
					b.x=b.y-B;
					b.y=B;

				}
				else b.x=0;
			}
			if(i==3)//把b倒入a
			{
				b.x=a.y+a.x;
				if(b.x>=A)
				{
					b.y=b.x-A;
					b.x=A;
				}
				else
					b.y=0;
			}
			if(i==4)//把a倒掉
			{
				b.x=0;
				b.y=a.y;
			}
			if(i==5)//把b倒掉
			{
				b.x=a.x;
				b.y=0;
			}

			if(book[b.x][b.y]==-1)
			{
				book[b.x][b.y]=book[a.x][a.y]+1;
				for(int j=1; j<=book[a.x][a.y]; j++)
				{
					as[b.x][b.y][j] = as[a.x][a.y][j];
				}
				as[b.x][b.y][book[a.x][a.y]+1] = i;
				que.push(b);
				//cout<<"@"<<endl;
			}
		}
	}

	if(flag)
	{
		cout<<book[a.x][a.y]<<endl;
		for(int i=1; i<=book[a.x][a.y]; i++)
		{
			print(as[a.x][a.y][i]);
		}
	}
	else cout<<"impossible"<<endl;;
	return 0;
}
```
 
 
