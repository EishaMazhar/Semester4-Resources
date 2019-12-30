/*
	Eisha Tir Raazia
	sec C
	17k-3730
	
*/

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

int main()
{
	ifstream input_file;
	char Transition_st[100];
	int ctr=0;
	char current[100];
	char In[100];
	char current_status[100];
	cout<<"Eisha\n";
	cout<<"17k-3730\n";
	cout<<"sec:C\n\n";
	
	input_file.open("pda_table.txt");
	input_file>>current[0];
	input_file>>In[0];	
	input_file>>Transition_st[0]; 
	input_file>>current_status[0];
	
	cout<<"\t\tPDA implementation!\nInput strings'output :\n";
	
	while(input_file.eof()!=true)
	{
		ctr+=1;
		input_file>>current[ctr];
		input_file>>In[ctr];
		input_file>>Transition_st[ctr];
		input_file>>current_status[ctr];
	}
	input_file.close();

	ifstream input_str;
	input_str.open("input_str.txt");
	string inStr[10];
	int strlength=0;
	
	while(!input_str.eof())
	{
		input_str>>inStr[strlength];
	//	cout<<inStr[strlength];
//		cout<<endl;
		strlength++;
	}
	input_str.close();
	
	string ab = "dd";
	for(int outermost_loop=0;outermost_loop<strlength;outermost_loop++)
		inStr[outermost_loop]= inStr[outermost_loop] + ab;
		
	char chr;
	char st;
	char t;
	
	ofstream output_file;
	output_file.open("output_file.txt");
	
	/*
	According to the question:
		1=>start
		2=>accept
		3=>read
		4=>pop
		5=>push
		x for empty symbol and states
	*/
	
	for(int outermost_loop=0;outermost_loop<strlength-1;)
	{
		stack <char> stk;
		st='1';
		int v=0;
		
		for(int u =0;u<inStr[outermost_loop].length();u++)
			stk.push('u');
			
		while(v < inStr[outermost_loop].length())
		{	
			for(int w =0;w<ctr;w++)
			{		
				if(st == current[w])
				{
					
					if(In[w]  == 'x'){
						st = Transition_st[w];
						if(current_status[w] == '4')
							if(stk.size()> 0)
							{
								stk.pop();	
							}
							
						if(current_status[w] == '5')
							stk.push('x');
						w = 1000;
				
					}
					else if(inStr[outermost_loop][v] == In[w]){
						st = Transition_st[w];	
						v+=1;
						w = 1000;
					}
				}
			}
		}
		char var;
		
		for(int w=0;w<ctr;)
		{
			if(st==current[w] )
			{

				chr=current_status[w];
				break;
			}
			w=w+1;
		}
		
		if(stk.size() == inStr[outermost_loop].length())
			 var = stk.top();
		else
			 var = 'a';
			 
		if(chr == '2' && (var == 'z' || var == 'x'))
		{

			output_file<<"string is Accepted\n";
			cout<<"Accepted\n";
		}
		else
		{

		one:output_file<<"string is Rejected\n";
			cout<<"Rejected\n";
		}
		
		outermost_loop++;
	}
}
