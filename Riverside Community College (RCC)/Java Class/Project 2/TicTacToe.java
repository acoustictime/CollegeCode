/*
 * Tic Tac Toe Game Class
 * 
 * Controls they whole game of tic tac toe for one player or two.  If two players,
 * second player pretends to be computer.  All computer ai is built into the class
 * and can be run completely independnt of the gui using the console output if programmed
 * to do so.
 */

import java.util.Random; // random number generator used for easy mode random square choosing

public class TicTacToe extends game // subclass of game class
{
	//instance variables
	private final int user = 5;
	private final int comp = 6;
	private int board[][];
	private int compMove;
	private int difficulty = 1;
	private int winningLine = 0;
	private boolean aiDone = false;
	Random randomizer = new Random();
	
	public TicTacToe() // constructor creates and initilizes board array to control board
	{
		board = new int[3][3];
		initialize();		
	}
	
	public void aiWin() // used if computer is going for the win
	{
		for(int row = 0;row < 3;row++) // loops through all three rows checking for possible win
		{
			if((board[row][0] + board[row][1] + board[row][2]) == (comp * 2) && aiDone == false) // if current row could be a win based on for loop above
			{
				for(int i = 0;i < 3;i++) // checks for specific square that is blank
				{
					if(board[row][i] == 0) // if blank, set square to computer number and determine individual square value that changed.
					{
						board[row][i] = comp;
						compMove = (row * 3) + i + 1;
					}
				}
				aiDone = true; // now says computer has made a move
			}	// end if loop
		} // end for loop
		
		for(int col = 0;col < 3;col++) // loops through all three columns checking for possible win
		{
			if((board[0][col] + board[1][col] + board[2][col]) == (comp * 2) && aiDone == false) // if current column could be a win based on for loop above
			{
				for(int i = 0;i < 3;i++) // checks for specific square that is blank
				{
					if(board[i][col] == 0) // if blank, set square to computer number and determine individual square value that changed.
					{
						board[i][col] = comp;
						compMove = (i * 3) + col + 1;
					}
				}
				aiDone = true;  // now says computer has made a move
			}	// end if loop	
		} // end for loop
		
		if((board[0][0] + board[1][1] + board[2][2]) == (comp * 2) && aiDone == false) // if diagnol is win
		{
				
			for(int i = 0;i < 3;i++) // checks for specific square that is blank
			{
				if(board[i][i] == 0)// if blank, set square to computer number and determine individual square value that changed.
				{
					board[i][i] = comp;
					compMove = ((i + i) * 2) + 1;
					aiDone = true; // now says computer has made a move
				} // end if loop
			}	//end for loop
		}	 // end if loop
		
		if((board[0][2] + board[1][1] + board[2][0]) == (comp * 2) && aiDone == false) // if diagnol is win
		{	
			for(int i = 0;i < 3;i++) // checks for specific square that is blank
			{	
				if(board[i][2 - i] == 0) // if blank, set square to computer number and determine individual square value that changed.
				{
					board[i][2 - i] = comp;
					compMove = (i * 3) + (2 - i) + 1;
					aiDone = true; // now says computer has made a move
				} // end if loop
			} // for loop
		}	// end if loop
	} // end aiWin method
	
	public void aiFork() // used to block if user is trying a fork
	{	
		if(board[0][0] == user && board[2][1] == user && board[2][0] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[2][0] = comp;
			compMove = 7;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[0][0] == user && board[1][2] == user && board[0][2] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[0][2] = comp;
			compMove = 3;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][0] == user && board[0][1] == user && board[0][0] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[0][0] = comp;
			compMove = 1;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][0] == user && board[1][2] == user && board[2][2] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[2][2] = comp;
			compMove = 9;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[0][2] == user && board[1][0] == user && board[0][0] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[0][0] = comp;
			compMove = 1;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[0][2] == user && board[2][1] == user && board[2][2] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[2][2] = comp;
			compMove = 9;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][2] == user && board[0][1] == user && board[0][2] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[0][2] = comp;
			compMove = 3;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][2] == user && board[1][0] == user && board[2][0] == 0 && !aiDone) // checks for a specific fork attempt and blocks it, sets square to computer number and determine individual square value that changed.
		{
			board[2][0] = comp;
			compMove = 7;
			aiDone = true; // now says computer has made a move
		}		
	} // end aiFork loop
	
	public void aiBlock() // checks if user is about to win and blocks it.
	{
		for(int row = 0;row < 3;row++) // loops through all rows checking for a block
		{
			if((board[row][0] + board[row][1] + board[row][2]) == (user * 2) && aiDone == false) // if current row needs to be blocked
			{
				for(int i = 0;i < 3;i++) // checks for individual square that needs to be blocked
				{
					if(board[row][i] == 0) // if blank, set square to computer number and determine individual square value that changed.
					{
						board[row][i] = comp;
						compMove = (row * 3) + i + 1;
					}
				} // end for loop
				aiDone = true; // now says computer has made a move
			}	// end if loop	
		} // end for loop
		
		for(int col = 0;col < 3;col++) // loops through all columns checking for a block
		{
			if((board[0][col] + board[1][col] + board[2][col]) == (user * 2) && aiDone == false)  // if current column needs to be blocked
			{
				for(int i = 0;i < 3;i++) // checks for individual square that needs to be blocked
				{
					if(board[i][col] == 0) // if blank, set square to computer number and determine individual square value that changed.
					{
						board[i][col] = comp;
						compMove = (i * 3) + col + 1;
					}
				} // end for loop
				aiDone = true; // now says computer has made a move
			}	// end if loop	
		} // end for loop
		
		if((board[0][0] + board[1][1] + board[2][2]) == (user * 2) && aiDone == false)  // if current diaganol needs to be blocked
		{
			if(board[0][0] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[0][0] = comp;
				compMove = 1;
			}
			
			if(board[1][1] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[1][1] = comp;
				compMove = 5;
			}
			
			if(board[2][2] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[2][2] = comp;
				compMove = 9;
			}
			
			aiDone = true; // now says computer has made a move
		}	 // end if loop
		
		if((board[0][2] + board[1][1] + board[2][0]) == (user * 2) && aiDone == false)  // if current row needs to be blocked
		{

			if(board[0][2] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[0][2] = comp;
				compMove = 3;
			}
			
			if(board[1][1] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[1][1] = comp;
				compMove = 5;
			}
			
			if(board[2][0] == 0) // if blank, set square to computer number and determine individual square value that changed.
			{
				board[2][0] = comp;
				compMove = 7;
			}
			aiDone = true; // now says computer has made a move
		}	// end if loop
		
	} // end aiBlock loop
	
	public void aiCenter() // checks if center square is blank
	{
		if(board[1][1] == 0 && aiDone == false) // if center blank, computer moves there and determines individual square value that changed
		{
			board[1][1] = comp;	
			compMove = 5;
			aiDone = true; // now says computer has made a move
		}
	} // end aiCenter
	
	public void aiOpposite() // checks if opposite square is blank
	{	
		if(board[0][0] == user && aiDone == false)  // checks for specific opposite open square
		{
			if(board[0][1] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[0][1] = comp;
				compMove = 2;
				aiDone = true; // now says computer has made a move
			}
			
			if(board[1][0] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[1][0] = comp;
				compMove = 4;
				aiDone = true; // now says computer has made a move
			}
		} // end if loop
		
		if(board[0][2] == user && aiDone == false)  // checks for specific opposite open square
		{
			if(board[0][1] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[0][1] = comp;
				compMove = 2;
				aiDone = true; // now says computer has made a move
			}
			if(board[1][2] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[1][2] = comp;
				compMove = 6;
				aiDone = true; // now says computer has made a move
			}				
		} // end if loop
		
		if(board[2][0] == user && aiDone == false)  // checks for specific opposite open square
		{
			if(board[1][0] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[1][0] = comp;
				compMove = 4;
				aiDone = true; // now says computer has made a move
			}
			if(board[2][1] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[2][1] = comp;
				compMove = 8;
				aiDone = true; // now says computer has made a move
			}
		} // end if loop
		
		if(board[2][2] == user && aiDone == false)  // checks for specific opposite open square
		{
			if(board[2][1] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[2][1] = comp;
				compMove = 8;
				aiDone = true; // now says computer has made a move
			}
			if(board[1][2] == 0 && aiDone == false) // if opposite is blank,  computer moves there and determines individual square value that changed
			{
				board[1][2] = comp;
				compMove = 6;
				aiDone = true; // now says computer has made a move
			}
		}	// end if loop
	} // end aiOpposite method
	
	public void aiEmptyCorner() // checks for empty corner
	{
		if(board[0][0] == 0 && aiDone == false) // if corner is blank, computer moves there and determines individual square value that changed
		{
			board[0][0] = comp;
			compMove = 1; 
			aiDone = true; // now says computer has made a move
		}
		
		if(board[0][2] == 0 && aiDone == false) // if corner is blank, computer moves there and determines individual square value that changed
		{
			board[0][2] = comp;
			compMove = 3;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][0] == 0 && aiDone == false) // if corner is blank, computer moves there and determines individual square value that changed
		{
			board[2][0] = comp;
			compMove = 7;
			aiDone = true; // now says computer has made a move
		}
		
		if(board[2][2] == 0 && aiDone == false) // if corner is blank, computer moves there and determines individual square value that changed
		{
			board[2][2] = comp;	
			compMove = 9;
			aiDone = true; // now says computer has made a move
		}
	} // end aiEmpty Corner method
	
	public void aiRandom() // randomly selects move
	{
		int random = 0;
		boolean valid = false; // used determine if valid move
		
		while(!valid) // while random number isn't an open square
		{
			random = randomizer.nextInt(9) + 1; // random number 1 to 9
			
			switch(random) // depends on random number
			{
			case 1:
				if(board[0][0] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[0][0] = comp;
					compMove = 1;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 2:
				if(board[0][1] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[0][1] = comp;
					compMove = 2;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 3:
				if(board[0][2] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[0][2] = comp;
					compMove = 3;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 4:
				if(board[1][0] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[1][0] = comp;
					compMove = 4;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 5:
				if(board[1][1] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[1][1] = comp;
					compMove = 5;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 6:
				if(board[1][2] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[1][2] = comp;
					compMove = 6;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 7:
				if(board[2][0] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[2][0] = comp;
					compMove = 7;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 8:
				if(board[2][1] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[2][1] = comp;
					compMove = 8;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			case 9:
				if(board[2][2] == 0 && aiDone == false) // if number selected and square is blank,  computer moves there and determines individual square value that changed
				{
					board[2][2] = comp;
					compMove = 9;
					valid = true; // switch to valid move taken
					aiDone = true; // now says computer has made a move
				}
				break;
			} // end switch
		} // end while not valid move loop
	} // end aiRandom method
	
	public void initialize() // initializes values of board to 0
	{
		for (int row = 0;row < 3;row++)
		{
			for (int col = 0;col < 3;col++)
			{
				board[row][col] = 0;
			}
		}	// end for loop	
		aiDone = false; // resets aiDone value
	} // end initialize method

	public void display() // method used if game was played on console.  Displays pretend board.  Used for initial testing only
	{
		for (int row = 0;row < 3;row++)
		{
			System.out.println(board[row][0] + "|" + board[row][1] + "|" + board[row][2]);
		}		
		System.out.print("\n");
	} // end display method
	
	public void userInput(int space) // takes as a parameter the user selected square and changes appropriate game square in class
	{
		switch (space) // switch for value entered and sets to user value
		{
		case 1:
			board[0][0] = user;
			break;
		case 2:
			board[0][1] = user;
			break;
		case 3:
			board[0][2] = user;
			break;
		case 4:
			board[1][0] = user;
			break;
		case 5:
			board[1][1] = user;
			break;
		case 6:
			board[1][2] = user;
			break;
		case 7:
			board[2][0] = user;
			break;
		case 8:
			board[2][1] = user;
			break;
		case 9:
			board[2][2] = user;
			break;
		} // end switch
	} // end userInput method
	
	public void userInput2(int space2) // takes as a parameter the user # 2 selected square and changes appropriate game square in class
	{
		switch (space2) // switch for value entered and sets to user value
		{
		case 1:
			board[0][0] = comp;
			break;
		case 2:
			board[0][1] = comp;
			break;
		case 3:
			board[0][2] = comp;
			break;
		case 4:
			board[1][0] = comp;
			break;
		case 5:
			board[1][1] = comp;
			break;
		case 6:
			board[1][2] = comp;
			break;
		case 7:
			board[2][0] = comp;
			break;
		case 8:
			board[2][1] = comp;
			break;
		case 9:
			board[2][2] = comp;
			break;
		} // end switch	
	} // end aiUserInput2 method

	public int aiInput() // method to tell computer to make move based on difficutly
	{
		aiDone = false;
		compMove = 0; // value returned based on move selected by computer
		
			/*
			 difficulty easy order: aiWin, aiCenter, aiRandom
			 difficutly hard order: aiWin, aiBlock,aiCenter,aiOpposite,aiEmptyCorner, aiRandom
			 difficulty harder order: aiWin, aiBlock, aiFork,aiCenter,aiOpposite,aiEmptyCorner, aiRandom
			 */

			aiWin();
				
			if(!aiDone && difficulty > 1)	
				aiBlock();	
			if(!aiDone && difficulty == 3)
				aiFork();
			if(!aiDone && difficulty > 0)
				aiCenter();
			if(!aiDone && difficulty > 1)
				aiOpposite();
			if(!aiDone && difficulty > 1)
				aiEmptyCorner();
			if(!aiDone)
				aiRandom();
		return compMove;
	}
	
	public void difficulty(int diff) // method to set game difficulty level
	{
		difficulty = diff;		
	}

	public int checkForWinner() // method to check for winner and returns 1 if user won, 2 if computer won, or 3 if tie
	{
		for(int row = 0;row < 3;row++) // loops through rows to determine if comp won
		{
			if((board[row][0] + board[row][1] + board[row][2]) == (comp * 3)) // if comp won on current row
			{
				winningLine = row + 1; // determine winning line number for gui
				return 2; // return computer won or if two player, player 2 won
			}		
		} // end for loop
		
		for(int col = 0;col < 3;col++) // loops through columns to determine if comp won
		{
			if((board[0][col] + board[1][col] + board[2][col]) == (comp * 3)) // if comp won on current column
			{
				winningLine = col + 4; // determine winning line number for gui
				return 2; // return computer won or if two player, player 2 won
			}		
		} // end for loop
		
		if((board[0][0] + board[1][1] + board[2][2]) == (comp * 3)) // if comp won on diaganol
		{
			winningLine = 7; // determine winning line number for gui
			return 2; // return computer won or if two player, player 2 won
		}	
		
		if((board[0][2] + board[1][1] + board[2][0]) == (comp * 3)) // if comp won on diaganol
		{
			winningLine = 8; // determine winning line number for gui
			return 2; // return computer won or if two player, player 2 won
		}

		for(int row = 0;row < 3;row++) // loops through rows to determine if user won
		{
			if((board[row][0] + board[row][1] + board[row][2]) == (user * 3)) // if user won on current row
			{
				winningLine = row + 1; // determine winning line number for gui
				return 1; // return player 1 won
			}		
		} // end for loop
		
		for(int col = 0;col < 3;col++) // loops through columns to determine if user won
		{
			if((board[0][col] + board[1][col] + board[2][col]) == (user * 3)) // if user won on current column
			{
				winningLine = col + 4; // determine winning line number for gui
				return 1; // return player 1 won
			}		
		} // end for looop
		
		if((board[0][0] + board[1][1] + board[2][2]) == (user * 3)) // if user won on diaganol
		{
			winningLine = 7; // determine winning line number for gui
			return 1; // return player 1 won
		}	
		
		if((board[0][2] + board[1][1] + board[2][0]) == (user * 3)) // if user won on diaganol
		{
			winningLine = 8; // determine winning line number for gui
			return 1; // return player 1 won
		}
		
		// checks if all squares taken and returns 3 for tie
		if(board[0][0] != 0 && board[0][1] != 0 && board[0][2] != 0 && board[1][0] != 0 && board[1][1] != 0 && board[1][2] != 0 && board[2][0] != 0 && board[2][1] != 0 && board[2][2] != 0)
		{
			return 3;
		}
		
		return 0; // returns 0 if no win or tie found
	}	// end checkForWinner method

	public int winningLine() // returns winning line number for gui
	{
		return winningLine;
	}
	
	public void setWinningLine(int winningLine) // set winning line number
	{
		this.winningLine = winningLine;
	}
}
