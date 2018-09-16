$(document).ready(function() {
  adminmessage();
  highestNumber();
  usernumber();
  localStorageUpdate();
  
  function retrieveKey() {
	  var nameEQ = "csrf" + "=", ca = document.cookie.split(';'), i = 0, c;
	    for(;i < ca.length;i++) {
	        c = ca[i];
	        while (c[0]==' ') c = c.substring(1);
	        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length);
	    }
	    return null;
	}
	 
  function loadFile(url) {
    function callback() {
	  if (req.readyState == 4) { // 4 = Loaded
	    if (req.status == 200) {
	      $("#ajaxhi").html(req.responseText);
	    } else {
	        // Error
	    }
	  }
	}
	  
	var req = new XMLHttpRequest();
	req.onreadystatechange = callback;
	req.open("GET", url, true);
	req.send("");
  }
	 
  $("#ajax").click(function(){
    loadFile("/ajax");
  });
	 
  $("#jquery").click(function() {
	var csrfToken = retrieveKey();
    $.get('jquery',{csrf:csrfToken},function(responseText) { 
	  $('#jqueryhi').html(responseText);      
	});
  });
	 
  $("#json").click(function() {
	  var csrfToken = retrieveKey();
    $.get('json',{csrf:csrfToken},function(responseText) { 
	  var json = responseText;	
	    $('#jsonhi').html(json.message);    
	});
  });

  $("#clear").click(function() {
    $("#ajaxhi").empty();
	$("#jqueryhi").empty();
	$("#jsonhi").empty();
  });
  
  $("#decrease").click(function() {
    var number = parseInt($("#personalNum").html());
	number--;    
	$("#personalNum").html(number);
  });
  
  $("#increase").click(function() {
    var number = parseInt($("#personalNum").html());
	number++;
	$("#personalNum").html(number);	   
  });
  
  function highestNumber() {
	  var csrfToken = retrieveKey();
    $.get('get-high-number',{csrf:csrfToken},function(responseText) { 
	  var highString = "The highest number amoung all users is: " + responseText;
	  $('#highest').html(highString);      
	});  	   
  }
  
  $("#submit").click(function() {
    var number = parseInt($("#personalNum").html());  
    var csrfToken = retrieveKey();  
	$.get('set-user-number', {userNum:number,csrf:csrfToken},function(responseText) { 
      $("#alertMessage").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You have successfully updated your personal number to " + number + ".</div>");	
      highestNumber();
	});
  });
	 
  function adminmessage() { 
	  var csrfToken = retrieveKey(); 
    $.get('get-admin-message',{csrf:csrfToken},function(responseText) { 
      $('#home').html(responseText);      
    });
  }
  
  function usernumber() { 
	  var csrfToken = retrieveKey();
    $.get('get-user-number',{csrf:csrfToken},function(responseText) { 
	  $('#personalNum').html(responseText);      
	});
  }
  
  function localStorageUpdate() {
	  var msg = localStorage.localMessage;
	  $("#pMessage").html(msg);
  }
  
  $("#submitLocal").click(function() {
    if(typeof(Storage)!=="undefined") {
	  var newMessage = $('#textArea').val();
	  localStorage.localMessage = newMessage;
	  $("#pMessage").html(newMessage);
	  $("#textArea").val("");
      $("#localMessageAlert").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You've updated your personal message in local storage successfully.</div>");
	}
	else {
	  $("#localMessageAlert").html("<div class= 'alert alert-error fade in'><a class= 'close' data-dismiss='alert'>x</a>Sorry, your browser doesn't support HTML5 Local Storage.</div>");
	}	
  });
  
  
  
 }); // end document ready function

 

