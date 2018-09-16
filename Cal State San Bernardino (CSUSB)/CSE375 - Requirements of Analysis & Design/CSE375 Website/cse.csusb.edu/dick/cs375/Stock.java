// Sample code implementing  the diagrams in Q5
import java.lang.*;
import java.util.*;
public class Stock {
   private int quantityOnHand;//quantity on hand
   public Stock(){
	quantityOnHand=0;
   }//create
   public Stock(int q){
	quantityOnHand=q;
   }//create

   public void reduce(int q){
	quantityOnHand=quantityOnHand-q;
   }//reduce

// used in unit tests
   public int getQuantityOnHand(){
	return quantityOnHand;
   }//qoh

   
}//Stock
