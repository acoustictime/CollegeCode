$(document).ready(function() {
  adminmessage();
  highestNumber();
  usernumber();
  localStorageUpdate();

	 
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
    $.get('jquery',function(responseText) { 
	  $('#jqueryhi').html(responseText);      
	});
  });
	 
  $("#json").click(function() {
    $.get('json',function(responseText) { 
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
    $.get('get-high-number',function(responseText) { 
	  var highString = "The highest number amoung all users is: " + responseText;
	  $('#highest').html(highString);      
	});  	   
  }
  
  $("#submit").click(function() {
    var number = parseInt($("#personalNum").html());  
	$.get('set-user-number', {userNum:number},function(responseText) { 
      $("#alertMessage").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You have successfully updated your personal number to " + number + ".</div>");	
      highestNumber();
	});
  });
	 
  function adminmessage() { 
    $.get('get-admin-message',function(responseText) { 
      $('#home').html(responseText);      
    });
  }
  
  function usernumber() { 
    $.get('get-user-number',function(responseText) { 
	  $('#personalNum').html(responseText);      
	});
  }
  
  function localStorageUpdate() {
	  var msg = localStorage.localMessage;
	  $("textArea").val(msg);
  }
  
  $("#submitLocal").click(function() {
    if(typeof(Storage)!=="undefined") {
	  var newMessage = $('#textArea').val();
	  localStorage.localMessage = newMessage;
      $("#localMessageAlert").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You've updated your personal message in local storage successfully.</div>");
	}
	else {
	  $("#localMessageAlert").html("<div class= 'alert alert-error fade in'><a class= 'close' data-dismiss='alert'>x</a>Sorry, your browser doesn't support HTML5 Local Storage.</div>");
	}	
  });
  
 }); // end document ready function

 












