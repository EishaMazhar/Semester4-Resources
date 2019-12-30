#include<iostream>
#include<utility>
#include<cstring>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
	private:
		T Data;
		Node<T> *Next;
		char Transition;
	public:
		//default constructor
		Node():Data(0),Next(0),Transition(0)
		{
			
		}
		//parameterized constuctor
		Node(T &d,char t)
		{
			Data=d;
			Next=0;
			Transition=t;
		}
		Node(Node<T> *n)
		{
			Next=n;
			Data=0;
			Transition=0;
		}
		void SetNext(Node<T> *n)
		{
			Next=n;
		}
		void SetTransition(char t)
		{
			Transition=t;
		}
		char GetTransition()
		{
		   return Transition;
		}
		Node <T>* GetNext()
		{
			return Next;
		}
		void SetData(const T &d)
		{
			Data=d;
		}
		T GetData() const
		{
			return Data;
		}
		
};
stack<int> s;
template<class T>
class SinglyLinkedList
{
	friend class DirectedGraph;
	private:
		Node <T>* Head;
		int IsFinal;
		//private function
		void DeleteAll()
		{
			Node<T>* current=Head;
			Node<T>* temp=current;
			while(current!=0)
			{
				current=current->GetNext();
			}
			temp->SetNext(0);
			delete temp;
			temp=current;
			Head=0;
		}
	public:
		
		//default constructor
		SinglyLinkedList()
		{
			Head=0;
			IsFinal=0;
		}
		Node<T>* GetHead()
		{
			return Head;
		}
		//copy constructor
		SinglyLinkedList(const SinglyLinkedList &rhs)
		{
			Head=0;
			Node<T>* current=rhs.Head;
			IsFinal=rhs.IsFinal;
			Node<T>* Last=0;
			//while loop
			while(current!=0)
			{
			    //Assigning the current value to node
				Node<T>* newnode=new Node<T> (current->GetData());
				if(Head==0)
				{
					Head=newnode;
					Last=Head;
				}
				else
				{
				  Last->SetNext(newnode);
					Last=newnode;
				}
				current=current->GetNext();
			}
	    }
	    
	    //Assignment operator overload
	    SinglyLinkedList<T>& operator =(const SinglyLinkedList &rhs )
	    {
	    	if(this!=&rhs)
	    	{
	    		//private function
	    		DeleteAll();
	    		Head=0;
				Node<T>* current=rhs.Head;
				IsFinal=rhs.IsFinal;
				Node<T>* Last=0;
				//while loop
				while(current!=0)
				{
				    //Assigning the current value to node
					Node<T>* newnode=new Node<T> (current->GetData());
					if(Head==0)
					{
						Head=newnode;
						Last=Head;
					}
					else
					{
						Last->SetNext(newnode);
						Last=newnode;
					}
					current=current->GetNext();
				}
	    		
			}
			return *this;
		}
		//Destructor
		~SinglyLinkedList()
		{
			DeleteAll();
		}
    	void InsertAtLast(T data,char t)
		{
			Node<T>* temp=new Node <T>(data,t);
			if(Head==0)
			{
				Head=temp;
			}
			else
			{
				Node<T>* current=Head;
				while(current->GetNext()!=0)
				{
					current=current->GetNext();
				}
				current->SetNext(temp);
			}
		}
		void Print()
		{
		 	if(Head==0)
		 	{
		 		cout<<"List is Empty!"<<endl;
		 	}
		 	else
		 	{
		 		Node<T>* temp=Head;
			 	while(temp!=0)
			 	{
					cout<<"State "<<temp->GetData().first<<" -("<<temp->GetTransition()<<")-> State "<<temp->GetData().second<<"\t";
			 		temp=temp->GetNext();
				}
				//cout<<endl;
		 	}
		} 
};
//adjacency list
class DirectedGraph
{
	private:
		SinglyLinkedList <pair<int,int> > *list;
		int Vertices;
	public:
		DirectedGraph():list(0),Vertices(0)
		{
			
		}
	  	DirectedGraph(int v)
	  	{
	  		Vertices=v;
	  		list= new SinglyLinkedList <pair<int,int> > [Vertices];
	  		//pair<int,int>;
		}
	    void AddEdge(int startstate,int secondstate,char t,int final)
	    {
	    	list[startstate].InsertAtLast(make_pair(startstate,secondstate),t);
	        list[startstate].IsFinal=final;
		}
		int SimulateDFA(int current,const char* input,int start)
		{
			 //if the length of input=final alphabet
			if(start==(int)strlen(input))
			{
				return list[current].IsFinal;
			}
			Node<pair<int,int> >* temp=list[current].GetHead();
			while(temp!=0)
			{
				if(input[start]==temp->GetTransition())
				if(SimulateDFA(temp->GetData().second,input,start+1)==1)
				return 1;
				temp=temp->GetNext();
			}
			return 0;
		}
		void PrintGraph()
		{
			for(int i=1;i<Vertices;i++)
			{
				if(list[i].IsFinal==1)
				cout<<"Accept State: ";
				
				else if(list[i].IsFinal==0)
				cout<<"Start State: ";
				
				else if(list[i].IsFinal==2)
				cout<<"Read State: ";
				
				else if(list[i].IsFinal==3)
				cout<<"Pop State: ";
				
				else if(list[i].IsFinal==4)
				cout<<"Push State: ";
				
				list[i].Print();
				cout<<endl;
			}
		}
};
int main()
{
      DirectedGraph pda(5);
	  string input;
	  ifstream instr;
	  ifstream infile;
	  ofstream outstr;
      int source,dest,is_final;
      char transition;
  
      infile.open("transition_table.txt");
	  instr.open("inputString.txt");
	  outstr.open("outputString.txt");
	  
////	  pda.AddEdge(0,1,'a',0);
////	  pda.AddEdge(0,0,'b',0);
////	  pda.AddEdge(1,1,'a',1);
////	  pda.AddEdge(1,0,'a',1);

				/*
					0=>start
					1=>accept
					2=>read
					3=>pop
					4=>push
				*/
				
	 while(!infile.eof())
	 {
	 	infile>>source;
	 	infile>>transition;
	 	infile>>dest;
	 	infile>>is_final;
	 	//cout<<source<<" "<<transition<<" "<<dest<<" "<<is_final<<endl;
	 	pda.AddEdge(source,dest,transition,is_final);
	 }
	 // pda.PrintGraph();
	  while(!instr.eof())
	  {
	  	instr>>input;
	  //	cout<<input<<endl;
	  	int result=pda.SimulateDFA(1,input.c_str(),0);
	  	
	  	if(result==1)	//1 is the accept state in this pda
	  	{
	  		outstr<<"Accept"<<endl;
	  	}
	  	else
	  		outstr<<"Reject"<<endl;
	  }

	  infile.close();
	  instr.close();
	  outstr.close();
}
