
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//declaring functions 
void show();
int put(int block, char c);

bool victory(char);
bool filled();

//            x1  |  x2  |  x3
//           -----+------+-----
//            v1  |  v2  |  v3
//           -----+------+-----
//            w1  |  w2  |  w3

//declaring variables
char x1=' ', x2=' ', x3=' ';
char v1=' ', v2=' ', v3=' ';
char w1=' ', w2=' ', w3=' ';


int main() 
{
//for generating random numbers
  srand(time(0));
  

  int choice=0;

  show();
  cout<<"Select Play Mode: "<<endl;
  cout<<"  1) SinglePlayer."<<endl;
  cout<<"  2) MultiPlayer."<<endl;
  cout<<"  0) Exit."<<endl;
  cout<<"Choice: "; 
  cin>>choice;

  switch(choice)
{
    case 1:
{
    while(!victory('X') || !victory('O') || !filled())
{
    cout<<endl;
    
    int block=0;
    show();
    
    do{
    cout<<"\n Enter Block Number (1-9): ";
    cin>>block;
    
    }while(!filled() && put(block,'X')==0);
    
    if(victory('X')) {cout<<"\nPlayer 1 has Won."<<endl; break;}

    do{
    block=rand() % 9 + 1;
    }while(!filled() && put(block,'O')==0);

    if(victory('O')) 
	{cout<<"\nYou have lost."<<endl; break;}
}

    if(!victory('X') && !victory('O')) 
	cout<<"Draw";
    break;
}

    case 2:
{
    while(!victory('X') || !victory('O') || !filled())
{
    cout<<endl;
    int block=0;
    
    show();
    
    do{
    cout<<"\n[X] Enter Block Number (1-9): ";
    cin>>block;
    
    }while(!filled() && put(block,'X')==0);
    
    show();
    
    if(victory('X')) {cout<<"\nPlayer 1 has won."<<endl; break;}

    do{
    cout<<"\n[O] Enter Block Number (1-9): ";
    cin>>block;
    
	}while(!filled() && put(block,'O')==0);
	
    if(victory('O')) {cout<<"\nPlayer 2 has won."<<endl; break;}
}

    if(!victory('X') && !victory('O')) cout<<"Draw";
    break;
}

    case 0:
{
    cout<<"\nBetter luck next Time "<<endl;
    break;
}

    default:
    cout<<"\nOption is invalid."<<endl;
}
}

//defining functions

int put(int block, char c)
{
  switch(block)
{
    case 1: 
{
    if(x1==' ') 
	{x1=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 2: 
{
    if(x2==' ') 
	{x2=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 3: 
{
    if(x3==' ') 
	{x3=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 4: 
{
    if(v1==' ') 
	{v1=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 5: 
{
    if(v2==' ') 
	{v2=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 6: 
{
    if(v3==' ') 
	{v3=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 7: 
{
    if(w1==' ') 
	{w1=c; return 1;}
	
    else 
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 8: 
{
    if(w2==' ') 
	{w2=c; return 1;}
	
    else
	{cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    case 9: 
{
    if(w3==' ') 
	{w3=c; return 1;}
	
    else {cout<<"\nOption is taken. Enter Again."<<endl; return 0;}
    break;
}
    default:
    cout<<"\nOption is Invalid"<<endl;
    
    return 0;
}
}

void show()
{
  cout<<"\t"<<x1<<" | "<<x2<<" | "<<x3<<endl;
  cout<<"\t--+---+--\n";
  cout<<"\t"<<v1<<" | "<<v2<<" | "<<v3<<endl;
  cout<<"\t--+---+--\n";
  cout<<"\t"<<w1<<" | "<<w2<<" | "<<w3<<endl<<endl;
}

bool filled()
{
  if(x1!=' ' &&  x2!=' '&&  x3!=' '&&  v1!=' '&&  v2!=' '&&  v3!=' '&&  w1!=' '&&  w2!=' '&&  w3!=' ')
  return true;
  
  else 
  return false;
}

bool victory(char c)
{
  if(x1==c && x2==c && x3==c) return true;
  if(v1==c && v2==c && v3==c) return true;
  if(w1==c && w2==c && w3==c) return true;

  if(x1==c && v1==c && w1==c) return true;
  if(x2==c && v2==c && w2==c) return true;
  if(x3==c && v3==c && w3==c) return true;

  if(w1==c && v2==c && x3==c) return true;
  if(x1==c && v2==c && w3==c) return true;

  return false;
}

