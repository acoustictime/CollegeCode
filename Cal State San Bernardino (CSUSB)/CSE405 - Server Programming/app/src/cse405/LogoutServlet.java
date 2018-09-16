package cse405;

import java.io.IOException;
import javax.servlet.http.*;
import com.google.appengine.api.users.User;
import com.google.appengine.api.users.UserService;
import com.google.appengine.api.users.UserServiceFactory;

@SuppressWarnings("serial")
public class LogoutServlet extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse resp)
              throws IOException {
        UserService userService = UserServiceFactory.getUserService();
        User user = userService.getCurrentUser();
        

        resp.setContentType("text/plain");
        
        if (userService.isUserAdmin()) {         
            resp.getWriter().println("Hello " + user.getNickname() + ", Since you're an admin you can go ahead and make changes. Please <a href = " + userService.createLogoutURL("/") + ">Logout</a> when done");
        } else {
        	resp.getWriter().println("Hello " + user.getNickname() + ", Since you are not an admin you can't make changes.  Please <a href = " +  userService.createLogoutURL("/") + ">Logout</a>.");
        }
    }
}