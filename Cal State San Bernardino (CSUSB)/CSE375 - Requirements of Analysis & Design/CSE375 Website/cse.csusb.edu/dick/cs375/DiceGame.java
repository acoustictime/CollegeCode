class DiceGame
{
  private Die die1;
  private Die die2;
  public DiceGame(){die1 = new Die(); die2 = new Die(); }

  public void play()
  {
  	die1 . roll();
  	int fv1=die1 . getFaceValue();
  
  	die2 . roll();
  	int fv2=die2 . getFaceValue();
  
  	score = fv1+fv2;
  }

// following not in book... but DiceGame can't be tested without them
  private int score;
  public int getScore(){return score;}
  public boolean getWin(){return score==7;}

/* This is a unit test of class DiceGame */

   public static void main(String argv[])
   {

	DiceGame g = new DiceGame();
	g . play();

	System.out.println( g.getScore());
	if( g.getWin() )
		System.out.println( "You Win");
	else
		System.out.println( "You Lose");
   }
}//end clas DiceGame
