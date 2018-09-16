package cse405;

import java.io.IOException;
import javax.servlet.http.*;

import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;

@SuppressWarnings("serial")
public class GetUserNumberServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		
		UserService userService = UserServiceFactory.getUserService();
        User user = userService.getCurrentUser();
        
        if (user != null) {
        	 String userId = user.getNickname();
             UserNumber userNumber = UserNumber.getUserNumber(userId);
             resp.setContentType("text/plain");
         	resp.getWriter().println(userNumber.getNumber());     
        }    
  }
}
		
		
