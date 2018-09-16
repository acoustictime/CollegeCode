$(document).ready(function() {
  update();
  signout();
	
  function update() {  
    $.get("get-admin-message",function(responseText) { 
      $('textArea').val(responseText);      
    });
  }
  
  $("#undo").click(function() {
    $.get("get-admin-message",function(responseText) { 
      $('textArea').val(responseText);      
    });
  });
	
  $("#submit").click(function() {
    var newMessage = $('#textArea').val();
    $.get("set-admin-message", {message:newMessage},function(responseText) {  
	  alert(responseText);
	  undo(); // updates the textArea box with the current message
	});
  });
	
  function signout() {  
    $.get("check-admin",function(responseText) {    
	  $("#update").html(responseText);
    });
  }
 });










