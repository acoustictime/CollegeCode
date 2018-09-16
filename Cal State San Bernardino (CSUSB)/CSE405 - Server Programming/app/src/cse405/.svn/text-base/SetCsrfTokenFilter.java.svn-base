package cse405;

import java.io.IOException;
import java.security.SecureRandom;

import javax.servlet.*;
import javax.servlet.http.*;

public class SetCsrfTokenFilter implements Filter {
	
	static SecureRandom random = new SecureRandom();
	
	public void doFilter(ServletRequest req, ServletResponse resp,
			FilterChain chain) throws IOException, ServletException {
		
		HttpServletResponse httpResp = (HttpServletResponse) resp;
		
		Cookie cookie = new Cookie("csrf", "" + random.nextLong());
		
		httpResp.addCookie(cookie);

		chain.doFilter(req, resp);
	}
	
	public void destroy() {	
	}
	
	public void init(FilterConfig arg0) throws ServletException {	
	}
	
}