$(document).ready(function() {

	 $( "#tabs" ).tabs();
	 
	 document.getElementById("tabs").style.display = "none";
	 document.getElementById("me").style.display = "none";
	 
 });

// Color Slider
 
 function hexFromRGB(r, g, b) {
     var hex = [
         r.toString( 16 ),
         g.toString( 16 ),
         b.toString( 16 )
     ];
     $.each( hex, function( nr, val ) {
         if ( val.length === 1 ) {
             hex[ nr ] = "0" + val;
         }
     });
     return hex.join( "" ).toUpperCase();
 }
 function refreshSwatch() {
     var red = $( "#red" ).slider( "value" ),
         green = $( "#green" ).slider( "value" ),
         blue = $( "#blue" ).slider( "value" ),
         hex = hexFromRGB( red, green, blue );
     $( "body" ).css( "background-color", "#" + hex );
 }
 $(function() {
     $( "#red, #green, #blue" ).slider({
         orientation: "horizontal",
         range: "min",
         max: 255,
         value: 127,
         slide: refreshSwatch,
         change: refreshSwatch
     });
     $( "#red" ).slider( "value", 255 );
     $( "#green" ).slider( "value", 255 );
     $( "#blue" ).slider( "value", 255 );
 });
 
 
 //Resets Settings after Pressing Header

function reset2() {
    $( "#red" ).slider( "value", 255 );
    $( "#green" ).slider( "value", 255 );
    $( "#blue" ).slider( "value", 255 );
	
	
	document.getElementById("tabs").style.display = "none";
	document.getElementById("me").style.display = "none";
}

function aboutMe() {
	document.getElementById("tabs").style.display = "none";
	document.getElementById("me").style.display = "block";
	
}

function tvShows() {
	document.getElementById("me").style.display = "none";
	document.getElementById("tabs").style.display = "block";
	
}

function example1() {
	
	window.open("example1.html", "_self");
	
}

function example2() {
	
	window.open("example2.html", "_self");
	
}