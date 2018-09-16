public class Time3
{
	private int seconds;
	
	public Time3()
	{
		this(0,0,0);
	}
	
	public Time3(int h)
	{
		this(h,0,0);
	}
	
	public Time3(int h, int m)
	{
		this(h,m,0);
	}
	
	public Time3(int h, int m, int s)
	{
		setTime(h,m,s);
	}

	public Time3(Time3 time)
	{
		this(time.getHour(), time.getMinute(), time.getSecond());
	}
	
	public void setTime(int h, int m, int s)
	{
		if(!(setHour(h)));
			
		if(!(setMinute(m)));

		if(!(setSecond(s)));
	}
	
	public boolean setHour(int h)
	{
		if(h >= 0 && h < 24)
		{	
			seconds = h * 60 * 60;
			return true;
		}
		else
			return false;
	}
	
	public boolean setMinute(int m)
	{
		if(m >= 0 && m < 60)
		{
			seconds += (m * 60);
			return true;
		}	
		else
			return false;
	}
	
	public boolean setSecond(int s)
	{
		if(s >= 0 && s < 60)
		{
			seconds += s;
			return true;
		}		
		else
			return false;
	}
	
	public int getHour()
	{
		int temp = 0;
		int temp2 = 0;
		
		temp = (seconds / 60);		
		temp2 = (temp / 60);
		


		return temp2;	
	}
	
	public int getMinute()
	{
		int temp = 0;
		int temp2 = 0;
		
		temp = (seconds / 60);		
		temp2 = 60 * (temp / 60);
		temp = temp - temp2;

		return temp;	
	}
	
	public int getSecond()
	{
		int temp = 0;

		temp = 60 * (seconds / 60);	
		temp = seconds - temp;
		
		return temp;	
	}
	
	public void nextSecond()
	{
		seconds++;
	}

	public String toUniversalString()
	{
		return String.format("%02d:%02d:%02d\n",getHour(),getMinute(),getSecond());
	}
	
	public String seconds()
	{
		return String.format("%d",seconds);
	}
	
	public String toString()
	{
		return String.format("%d:%02d:%02d %s\n",((getHour() == 0 || getHour() == 12) ? 12: getHour() % 12), getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
	}
}