$(document).ready(function() {
  update();
  signout();
	
  function update() {  
	  var csrfToken = retrieveKey();
    $.get("get-admin-message",{csrf:csrfToken},function(responseText) { 
      $('textArea').val(responseText);      
    });
  }
  
  $("#undo").click(function() {
	  var csrfToken = retrieveKey();
    $.get("get-admin-message",{csrf:csrfToken},function(responseText) { 
      $('textArea').val(responseText);      
    });
  });
	
  $("#submit").click(function() {
	  var csrfToken = retrieveKey();
    var newMessage = $('#textArea').val();
    $.get("set-admin-message", {message:newMessage, csrf:csrfToken},function(responseText) {  
	  alert(responseText);
	  undo(); // updates the textArea box with the current message
	});
  });
	
  function signout() {  
	  var csrfToken = retrieveKey();
    $.get("check-admin",{csrf:csrfToken},function(responseText) {    
	  $("#update").html(responseText);
    });
  }
  
  function retrieveKey() {
	  var nameEQ = "csrf" + "=", ca = document.cookie.split(';'), i = 0, c;
	    for(;i < ca.length;i++) {
	        c = ca[i];
	        while (c[0]==' ') c = c.substring(1);
	        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length);
	    }
	    return null;
	}
 });










