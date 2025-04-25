#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void initialize_board(char board[][8]);                    //recursive functions and structure used in the process
void checkposition(char board[][8]);
int checkdirection1(char board[][8]);
int checkdirection2(char board[][8]);
void player1(char board[][8]);
void player2(char board[][8]);
void dboard(char board[][8]);
void king(char board[][8]);
int kingposition1(char board[][8]);
int kingposition2(char board[][8]);
struct var
{
	int x;                       //rows of board
	int y;                       //columns of board
	char playername1[20];
	char playername2[20];
	char position[2];            //Position of each piece
	int direction;               //direction to where the piece
	char a;                      //symbol of player 1
	char b;                       //symbol of player 2
	int p1g;                     // number of pieces of player 1
	int p2g;                    // number of pieces of player 2
	int count;                   // counter for turns
	char t1;                    // king symbol of player 1
	char t2;                    //king symbol of player 2
}v;
int main()                                                             
{
	char board[8][8],t1,t2;
	v.t1='k';v.t2='K';
	v.p1g=12,v.p2g=12,v.count=0;
	printf("\033[0;32m");
	printf("\t\t\t\t\tCHECKERS GAME\n");
	printf("\033[0;34m");
	printf("Enter name of player 1: ");
	fflush(stdin);
	scanf("%[^\n]s",v.playername1);
	printf("\nEnter name of player 2: ");
	fflush(stdin);
	scanf("%[^\n]s",v.playername2);
	scheck1:;
	printf("\033[0;35m");
	printf("\nCHOOSE SYMBOLS TO PLAY X OR O\n");
	printf("%s: ",v.playername1);
	fflush(stdin);
	scanf("%c",&v.a);
	printf("%s: ",v.playername2);
	fflush(stdin);
	scanf("%c",&v.b);
	if(v.a==v.b)
	{
		printf("CHOOSE SYMBOLS AGAIN");
		goto scheck1;
	}	
    initialize_board(board);
    player1(board); 
}
void initialize_board(char board[][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			board[i][j]=' ';
		}
	}
	board[0][0]=v.a;board[0][2]=v.a;board[0][4]=v.a;board[0][6]=v.a;
    board[1][1]=v.a;board[1][3]=v.a;board[1][5]=v.a;board[1][7]=v.a;
    board[2][0]=v.a;;board[2][2]=v.a;board[2][4]=v.a;board[2][6]=v.a;
    board[5][1]=v.b;board[5][3]=v.b;board[5][5]=v.b;board[5][7]=v.b;
    board[6][0]=v.b;board[6][2]=v.b;board[6][4]=v.b;board[6][6]=v.b;
    board[7][1]=v.b;board[7][3]=v.b;board[7][5]=v.b;board[7][7]=v.b;
}
void dboard(char board[][8])                           //Displaying the board
{
	system("cls");
	int x,y;
	int z=1;
	printf("\033[0;37m");
	printf("  A  B  C  D  E  F  G  H");
	printf("\n +--+--+--+--+--+--+--+--+\n");
	for(x=0;x<8;x++)
	{
		printf("%d",z);
		for(y=0;y<8;y++)
		{
			printf("|");
			if(board[x][y]=='X' || board[x][y]=='x')
			{
				printf("\033[0;33m");
			    printf("%c ",board[x][y]);
			    printf("\033[0;37m");
		    }
		    else if(board[x][y]=='O' || board[x][y]=='o')
		    {
		    	printf("\033[0;31m");
			    printf("%c ",board[x][y]);
			    printf("\033[0;37m");
			}
			else if(board[x][y]==v.t1 )
			{
				printf("\033[0;33m");
			    printf("%c ",board[x][y]);
			    printf("\033[0;37m");
			}
			else if(board[x][y]==v.t2)
			{
				printf("\033[0;31m");
			    printf("%c ",board[x][y]);
			    printf("\033[0;37m");
			}
			else
			{
				printf("%c ",board[x][y]);
				printf("\033[0;37m");
			}			
		}
		printf("\033[0;37m");
		printf("|");
		printf("%d",z);
		z++;
		printf("\n");
		printf(" +--+--+--+--+--+--+--+--+\n"); 
	}
	printf("  A  B  C  D  E  F  G  H");
}
void player1(char board[][8])
{
	dboard(board);
    printf("\033[0;34m");
    printf("\n%s turn: %c",v.playername1,v.a);
    checkposition(board);
    checkdirection1(board);
}
void player2(char board[][8])
{
	dboard(board);
    printf("\033[;35m");
    fflush(stdin);
    printf("\n %s turn: %c",v.playername2,v.b);
    checkposition(board);
	checkdirection2(board);
}
void checkposition(char board[][8])                                     //positions of all pieces
{
	printf("\nEnter position of piece (ALPHABET)(NUMBER): \n");
    fflush(stdin);
    scanf("%s",v.position);
    if(strlen(v.position)!=2)
    checkposition(board);
    if(v.position[0]=='A' || v.position[0]=='a')
    v.y=0;
    else if(v.position[0]=='B'|| v.position[0]=='b')
    v.y=1;
    else if(v.position[0]=='C'|| v.position[0]=='c')
    v.y=2;
    else if(v.position[0]=='D'|| v.position[0]=='d')
    v.y=3;
    else if(v.position[0]=='E'|| v.position[0]=='e')
    v.y=4;
    else if(v.position[0]=='F'|| v.position[0]=='f')
    v.y=5;
    else if(v.position[0]=='G'|| v.position[0]=='g')
    v.y=6;
    else if(v.position[0]=='H'|| v.position[0]=='h')
    v.y=7;
    else 
    {
    	printf("\ninvalid position\n");
    	checkposition(board);
	}
	if(v.position[1]=='1')
    v.x=0;
    else if(v.position[1]=='2')
    v.x=1;
    else if(v.position[1]=='3')
    v.x=2;
    else if(v.position[1]=='4')
    v.x=3;
    else if(v.position[1]=='5')
    v.x=4;
    else if(v.position[1]=='6')
    v.x=5;
    else if(v.position[1]=='7')
    v.x=6;
    else if(v.position[1]=='8')
    v.x=7;
    else if(v.position[1]>'8')
    {
    	printf("\ninvalid position\n");
        checkposition(board);
	}
	if(v.count%2==0)                                                                 //checks whether player 1 entered its own symbol
	{
		if(board[v.x][v.y]==v.b || board[v.x][v.y]==' ' || board[v.x][v.y]==v.t2)
		{
			printf("\ninvalid position\n");
			checkposition(board);
		}	
	}
	else if(v.count%2!=0)                                                               //checks whether player 2 entered its own symbol
	{
		if(board[v.x][v.y]==v.a || board[v.x][v.y]==' ' || board[v.x][v.y]==v.t1)
		{
			printf("\ninvalid position\n");
			checkposition(board);
		}	
	}
	if(board[v.x][v.y]==v.t2 || board[v.x][v.y]==v.t1)              //checks if king is present
	{	
		king(board);
	}
}
int checkdirection1(char board[][8])                                               ///////checks player1 direction and king of player 1 direction/////
{
	printf("\nCHOOSE DIRECTION TO MOVE IN:\n 1-downward left\n 2-downward right: ");
    scanf("%d",&v.direction);
	if(v.direction==1)
	{
        if(v.y==0 || v.x==7)                          //when piece resides downward or at the left
        {
    	    printf("\ninvalid move\n");
    	    checkposition(board);                         
	    }
	    if(board[v.x+1][v.y-1]==v.a || board[v.x+1][v.y-1]==v.t1)               //if at diagonal lies its own piece
	    {
		    printf("\ninvalid move\n");
		    if(board[v.x+1][v.y+1]==v.a || board[v.x+1][v.y+1]==v.t1)
		    player1(board);
		    else if(board[v.x+1][v.y+1]!=v.a || board[v.x+1][v.y+1]!=v.t1)
		    checkdirection1(board);
	    }
	    if(board[v.x+1][v.y-1]==' ')
	    {
		    if(v.x+1==7)                             //converts player 1 piece to king of player 1
		    {
			    board[v.x+1][v.y-1]=v.t1;
		        board[v.x][v.y]=' ';
		    }
		    else if(v.x+1<7)                        // moves player 1's piece and king
		    {
			    if(board[v.x][v.y]==v.t1)
			    {
				    board[v.x+1][v.y-1]=v.t1;
		            board[v.x][v.y]=' ';
			    }
			    else
			    {
		            board[v.x+1][v.y-1]=v.a;
		            board[v.x][v.y]=' ';
		        }
	        }
	        v.count++;
	        player2(board);
	    }
	    if(board[v.x+1][v.y-1]==v.b || board[v.x+1][v.y-1]==v.t2)          //checks the enemy
	    {
		    if(board[v.x+2][v.y-2]!=' ')                          
		    {
			    printf("\ninvalid position\n");                
    	        checkposition(board);
		    }
		    else if(board[v.x+2][v.y-2]==' ')
		    {
		    	if(v.y-2<0)                            //when jumping direction is outside the array
			    {
			    	checkposition(board);
				}
				else
				{
			        if(v.x+2==7)                              //jumps and becomes king
			        {
				       board[v.x][v.y]=' ';
			           board[v.x+2][v.y-2]=v.t1;
			           board[v.x+1][v.y-1]=' ';
			        }
			        else if(v.x+2<7)                         //jumps and defeats enemy pieces for both player 1's pieces and king
		            {
			            if(board[v.x][v.y]==v.t1)
			            {
			     	       board[v.x][v.y]=' ';
			               board[v.x+2][v.y-2]=v.t1;
			               board[v.x+1][v.y-1]=' ';
				        }
				        else
				        {
			               board[v.x][v.y]=' ';
			               board[v.x+2][v.y-2]=v.a;
			               board[v.x+1][v.y-1]=' ';
			            }
			        }
			        v.p2g--;
			        if(v.p2g==0)                            //terminating statement when player 2 pieces are all gone
		            {
			            system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername1);
		                return 0;
		            }
			        v.count++;
			        player2(board);
			    }
		   }
	    }
    }
    else if(v.direction==2)     
	{
		if(v.y==7 || v.x==7)                  //when piece resides downward or at the right
		{
			printf("\ninvalid position\n");
			checkposition(board);                                  
		}
		if(board[v.x+1][v.y+1]==v.a || board[v.x+1][v.y+1]==v.t1)    //if at diagonal lies its own piece
	    {
		    printf("\ninvalid position\n");
		    if(board[v.x+1][v.y-1]==v.a || board[v.x+1][v.y-1]==v.t1) 
		    player1(board);
		    else if(board[v.x+1][v.y-1]!=v.a || board[v.x+1][v.y-1]!=v.t1 )
		    checkdirection1(board);
	    }
	    if(board[v.x+1][v.y+1]==' ')
	    {
		   if(v.x+1==7)                      //converts player 1 piece to king of player 1
		   {
			   board[v.x+1][v.y+1]=v.t1;
		       board[v.x][v.y]=' ';
		   }
		   else if(v.x+1<7)
		   {   if(board[v.x][v.y]==v.t1)           // moves player 1's piece and king
		       {
		   	        board[v.x+1][v.y+1]=v.t1;
		            board[v.x][v.y]=' ';
		       }
		       else
		       {
		            board[v.x+1][v.y+1]=v.a;
		            board[v.x][v.y]=' ';
		       }
	       }
	        v.count++;
	        player2(board);
	    }
	    if(board[v.x+1][v.y+1]==v.b || board[v.x+1][v.y+1]==v.t2)       //checks the enemy
	    {
		    if(board[v.x+2][v.y+2]!=' ')
		    {
			    printf("\ninvalid move\n");
    	        checkposition(board);
		    }
		    else if(board[v.x+2][v.y+2]==' ')
		    {
		    	if(v.y+2>7)                             //when jumping direction is outside the array
		    	{
		    		checkposition(board);
				}
				else
				{
		    	    if(v.x+2==7)                       //jumps and becomes king
		    	    {
		    		   board[v.x][v.y]=' ';
			           board[v.x+2][v.y+2]=v.t1;
			           board[v.x+1][v.y+1]=' ';
				    }
				    else if(v.x<7)
				    {    if(board[v.x][v.y]==v.t1)           //jumps and defeats enemy pieces for both player 1's pieces and king
				        {
					        board[v.x][v.y]=' ';
			                board[v.x+2][v.y+2]=v.t1;
			                board[v.x+1][v.y+1]=' ';
				        }
					    else
					    {
					       board[v.x][v.y]=' ';
			               board[v.x+2][v.y+2]=v.a;
			               board[v.x+1][v.y+1]=' ';
			            }
				    }
			        v.p2g--;
			        if(v.p2g==0)
		            {
			            system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername1);
		                return 0;
		            }
			        v.count++;
			        player2(board);
			    }
			}
		}
    }
    else
    {
    	printf("\ninvalid position\n");
    	checkdirection1(board);
	}
    }
int checkdirection2(char board[][8])                                                    //////player2 direction and king2 direction////////
{
	printf("\nCHOOSE DIRECTION TO MOVE IN:\n 3-upward left\n 4-upward right: ");
	scanf("%d",&v.direction);
    if(v.direction==3)                         
	{
	    if(v.y==0 || v.x==0)              //when piece resides upward or at the left in board
        {
    	    printf("\ninvalid move\n");
    	    checkposition(board);                         
	    }
	    if(board[v.x-1][v.y-1]==v.b || board[v.x-1][v.y-1]==v.t2)               //if at diagonal lies its own piece
	    {
		    printf("\ninvalid move\n");
		    if(board[v.x-1][v.y+1]==v.b || board[v.x-1][v.y+1]==v.t2)
		    player2(board);
		    else if(board[v.x-1][v.y+1]!=v.b || board[v.x-1][v.y+1]!=v.t2)
    	    checkdirection2(board);
	    }
	    else if(board[v.x-1][v.y-1]==' ')
	    {
		    if(v.x-1==0)                        //converts player 2 piece to king of player 2
		    {
			   board[v.x-1][v.y-1]=v.t2;
		       board[v.x][v.y]=' ';
		    }
		    else if(v.x>0)                   // moves player 2's piece and king
		    {
			   if(board[v.x][v.y]==v.t2)      
			   {
				   board[v.x-1][v.y-1]=v.t2;
		           board[v.x][v.y]=' ';
			   }
			   else
			   {
			       board[v.x-1][v.y-1]=v.b;
		           board[v.x][v.y]=' ';
		       }
		    }
		    v.count++;
		    player1(board);
	    }
	    else if(board[v.x-1][v.y-1]==v.a || board[v.x-1][v.y-1]==v.t1)     //checks the enemy
	    {
		    if(board[v.x-2][v.y-2]!=' ')
		    {
			    printf("\ninvalid position\n");
    	        checkposition(board);
		    }
		    else if(board[v.x-2][v.y-2]==' ')
		    {
		    	if(v.y-2<0)                                //when jumping direction is outside the array
		    	{
		    		checkposition(board);
				}
				else
				{
			        if(v.x-2==0)                   //jumps and becomes king
			        {
				        board[v.x][v.y]=' ';
			            board[v.x-2][v.y-2]=v.t2;
			            board[v.x-1][v.y-1]=' ';
			        }
			        else if(v.x-2>0)               //jumps and defeats enemy pieces for both player 2's pieces and king
			        {
			    	    if(board[v.x][v.y]==v.t2)
			    	    {
			    		    board[v.x][v.y]=' ';
			                board[v.x-2][v.y-2]=v.t2;
			                board[v.x-1][v.y-1]=' ';
					    }
					    else
					    {
			                board[v.x][v.y]=' ';
			                board[v.x-2][v.y-2]=v.b;
			                board[v.x-1][v.y-1]=' ';
			            }
		            }
			        v.p1g--;
			        if(v.p1g==0)
	                {
     	                system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername2);
		                return 0;
	                }
			        v.count++;
			        player1(board);
			    }
		    }
	    }
    }
	else if(v.direction==4)                      
	{
		if(v.y==7 || v.x==0)                                //when piece resides upward or at the right in board
		{
			printf("\ninvalid position\n");
			checkposition(board);
		}
		if(board[v.x-1][v.y+1]==v.b || board[v.x-1][v.y+1]==v.t2)         //if at diagonal lies its own piece
	    {
		    printf("\ninvalid position\n");
		    if(board[v.x-1][v.y-1]==v.b || board[v.x-1][v.y-1]==v.t2)
		    player2(board);
		    else if(board[v.x-1][v.y-1]!=v.b || board[v.x-1][v.y-1]!=v.t2)
    	    checkdirection2(board); 
	    }
	    else if(board[v.x-1][v.y+1]==' ')
	    {
		    if(v.x-1==0)                                      //converts player 2 piece to king of player 2
		    {
			   board[v.x-1][v.y+1]=v.t2;
		       board[v.x][v.y]=' ';
		    }
		    else if(v.x>0)                                // moves player 2's piece and king
		    {
		    	if(board[v.x][v.y]==v.t2)
		    	{
		    		board[v.x-1][v.y+1]=v.t2;
		            board[v.x][v.y]=' ';
				}
				else
				{
					board[v.x-1][v.y+1]=v.b;
		            board[v.x][v.y]=' ';
				}
		    }
		    v.count++;
		    player1(board);
	    }
	    else if(board[v.x-1][v.y+1]==v.a || board[v.x-1][v.y+1]==v.t1)     //checks the enemy
	    {
		    if(board[v.x-2][v.y+2]!=' ')
		    {
			    printf("\ninvalid position\n");
    	       checkdirection2(board);
		    }
		    else if(board[v.x-2][v.y+2]==' ')
		    {
		    	if(v.y+2>7)                             //when jumping direction is outside the array
		    	{
		    		checkposition(board);
				}
				else
				{
			        if(v.x-2==0)                            //jumps and becomes king
			        {
				       board[v.x][v.y]=' ';
			           board[v.x-2][v.y+2]=v.t2;                                  
			           board[v.x-1][v.y+1]=' ';
			        }
			        else if(v.x-2>0)
			        {
			    	    if(board[v.x][v.y]==v.t2)               //jumps and defeats enemy pieces for both player 2's pieces and king
			    	    {
			    		   board[v.x][v.y]=' ';
			               board[v.x-2][v.y+2]=v.t2;
			               board[v.x-1][v.y+1]=' ';
					   }
					    else
					    {
			               board[v.x][v.y]=' ';
			               board[v.x-2][v.y+2]=v.b;
			               board[v.x-1][v.y+1]=' ';
			            }
		            }
			        v.p1g--;
			        if(v.p1g==0)
			        {
				        system("cls");
				        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername2);
				        return 0;
			        }
		     	    v.count++;
			        player1(board);
			    }
			}
		}
    }
    else
    {
    	printf("\ninvalid position\n");
    	checkdirection2(board);
	}
}
void king(char board[][8])
{
	int a;
	printf("CHOOSE OBJECTIVE FOR PIECE:\n1-UP   2-DOWN: ");
	scanf("%d",&a);
	if(a==1)           //for upwards(direction2 is for origonally for player 2 but player 2 king can also be used for this)
	{
		if(v.x!=0)    
		{
		    if(board[v.x][v.y]==v.t2)               
		    checkdirection2(board);
		    else if(board[v.x][v.y]==v.t1)
		    kingposition1(board);
	    }
	    else if(v.x==0)                 //checking whether it is at the highest upper side of the board
	    {
	    	checkposition(board);
		}
	}
	if(a==2)          //for downwards(direction1 is for origonally for player 1 but player 1 king can also be used for this)
	{
		if(v.x!=7)
		{
		    if(board[v.x][v.y]==v.t1)
		    checkdirection1(board);
		    else if(board[v.x][v.y]==v.t2)
		    kingposition2(board);
	    }
	    else if(v.x==7)            //checking whether it is at the lowest downward side of the board
	    {
	    	checkposition(board);
		}
	}	
}
int kingposition1(char board[][8])             //same function as player 2's direction if-else conditions but replaced the symbols to player 1's(making it functional for king1 at upward direction) 
{
	printf("\nCHOOSE DIRECTION TO MOVE IN:\n 3-upward left\n 4-upward right: ");
	scanf("%d",&v.direction);
    if(v.direction==3)
	{
        if(v.y==0 || v.x==0)
        {
    	    printf("\ninvalid move\n");
    	    checkposition(board);                         
	    }
	    if(board[v.x-1][v.y-1]==v.a || board[v.x-1][v.y-1]==v.t1)
	    {
		    printf("\ninvalid move\n");
		    if(board[v.x-1][v.y+1]==v.a || board[v.x-1][v.y+1]==v.t1)
		    player1(board);
		    else if(board[v.x-1][v.y+1]!=v.a || board[v.x-1][v.y+1]!=v.t1)
    	    kingposition1(board);
	    }
	    else if(board[v.x-1][v.y-1]==' ')
	    {
		    if(v.x-1==0)
		    {
			   board[v.x-1][v.y-1]=v.t1;
		       board[v.x][v.y]=' ';
		    }
		    else if(v.x>0)
		    {
			   if(board[v.x][v.y]==v.t1)
			   {
				   board[v.x-1][v.y-1]=v.t1;
		           board[v.x][v.y]=' ';
			   }
			   else
			   {
			       board[v.x-1][v.y-1]=v.a;
		           board[v.x][v.y]=' ';
		       }
		    }
		    v.count++;
		    player2(board);
	    }
	    else if(board[v.x-1][v.y-1]==v.b || board[v.x-1][v.y-1]==v.t2)
	    {
		    if(board[v.x-2][v.y-2]!=' ')
		    {
			    printf("\ninvalid position\n");
    	        checkposition(board);
		    }
		    else if(board[v.x-2][v.y-2]==' ')
		    {
		    	if(v.y-2<0)
		    	{
		    		checkposition(board);
				}
				else
				{
			        if(v.x-2==0)
			        {
				        board[v.x][v.y]=' ';
			            board[v.x-2][v.y-2]=v.t1;
			            board[v.x-1][v.y-1]=' ';
			        }
			        else if(v.x-2>0)
			        {
			    	    if(board[v.x][v.y]==v.t1)
			    	    {
			    		    board[v.x][v.y]=' ';
			                board[v.x-2][v.y-2]=v.t1;
			                board[v.x-1][v.y-1]=' ';
					    }
					    else
					    {
			                board[v.x][v.y]=' ';
			                board[v.x-2][v.y-2]=v.a;
			                board[v.x-1][v.y-1]=' ';
			            }
		            }
			        v.p2g--;
			        if(v.p2g==0)
	                {
     	                system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername1);
		                return 0;
	                }
			        v.count++;
			        player2(board);
			    }
		    }
	    }
    }
	else if(v.direction==4)                      
	{
		if(v.y==7 || v.x==0)
		{
			printf("\ninvalid position\n");
			checkposition(board);
		}
		if(board[v.x-1][v.y+1]==v.a || board[v.x-1][v.y+1]==v.t1)
	    {
		    printf("\ninvalid position\n");
		    if(board[v.x-1][v.y-1]==v.a || board[v.x-1][v.y-1]==v.t1)
		    player1(board);
		    else if(board[v.x-1][v.y-1]!=v.a || board[v.x-1][v.y-1]!=v.t1)
    	    kingposition1(board); 
	    }
	    else if(board[v.x-1][v.y+1]==' ')
	    {
		    if(v.x-1==0)
		    {
			   board[v.x-1][v.y+1]=v.t1;
		       board[v.x][v.y]=' ';
		    }
		    else if(v.x>0)
		    {
		    	if(board[v.x][v.y]==v.t1)
		    	{
		    		board[v.x-1][v.y+1]=v.t1;
		            board[v.x][v.y]=' ';
				}
				else
				{
					board[v.x-1][v.y+1]=v.a;
		            board[v.x][v.y]=' ';
				}
		    }
		    v.count++;
		    player2(board);
	    }
	    else if(board[v.x-1][v.y+1]==v.b || board[v.x-1][v.y+1]==v.t2)
	    {
		    if(board[v.x-2][v.y+2]!=' ')
		    {
			    printf("\ninvalid position\n");
    	       checkposition(board);
		    }
		    else if(board[v.x-2][v.y+2]==' ')
		    {
		    	if(v.y+2>7)
		    	{
		    		checkposition(board);
				}
				else
				{
			        if(v.x-2==0)
			        {
				        board[v.x][v.y]=' ';
			            board[v.x-2][v.y+2]=v.t1;                                   
			            board[v.x-1][v.y+1]=' ';
			        }
			        else if(v.x-2>0)
			        {
			    	    if(board[v.x][v.y]==v.t1)
			    	    {
			    		   board[v.x][v.y]=' ';
			               board[v.x-2][v.y+2]=v.t1;
			               board[v.x-1][v.y+1]=' ';
					    }
					    else
					    {
			               board[v.x][v.y]=' ';
			               board[v.x-2][v.y+2]=v.a;
			               board[v.x-1][v.y+1]=' ';
			             }
		            }
			        v.p2g--;
			        if(v.p2g==0)
			        {
				        system("cls");
				        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername1);
				        return 0;
			        }
		     	    v.count++;
			        player2(board);
			    }
			}
		}
    }
    else
    {
    	printf("\ninvalid position\n");
    	kingposition1(board);
	}
}
int kingposition2(char board[][8])             //same function as player 2's direction if-else conditions but replaced the symbols to player 1's(making it functional for king2 at downward direction)
{
	printf("\nCHOOSE DIRECTION TO MOVE IN:\n 1-downward left\n 2-downward right: ");
    scanf("%d",&v.direction);
	if(v.direction==1)
	{
        if(v.y==0 || v.x==7)
        {
    	    printf("\ninvalid move\n");
    	    checkposition(board);                         
	    }
	    if(board[v.x+1][v.y-1]==v.b || board[v.x+1][v.y-1]==v.t2)
	    {
		    printf("\ninvalid move\n");
		    if(board[v.x+1][v.y+1]==v.b || board[v.x+1][v.y+1]==v.t2)
		    player2(board);
		    else if(board[v.x+1][v.y+1]!=v.b || board[v.x+1][v.y+1]!=v.t2)
		    kingposition2(board);
	    }
	    if(board[v.x+1][v.y-1]==' ')
	    {
		    if(v.x+1==7)
		    {
			    board[v.x+1][v.y-1]=v.t2;
		        board[v.x][v.y]=' ';
		    }
		    else if(v.x+1<7)
		    {
			    if(board[v.x][v.y]==v.t2)
			    {
				    board[v.x+1][v.y-1]=v.t2;
		            board[v.x][v.y]=' ';
			    }
			    else
			    {
		            board[v.x+1][v.y-1]=v.b;
		            board[v.x][v.y]=' ';
		        }
	        }
	        v.count++;
	        player1(board);
	    }
	    if(board[v.x+1][v.y-1]==v.a || board[v.x+1][v.y-1]==v.t1)
	    {
		    if(board[v.x+2][v.y-2]!=' ')
		    {
			    printf("\ninvalid position\n");
    	        kingposition2(board);
		    }
		    else if(board[v.x+2][v.y-2]==' ')
		    {
		    	if(v.y-2<0)
		    	{
		    		checkposition(board);
				}
				else
				{
			       if(v.x+2==7)
			       {
				        board[v.x][v.y]=' ';
			            board[v.x+2][v.y-2]=v.t2;
			            board[v.x+1][v.y-1]=' ';
			       }
			       else if(v.x+2<7)
		           {
			            if(board[v.x][v.y]==v.t2)
			            {
			     	        board[v.x][v.y]=' ';
			                board[v.x+2][v.y-2]=v.t2;
			                board[v.x+1][v.y-1]=' ';
				        }
				        else
				        {
			                board[v.x][v.y]=' ';
			                board[v.x+2][v.y-2]=v.b;
			                board[v.x+1][v.y-1]=' ';
			            }
		            }
			        v.p1g--;
			        if(v.p1g==0)
		            {
			             system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername2);
		                return 0;
		            }
			        v.count++;
			        player1(board);
			    }
		    }
	    }
    }
    else if(v.direction==2)
	{
		if(v.y==7 || v.x==7)
		{
			printf("\ninvalid position\n");
			checkposition(board);                                  
		}
		if(board[v.x+1][v.y+1]==v.b || board[v.x+1][v.y+1]==v.t2)
	    {
		    printf("\ninvalid position\n");
		    
		    if(board[v.x+1][v.y-1]==v.b || board[v.x+1][v.y-1]==v.t2) 
		    player2(board);
		    else if(board[v.x+1][v.y-1]!=v.b || board[v.x+1][v.y-1]!=v.t2 )
		    kingposition2(board);
	    }
	    if(board[v.x+1][v.y+1]==' ')
	    {
		   if(v.x+1==7)
		   {
			   board[v.x+1][v.y+1]=v.t2;
		       board[v.x][v.y]=' ';
		   }
		   else if(v.x+1<7)
		   {   if(board[v.x][v.y]==v.t2)
		       {
		   	        board[v.x+1][v.y+1]=v.t2;
		            board[v.x][v.y]=' ';
		       }
		       else
		       {
		            board[v.x+1][v.y+1]=v.b;
		            board[v.x][v.y]=' ';
		       }
	       }
	        v.count++;
	        player1(board);
	    }
	    if(board[v.x+1][v.y+1]==v.a || board[v.x+1][v.y+1]==v.t1)
	    {
		    if(board[v.x+2][v.y+2]!=' ')
		    {
			    printf("\ninvalid moves\n");
    	        kingposition2(board);
		    }
		    else if(board[v.x+2][v.y+2]==' ')
		    {
		    	if(v.y+2>7)
		    	{
		    		checkposition(board);
				}
				else
				{
		    	    if(v.x+2==7)
		    	    {
		    		    board[v.x][v.y]=' ';
			            board[v.x+2][v.y+2]=v.t2;
			            board[v.x+1][v.y+1]=' ';
				    }
				    else if(v.x<7)
				    {   if(board[v.x][v.y]==v.t2)
				        {
					        board[v.x][v.y]=' ';
			                board[v.x+2][v.y+2]=v.t2;
			                board[v.x+1][v.y+1]=' ';
				        }
					    else
					    {
					        board[v.x][v.y]=' ';
			                board[v.x+2][v.y+2]=v.b;
			                board[v.x+1][v.y+1]=' ';
			            }
				    }
			        v.p1g--;
			        if(v.p1g==0)
		            {
			            system("cls");
		                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%s wins",v.playername2);
		                return 0;
		            }
			        v.count++;
			        player1(board);
			    }
			}
		}
    }
    else
    {
    	printf("\ninvalid position\n");
    	kingposition2(board);
	}
}




    
	