/** Java Example of the GoF Decorator patter
*/
import java.lang.*;
interface Common{
public void common(String s);
}//interace Common

class Undecorated implements Common{
public Undecorated(){}
public void common(String s){
	System.out.print(s+": ");
	System.out.println("Undecorated");
}//common()

}//class Undecorated

class Decorator1 implements Common{
private Common decorates;
public Decorator1(Common d){decorates=d;}
public void common(String s){
	System.out.print(s+": ");
	System.out.println("Decoration1");
	decorates.common(s);
}//common()

}//class Decorator1

class Decorator2 implements Common{
private Common decorates;
public Decorator2(Common d){decorates=d;}
public void common(String s){
	System.out.print(s+": ");
	System.out.println("Decoration2");
	decorates.common(s);
}//common()

}//class Decorator2

class TestDecorator{

    public static void main(String argv[]){

	System.out.println("TestDecorator ");
	Common t = new Undecorated();
	t.common("test undecorated");
	t = new Decorator1(t);
	t.common("test decorator1");
	t = new Decorator2(t);
	t.common("test decorator2");

    }//main
    

}//class Hello


