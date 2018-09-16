package cse405;

import java.io.IOException;
import javax.servlet.http.*;

@SuppressWarnings("serial")
public class GetAdminMessageServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		AdminMessage adminMessage = AdminMessage.getAdminMessage();
		resp.setContentType("text/plain");
		resp.getWriter().println(adminMessage.getText());
	}
}
