/*
 Game Class
 
 Controls wins, loses, and ties for any game.  1 player vs cpu or two player
 */


public class game 
{
	//Instance variables for wins, losses, and ties
	private int player1Wins,player2Wins,cpuWins;
	private int player1Losses,player2Losses,cpuLosses;
	private int player1Ties,player2Ties,cpuTies;
	
	public game() // constructor sets all variables to 0
	{
		player1Wins = 0;
		player2Wins = 0;
		cpuWins = 0;
		player1Losses = 0;
		player2Losses = 0;
		cpuLosses = 0;
		player1Ties = 0;
		player2Ties = 0;
		cpuTies = 0;
	}
	
	public void player1WinsIncrease() // increases player 1 wins by 1
	{
		player1Wins++;
	}
	
	public void player2WinsIncrease() // increases player 2 wins by 1
	{
		player2Wins++;
	}
	
	public void cpuWinsIncrease() // increases cpu wins by 1
	{
		cpuWins++;
	}
	
	public void player1LossesIncrease() // increases player 1 losses by 1
	{
		player1Losses++;
	}
	
	public void player2LossesIncrease() // increases player 2 losses by 1
	{
		player2Losses++;
	}
	
	public void cpuLossesIncrease() // increases cpu losses by 1
	{
		cpuLosses++;
	}
	
	public void player1TiesIncrease() // increases player 1 ties by 1
	{
		player1Ties++;
	}
	
	public void player2TiesIncrease() // increases player 2 ties by 1
	{
		player2Ties++;
	}
	
	public void cpuTiesIncrease() // increases cpu ties by 1
	{
		cpuTies++;
	}
	
	public int getPlayer1Wins() // get player 1 wins
	{
		return player1Wins;
	}
	
	public int getPlayer2Wins() // get player 2 wins
	{
		return player2Wins;
	}
	
	public int getCpuWins() // get cpu wins
	{
		return cpuWins;
	}
	
	public int getPlayer1Losses() // get player 1 losses
	{
		return player1Losses;
	}
	
	public int getPlayer2Losses()  // get player 2 losses
	{
		return player2Losses;
	}
	
	public int getCpuLosses()  // get cpu losses
	{
		return cpuLosses;
	}
	
	public int getPlayer1Ties()  // get player 1 ties
	{
		return player1Ties;
	}
	
	public int getPlayer2Ties()   // get player 2 ties
	{
		return player2Ties;
	}
	
	public int getCpuTies()  // get cpu ties
	{
		return cpuTies;
	}
}
