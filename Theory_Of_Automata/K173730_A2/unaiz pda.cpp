#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <stack>

using namespace std;

int main()
{
	stack<char> mys;
	char source[100],trans[100],out[100],type[5],t[100];
	char c;
	type[0]='1';
	type[1]='2'; 
	type[2]='3'; 
	type[3]='4';
	type[4]='5'; 
	ifstream obj1;
	obj1.open("(Q1)TransitionTable.txt");
	
	obj1>>source[0];
	obj1>>trans[0];
	obj1>>out[0];
	obj1>>t[0];
	int endt=0;
	while(!obj1.eof())
	{
		endt++;
		obj1>>source[endt];
		obj1>>trans[endt];
		obj1>>out[endt];
		obj1>>t[endt];
	}
	obj1.close();
	char st[100];
	cin	>>st;
	int length=strlen(st);
	cout<<"Input string: "<<st<<endl;
	int i=0;
	char tr;
	int f=0;
	c=source[0];
	if(c=='1' && t[i]==type[0])
	{
		c='2';
	}
	while(i<length)
	{
		tr=st[i];
		if(c=='2')
		{
			if(tr=='a')
			{
				c='3';
				i++;
				f--;
			}
			else if(tr=='b')
			{
				c='4';
				i++;
				f++;
			}
			
		}
		if(c=='3')
		{
			c='2';
			mys.push(tr);
		}
		else if(c=='4')
		{
			c='2';
			if(mys.empty()==false)
			mys.pop();	
			else
			f++;
		}
		
	}
	ofstream output;
	output.open("Output.txt");
	if(c=='2' || f==0)
	{
		c='5';	
		if(f!=0)
		{
			cout<<"Rejected";
		}
		else
		{
			c='6';
			cout<<"Accepted";
			
		}
	}
	else
	{
		cout<<"Rejected";
	}
}
	
	
