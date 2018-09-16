import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;

public class TicTacToeGame extends JApplet implements ActionListener {

	private static final long serialVersionUID = 10101010;
	private Container c;
	private JLabel middle,middle2,bottom,player1Wins,player2Wins,cpuWins,player1Losses,player2Losses,cpuLosses,player1Ties,player2Ties,cpuTies;
	private JRadioButton easy,hard,harder,players,cpu;
	private JButton newGame,help,grid[];
	private JPanel left,center,right,bleft,bcenter,bright,top;
	private Border bevel;
	
	private boolean gameOn = false, helpMenu = false;
	private int compMove;
	private boolean twoPlayer = false;
	private int turn = 1;
	private int difficulty = 1;
	private Font f = new Font("Dialog", Font.PLAIN, 148);
	
	TicTacToe ttt = new TicTacToe();

	public void init()
	{		
		guiSetup(); // Run's method to setup gui
	} // end init method

	public void actionPerformed( ActionEvent e ) // waits for action performed
	{	
		if(e.getSource() == hard)
		{
			easy.setSelected(false);
			harder.setSelected(false);
			difficulty = 2;
		}
		
		if(e.getSource() == easy)
		{
			hard.setSelected(false);
			harder.setSelected(false);
			difficulty = 1;
		}
		
		if(e.getSource() == harder)
		{
			easy.setSelected(false);
			hard.setSelected(false);
			difficulty = 3;
		}
		
		if(e.getSource() == players)
		{
			cpu.setSelected(false);	
			twoPlayer = true;
		}
		
		if(e.getSource() == cpu)
		{
			players.setSelected(false);
			twoPlayer = false;
		}
		
		if(e.getSource() == help)
			help();
		
		for(int i = 1;i <= 9;i++)
		{
			if(!twoPlayer)
			{
				if(e.getSource() == grid[i])
				{
					grid[i].setEnabled(false);
					grid[i].setText("X");
					ttt.userInput(i);		
				
					if(ttt.checkForWinner() != 0)
					{
						gameOver(ttt.checkForWinner());
						break;
					}
				
					if(gameOn)
					{
						compMove = ttt.aiInput();
						grid[compMove].setText("O");
						grid[compMove].setEnabled(false);
					
				
						if(ttt.checkForWinner() != 0)
						{
							gameOver(ttt.checkForWinner());
							break;
						}
					} // end game on if
				} // end button get source
			} // end if two player
			else
			{
				if(e.getSource() == grid[i])
				{
					if(turn == 1 && gameOn)
					{			
						grid[i].setEnabled(false);
						grid[i].setText("X");
						ttt.userInput(i);
					
				
						if(ttt.checkForWinner() != 0)
						{
							gameOver(ttt.checkForWinner());
							break;
						}
					
						turn = 2;
					}
					else if(turn == 2 && gameOn)
					{
						grid[i].setEnabled(false);
						grid[i].setText("O");
						ttt.userInput2(i);	
				
						if(ttt.checkForWinner() != 0)
						{
							gameOver(ttt.checkForWinner());
							break;
						}
					
						turn = 1;
					}
				}	
			}
		} // end for loop for buttons
		
		if(e.getSource() == newGame)
		{
			if(gameOn)
			{
				easy.setEnabled(true);
				hard.setEnabled(true);
				harder.setEnabled(true);
				cpu.setEnabled(true);
				players.setEnabled(true);
				newGame.setText("New Game");
				gameOn = false;
				
				for(int i = 1;i <= 9;i++)
				{
					grid[i].setEnabled(false);
					grid[i].setText("");
					grid[i].setBackground(Color.white);
				}
				ttt.initialize();		
			}
			else
			{
				easy.setEnabled(false);
				hard.setEnabled(false);
				harder.setEnabled(false);
				cpu.setEnabled(false);
				players.setEnabled(false);
				newGame.setText("Quit Game");
				gameOn = true;
				
				for(int i = 1;i <= 9;i++)
				{
					grid[i].setEnabled(true);
				}
				
				ttt.difficulty(difficulty);			
			}	
		}	
	} // end action performed method
	
	public void help()
	{
		if(helpMenu)
		{
			helpMenu = false;
			middle.setVisible(true);
			easy.setEnabled(true);
			hard.setEnabled(true);
			harder.setEnabled(true);
			cpu.setEnabled(true);
			players.setEnabled(true);
			newGame.setEnabled(true);
			help.setText("Help Menu");	

		}
		else
		{
			helpMenu = true;
			middle.setVisible(false);
			easy.setEnabled(false);
			hard.setEnabled(false);
			harder.setEnabled(false);
			cpu.setEnabled(false);
			players.setEnabled(false);
			newGame.setEnabled(false);
			help.setText("Return to Game");	
			c.add(middle2, BorderLayout.CENTER);
			
		}
		
	}

	public void gameOver(int winner)
	{
		
		highlightWinner();
		ttt.setWinningLine(0);
		
		if(twoPlayer)
		{
			if(winner == 1)
			{
				ttt.player1WinsIncrease();
				ttt.player2LossesIncrease();
				JOptionPane.showMessageDialog(
						null,"Player 1 Won!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
			}
			else if (winner == 2)
			{
				ttt.player2WinsIncrease();
				ttt.player1LossesIncrease();
				JOptionPane.showMessageDialog(
						null,"Player 2 Won!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
				
			}
			else if (winner == 3)
			{
				ttt.player1TiesIncrease();
				ttt.player2TiesIncrease();
				JOptionPane.showMessageDialog(
						null,"It's a tie!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
			}
		}
		else
		{
			if(winner == 1)
			{
				ttt.player1WinsIncrease();
				ttt.cpuLossesIncrease();
				JOptionPane.showMessageDialog(
						null,"Player 1 Won!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
			}
			else if (winner == 2)
			{
				ttt.cpuWinsIncrease();
				ttt.player1LossesIncrease();
				JOptionPane.showMessageDialog(
						null,"You Lost!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
			}
			else if (winner == 3)
			{
				ttt.player1TiesIncrease();
				ttt.cpuTiesIncrease();
				JOptionPane.showMessageDialog(
						null,"It's a tie!!!!!!!","Tic Tac Toe",
						JOptionPane.INFORMATION_MESSAGE );
			}	
		}
		
		refreshBottomDisplay();

		for(int i = 1;i <= 9;i++)
		{
			grid[i].setEnabled(false);
		}		
	}
		
	public void highlightWinner()
	{
		switch(ttt.winningLine())
		{
		case 1:
			grid[1].setBackground(new Color(185,211,238));
			grid[2].setBackground(new Color(185,211,238));
			grid[3].setBackground(new Color(185,211,238));
			break;
		case 2:
			grid[4].setBackground(new Color(185,211,238));
			grid[5].setBackground(new Color(185,211,238));
			grid[6].setBackground(new Color(185,211,238));
			break;
		case 3:
			grid[7].setBackground(new Color(185,211,238));
			grid[8].setBackground(new Color(185,211,238));
			grid[9].setBackground(new Color(185,211,238));
			break;
		case 4:
			grid[1].setBackground(new Color(185,211,238));
			grid[4].setBackground(new Color(185,211,238));
			grid[7].setBackground(new Color(185,211,238));
			break;
		case 5:
			grid[2].setBackground(new Color(185,211,238));
			grid[5].setBackground(new Color(185,211,238));
			grid[8].setBackground(new Color(185,211,238));
			break;
		case 6:
			grid[3].setBackground(new Color(185,211,238));
			grid[6].setBackground(new Color(185,211,238));
			grid[9].setBackground(new Color(185,211,238));
			break;
		case 7:
			grid[1].setBackground(new Color(185,211,238));
			grid[5].setBackground(new Color(185,211,238));
			grid[9].setBackground(new Color(185,211,238));
			break;
		case 8:
			grid[3].setBackground(new Color(185,211,238));
			grid[5].setBackground(new Color(185,211,238));
			grid[7].setBackground(new Color(185,211,238));
			break;
		}
		
	}
	
	public void refreshBottomDisplay()
	{
		player1Wins.setText("Wins = " + ttt.getPlayer1Wins());
		player2Wins.setText("Wins = " + ttt.getPlayer2Wins());
		cpuWins.setText("Wins = " + ttt.getCpuWins());
		
		player1Losses.setText("Losses = " + ttt.getPlayer1Losses());
		player2Losses.setText("Losses = " + ttt.getPlayer2Losses());
		cpuLosses.setText("Losses = " + ttt.getCpuLosses());
		
		player1Ties.setText("Ties = " + ttt.getPlayer1Ties());
		player2Ties.setText("Ties = " + ttt.getPlayer2Ties());
		cpuTies.setText("Ties = " + ttt.getCpuTies());
	}
	
	public void guiSetup() // Setup Gui portion of program
	{		
		c = getContentPane(); // Setup container with gridlayout with 1 column
	
		bevel = BorderFactory.createRaisedBevelBorder();
		TitledBorder titlePlayer1 = BorderFactory.createTitledBorder(bevel, "Player 1");
		titlePlayer1.setTitleJustification(TitledBorder.CENTER);
		TitledBorder titlePlayer2 = BorderFactory.createTitledBorder(bevel, "Player 2");
		titlePlayer2.setTitleJustification(TitledBorder.CENTER);
		TitledBorder titleCpu = BorderFactory.createTitledBorder(bevel, "CPU");
		titleCpu.setTitleJustification(TitledBorder.CENTER);
		
		top = new JPanel();
		top.setOpaque(true);
		top.setBackground(new Color(185,211,238));
		top.setPreferredSize(new Dimension(800,50));
		top.setLayout(new GridLayout(0,3));
		
		left = new JPanel();
		left.setOpaque(true);
		left.setBackground(new Color(185,211,238));
		left.setPreferredSize(new Dimension(800,50));
		left.setBorder(bevel);
		left.setLayout(new GridLayout(0,2));
		
		center = new JPanel();
		center.setBackground(new Color(185,211,238));
		center.setPreferredSize(new Dimension(800,50));
		center.setBorder(bevel);
		center.setLayout(new GridLayout(0,3));
		
		right = new JPanel();
		right.setBackground(new Color(185,211,238));
		right.setPreferredSize(new Dimension(800,50));
		right.setBorder(bevel);
		right.setLayout(new GridLayout(0,2));
		
		top.add(left);
		top.add(center);
		top.add(right);
		
		easy = new JRadioButton("Easy");
		easy.setBackground(new Color(185,211,238));
		easy.setSelected(true);
		easy.addActionListener(this);
		
		hard = new JRadioButton("Hard");
		hard.setBackground(new Color(185,211,238));
		hard.addActionListener(this);
		
		harder = new JRadioButton("Hardest");
		harder.setBackground(new Color(185,211,238));
		harder.addActionListener(this);
		
		players = new JRadioButton("Player Vs Player");
		players.setBackground(new Color(185,211,238));
		players.addActionListener(this);
		
		cpu = new JRadioButton("Player Vs Cpu");
		cpu.setBackground(new Color(185,211,238));
		cpu.setSelected(true);
		cpu.addActionListener(this);
		
		newGame = new JButton("Start Game");
		newGame.addActionListener(this);
		help = new JButton("Help Menu");
		help.addActionListener(this);
		
		left.add(newGame);
		left.add(help);
		center.add(easy);
		center.add(hard);
		center.add(harder);
		right.add(players);
		right.add(cpu);
		
		middle2 = new JLabel("<html>****** Help Menu ******<br></br>This is a just a simple game of tic tac toe.  If you're playing<br></br>" +
																   "against the computer, specifiy the difficulty with the radio buttons.<br></br>" +
																   "See if you can beat the computer on the hardest difficulty setting.<br></br>" +
																   "It's pretty much impossible.  If you'd like to play with two human<br></br>" +
																   "players, select the appropriate radio button.  Once you have your<br></br>" +
																   "settings selected, press Start Game.  Click the appropriate square youd'd<br></br>" +
																   "like to select.  That's pretty much it.</html>");
		middle2.setBackground(Color.darkGray);
		middle2.setPreferredSize(new Dimension(600,600));
		middle2.setLayout(new FlowLayout());
		middle2.setHorizontalAlignment( SwingConstants.CENTER );
		middle2.setVerticalAlignment( SwingConstants.CENTER );


		middle = new JLabel();
		middle.setBackground(Color.darkGray);
		middle.setPreferredSize(new Dimension(600,600));
		middle.setLayout(new GridLayout(3,3));

		grid = new JButton[10];
		
		for(int i = 1;i <= 9;i++)
		{
			grid[i] = new JButton();
			grid[i].addActionListener(this);
			grid[i].setOpaque(true);
			grid[i].setFont(f);
			grid[i].setEnabled(false);
			middle.add(grid[i]);	
		}
		
		bottom = new JLabel();
		bottom.setOpaque(true);
		bottom.setBackground(new Color(185,211,238));
		bottom.setPreferredSize(new Dimension(800,90));
		bottom.setLayout(new GridLayout(0,3));
		bottom.setBorder(bevel);
		
		bleft = new JPanel();
		bleft.setOpaque(true);
		bleft.setBackground(new Color(185,211,238));
		bleft.setPreferredSize(new Dimension(800,90));
		bleft.setBorder(titlePlayer1);
		bleft.setLayout(new GridLayout(3,1));

		player1Wins = new JLabel();
		player1Wins.setBackground(new Color(185,211,238));
		player1Wins.setHorizontalAlignment( SwingConstants.CENTER );
		
		player1Ties = new JLabel();
		player1Ties.setBackground(new Color(185,211,238));
		player1Ties.setHorizontalAlignment( SwingConstants.CENTER );
		
		player1Losses = new JLabel();
		player1Losses.setBackground(new Color(185,211,238));
		player1Losses.setHorizontalAlignment( SwingConstants.CENTER );
		
		bleft.add(player1Wins);
		bleft.add(player1Ties);
		bleft.add(player1Losses);
		
		bottom.add(bleft);
		
		bcenter = new JPanel();
		bcenter.setOpaque(true);
		bcenter.setBackground(new Color(185,211,238));
		bcenter.setPreferredSize(new Dimension(800,90));
		bcenter.setBorder(titlePlayer2);
		bcenter.setLayout(new GridLayout(3,1));

		player2Wins = new JLabel();
		player2Wins.setBackground(new Color(185,211,238));
		player2Wins.setHorizontalAlignment( SwingConstants.CENTER );
		
		player2Ties = new JLabel();
		player2Ties.setBackground(new Color(185,211,238));
		player2Ties.setHorizontalAlignment( SwingConstants.CENTER );
		
		player2Losses = new JLabel();
		player2Losses.setBackground(new Color(185,211,238));
		player2Losses.setHorizontalAlignment( SwingConstants.CENTER );
		
		bcenter.add(player2Wins);
		bcenter.add(player2Ties);
		bcenter.add(player2Losses);
		
		bottom.add(bcenter);
		
		bright = new JPanel();
		bright.setOpaque(true);
		bright.setBackground(new Color(185,211,238));
		bright.setPreferredSize(new Dimension(800,90));
		bright.setBorder(titleCpu);
		bright.setLayout(new GridLayout(3,1));

		cpuWins = new JLabel();
		cpuWins.setBackground(new Color(185,211,238));
		cpuWins.setHorizontalAlignment( SwingConstants.CENTER );
		
		cpuTies = new JLabel();
		cpuTies.setBackground(new Color(185,211,238));
		cpuTies.setHorizontalAlignment( SwingConstants.CENTER );
		
		cpuLosses = new JLabel();
		cpuLosses.setBackground(new Color(185,211,238));
		cpuLosses.setHorizontalAlignment( SwingConstants.CENTER );
		
		bright.add(cpuWins);
		bright.add(cpuTies);
		bright.add(cpuLosses);
		
		bottom.add(bright);

		c.add(top,BorderLayout.NORTH);
		c.add(middle, BorderLayout.CENTER);
		c.add(bottom, BorderLayout.SOUTH);

		refreshBottomDisplay();
		
		setSize(800,740);

	} // end guiSetup method
} 