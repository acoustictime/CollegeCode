/** Declares a class in Page 10 of Larman */
import java.util.Random;
public class Die
{ protected int faceValue;
  protected Random rand;
  public void roll()
	{
		faceValue = 1+rand.nextInt(6);
	}
  public int getFaceValue()
	{
		return faceValue;
	}
  public Die () {rand=new Random(); roll(); };


   public static void main(String argv[])
   /** Unit test of a Die class */
   {
	Die die=new Die();

	int SAMPLE =1000;
	for(int i=0; i<SAMPLE; i++)
	{
		die . roll();
		int fv = die . getFaceValue();
		System.out.println(fv);
	}
	

   }//main
}//Die
