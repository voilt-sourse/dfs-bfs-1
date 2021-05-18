/*
还记得2020年招新赛中“编织字符串”这一道题吗？
tls在ac完以后想出了一个更有趣的问题，具体是这样的：
给定两个长度均为len的字符串s1、s2和一个长度为len*2的字符串s，
每一次我们按照编织字符串的操作将s1和s2拼接起来（注意这里s2先拼接，具体请看样例），得到长度为len*2的字符串s'
然后令s1为s'的前一半，s2为s'的后一半，反复以上操作。
若在某一次中s'和s相等则结束循环。
假设有s1="JNU",s2="ACM",s="NAMJUC"
第一次操作后得到s'="AJCNMU"，与s不相等。
令s1="AJC",s2="NMU"
第二次操作后得到s'="NAMJUC"，与s相等，结束循环。
输出操作次数为2
Input
第一行一个整数T(1≤T≤1000)，代表测试数据组个数。
对于每组数据，第一行为len(1≤len≤100)，第二行为字符串s1，第三行为字符串s2，第四行为字符串s。
输入保证s1和s2长度均为len，s长度为len*2
Output
对每一组数据，输出数据组编号和答案。
如果无论经过多少次操作也无法结束循环，答案输出-1
Sample Input
2
3
JNU
ACM
NAMJUC
3
JNU
ACM
ACMJNU
Sample Output
1 2
2 -1

思路：对过程进行模拟，用map把前面出现的队列存下来如果遇到重复的就无法准换为s
```
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
const int maxn = 1e5;
char s1[300],s2[300],s[300];
char ss[300];
int cnt;

int main()
{
	int t;
	cin>>t;
	for(int k=1; k<=t; k++)
	{
		int len;
		int flag=0;
		map<string,int> mp;
		cin>>len;
		cin>>s1>>s2>>s;
		int ans=1;
		ss[len]=0;
		while(1)
		{

			cnt=0;
			for(int i=0; i<len; i++)
			{
				ss[cnt++]=s2[i];
				ss[cnt++]=s1[i];
			}
			ss[cnt]=0;
			int cnt1=0;
			cnt=0;
//			cout<<s1<<" "<<s2<<endl;
//			cout<<ss<<endl;
			if(strcmp(ss,s)==0)
			{
				flag=1;
				break;
			}
			if(mp[ss]!=0)
			{
				break;
			}
			mp[ss]++;
			for(int i=0; i<len; i++)
			{
				s1[i]=ss[i];
				s2[i]=ss[i+len];
			}
			ans++;
		}
		cout<<k<<" ";
		if(flag)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
```
