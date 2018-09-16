// Sample code implementing  the diagrams in Q5
import java.lang.*;
import java.util.*;
public class SalesItem {
   private Stock stock;
   private SalesOrder salesOrder;
   private int quantity;
   public SalesItem(Stock s, SalesOrder sO, int q)
   {
	quantity=q;
	salesOrder=sO;
	stock=s;

	stock.reduce(quantity);
   }
      
}//SalesItem
