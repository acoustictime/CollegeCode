import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.Border;
import java.util.Random;

public class DiceGame extends JApplet implements ActionListener {

	private static final long serialVersionUID = 10101010;
	
	//Gui Variables
	private JLabel one,two,three,four,five,six,rollTotal,bankTotal;
	private JLabel oneValue,twoValue,threeValue,fourValue,fiveValue,sixValue,rollTotalValue,bankTotalValue;
	private JLabel betAmount,betType,betAmountValue,betTypeValue,dice1,dice2,dice1Label,dice2Label;
	private JButton roll,quit,betButton,help;
	private JPanel topPanel,bottomPanel;

	//Rest of the variables, non gui
	private int rollAmount = 0,oneAmount = 0,twoAmount = 0,threeAmount = 0,fourAmount = 0,fiveAmount = 0,sixAmount = 0,bankAmount = 10000;
	private String betString = "No Bet";
	private boolean isPair, isEven,isOdd;
	private int betDollarAmount = 0, dice1Value = 0, dice2Value = 0, betStringInt = 0, betNumber = 0,temp = 0;
	Random randomizer = new Random(); // random object
private String choice; // current menu choice

	public void init()
	{		
		guiSetup(); // Run's method to setup gui
	} // end init method

	public void actionPerformed( ActionEvent e ) // waits for action performed
	{	
		if (e.getSource() == quit) // if quit button, exit program
		{
			System.exit(0);
		}
		else if (e.getSource() == help) // If help button, run help menu, then quick bet methods
		{
			help();
			quickBet();
		}
		else if (e.getSource() == betButton) // if bet button, run betMenu method
		{
			betMenu();
		}
		else if (e.getSource() == roll) // if roll button pressed, run roller method
		{
			roller();
		}
		
		labelUpdate(); // update labels on gui before beginning to wait for next action
	} // end action performed method
	
	public void labelUpdate() // update gui labels based on current values
	{
		oneValue.setText(Integer.toString(oneAmount));
		twoValue.setText(Integer.toString(twoAmount));
		threeValue.setText(Integer.toString(threeAmount));
		fourValue.setText(Integer.toString(fourAmount));
		fiveValue.setText(Integer.toString(fiveAmount));	
		sixValue.setText(Integer.toString(sixAmount));
		rollTotalValue.setText(Integer.toString(rollAmount));
		bankTotalValue.setText("$" + Integer.toString(bankAmount) + ".00");
		betAmountValue.setText("$" + Integer.toString(betDollarAmount) + ".00");
		betTypeValue.setText(betString);
		dice1Label.setText(Integer.toString(dice1Value));
		dice2Label.setText(Integer.toString(dice2Value));
	} // end labelUpdate method

	public void help() // display help menu
	{
		//help message
		JOptionPane.showMessageDialog( 
				null,"This is a very simple dice betting game.  Pick from one of the\n" +
					 "availiable bets.  Determine how much you are willing to risk, and\n" +
					 "then roll the dice.  Sometimes you win, most of the time you lose\n" +
					 "but hey, at least it isn't real money.  Pay attention to the scoreboard.\n" +
					 "It keeps track of how many times each dice number appeared to\n" +
					 "help you decide your bet.  See if you can win the multiply bet.  In \n" +
					 "my testing, I couldn't win it.  The payouts are below:\n\n" +
					 "High - 10 to 1\nLow - 10 to 1\nSum - 20 to 1\nDifference - 20 to 1\nPairs - 50 to 1\n" +
					 "Both Even - 75 to 1\nBoth Odd - 75 to 1\nMultiply Numbers - 100 to 1\n\nGood Luck!!!!!!","***The Dice Game***", // Output results
				JOptionPane.INFORMATION_MESSAGE );
	} // end help method
	
	public void betMenu() // display bet menu and receive bet amount
	{
		do // display bet menu and wait for user input.
		{
			choice = JOptionPane.showInputDialog(null, 
			"Which item do you want to bet on?\n\n" +
			"Press 1: Bet on High Number\n" +
			"Press 2: Bet on Low Number\n" +
			"Press 3: Bet on Sum of Numbers\n" +
			"Press 4: Bet on Difference of Numbers\n" +
			"Press 5: Bet on if Pairs\n" +
			"Press 6: Bet on if both numbers Even\n" +
			"Press 7: Bet on if both numbers Odd\n" +
			"Press 8: Bet on Multiply","***The Dice Game***",JOptionPane.QUESTION_MESSAGE );
		}while((Integer.parseInt(choice)) > 8 || (Integer.parseInt(choice)) < 1);
		
		betStringInt = Integer.parseInt(choice); // set betStringInt based on choice entered above
		
		switch(Integer.parseInt(choice)) // switch based on bet type entered.
		{
			case 1: // if high number bet selected
				do 
				{
					choice = JOptionPane.showInputDialog(null, 
					"What will the high number be???\n" +
					"Valid Choices are 1 through 6","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
				}while((Integer.parseInt(choice)) > 6 || (Integer.parseInt(choice)) < 1);
				
				betString = "High is " + Integer.parseInt(choice);	// set betString to bet choice and value	
				break;
			case 2: // if low number bet selected
				do 
				{
					choice = JOptionPane.showInputDialog(null, 
					"What will the low number be???\n" +
					"Valid Choices are 1 through 6","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
				}while((Integer.parseInt(choice)) > 6 || (Integer.parseInt(choice)) < 1);
				
				betString = "Low is " + Integer.parseInt(choice); // set betString to bet choice and value	
				
				break;
			case 3: // if sum of numbers bet selected
				do 
				{
					choice = JOptionPane.showInputDialog( null,
					"What will the sum of the numbers be???\n" +
					"Valid Choices are 2 through 12","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
				}while((Integer.parseInt(choice)) > 12 || (Integer.parseInt(choice)) < 2);
				
				betString = "Sum is " + Integer.parseInt(choice);	 // set betString to bet choice and value		
				break;
			case 4: // if difference of numbers bet selected
				do 
				{
					choice = JOptionPane.showInputDialog( null,
					"What will the difference of the numbers be???\n" +
					"Valid Choices are 0 through 5","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
				}while((Integer.parseInt(choice)) > 5 || (Integer.parseInt(choice)) < 0);
				
				betString = "Difference is " + Integer.parseInt(choice);		 // set betString to bet choice and value	
				break;
			case 5:	 // if pairs bet selected
				choice = Integer.toString(JOptionPane.showConfirmDialog(null, 
				"Will it be pairs, yes or no","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE ));
				
				if(Integer.parseInt(choice) == 0) // if betting on pairs
				{
					betString = "Pairs Yes"; // set betString to bet choice and value
					isPair = true;
				}
				else // if betting on not pairs
				{
					betString = "Pairs No"; // set betString to bet choice and value
					isPair = false;
				}
				break;
			case 6: // if even bet selected
				choice = Integer.toString(JOptionPane.showConfirmDialog(null, 
				"Will both dice be even, yes or no??","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE ));
				
				if(Integer.parseInt(choice) == 0) // if betting on even
				{
					betString = "Even Yes"; // set betString to bet choice and value
					isEven = true;
				}
				else // if betting on not even
				{
					betString = "Even No"; // set betString to bet choice and value
					isEven = false;
				}		
				break;
			case 7: // if odd bet selected
				choice = Integer.toString(JOptionPane.showConfirmDialog(null, 
				"Will both dice be odd, yes or no??","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE ));
				
				if(Integer.parseInt(choice) == 0) // if betting on odd
				{
					betString = "Odd Yes";  // set betString to bet choice and value
					isOdd = true;
				}
				else // if betting on not odd
				{
					betString = "Odd No";  // set betString to bet choice and value
					isOdd = false;
				}
				break;
			case 8: // if multiply bet is selected
				do 
				{
					choice = JOptionPane.showInputDialog(null, 
					"What will be the result if both numbers are multiplied???\n" +
					"Valid Choices are 1 through 36","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
				}while((Integer.parseInt(choice)) > 36 || (Integer.parseInt(choice)) < 1);
				
				betString = "Multiply is " + Integer.parseInt(choice);	 // set betString to bet choice and value		
				break;
			default:
				break;
		}
		
		betNumber = Integer.parseInt(choice); // set bet choice as betNumber variable
		
		do // ask user how much to wager, constraints of 1 to bank balance
		{
			choice = JOptionPane.showInputDialog( null,
			"How much do you want to wager on your bet???\n" +
			"Bet at least $1.00 but less than what you have!!!","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
		}while((Integer.parseInt(choice)) > bankAmount || (Integer.parseInt(choice)) < 1);
		
		betDollarAmount = Integer.parseInt(choice);	//set current bet dollar amount to input above
	} // End betMenu method

	public void roller() //roll dice and record results
	{
		if(betDollarAmount == 0) // if current bet is 0, tell user to make a bet first
		{
			JOptionPane.showMessageDialog(
					null,"You didn't place a bet\nPlace a bet before rolling the dice","***The Dice Game***",
					JOptionPane.INFORMATION_MESSAGE );
		}
		else // if current bet is not 0
		{		
			// run dice() method for both dice, and increase roll count
			dice1Value = dice();
			dice2Value = dice();	
			rollAmount++;
			
			switch(dice1Value) // switch on dice1Value to increase count per number
			{
			case 1:
				oneAmount++;
			break;
			case 2:
				twoAmount++;
			break;
			case 3:
				threeAmount++;
			break;
			case 4:
				fourAmount++;
			break;
			case 5:
				fiveAmount++;
			break;
			case 6:
				sixAmount++;
			break;
			default:
				break;
			}
			
			switch(dice2Value) // switch on dice2Value to increase count per number
			{
			case 1:
				oneAmount++;
			break;
			case 2:
				twoAmount++;
			break;
			case 3:
				threeAmount++;
			break;
			case 4:
				fourAmount++;
			break;
			case 5:
				fiveAmount++;
			break;
			case 6:
				sixAmount++;
			break;
			default:
				break;
			}
			
			results(); // run results method
		}	
	} // end roller method
	
	public void results() // results method to determine if winner or not
	{
		switch(betStringInt) // switch based on type of bet entered
		{
			case 1: // if high bet
				if(dice1Value > dice2Value) // determine high number based on dice rolled
					temp = dice1Value;
				else
					temp = dice2Value;
				
				if(betNumber == temp) // if guessed high number
				{
					bankAmount += (betDollarAmount * 10); // increase bank balance based on wager and odds, tell user they won.
					
					JOptionPane.showMessageDialog(
							null,"You won!!!!!!  You guessed the high number correctly.\n\nWinnings = $" + (betDollarAmount  * 10) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
							JOptionPane.INFORMATION_MESSAGE );
				}
				else // if didn't guess high number
				{
					JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
					bankAmount -= betDollarAmount; // decrease bank balance by wager
				}
				break;
			case 2:
				if(dice1Value > dice2Value) // determine low number based on roll
					temp = dice2Value;
				else
					temp = dice1Value;
				
				if(betNumber == temp) // if guessed low number
				{
					bankAmount += (betDollarAmount * 10); // increase bank balance based on wager and odds, tell user they won.
					
					JOptionPane.showMessageDialog(
							null,"You won!!!!!!  You guessed the low number correctly.\n\nWinnings = $" + (betDollarAmount  * 10) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
							JOptionPane.INFORMATION_MESSAGE );
				}
				else // if lost
				{
					JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
					bankAmount -= betDollarAmount; // decrease bank balance by wager
				}
				break;
			case 3:
				if((dice1Value + dice2Value) == betNumber) // if sum of numbers equal bet number
				{
					bankAmount += (betDollarAmount * 20); // increase bank balance based on wager and odds, tell user they won.
					
					JOptionPane.showMessageDialog(
							null,"You won!!!!!!  You guessed the sum of the numbers correctly.\n\nWinnings = $" + (betDollarAmount  * 20) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
							JOptionPane.INFORMATION_MESSAGE );
				}
				else // if lost
				{
					JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
					bankAmount -= betDollarAmount; // decrease bank balance by wager
				}
				break;
			case 4:			
				if(betNumber == Math.abs(dice1Value - dice2Value)) // if difference of numbers equals bet number
				{
					bankAmount += (betDollarAmount * 20); // increase bank balance based on wager and odds, tell user they won.
					
					JOptionPane.showMessageDialog(
							null,"You won!!!!!!  You guessed the difference of the numbers correctly.\n\nWinnings = $" + (betDollarAmount  * 20) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
							JOptionPane.INFORMATION_MESSAGE );
				}
				else // if lost
				{
					JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
					bankAmount -= betDollarAmount; // decrease bank balance by wager
				}
				break;
			case 5:				
				if(dice1Value == dice2Value) // if dice rolled pairs
				{
					if(isPair) // if bet there will be pairs
					{
						bankAmount += (betDollarAmount * 50); // increase bank balance based on wager and odds, tell user they won.
					
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be pairs correctly.\n\nWinnings = $" + (betDollarAmount  * 50) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
					else // if lost
					{
						JOptionPane.showMessageDialog(
								null,"You lose. Try again next time","Sucks to be you", // Output results
								JOptionPane.INFORMATION_MESSAGE );
						
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
				}
				else // if dice didn't roll pairs
				{			
					if(isPair) // lost if bet there will be pairs
					{
						JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
					else // win if bet there won't be pairs
					{
						bankAmount += (betDollarAmount * 50); // increase bank balance based on wager and odds, tell user they won.
						
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be pairs correctly.\n\nWinnings = $" + (betDollarAmount  * 50) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
				}
				break;
			case 6:
				if(dice1Value % 2 == 0 && dice2Value % 2 == 0) // check if dice are both even
				{
					if(isEven) // win if both are even
					{
						bankAmount += (betDollarAmount * 75); // increase bank balance based on wager and odds, tell user they won.
					
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be even.\n\nWinnings = $" + (betDollarAmount  * 75) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
					else // lose if both aren't even
					{
						JOptionPane.showMessageDialog(
								null,"You lose. Try again next time","Sucks to be you", // Output results
								JOptionPane.INFORMATION_MESSAGE );
						
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
				}
				else // if dice are not even
				{	
					if(isEven) // lose if bet they will be even
					{
						JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
					else // win if dice not even
					{
						bankAmount += (betDollarAmount * 75); // increase bank balance based on wager and odds, tell user they won.
						
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be even.\n\nWinnings = $" + (betDollarAmount  * 75) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
				}
				break;
			case 7:
				if(dice1Value % 2 != 0 && dice2Value % 2 != 0) // if dice are both odd
				{
					if(isOdd) // win if bet they both were odd
					{
						bankAmount += (betDollarAmount * 75); // increase bank balance based on wager and odds, tell user they won.
					
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be odd.\n\nWinnings = $" + (betDollarAmount  * 75) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
					else // lose if both aren't odd
					{
						JOptionPane.showMessageDialog(
								null,"You lose. Try again next time","Sucks to be you", // Output results
								JOptionPane.INFORMATION_MESSAGE );
						
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
				}
				else // if dice are both not odd
				{	
					if(isOdd) // lose if bet both are odd
					{
						JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
						bankAmount -= betDollarAmount; // decrease bank balance by wager
					}
					else // win if both aren't odd
					{
						bankAmount += (betDollarAmount * 75); // increase bank balance based on wager and odds, tell user they won.
						
						JOptionPane.showMessageDialog(
								null,"You won!!!!!!  You guessed the numbers would be odd.\n\nWinnings = $" + (betDollarAmount  * 75) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
								JOptionPane.INFORMATION_MESSAGE );
					}
				}
				break;
			case 8:
				if(dice1Value * dice2Value == betNumber) // if multiply of numbers is bet number
				{
					bankAmount += (betDollarAmount * 100); // increase bank balance based on wager and odds, tell user they won.
					
					JOptionPane.showMessageDialog(
							null,"You won!!!!!!  You guessed the result of multiplying the numbers.\n\nWinnings = $" + (betDollarAmount  * 100) + ".00.\n\nYour new bank balance is $" + bankAmount + ".00.","Winner Winner Chicken Dinner", // Output results
							JOptionPane.INFORMATION_MESSAGE );
				}
				else // if multiply of numbers not bet number
				{
					JOptionPane.showMessageDialog(
							null,"You lose. Try again next time","Sucks to be you", // Output results
							JOptionPane.INFORMATION_MESSAGE );
					
					bankAmount -= betDollarAmount; // decrease bank balance by wager
				}
				break;
			default:
				break;
		}

		//This round over, reset variables to default for next roll
		betString = "No Bet";
		temp = 0;
		betStringInt = 0;
		betDollarAmount = 0;
		
		if(bankAmount == 0) // if out of money, let user know that.  Ask if want to play agin.
		{
			choice = Integer.toString(JOptionPane.showConfirmDialog(null, 
			"Game over.  You are broke!!!\n\nDo you want to play again?"));
			
			if(Integer.parseInt(choice) == 0) // if yes play again
			{
				//reset all variables back to default
				bankAmount = 10000;
				oneAmount = 0;
				twoAmount = 0;
				threeAmount = 0;
				fourAmount = 0;
				fiveAmount = 0;
				sixAmount = 0;
				rollAmount = 0;
			}
			else // if not play again, exit game
			{
				System.exit(0);
			}
		}	
	} // end results method
	
	public int dice() // randomize dice
	{
		return randomizer.nextInt(6) + 1; // random number 1 to 6	
	} // end dice method

	public void quickBet() // plays quick bet game from help menu
	{
		do // ask user for value 1 to 6
		{
		choice = JOptionPane.showInputDialog(null, 
				"Since you looked at the help menu, you get to play\n" +
				"Quick Bet!!  Very simple, pick a number between 1 and 6.\n" +
				"Guess right and win an easy $1,000.00.  Good Luck\n\nWhat's your guess??","***The Dice Game***",JOptionPane.INFORMATION_MESSAGE );
		}while((Integer.parseInt(choice)) > 6 || (Integer.parseInt(choice)) < 1);	
		
		temp = Integer.parseInt(choice); // set temp variable as guess
		
		if(dice() == temp) // if 1 dice rolled matches guess, say winner
		{
			JOptionPane.showMessageDialog(
					null,"Guess what!!!! You won!!!!!!\n" +
					"That was an easy $1,000.00 now wasn't it.","***The Dice Game***", // Output results
					JOptionPane.INFORMATION_MESSAGE );
			bankAmount += 1000; // increase bank balance by 1000
		}
		else // if didn't guess correctly
		{
			JOptionPane.showMessageDialog(
					null,"You lost but you didn't lose any money, which is a good thing.\n" +
					"Since I feel sorry for you, here's a pity $1.00.  Enjoy","***The Dice Game***", // Output results
					JOptionPane.INFORMATION_MESSAGE );
			bankAmount += 1; // increase bank balance by 1 for pity
		}
	} // end quickBet method
	
	public void guiSetup() // Setup Gui portion of program
	{
		Container c = getContentPane(); // Setup container with gridlayout with 1 column
		c.setLayout(new GridLayout(0,1));
		
		//Setup etched border with titles
		Border etched = BorderFactory.createEtchedBorder();
		Border title = BorderFactory.createTitledBorder(etched, "The Dice Game - ScoreBoard");
		Border title2 = BorderFactory.createTitledBorder(etched, "Current Results");

		//Setup top panel with gridlayout and two columns
		topPanel = new JPanel();
        topPanel.setLayout(new GridLayout(0,2));
        topPanel.setBackground(Color.lightGray);
        topPanel.setBorder(title);
        
        //Setup botttom panel with gridlayout and two columns
        bottomPanel = new JPanel();
        bottomPanel.setLayout(new GridLayout(0,2));
        bottomPanel.setBackground(Color.lightGray);
        bottomPanel.setBorder(title2);

		// setup one count labels and add to top panel
        one = new JLabel("One Total Rolls =");
		topPanel.add(one);
		oneValue = new JLabel(Integer.toString(oneAmount));
		topPanel.add(oneValue);

		// setup two count labels and add to top panel
		two = new JLabel("Two Total Rolls =");
		topPanel.add(two);
		twoValue = new JLabel(Integer.toString(twoAmount));
		topPanel.add(twoValue);
		
		// setup three count labels and add to top panel
		three = new JLabel("Three Total Rolls =");
		topPanel.add(three);
		threeValue = new JLabel(Integer.toString(threeAmount));
		topPanel.add(threeValue);
		
		// setup four count labels and add to top panel
		four = new JLabel("Four Total Rolls =");
		topPanel.add(four);
		fourValue = new JLabel(Integer.toString(fourAmount));
		topPanel.add(fourValue);
		
		// setup five count labels and add to top panel
		five = new JLabel("Five Total Rolls =");
		topPanel.add(five);
		fiveValue = new JLabel(Integer.toString(fiveAmount));
		topPanel.add(fiveValue);
		
		// setup six count labels and add to top panel
		six = new JLabel("Six Total Rolls =");
		topPanel.add(six);
		sixValue = new JLabel(Integer.toString(sixAmount));
		topPanel.add(sixValue);
		
		// setup roll count labels and add to top panel
		rollTotal = new JLabel("Totals Rolls =");
		topPanel.add(rollTotal);
		rollTotalValue = new JLabel(Integer.toString(rollAmount));
		topPanel.add(rollTotalValue);
		
		// setup bank balance labels and add to top panel
		bankTotal = new JLabel("Bank Balance = ");
		topPanel.add(bankTotal);
		bankTotalValue = new JLabel("$" + Integer.toString(bankAmount) + ".00");
		topPanel.add(bankTotalValue);
		
		// setup dice1 labels and add to bottom panel
		dice1 = new JLabel("Dice 1 Last = ");
		bottomPanel.add(dice1);
		dice1Label = new JLabel(Integer.toString(dice1Value));
		bottomPanel.add(dice1Label);
		
		// setup dice2 labels and add to bottom panel
		dice2 = new JLabel("Dice 2 Last = ");
		bottomPanel.add(dice2);
		dice2Label = new JLabel(Integer.toString(dice2Value));
		bottomPanel.add(dice2Label);
		
		// setup bet type labels and add to bottom panel
		betType = new JLabel("Bet Type = ");
		bottomPanel.add(betType);
		betTypeValue = new JLabel(betString);
		bottomPanel.add(betTypeValue);
		
		
		// setup bet amount labels and add to bottom panel
		betAmount = new JLabel("Bet Amount = ");
		bottomPanel.add(betAmount);
		betAmountValue = new JLabel("$" + Integer.toString(betDollarAmount) + ".00");
		bottomPanel.add(betAmountValue);
		
		// setup roll button and add to bottom panel
		roll = new JButton("Roll Dice");
		roll.addActionListener(this);
		bottomPanel.add(roll);
		
		// setup bet button and add to bottom panel
		betButton = new JButton("Place Bet");
		betButton.addActionListener(this);
		bottomPanel.add(betButton);
		
		// setup quit button and add to bottom panel
		quit = new JButton("Quit");
		quit.addActionListener(this);
		bottomPanel.add(quit);
		
		// setup help button and add to bottom panel
		help = new JButton("Help");
		help.addActionListener(this);
		bottomPanel.add(help);
		
        //add panels to container
		c.add(topPanel, BorderLayout.NORTH);
        c.add(bottomPanel, BorderLayout.SOUTH);

        //set size of applet
        setSize(300,410);
	} // end guiSetup method
} // end dice game method