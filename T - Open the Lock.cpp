/*

题目：https://vjudge.net/contest/438445#problem/T
题解：开个四维数组表示到XXXX走了多少步
bfs枚举每一次+1，-1能到达的XXXX
*/
```
#include <bits/stdc++.h>
#include <queue>
using namespace std;
string s1,s2;
int book[10][10][10][10];

struct node
{
	string num;
	int step;
};

int bfs()
{

	node first,next;
	first.num=s1;
	first.step=0;
	book[s1[0]-'0'][s1[1]-'0'][s1[2]-'0'][s1[3]-'0']=1;
	queue<node> que;
	que.push(first);
	while(!que.empty())
	{
		first=que.front();
		que.pop();
		if(first.num==s2)
			return first.step;
		int i;
		for(i=0; i<4; i++)
		{

			next.num=first.num;
			if(next.num[i]=='9')
				next.num[i]='1';
			else
				next.num[i]+=1;
			next.step=first.step+1;
			if(!book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0'])
			{
				book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0']=1;
				que.push(next);
			}
			next.num=first.num;
			if(next.num[i]=='1')
				next.num[i]='9';
			else
				next.num[i]-=1;
			next.step=first.step+1;
			if(!book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0'])
			{
				book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0']=1;
				que.push(next);
			}
			if(i<3)
			{
				next.num=first.num;
				next.num[i]=first.num[i+1];
				next.num[i+1]=first.num[i];
				next.step=first.step+1;
				if(!book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0'])
				{
					book[next.num[0]-'0'][next.num[1]-'0'][next.num[2]-'0'][next.num[3]-'0']=1;
					que.push(next);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	cin>>t;
	{
		while(t--)
		{
			cin>>s1>>s2;
			int ans=bfs();
			cout<<ans<<endl;
			memset(book,0,sizeof(book));
		}
		
	}
	return 0;
}
```
