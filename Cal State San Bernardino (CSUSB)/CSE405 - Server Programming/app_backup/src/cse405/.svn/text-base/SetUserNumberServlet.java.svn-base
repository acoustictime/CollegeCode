package cse405;

import java.io.IOException;
import javax.servlet.http.*;
import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;



@SuppressWarnings("serial")
public class SetUserNumberServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		
		//check if user is logged in and get Id and 
		
		UserService userService = UserServiceFactory.getUserService();
        User user = userService.getCurrentUser();
        
        if (user != null) { 
        	String userId = user.getNickname();
        	int number = Integer.parseInt(req.getParameter("userNum"));
    		UserNumber.createOrUpdate(number,userId);
        }   
	}
}