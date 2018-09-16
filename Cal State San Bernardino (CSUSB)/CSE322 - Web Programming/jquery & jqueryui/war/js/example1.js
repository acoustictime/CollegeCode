$(function() {
    $( "#datePicker" ).datepicker(
    {onSelect: function(dateText) {
    	$("#displayDate").html(dateText);
    }		
    
    
	});
   
});


$(function() {
    $( "#sizeSlider" ).slider({
        min: 5,
        max: 100,
        value: 5,
        slide: function (even, ui) {
        	alert
        	$("#displayDate").css("font-size", ui.value);
        }

    });
});

function redButton() {
	$("#displayDate").css("color","red");
}

function blueButton() {
	$("#displayDate").css("color","blue");
}

function back() {
	window.open("index.html", "_self");
}