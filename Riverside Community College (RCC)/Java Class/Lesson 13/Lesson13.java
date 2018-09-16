import javax.swing.JApplet;
import javax.swing.JOptionPane;
 
public class Lesson13 extends JApplet{

	private static final long serialVersionUID = 101010;

	public void init()
	{	
		// Input system to determine which problem to run
		int inN;
		do{
	         inN=getN();
	         switch(inN)
	         {
	          case 1:    problem1();break;
	          case 2:    problem2();break;
	          default:
	         }
	       }while(inN != 0);	
	}
	
	public static int getN() // Used to actual enter which program to run.
	{
		int value = 0;
		String choice = "";
	
		do
		{
			choice = JOptionPane.showInputDialog( 
					"\nHomework Menu\n\n" +
					"Press 1 for Problem 9.7\n"+
					"Press 2 for Problem 9.8\n"+
					"Press 0 To Quit\n");
		}while((Integer.parseInt(choice)) > 2 || (Integer.parseInt(choice)) < 0);
			
		value = Integer.parseInt(choice);
		
		return value;
	}

	public void problem1() // problem 1 method
	{
		
		triangle shape3 = new triangle();
		rectangle shape4 = new rectangle();
		pentagon shape5 = new pentagon();
		trapazoid shape6 = new trapazoid();
		rhombus shape7 = new rhombus();
		prism shape9 = new prism();
		cube shape10 = new cube();
		rhombohedron shape11 = new rhombohedron();
		pyramid shape12 = new pyramid();
		cone shape13 = new cone();
		
		System.out.print("Triangle\n");
		shape3.name();
		System.out.print("Rectangle\n");
		shape4.name();
		System.out.print("Pentagon\n");
		shape5.name();
		System.out.print("Trapazoid\n");
		shape6.name();
		System.out.print("Rhombus\n");
		shape7.name();
		System.out.print("Prism\n");
		shape9.name();
		System.out.print("Cube\n");
		shape10.name();
		System.out.print("Rhombohedron\n");
		shape11.name();
		System.out.print("Pyramid\n");
		shape12.name();
		System.out.print("Cone\n");
		shape13.name();
		
	
	} // end problem 1
	
	public void problem2() // problem 2 method
	{
		Employee emp1 = new Employee("James","Small",540035548);
		System.out.print("Employee Class\n");
		System.out.printf("Employee Name: %s %s\n",emp1.getFirstName(),emp1.getLastName());
		System.out.printf("Social Security: %.0f\n",emp1.getSocial());
		
		SalariedEmployee emp2 = new SalariedEmployee("Jose","Smith",453531132,920.00);
		System.out.print("\nSalaried Employee Class\n");
		System.out.printf("Employee Name: %s %s\n",emp2.getFirstName(),emp2.getLastName());
		System.out.printf("Social Security: %.0f\n",emp2.getSocial());
		System.out.printf("Weekly Salary: %.2f\n",emp2.getWeeklySalary());
		
		HourlyEmployee emp3 = new HourlyEmployee("Mark","Andrade",353223535,23.00,35);
		System.out.print("\nHourly Employee Class\n");
		System.out.printf("Employee Name: %s %s\n",emp3.getFirstName(),emp3.getLastName());
		System.out.printf("Social Security: %.0f\n",emp3.getSocial());
		System.out.printf("Wage per Hour: %.2f\n",emp3.getWage());
		System.out.printf("Hours Worked: %.2f\n",emp3.getHours());
		System.out.printf("Total Paid: %.2f\n",emp3.getWage() * emp3.getHours());
		
		CommissionEmployee emp4 = new CommissionEmployee("Kevin","Anderson",442035523,5350.00,5);
		System.out.print("\nCommission Employee Class\n");
		System.out.printf("Employee Name: %s %s\n",emp4.getFirstName(),emp4.getLastName());
		System.out.printf("Social Security: %.0f\n",emp4.getSocial());
		System.out.printf("Comm Rate: %d.0\n",emp4.getCommissionRate());
		System.out.printf("Gross Sales: %.2f\n",emp4.getGrossSales());
		System.out.printf("Total Paid: %.2f\n",((double)emp4.getCommissionRate() / 100) * emp4.getGrossSales());
		
		BasePlusCommissionEmployee emp5 = new BasePlusCommissionEmployee("Mike","Baldridge",356223953,7000.00,6,300.00);
		System.out.print("\nBase Plus Commission Employee Class\n");
		System.out.printf("Employee Name: %s %s\n",emp5.getFirstName(),emp5.getLastName());
		System.out.printf("Social Security: %.0f\n",emp5.getSocial());
		System.out.printf("Comm Rate: %d.0\n",emp5.getCommissionRate());
		System.out.printf("Gross Sales: %.2f\n",emp5.getGrossSales());
		System.out.printf("Base Pay: %.2f\n",emp5.getBaseSalary());
		System.out.printf("Total Paid: %.2f\n",(((double)emp5.getCommissionRate() / 100) * emp5.getGrossSales()) + emp5.getBaseSalary());
	
	} // end problem 2
}
