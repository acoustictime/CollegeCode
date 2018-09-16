<%@ page import = "com.google.appengine.api.users.User" %>
<%@ page import = "com.google.appengine.api.users.UserService" %>
<%@ page import = "com.google.appengine.api.users.UserServiceFactory" %>

<!DOCTYPE html>
  <head>
    <title>CSE405 Bootstrap App</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
     <!-- Bootstrap Stylesheets and Main Stylesheet -->
     
    <link href="css/bootstrap.min.css" rel="stylesheet" media="screen">
	<link href="css/bootstrap-responsive.css" rel="stylesheet">
    <link href="css/main.css" rel="stylesheet"> 
    
    <!-- Bootstrap, Jquery, and Main Javascript -->
    
    <script src="//code.jquery.com/jquery-latest.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <script src="js/main.js"></script>  
    <script src="js/drive.js"></script> 
  </head>
  
  <body>
  
    <!-- Page is in Two Sections, the First below is the Nav Bar on top of the screen -->
    
    <div class="navbar navbar-inverse navbar-fixed-top">
      <div class="navbar-inner">
        <div class="container">
          
          <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </a>
          
          <a href = "../" class="brand">CSE405 Bootstrap</a>
          
          <div class="nav-collapse collapse">
            <ul class="nav">
              <li id="homenav" class="active"><a>Home</a></li>
              <li id="adminnav"><a href= "/admin/admin.html">Admin Page</a></li>
              <li id="styleguide"><a href= "styleguide.html">Styleguide</a></li>
              <li id="ajaxhtml"><a href= "ajax.html">Ajax Assignment</a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>
    
    <!-- Page is in Two Sections, the Second below is the main container for content -->
    
    <div class="container">
    
      <!--Main Div used to display message from Admin -->
      <div class="hero-unit" id="home"></div> 
      
      <!--Div used to display Highest Personal Number -->
      <div id="highest"></div>
      <br>
      <br>
      
      <% 
        UserService userService = UserServiceFactory.getUserService();
        User user = userService.getCurrentUser();
         
        if (user != null) {
      %>
      	
      <p>Please logout when done setting your personal number, <a href="<%= userService.createLogoutURL(request.getRequestURI()) %>">Sign Out</a></p>
      <br>
      <br>
      
      <table>
        <tbody>
          <tr>
            <td><button class="btn btn-inverse" id="decrease">-</button></td>
            <td><div id="personalNum">0</div></td>
            <td><button class="btn btn-inverse" id="increase">+</button></td>
            <td><button class="btn" id="submit">Submit</button></td>
          </tr>
        </tbody>
      </table>
      <br>
      
      <!--Div used to display alerts when submit button pressed -->
      <div id="alertMessage"></div>
      
      <br>
      <br>
      
      <p>Your Personal Message is: </p>
      <div id="pMessage"></div>
     
      <br>
      <br>
      
      <p>Set your personal message below.  If you already have one, it's displayed below:</p>
      <textarea id="textArea" class="span7 offset1"></textarea>
	  <br>
	  <button class="btn btn-inverse" id="submitLocal">Submit to HTML5 Local Storage</button>
	  <button class="btn btn-inverse" id="doitButton"      style="display: none">Submit to Google Drive</button>
	  <button class="btn btn-inverse" id="readButton"      style="display: none">Read from Google Drive</button>
      <button class="btn btn-inverse" id="authorizeButton" style="display: none">Authorize Google Drive</button>
	  <br>
	  <div id="localMessageAlert"></div>
      
      <%
        } else {
	  %>
      
      <p>Please login to setup your personal number, <a href="<%= userService.createLoginURL("/") %>">Sign In</a></p>
      
      <%
        }
	  %>
	  
	  <script type="text/javascript" src="https://apis.google.com/js/client.js?onload=handleClientLoad"></script>
	
    </div>
  </body>
</html>  