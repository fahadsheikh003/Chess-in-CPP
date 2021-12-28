/*
Fahad Waheed
20I-0651
BS (CYS)-T
PF Project (Chess)
Assigned Pieces: King & 2 Bishops
*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int king_row, king_col;
int bishop1_row, bishop1_col;
int bishop2_row, bishop2_col;

void gui(char (*)[8]);
void initial_position_bishop(char (*)[8]);
void random_initial_position_bishop(char (*)[8]);
void initial_position_king(char (*)[8]);
void random_initial_position_king(char (*)[8]);
void king_move(char (*)[8]);
void bishop_move(char (*)[8], int, int, int);
void random_king_move(char (*)[8]);
void random_bishop1_move(char (*)[8], int, int);
void random_bishop2_move(char (*)[8], int, int);

void start();
void singleplayer();
void doubleplayer();

int main()
{
	start();
}

void start()
{
	cout<<setw(60)<<"Chess"<<"\nMenu:\n(1) Player\n(2) Player\n(Q)uit";
	
	char choice;
	cout<<"\nEnter Choice: ";
	cin>>choice;
	
	while (!(choice=='1'||'2'||'Q'||'q'))
	{
		cout<<"Invalid input!\nPlease Enter valid option: ";
		cin>>choice;
	}
	
	switch (choice)
	{
		case '1':
			{
				singleplayer();
				
				break;
			}
			
		case '2':
			{
				doubleplayer();
			
				break;
			}
			
		case 'Q':
		case 'q':
			{
				exit(0);
			}
	}
}

//Your Next Move Portion
void singleplayer()
{
	char chess[8][8];
	char inchoice;
				
	cout<<"\nChoose b/w (K)ing and 2 (B)ishops \nEnter your choice: ";
	cin>>inchoice;
				
	while (!(inchoice=='K'||'k'||'B'||'b'))
	{			
		cout<<"Invalid input!\nPlease Enter valid option: ";
		cin>>inchoice;
	}
				
	switch (inchoice)
	{
		case 'K':
		case 'k':
			{
				initial_position_king(chess);
				chess[king_row][king_col]='K';
							
				gui(chess);
				cout<<"\nPress any key to see opponent\'s move \n";
				cin.get();
				cin.get();

				random_initial_position_bishop(chess);
				chess[bishop1_row][bishop1_col]='B';
				chess[bishop2_row][bishop2_col]='B';
							
				gui(chess);

				char ch;

				do
				{
					cout<<"\nNext Move of King: "<<endl;
					int iking_row=king_row, iking_col=king_col;
								
					king_move(chess);
								
					static int count1=0;
								
					if (chess[king_row][king_col]==' ')
					{
						char temp=chess[king_row][king_col];
						chess[king_row][king_col]=chess[iking_row][iking_col];
						chess[iking_row][iking_col]=temp;
					}
								
					else if (chess[king_row][king_col]=='B')
					{
						chess[king_row][king_col]=chess[iking_row][iking_col];
						chess[iking_row][iking_col]=' ';
									
						count1++;
									
						if (count1==2)
						{
							cout<<"\n\nYou Win!\n";
							gui(chess);
							cin.get();
							cin.get();
							exit(0);
						}
					}
								
								
								
					gui(chess);
					cout<<"\nPress any key to see opponent\'s move \n";
					cin.get(); cin.get();
								
					srand(time(NULL));

					int bishop_choice;
								
					if (chess[bishop2_row][bishop2_col]!='B')
					{
						bishop_choice=1;
					}
								
					else if (chess[bishop1_row][bishop1_col]!='B')
					{
						bishop_choice=2;
					}
								
					else
					{
						bishop_choice=(rand()%2)+1;
					}
								
					cout<<"\nBishop Chosen: "<<bishop_choice<<endl;
								
					if (bishop_choice==1)
					{
						int ibishop1_row=bishop1_row, ibishop1_col=bishop1_col;
																		
						random_bishop1_move(chess, ibishop1_row, ibishop1_col);
									
						chess[bishop1_row][bishop1_col]=chess[ibishop1_row][ibishop1_col];
						chess[ibishop1_row][ibishop1_col]=' ';
					}
								
					else if (bishop_choice==2)
					{
						int ibishop2_row=bishop2_row, ibishop2_col=bishop2_col;
																		
						random_bishop2_move(chess, ibishop2_row, ibishop2_col);
									
						chess[bishop2_row][bishop2_col]=chess[ibishop2_row][ibishop2_col];
						chess[ibishop2_row][ibishop2_col]=' ';
									
					}
								
					gui(chess);
								
					cout<<"\nEnter \"0\" if you want to exit : ";
					cin>>ch;
				}
				while (!(ch=='0'));

				break;
			}
						
		case 'B':
		case 'b':
			{
				initial_position_bishop(chess);
				chess[bishop1_row][bishop1_col]='B';
				chess[bishop2_row][bishop2_col]='B';
							
				gui(chess);
				cout<<"\nPress any key to see opponent\'s move \n";
				cin.get(); cin.get();							
							
				random_initial_position_king(chess);
				chess[king_row][king_col]='K';
							
				gui(chess);

				char ch;
							
				do
				{
					cout<<"\nNext Move: \n"<<endl;
								
					int bishop_choice;
								
					if (chess[bishop2_row][bishop2_col]!='B')
					{
						bishop_choice=1;
					}
								
					else if (chess[bishop1_row][bishop1_col]!='B')
					{
						bishop_choice=2;
					}
								
					else
					{
						do
						{
							cout<<"Please Enter \"1\" if you want to move Bishop 1\nEnter \"2\" if you want to move Bishop 2\nYour choice: ";
							cin>>bishop_choice;								
						}
						while (!(bishop_choice==1||2));
					}
																								
					if (bishop_choice==1)
					{
						int ibishop1_row=bishop1_row, ibishop1_col=bishop1_col;
																			
						bishop_move(chess, ibishop1_row, ibishop1_col, bishop_choice);
									
						chess[bishop1_row][bishop1_col]=chess[ibishop1_row][ibishop1_col];
						chess[ibishop1_row][ibishop1_col]=' ';
					}
								
					else if (bishop_choice==2)
					{
						int ibishop2_row=bishop2_row, ibishop2_col=bishop2_col;
																		
						bishop_move(chess, ibishop2_row, ibishop2_col, bishop_choice);
									
						chess[bishop2_row][bishop2_col]=chess[ibishop2_row][ibishop2_col];
						chess[ibishop2_row][ibishop2_col]=' ';	
					}
								
					gui(chess);
					cout<<"\nPress any key to see opponent\'s move \n";
					cin.get(); cin.get();
								
					int iking_row=king_row, iking_col=king_col;
								
					random_king_move(chess);
								
					if (chess[king_row][king_col]==' ')
					{
						char temp=chess[king_row][king_col];
						chess[king_row][king_col]=chess[iking_row][iking_col];
						chess[iking_row][iking_col]=temp;
					}
								
					else if (chess[king_row][king_col]=='B')
					{
						chess[king_row][king_col]=chess[iking_row][iking_col];
						chess[iking_row][iking_col]=' ';
					}
							
					gui(chess);							
								
					cout<<"\nEnter \"0\" if you want to exit : ";
					cin>>ch;
				}
				while (!(ch=='0'));

				break;						
			}
	}
}

//Save the King Portion
void doubleplayer()
{
	char chess[8][8];
	char P1, P2;
				
	cout<<"\nOnly Player One can choose first, as this chess game has only two pieces (King & Bishops)\n";
	cout<<"Choose b/w (K)ing and (B)ishops \nEnter Player 1\'s choice: ";
	cin>>P1;
				
	while (!(P1=='K'||'k'||'B'||'b'))
	{			
		cout<<"Invalid input!\nPlease Enter valid option: ";
		cin>>P1;
	}
				
	if (P1=='K'||'k')
	{
		cout<<"Player 1: King\nPlayer 2: 2 Bishops\n";
		P2='B';
	}
				
	else
	{
		cout<<"Player 1: 2 Bishops\nPlayer 2: King\n";
		P2='K';
	}
				
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			chess[i][j]=' ';
		}
	}
				
	random_initial_position_bishop(chess);
	chess[bishop1_row][bishop1_col]='B';
	chess[bishop2_row][bishop2_col]='B';

	random_initial_position_king(chess);
	chess[king_row][king_col]='K';

	gui(chess);
	cout<<"Press any key to continue..";
	cin.get(); cin.get();
				
	char ch;

	do
	{
		cout<<"\nNext Move of King: "<<endl;
		int iking_row=king_row, iking_col=king_col;
									
		king_move(chess);
							
		static int count1=0;
								
		if (chess[king_row][king_col]==' ')
		{
			char temp=chess[king_row][king_col];
			chess[king_row][king_col]=chess[iking_row][iking_col];
			chess[iking_row][iking_col]=temp;
		}
								
		else if (chess[king_row][king_col]=='B')
		{
			chess[king_row][king_col]=chess[iking_row][iking_col];
			chess[iking_row][iking_col]=' ';
										
			count1++;
										
			if (count1==2)
			{
				cout<<"\n\nKing Win!\n";
				gui(chess);
				cin.get(); cin.get();
				exit(0);
			}
		}
															
		gui(chess);
		cout<<"\nPress any key to see opponent\'s move \n";
		cin.get(); cin.get();
					
		int bishop_choice;
								
		if (chess[bishop2_row][bishop2_col]!='B')
		{
			bishop_choice=1;
		}
								
		else if (chess[bishop1_row][bishop1_col]!='B')
		{
			bishop_choice=2;
		}
								
		else
		{
			do
			{
				cout<<"Please Enter \"1\" if you want to move Bishop 1\nEnter \"2\" if you want to move Bishop 2\nYour choice: ";
				cin>>bishop_choice;								
			}
			while (!(bishop_choice==1||2));
		}
																								
		if (bishop_choice==1)
		{
			int ibishop1_row=bishop1_row, ibishop1_col=bishop1_col;
																
			bishop_move(chess, ibishop1_row, ibishop1_col, bishop_choice);
								
			chess[bishop1_row][bishop1_col]=chess[ibishop1_row][ibishop1_col];
			chess[ibishop1_row][ibishop1_col]=' ';
		}
								
		else if (bishop_choice==2)
		{
			int ibishop2_row=bishop2_row, ibishop2_col=bishop2_col;
																		
			bishop_move(chess, ibishop2_row, ibishop2_col, bishop_choice);
									
			chess[bishop2_row][bishop2_col]=chess[ibishop2_row][ibishop2_col];
			chess[ibishop2_row][ibishop2_col]=' ';	
		}
								
		gui(chess);
					
		cout<<"\nEnter \"0\" if you want to exit : ";
		cin>>ch;
	}
	while (!(ch=='0'));

}

void initial_position_king(char (*array)[8])
{
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			array[i][j]=' ';
		}
	}

	cout<<"Enter initial position of king: \nEnter row (0-7): ";
	cin>>king_row;
	while (!(king_row>=0 && king_row<=7))
	{
		cout<<"Invalid input!\nPlease enter valid row number: ";
		cin>>king_row;
	}
				
	cout<<"Enter column (0-7): ";
	cin>>king_col;
	while (!(king_col>=0 && king_col<=7))
	{
		cout<<"Invalid input!\nPlease enter valid column number: ";
		cin>>king_col;
	}

}

void initial_position_bishop(char (*array)[8])
{
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			array[i][j]=' ';
		}
	}
	
	cout<<"Enter initial position of Bishop 1: \nEnter row (0-7): ";
	cin>>bishop1_row;
	while (!(bishop1_row>=0 && bishop1_row<=7))
	{
		cout<<"Invalid input!\nPlease enter valid row number: ";
		cin>>bishop1_row;
	}
				
	cout<<"Enter column (0-7): ";
	cin>>bishop1_col;
	while (!(bishop1_col>=0 && bishop1_col<=7))
	{
		cout<<"Invalid input!\nPlease enter valid column number: ";
		cin>>bishop1_col;
	}		
	
	cout<<"Enter initial position of Bishop 2: \nEnter row (0-7): ";
	cin>>bishop2_row;
	while (!(bishop2_row>=0 && bishop2_row<=7))
	{
		cout<<"Invalid input!\nPlease enter valid row number: ";
		cin>>bishop2_row;
	}
				
				
	cout<<"Enter column (0-7): ";
	cin>>bishop2_col;
	while (!(bishop2_col>=0 && bishop2_col<=7))
	{
		cout<<"Invalid input!\nPlease enter valid column number: ";
		cin>>bishop2_col;
	}	
	
	while (bishop2_row==bishop1_row&&bishop2_col==bishop1_col)
	{
		cout<<"Error! Overlapping....\n";
		
		cout<<"Enter initial position of Bishop 2: \nEnter row (0-7): ";
		cin>>bishop2_row;
		while (!(bishop2_row>=0 && bishop2_row<=7))
		{
			cout<<"Invalid input!\nPlease enter valid row number: ";
			cin>>bishop2_row;
		}
				
				
		cout<<"Enter column (0-7): ";
		cin>>bishop2_col;
		while (!(bishop2_col>=0 && bishop2_col<=7))
		{
			cout<<"Invalid input!\nPlease enter valid column number: ";
			cin>>bishop2_col;
		}	
	}

}

void random_initial_position_bishop(char (*array)[8])
{
	srand(time(NULL));
	
	bishop1_row=rand()%8;
	bishop1_col=rand()%8;
	
	while (bishop1_row==king_row&&bishop1_col==king_col)
	{
		bishop1_row=rand()%8;
		bishop1_col=rand()%8;
	}
	
	bishop2_row=rand()%8;
	bishop2_col=rand()%8;
	
	while ((bishop2_row==king_row&&bishop2_col==king_col)||(bishop2_row==bishop1_row&&bishop2_col==bishop1_col))
	{
		bishop2_row=rand()%8;
		bishop2_col=rand()%8;
	}

}

void random_initial_position_king(char (*array)[8])
{
	king_row=rand()%8;
	king_col=rand()%8;
	
	while ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
	{
		king_row=rand()%8;
		king_col=rand()%8;
	}
	
}


void gui(char (*array)[8])
{
	cout<<"\n     "<<0<<setw(5)<<1<<setw(5)<<2<<setw(5)<<3<<setw(5)<<4<<setw(5)<<5<<setw(5)<<6<<setw(5)<<7<<endl<<endl;
	for (int i=0 ; i<8 ; i++)
	{
		cout<<i;
		for (int j=0 ; j<8 ; j++)
		{
			cout<<setw(5)<<array[i][j];
		}
		cout<<endl<<endl;
	}

	if (array[king_row][king_col]=='K')
		cout<<"\nCurrent Position of king: ("<<king_row<<","<<king_col<<")";
	if (array[bishop1_row][bishop1_col]=='B')
		cout<<"\nCurrent Position of Bishop 1: ("<<bishop1_row<<","<<bishop1_col<<")";
	if (array[bishop2_row][bishop2_col]=='B')
		cout<<"\nCurrent Position of Bishop 2: ("<<bishop2_row<<","<<bishop2_col<<")";
}

void king_move(char (*array)[8])
{
	int iking_row=king_row, iking_col=king_col;

	if (iking_row==0&&iking_col==0)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col+1<<"),("<<iking_row+1<<","<<iking_col<<"),("<<iking_row+1<<","<<iking_col+1<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_row==0&&iking_col==7)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col-1<<"),("<<iking_row+1<<","<<iking_col-1<<"),("<<iking_row+1<<","<<iking_col<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_row==7&&iking_col==0)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col+1<<"),("<<iking_row-1<<","<<iking_col<<"),("<<iking_row-1<<","<<iking_col+1<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_row==7&&iking_col==7)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col-1<<"),("<<iking_row-1<<","<<iking_col-1<<"),("<<iking_row-1<<","<<iking_col<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_col==0)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row-1<<","<<iking_col<<"),("<<iking_row-1<<","<<iking_col+1<<"),("<<iking_row<<","<<iking_col+1<<")"
			<<",("<<iking_row+1<<","<<iking_col<<"),("<<iking_row+1<<","<<iking_col+1<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;

		while (!((king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)||(king_row==iking_row&&king_col==iking_col+1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_col==7)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row-1<<","<<iking_col<<"),("<<iking_row-1<<","<<iking_col-1<<"),("<<iking_row<<","<<iking_col-1<<")"
			<<",("<<iking_row+1<<","<<iking_col-1<<"),("<<iking_row+1<<","<<iking_col<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_row==0)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col-1<<"),("<<iking_row<<","<<iking_col+1<<"),("<<iking_row+1<<","<<iking_col-1<<")"
			<<",("<<iking_row+1<<","<<iking_col<<"),("<<iking_row+1<<","<<iking_col+1<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else if (iking_row==7)
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row<<","<<iking_col-1<<"),("<<iking_row<<","<<iking_col+1<<"),("<<iking_row-1<<","<<iking_col-1<<")"
			<<",("<<iking_row-1<<","<<iking_col<<"),("<<iking_row-1<<","<<iking_col+1<<")";
		
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row-1&&king_col==iking_col-1)
				||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}
	
	else 
	{
		cout<<"User\'s Turn: \nAvailable Options: ("<<iking_row-1<<","<<iking_col-1<<"),("<<iking_row-1<<","<<iking_col<<")"
			<<",("<<iking_row-1<<","<<iking_col+1<<"),("<<iking_row<<","<<iking_col-1<<"),("<<iking_row<<","<<iking_col+1<<")"
			<<",("<<iking_row+1<<","<<iking_col-1<<"),("<<iking_row+1<<","<<iking_col<<"),("<<iking_row+1<<","<<iking_col+1<<")";
			
		cout<<"\nEnter new Position of King:\nEnter row: ";
		cin>>king_row;
		
		cout<<"Enter column: ";
		cin>>king_col;
		
		while (!((king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)
				||(king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row+1&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)))
		{
			cout<<"Invalid Input!\n";
			
			cout<<"Enter valid Position of King:\nPlease Enter row: ";
			cin>>king_row;
		
			cout<<"Please Enter column: ";
			cin>>king_col;
		}	
	}


}

void bishop_move(char (*array)[8], int row, int col, int choice)
{
	int x_axis[4]={-1,-1,1,1}, y_axis[4]={-1,1,-1,1};
	bool king_check=false;
	
	if (array[row][col]=='B')
	{
		for (int pass=0 ; pass<4 ; pass++)
		{
			for (int counter=1 ; counter<8 ; counter++)
			{
				int x, y;
				
				x=row+x_axis[pass]*counter;
				y=col+y_axis[pass]*counter;

				if (x>=0 && x<=7 && y>=0 && y<=7)
				{					
					if (array[x][y]=='K')
					{
						king_check=true;
						break;
					}
					
					else if (array[x][y]=='B')
					{
						continue;
					}
					
					else //if (array[x][y]==' '||'+')
					{
						array[x][y]='+';
					}
				}
				
				else 
				{
					break;
				}
			}
		}
	}
	
	if (king_check==true)
	{
		cout<<"Available Moves: ("<<king_row<<","<<king_col<<") ";
	}
	
	else
	{
		cout<<"Available Moves: ";
	}
	
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			if (array[i][j]=='+')
			{
				cout<<"("<<i<<","<<j<<") ";
			}
		}
	}
	
	if (choice==1)
	{
		if (king_check==true)
		{
			cout<<"\nEnter row: ";
			cin>>bishop1_row;
			
			cout<<"Enter column: ";
			cin>>bishop1_col;
			
			while (!(bishop1_row==king_row&&bishop1_col==king_col)||(array[bishop1_row][bishop1_col]=='+'))
			{
				cout<<"Invalid Input!\n";
				
				cout<<"Please Enter valid row: ";
				cin>>bishop1_row;
			
				cout<<"Please Enter valid column: ";
				cin>>bishop1_col;
				
			}
			
			if (bishop1_row==king_row&&bishop1_col==king_col)
			{
				cout<<"\nBishop Win!\n";
				array[bishop1_row][bishop1_col]='B';
				array[king_row][king_col]=' ';
				
				for (int i=0 ; i<8 ; i++)
				{
					for (int j=0; j<8; j++)
					{
						if (array[i][j]=='+')
						{
							array[i][j]=' ';
						}
					}
				}
				
				gui(array);
				cin.get(); cin.get();
				exit(0);
			}
		}
		
		else
		{
			cout<<"\nEnter row: ";
			cin>>bishop1_row;
			
			cout<<"Enter column: ";
			cin>>bishop1_col;
			
			while (!(array[bishop1_row][bishop1_col]=='+'))
			{
				cout<<"Invalid Input!\n";
				
				cout<<"Please Enter valid row: ";
				cin>>bishop1_row;
			
				cout<<"Please Enter valid column: ";
				cin>>bishop1_col;
				
			}
		}
	}
	
	else if (choice==2)
	{
		if (king_check==true)
		{
			cout<<"\nEnter row: ";
			cin>>bishop2_row;
			
			cout<<"Enter column: ";
			cin>>bishop2_col;
			
			while (!(bishop2_row==king_row&&bishop2_col==king_col)||(array[bishop2_row][bishop2_col]=='+'))
			{
				cout<<"Invalid Input!\n";
				
				cout<<"Please Enter valid row: ";
				cin>>bishop2_row;
			
				cout<<"Please Enter valid column: ";
				cin>>bishop2_col;
				
			}
			
			if (bishop2_row==king_row&&bishop2_col==king_col)
			{
				cout<<"\nBishop Win!\n";
				array[bishop2_row][bishop2_col]='B';
				array[king_row][king_col]=' ';
				
				for (int i=0 ; i<8 ; i++)
				{
					for (int j=0; j<8; j++)
					{
						if (array[i][j]=='+')
						{
							array[i][j]=' ';
						}
					}
				}
				
				gui(array);
				cin.get(); cin.get();
				exit(0);
			}
		}
		
		else
		{
			cout<<"\nEnter row: ";
			cin>>bishop2_row;
			
			cout<<"Enter column: ";
			cin>>bishop2_col;
			
			while (!(array[bishop2_row][bishop2_col]=='+'))
			{
				cout<<"Invalid Input!\n";
				
				cout<<"Please Enter valid row: ";
				cin>>bishop2_row;
			
				cout<<"Please Enter valid column: ";
				cin>>bishop2_col;
				
			}
		}
	}
	
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0; j<8; j++)
		{
			if (array[i][j]=='+')
			{
				array[i][j]=' ';
			}
		}
	}
}

void random_bishop1_move(char (*array)[8], int row, int col)
{
	int x_axis[4]={-1,-1,1,1}, y_axis[4]={-1,1,-1,1};
	
	if (array[row][col]=='B')
	{
		for (int pass=0 ; pass<4 ; pass++)
		{
			for (int counter=1 ; counter<8 ; counter++)
			{
				int x, y;
				
				x=row+x_axis[pass]*counter;
				y=col+y_axis[pass]*counter;

				if (x>=0 && x<=7 && y>=0 && y<=7)
				{					
					if (array[x][y]=='K')
					{
						cout<<"\n\nYou Lose!\n Better Luck next time..\n";
						bishop1_row=king_row, bishop1_col=king_col;
						
						array[row][col]=' ';
						array[bishop1_row][bishop1_col]='B';
						
						for (int i=0 ; i<8 ; i++)
						{
							for (int j=0 ; j<8 ; j++)
							{
								if (array[i][j]=='+')
								{
									array[i][j]=' ';
								}
							}
						}
						
						gui(array);
						
						cin.get(); cin.get();
						exit(0);
					}
					
					else if (array[x][y]=='B')
					{
						continue;
					}
					
					else //if (array[x][y]==' '||'+')
					{
						array[x][y]='+';
					}
				}
				
				else 
				{
					break;
				}
			}
		}
	}
	
	srand(time(0));
	do
	{
		bishop1_row=rand()%8;
		bishop1_col=rand()%8;
	}
	while (!(array[bishop1_row][bishop1_col]=='+'));
	
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			if (array[i][j]=='+')
			{
				array[i][j]=' ';
			}
		}
	}

}

void random_bishop2_move(char (*array)[8], int row, int col)
{
	int x_axis[4]={-1,-1,1,1}, y_axis[4]={-1,1,-1,1};
	
	if (array[row][col]=='B')
	{
		for (int pass=0 ; pass<4 ; pass++)
		{
			for (int counter=1 ; counter<8 ; counter++)
			{
				int x, y;
				
				x=row+x_axis[pass]*counter;
				y=col+y_axis[pass]*counter;

				if (x>=0 && x<=7 && y>=0 && y<=7)
				{					
					if (array[x][y]=='K')
					{
						cout<<"\n\nYou Lose!\nBetter luck next time..";
						bishop2_row=king_row, bishop2_col=king_col;
						
						array[row][col]=' ';
						array[bishop2_row][bishop2_col]='B';
						
						for (int i=0 ; i<8 ; i++)
						{
							for (int j=0 ; j<8 ; j++)
							{
								if (array[i][j]=='+')
								{
									array[i][j]=' ';
								}
							}
						}
						
						gui(array);
						
						cin.get(); cin.get();
						exit(0);
					}
					
					else if (array[x][y]=='B')
					{
						continue;
					}
					
					else //if (array[x][y]==' '||'+')
					{
						array[x][y]='+';
					}
				}
				
				else 
				{
					break;
				}
			}
		}
	}
	
	srand(time(0));
	do
	{
		bishop2_row=rand()%8;
		bishop2_col=rand()%8;
	}
	while (!(array[bishop2_row][bishop2_col]=='+'));
	
	for (int i=0 ; i<8 ; i++)
	{
		for (int j=0 ; j<8 ; j++)
		{
			if (array[i][j]=='+')
			{
				array[i][j]=' ';
			}
		}
	}

}

void random_king_move(char (*array)[8])
{
	int iking_row=king_row, iking_col=king_col;
	srand(time(0));
	static int count=0;

	if (iking_row==0&&iking_col==0)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)));	
	}
	
	else if (iking_row==0&&iking_col==7)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col)));	
	}
	
	else if (iking_row==7&&iking_col==0)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)));	
	}
	
	else if (iking_row==7&&iking_col==7)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col)));	
	}
	
	else if (iking_col==0)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)||(king_row==iking_row&&king_col==iking_col+1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)));	
	}
	
	else if (iking_col==7)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col-1)||(king_row==iking_row+1&&king_col==iking_col)));	
	}
	
	else if (iking_row==0)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}	
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)));
	}
	
	else if (iking_row==7)
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}
		while (!((king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row-1&&king_col==iking_col-1)
				||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)));	
	}
	
	else 
	{
		do
		{
			king_row=rand()%8;
			king_col=rand()%8;
			
			if ((king_row==bishop1_row&&king_col==bishop1_col)||(king_row==bishop2_row&&king_col==bishop2_col))
			{
				count++;
			}
		}	
		while (!((king_row==iking_row-1&&king_col==iking_col-1)||(king_row==iking_row-1&&king_col==iking_col)||(king_row==iking_row-1&&king_col==iking_col+1)
				||(king_row==iking_row&&king_col==iking_col-1)||(king_row==iking_row&&king_col==iking_col+1)||(king_row==iking_row+1&&king_col==iking_col-1)
				||(king_row==iking_row+1&&king_col==iking_col)||(king_row==iking_row+1&&king_col==iking_col+1)));
	}

	if (count==2)
	{
		cout<<"\n\nYou Lose!\nBetter Luck next Time..\n";
		array[king_row][king_col]='K';
		gui(array);
		cin.get(); cin.get();
		exit(0);
	}
}
