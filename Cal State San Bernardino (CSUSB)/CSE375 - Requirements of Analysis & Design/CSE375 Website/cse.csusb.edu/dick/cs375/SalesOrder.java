// Sample code implementing  the diagrams in Q5
import java.lang.*;
import java.util.*;
public class SalesOrder{
  private Vector salesItems;//the simplest thing that could possibly work!

  public SalesOrder(){
	salesItems = new Vector();
  }//create

  public void pick(Stock s, int q){
	SalesItem si= new SalesItem(s,this,q);
	add(si);
  }//pick

  public void add(SalesItem si){
	salesItems.add(si);
  }//add

  
// Test program
    public static void main(String argv[]){

	System.out.println("Test SalesOrder ");
	SalesOrder testOrder = new SalesOrder();
	System.out.println("Constructed SalesOrder ");
	Stock testStock = new Stock(5);
	System.out.println("Constructed Stock");
	System.out.print("testStock.getQuantityOnHand() =");
	System.out.println(testStock.getQuantityOnHand());
	testOrder.pick(testStock, 1);
	System.out.println("Executed pick ");
	System.out.print("testStock.getQuantityOnHand() =");
	System.out.println(testStock.getQuantityOnHand());

    }//main
    

}//SalesOrder
