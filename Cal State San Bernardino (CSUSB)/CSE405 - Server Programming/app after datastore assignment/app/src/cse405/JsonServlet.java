package cse405;

import java.io.IOException;
import javax.servlet.http.*;
import org.json.simple.JSONObject;


@SuppressWarnings("serial")
public class JsonServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		
		JSONObject obj = new JSONObject();
		obj.put("message","Sup!");
		resp.setContentType("application/json");
		resp.getWriter().println(obj);
	}
}
