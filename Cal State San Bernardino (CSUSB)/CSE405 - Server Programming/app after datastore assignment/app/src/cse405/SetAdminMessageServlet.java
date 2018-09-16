package cse405;

import java.io.IOException;
import javax.servlet.http.*;

import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;

@SuppressWarnings("serial")
public class SetAdminMessageServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		
		 UserService userService = UserServiceFactory.getUserService();

		 if (userService.isUserAdmin()) {         
			 String newMessage = req.getParameter("message");	 
			 newMessage = checkForHTML(newMessage);		 
			 AdminMessage adminMessage = AdminMessage.getAdminMessage();
			 adminMessage = adminMessage.createOrUpdate(newMessage); 
			 resp.setContentType("text/plain");
			 resp.getWriter().println("Your message was updated successfully!");
	     }
		 else {
			 resp.setContentType("text/plain");
			 resp.getWriter().println("You're not an administrator.  You can't change the message!"); 
		 }
		 
	}
	
	private String checkForHTML(String temp) {
		String newString = "";
		
		for (int i = 0;i < temp.length(); i++) {
			char c = temp.charAt(i);
			if(c != '<') {
				newString += c;
			}
		}
		return newString;
	}
}
