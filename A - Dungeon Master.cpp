/*
XHK被困在一个三维的网吧中,现在要寻找最短路径逃生！ 空间由立方体单位构成 你每次向上下前后左右移动一个单位需要一分钟
你不能对角线移动并且四周封闭 是否存在逃出生天的可能性？如果存在，则需要多少时间？
Input - 输入
　　输入第一行是一个数表示空间的数量。 　　每个空间的描述的第一行为L，R和C（皆不超过30）。 　　
  L表示空间的高度。 R和C分别表示每层空间的行与列的大小。 　　随后L层地牢，每层R行，每行C个字符。 　
  每个字符表示空间的一个单元。'#'表示不可通过单元，'.'表示空白单元。你的起始位置在'S'，出口为'E'。 
  每层空间后都有一个空行。L，R和C均为0时输入结束。
Output - 输出
　　每个空间对应一行输出。
　　如果可以逃生，则输出如下
Escaped in x minute(s).
　　x为最短脱离时间。

　　如果无法逃生，则输出如下
Trapped!
Sample Input - 输入样例
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0
Sample Output - 输出样例
Escaped in 11 minute(s).
Trapped!

思路：三维bfs模板，原坐标加一维，找到最小时间
 */
 ```
 #include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int L,R,C;
char s[100][100][100];
int dp[100][100][100];
int dx[8]= {1,-1,0,0,0,0};
int dy[8]= {0,0,-1,0,1,0};
int dz[8]= {0,0,0,1,0,-1};
struct node
{
	int x,y,z;
} start,end;
void bfs()
{
	queue<node> que;
	que.push(start);
	dp[start.x][start.y][start.z]=0;
	while(!que.empty())
	{
		node p=que.front();
		que.pop();
		for(int i=0; i<6; i++)
		{
			node d;
			d.x=p.x+dx[i];
			d.y=p.y+dy[i];
			d.z=p.z+dz[i];
			if(d.x>=0&&d.y>=0&&d.z>=0&&d.x<R&&d.y<C&&d.z<L&&s[d.x][d.y][d.z]=='.'&&dp[d.x][d.y][d.z]==-1)
			{
				dp[d.x][d.y][d.z]=dp[p.x][p.y][p.z]+1;
				que.push(d);
			}
		}
	}
}

int main()
{
	while(cin>>R>>C>>L)
	{
		if(R==C&&R==L&&L==C&&R==0)
		break;
		memset(dp,-1,sizeof dp);
		for(int i=0; i<R; i++)
		{
			for(int j=0; j<C; j++)
			{
				for(int k=0; k<L; k++)
				{
					cin>>s[i][j][k];
					if(s[i][j][k]=='S')
					{
						start.x=i;
						start.y=j;
						start.z=k;
					}
					if(s[i][j][k]=='E')
					{
						end.x=i;
						end.y=j;
						end.z=k;
						s[i][j][k]='.';
					}
				}
			}
		}
		bfs();
		int ans=dp[end.x][end.y][end.z];
		if(ans==-1) 
			cout<<"Trapped!"<<endl;
		else 
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
	}
}
```
 
 
