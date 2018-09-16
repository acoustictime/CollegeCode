public class Time2 
{
	private int hour;
	private int minute;
	private int second;
	
	public Time2()
	{
		this(0,0,0);
	}
	
	public Time2(int h)
	{
		this(h,0,0);
	}
	
	public Time2(int h, int m)
	{
		this(h,m,0);
	}
	
	public Time2(int h, int m, int s)
	{
		setTime(h,m,s);
	}

	public Time2(Time2 time)
	{
		this(time.getHour(), time.getMinute(), time.getSecond());
	}
	
	public void setTime(int h, int m, int s)
	{
		if(!(setHour(h)))
		{
			hour = 0;
		}
		if(!(setMinute(m)))
		{
			minute = 0;
		}
		if(!(setSecond(s)))
		{
			second = 0;
		}
	}
	
	public boolean setHour(int h)
	{
		if(h >= 0 && h < 24)
		{	
			hour = h;
			return true;
		}
		else
			return false;
	}
	
	public boolean setMinute(int m)
	{
		if(m >= 0 && m < 60)
		{
			minute = m;
			return true;
		}	
		else
			return false;
	}
	
	public boolean setSecond(int s)
	{
		if(s >= 0 && s < 60)
		{
			second = s;
			return true;
		}		
		else
			return false;
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
			second = ((setSecond(0)) ? 0 : 0);
			nextMinute();
		}
		else
		{
			second = ((setSecond(second + 1)) ? (second + 1) : 0);
		}
	}
	
	public void nextMinute()
	{
		if(minute + 1 == 60)
		{
			minute = ((setMinute(0)) ? 0 : 0);
			nextHour();
		}
		else
		{
			minute = ((setMinute(minute + 1)) ? (minute + 1) : 0);
		}
	}
	
	public void nextHour()
	{
		if(hour + 1 == 24)
		{	
			hour = ((setHour(1)) ? 1 : 0);
		}
		else
		{
			hour = ((setHour(hour + 1)) ? (hour + 1) : 0);
		}
	}
	
	public String toUniversalString()
	{
		return String.format("%02d:%02d:%02d\n",getHour(),getMinute(),getSecond());
	}
	
	public String toString()
	{
		return String.format("%d:%02d:%02d %s\n",((getHour() == 0 || getHour() == 12) ? 12: getHour() % 12), getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
	}
}