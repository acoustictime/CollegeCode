
public class Date 
{
	private int month;
	private int day;
	private int year;
	private int daysPerMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	public Date(int theMonth, int theDay, int theYear) // date constructor
	{
		month = checkMonth(theMonth);
		year = checkYear(theYear);
		day = checkDay(theDay);
		
		System.out.printf("Date object constructor for date %s\n", this);
	}
	
	private int checkMonth(int testMonth)// tests for valid month
	{
		if(testMonth > 0 && testMonth <= 12)
			return testMonth;
		else
		{
			System.out.printf("Invalid month (%d) set to 1.", testMonth);
			return 1;
		}
	}
	
	private int checkYear(int testYear) // tests for valid year
	{
		if(testYear > 1000 && testYear <= 9999)
			return testYear;
		else
		{
			System.out.printf("Invalid year (%d) set to 1900.", testYear);
			return 1900;
		}
	}
	
	private int checkDay(int testDay) // tests for valid day
	{
		if(testDay > 0 && testDay <= daysPerMonth[month])
			return testDay;
		
		if(month == 2 && testDay == 29 && leap() == true)
			return testDay;
			
			System.out.printf("Invalid day (%d) set to 1.",testDay);
			return 1;	
	}
	
	public String toString() // return date
	{
		return String.format("%d/%d/%d\n",month,day,year);	
	}
	
	public boolean leap() // check for leap year
	{
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				return true;
		else
			return false;
	}
	
	public void nextDay() // increment day
	{
		if((day + 1) > daysPerMonth[month])
		{
			if (month == 2 && day + 1 == 29 && leap() == true)
			{	
				day = checkDay(day + 1);
			}
			else
			{
				day = checkDay(1);
				nextMonth();
			}
		}		
		else
		{
			day = checkDay(day + 1);
		}	
	}
	
	public void nextMonth() // increment month
	{
		if((month + 1) > 12)
		{
			month = checkMonth(1);
			nextYear();
		}
		else
		{
			month = checkMonth(month + 1);
		}	
	}
	
	public void nextYear() // increment year
	{
		year = checkYear(year + 1);
	}
}