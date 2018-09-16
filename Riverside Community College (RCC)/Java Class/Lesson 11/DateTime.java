
public class DateTime 
{
	private int month;
	private int day;
	private int year;
	private int daysPerMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	private int hour;
	private int minute;
	private int second;
	
	public DateTime(int theMonth, int theDay, int theYear, int theHour, int theMinute, int theSecond)
	{
		month = checkMonth(theMonth);
		year = checkYear(theYear);
		day = checkDay(theDay);
		setTime(theHour,theMinute,theSecond);
		System.out.printf("Date object constructor for date %s\n", this);
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
	

	//	return String.format("%d/%d/%d\n",month,day,year);	

	
	public String toUniversalString()
	{
		return String.format("%d/%d/%d - %02d:%02d:%02d\n",month,day,year,getHour(),getMinute(),getSecond());
	}
	
	public String toString()
	{
		return String.format("%d/%d/%d - %d:%02d:%02d %s\n",month, day, year,((getHour() == 0 || getHour() == 12) ? 12: getHour() % 12), getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
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
	
	public DateTime()
	{
		this(0,0,0);
	}
	
	public DateTime(int h)
	{
		this(h,0,0);
	}
	
	public DateTime(int h, int m)
	{
		this(h,m,0);
	}
	
	public DateTime(int h, int m, int s)
	{
		setTime(h,m,s);
	}

	public DateTime(DateTime time)
	{
		this(time.getHour(), time.getMinute(), time.getSecond());
	}
	
	public void setTime(int h, int m, int s)
	{
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	
	public void setHour(int h)
	{
		hour = ((h >= 0 && h < 24) ? h : 0);
	}
	
	public void setMinute(int m)
	{
		minute = ((m >= 0 && m < 60) ? m : 0);
	}
	
	public void setSecond(int s)
	{
		second = ((s >= 0 && s < 60) ? s : 0);
	}
	
	public int getHour()
	{
		return hour;
	}
	
	public int getMinute()
	{
		return minute;
	}
	
	public int getSecond()
	{
		return second;
	}
	
	public void nextSecond()
	{
		
		if(second + 1 == 60)
		{
			setSecond(0);
			nextMinute();
		}
		else
		{
			setSecond(second + 1);
		}
	}
	
	public void nextMinute()
	{
		if(minute + 1 == 60)
		{
			setMinute(0);
			nextHour();
		}
		else
		{
			setMinute(minute + 1);
		}
	}
	
	public void nextHour()
	{
		if(hour + 1 == 24)
		{
			setHour(0);
			nextDay();
		}
		else
		{
			setHour(hour + 1);
		}
	}
	
	
}
