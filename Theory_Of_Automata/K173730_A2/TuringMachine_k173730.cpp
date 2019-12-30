/* Eisha Tir Raazia
	17K-3730
	sec C
*/
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	
	char currentState[100];
	char input[100];
	char write[100];
	char trans[100];
	char mv[100];
	char status[100];
	int cnt=0;
	ifstream input_file;
	input_file.open("turing machine table.txt");
	
		input_file>>currentState[0];
		input_file>>input[0];
		input_file>>write[0];
		input_file>>trans[0];
		input_file>>mv[0];
		input_file>>status[0];
		
		
		
	/*	input_file.open("transition_table_tunning.txt");
	
		input_file>>currentState[0];
		input_file>>input[0];
		input_file>>write[0];
		input_file>>trans[0];
		input_file>>mv[0];
		input_file>>status[0];
	*/
	
	while(!input_file.eof())
	{
		cnt++;
		input_file>>currentState[cnt];
		input_file>>input[cnt];
		input_file>>write[cnt];
		input_file>>trans[cnt];
		input_file>>mv[cnt];
		input_file>>status[cnt];
	}

	input_file.close();

	ifstream in;
	in.open("turing input.txt");
	string input_string[10];
	int strlength=0;
	
	while(!in.eof())
	{
		in>>input_string[strlength];
		strlength++;
	}
	in.close();
	char chr,state,t;
	ofstream output;
	output.open("turing output.txt");
		output<<"Eisha Tir Raazia\n\t17k-3730\n\tsec C\n\n";
	for(int out_loop=0;out_loop<strlength;out_loop++)
	{
		state='1';
		for(int in_loop=0;in_loop<input_string[out_loop].length();)
		{
			for(int k=0;k<cnt;k++)
				if(state == currentState[k])
					if(input_string[out_loop][in_loop] == input[k])
					{
						state=trans[k];
						input_string[out_loop][in_loop] = write[k];
						if(mv[k] == 'R')
						{
							in_loop++;
						}	
						else
						{
							in_loop--;
						}
							
					}
		}
		
		for(int k=0;k<cnt;k++)
		{
			if(state==currentState[k])
			{
				chr=status[k];
				break;
			}
		}
	
		if(chr=='1')
		{
			cout<<"Accept\n";
			output<<"String is Accepted\n";
			
		}
		else
		{
			output<<"String is Rejected\n";
			cout<<"Reject\n";
		}
	}
}
