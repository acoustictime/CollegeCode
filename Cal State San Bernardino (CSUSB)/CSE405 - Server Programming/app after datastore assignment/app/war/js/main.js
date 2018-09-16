$(document).ready(function() {
  adminmessage();
	 
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
	 
  function adminmessage() { 
    $.get('get-admin-message',function(responseText) { 
      $('#home').html(responseText);      
    });
  }
  
 });

 












