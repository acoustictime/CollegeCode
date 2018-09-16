package cse405;

import java.io.IOException;
import java.util.logging.Logger;

import javax.servlet.*;
import javax.servlet.http.*;

public class VerifyCsrfTokenFilter implements Filter {
	
	public void doFilter(ServletRequest req, ServletResponse resp,
			FilterChain chain) throws IOException, ServletException {
		
		HttpServletRequest httpReq = (HttpServletRequest) req;
		HttpServletResponse httpResp = (HttpServletResponse) resp;
		
		Cookie cookies[] = httpReq.getCookies();
		
		String tokenFromCookie = null;
		for (int i = 0;i < cookies.length;++i) {
			if(cookies[i].getName().equals("csrf")) {
				tokenFromCookie = cookies[i].getValue();
			}	
		}
		
		if(tokenFromCookie == null) {
			
			Logger.getLogger("app").warning("Request with no csrf cookie");
			httpResp.sendError(HttpServletResponse.SC_UNAUTHORIZED);
			return;
		}
		
		
		String csrfToken = httpReq.getParameter("csrf");
		
		if(csrfToken == null) {
			httpResp.sendError(HttpServletResponse.SC_UNAUTHORIZED);
			return;
		}
		
		
		if(csrfToken.equals(tokenFromCookie)) {
			chain.doFilter(req, resp);
		}
		else {
			httpResp.sendError(HttpServletResponse.SC_UNAUTHORIZED);
		}
		
		
		
	}
	
	public void destroy() {	
	}
	
	public void init(FilterConfig arg0) throws ServletException {	
	}
	
}