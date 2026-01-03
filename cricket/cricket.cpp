#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int isValid ( string str );
int input ( string str );
void wait();

class Cricket
{
	int user,comp;
	int ining;
	int uruns,uballs;
	int cruns,cballs;
	string s;
	
	public:
		Cricket()
		{
			ining= uruns= uballs= cruns= cballs= 0;
		}
		int tos();
		void bating();
		void choose(int res);
		void bowling();
		void result();
};	

int Cricket :: tos()
{

	// Choosing For Toss
	againToss:
	
	again:
	
	cout << "\n Choose 0-Heads / 1-Tails : ";
	getline(cin, s);
	user = input(s);
	
	if ( user==-1 )
	{
		cout << "\n plese enter only integer numbers.";
		wait();
		goto again;
	}
	
	if ( user==0 )
		cout << "\n You Choose Heads";
	else if ( user==1 )
		cout << "\n You Choose Tails";
	else
	{
		cout << "\n Invalid Input..\n try again...";
		goto againToss;
	}
	
	// desesion
	comp = rand()%2;
	// temp = ( comp==0 ) ? "Heads" : "Tails" ;
	cout << "\n\n Coin Fliped : " << ( (comp==0 ) ? "Heads" : "Tails");
	if ( user==comp )
	{	
		cout << "\n You Won The Toss";
		wait();
		return 1;
	}
	else
	{			
		cout << "\n You Lose The Toss...";
		wait();
		return 0;
	}
}

void Cricket :: choose ( int res )
{
	Cricket p;
	if ( res )
	{
		againChoose:
		
		again:
		
		cout << "\n Choose 0-Batting/1-Balling : ";
		getline(cin, s);
		user = input(s);
	
		if ( user==-1 )
		{
			cout << "\n plese enter only integer numbers.";
			wait();
			goto again;
		}
		
		if ( user==0 )
		{
			cout << "\n You Choose Batting";
			wait();
			ining++;
			bating();
		}
		else if ( user==1 )
		{
			cout << "\n You Choose Balling";
			wait();
			ining++;
			bowling();
		}
		else
		{
			cout << "\n Invalid Input..\n try again...";
			goto againChoose;
		}
	}
	else
	{
		
		comp = rand()%2;
		if ( comp== 0 )
		{
			cout << "\n Computer Choose Balling.";
			wait();
			ining++;
			bating();
		}
		else
		{
			cout << "\n Computer Choose Batting.";
			wait();
			ining++;
			bowling();
		}
	}
}
void Cricket :: bating()
{
	cout << "\n\n\n -----Your Batting Starts----";
	wait();
	int rang[] = {1, 2, 3, 4, 6}, c=3, u=1, ind;
	while ( u )
	{	
		againChoose:
		
		ind = rand() %5;
		c = rang[ind];
		
		again:
		cout << "\n\n Enter your choice {1,2,3,4,6} : ";
		getline(cin, s);
		u = input(s);
	
		if ( u==-1 )
		{
			cout << "\n plese enter only integer numbers.";
			wait();
			goto again;
		}
		
		if ( u==1 || u==2 || u==3 || u==4 || u==6 )
		{
			cout << "\n Computer bowled : " << c;
			cout << "\n   You  played   : " << u;
			if ( u==c )
			{
				cout << "\n\n You are OUt !...";
				cout << "\n---------------------";
				cout << "\n   Your Score ";
				cout << "\n   Total Runs    : " << uruns;
				cout << "\n   Total Balls   : " << uballs;			
				cout << "\n---------------------";
				
				wait();
				break;
			}
			else
			{
				uballs++;
				uruns+=u;
				cout << "\n---------------------";
				cout << "\n   Runs     : " << uruns;
			}
			
			wait();
		}
		else
		{
			cout << "\n Invalid input.\n try again...";
			goto againChoose;
		}
	}
	if ( ining==1 )
	{	
		// user's bating is complete
		ining++;
		// now user will switch to bowling
		bowling();
	}
	else
		result();
}
void Cricket :: bowling()
{
	cout << "\n\n\n -----Your Balling Starts----";
	wait();
	int rang[] = {1, 2, 3, 4, 6}, c=3, u=1, ind;
	while ( u )
	{	
		againChoose:
		
		ind = rand() %5;
		c = rang[ind];
		
		again:
		
		cout << "\n\n Enter your choice {1,2,3,4,6} : ";
		getline(cin, s);
		u = input(s);
	
		if ( u==-1 )
		{
			cout << "\n plese enter only integer numbers.";
			wait();
			goto again;
		}
		
		if(u==1 || u==2 || u==3 || u==4 || u==6)
		{
			cout << "\n    You bowled   : "<<u;
			cout << "\n Computer played : "<<c;
			if ( u==c )
			{
				cout << "\n\n Computer Is OUt !...";
				cout << "\n---------------------";
				cout << "\n Computer's Score ";
				cout << "\n   Total Runs    : " << cruns;
				cout << "\n   Total Balls   : " << cballs;
				cout << "\n---------------------";
				
				wait();
				break;
			}
			else
			{
				cballs++;
				cruns+=c;
				cout << "\n---------------------";
				cout << "\n   Runs     : " << cruns;
				wait();
			}
		}
		else
		{
			cout << "\n Invalid input.\n try again...";
			goto againChoose; 
		}
	}
	if ( ining==1 )
	{
		ining++;
		// user's bowling is complete
		// now user will switch to bating
		bating(); 
	}
	else
		result();	
}
void Cricket :: result()
{
	
	cout << "\n ---- Your Score ---";
	cout << "\n Run : " << uruns;
	cout << "\n Balls : " << uballs;
	
	cout << "\n\n ---- Computer Score ----";
	cout << "\n Runs : " << cruns;
	cout << "\n Balls : " << cballs;
	
	
	if ( uruns==cruns )
		cout << "\n\n it's a draw match...";
	else if ( uruns>cruns )
		cout << "\n\n You Won";
	else if ( uruns<cruns  )
		cout << "\n\n Computer Won";
	wait();
}

int main()
{
	srand ( time(0) );
	Cricket play;
	int a = play.tos();
	play.choose(a);
	return 0;
}

// validity checker 
int isValid ( string str )
{
	int len = 0, temp = 0, limit;
	limit = 1; // length limit
	len = str.length();
	if ( str.length() <= limit && str.length() > 0)
	{
		for ( int i = 0 ; str[i] != '\0' ; i++)
			if ( str[i] < 48 || str[i] > 57 )
			{	
				temp++;
				break;
			}
			
		if ( temp==0 )
			return 1; // converting
		else 
			return -1; // not converting
	}
	else 
	{
		cout << "\n length limit is "<< limit << "." ;
		wait();
		return -1; // not converting
	}
}

// converting string in to integer
int input ( string str )
{
	int temp;
	if ( isValid(str) == 1 )
	{
		temp = atoi(str.c_str()); // converting string to integer 
		return temp; // returning converted number
	}	
	else
		return -1; // not convertig
}

// to wait
void wait()
{
	cin.ignore(1,'\n');
	system("cls");
}