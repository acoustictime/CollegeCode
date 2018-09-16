package cse405;

import java.io.IOException;
import javax.servlet.http.*;

@SuppressWarnings("serial")
public class GetHighestNumberServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		
		
        
        resp.setContentType("text/plain");
    	resp.getWriter().println(UserNumber.largestValue());     
  }
}
		
		
