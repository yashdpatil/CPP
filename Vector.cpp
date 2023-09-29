#include<bits/stdc++.h>
using namespace std;

		 void printvec(vector<int>v)
{
		for(int i =0; i<v.size();i++)
		{
		
			if(v[i]>10){
			
			
			cout<<i;
		}
			
		}
	}
	int main()
	{
	
			
	
	vector<int> v;
	v.push_back(40);
	v.push_back(60);
//	v.push_back(70);
	vector<int> ::iterator it =v.begin();
//	cout<<(*it)<<endl;
	cout<<*it++<<endl;
	printvec(v);
	}

