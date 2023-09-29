#include<bits/stdc++.h>
using namespace std;
int main()
	{
		string s; cin>>s;
		for(int i=0;i<=s.size();i++)
		{
			if(i%2==0)
			{
				if(!(s[i]>='a' && s[i]<'z'))
					s[i]+=32;
			//	s[i]=tolower(s[i]);
				
			}
			else
			{
					if(!(s[i]>='A' && s[i]<'Z'))
					s[i]-=32;
			//	s[i]=toupper(s[i]);
			}
		}
		cout<<s;
	}
