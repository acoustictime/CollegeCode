public class DateNew 
{
	private int month;
	private int day;
	private int year;
	private int daysPerMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	private String months[] = {"","January","February","March","April","May","June","July",	"August","September","October","November","December"};
	
	public DateNew(int theMonth, int theDay, int theYear)
	{
		month = checkMonth(theMonth);
		year = checkYear(theYear);
		day = checkDay(theDay);
	}
	
	public DateNew(String theMonth, int theDay, int theYear)
	{
		if(theMonth == "January")
			month = 1;
		else if (theMonth == "February")
			month = 2;
		else if (theMonth == "March")
			month = 3;
		else if (theMonth == "April")
			month = 4;
		else if (theMonth == "May")
			month = 5;
		else if (theMonth == "June")
			month = 6;
		else if (theMonth == "July")
			month = 7;
		else if (theMonth == "August")
			month = 8;
		else if (theMonth == "September")
			month = 9;
		else if (theMonth == "October")
			month = 10;
		else if (theMonth == "November")
			month = 11;
		else if (theMonth == "December")
			month = 12;
		else
			month = 1;
		
		
		year = checkYear(theYear);
		day = checkDay(theDay);
	}
	
	public DateNew(int theDay, int theYear)
	{
		month = 1;
		year = checkYear(theYear);
		day = checkDay(theDay);
	}
	
	
	private int checkMonth(int testMonth)
	{
		if(testMonth > 0 && testMonth <= 12)
			return testMonth;
		else
		{
			System.out.printf("Invalid month (%d) set to 1.", testMonth);
			return 1;
		}
	}
	
	private int checkYear(int testYear)
	{
		if(testYear > 1000 && testYear <= 9999)
			return testYear;
		else
		{
			System.out.printf("Invalid year (%d) set to 1900.", testYear);
			return 1900;
		}
	}
	
	private int checkDay(int testDay)
	{
		if(testDay > 0 && testDay <= daysPerMonth[month])
			return testDay;
		
		if(month == 2 && testDay == 29 && leap() == true)
			return testDay;
			
			System.out.printf("Invalid day (%d) set to 1.",testDay);
			return 1;	
	}
	
	public String toString()
	{
		return String.format("%d/%d/%d\n",month,day,year);	
	}
	
	public String toString2()
	{
		return String.format("%s %d, %d",months[month],day,year);
	}
	
	public String toString3()
	{
		return String.format("%d %d",day,year);
	}
	
	public boolean leap()
	{
		if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				return true;
		else
			return false;
	}
	
	public void nextDay()
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
	
	public void nextMonth()
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
	
	public void nextYear()
	{
		year = checkYear(year + 1);
	}
}