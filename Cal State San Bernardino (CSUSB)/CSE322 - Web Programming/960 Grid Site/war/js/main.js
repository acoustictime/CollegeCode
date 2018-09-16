$(document).ready(function() {
	 
	 document.getElementById("tabs1").style.display = "none";
	 document.getElementById("tabs2").style.display = "none";
	 document.getElementById("tabs3").style.display = "none";
	 document.getElementById("tabs4").style.display = "none";
	 document.getElementById("picker").style.display = "none";
	 document.getElementById("tictac").style.display = "none";
	 document.getElementById("me").style.display = "none";
	 document.getElementById("me2").style.display = "none";	 
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

    	 document.getElementById("tabs1").style.display = "none";
	 document.getElementById("tabs2").style.display = "none";
	 document.getElementById("tabs3").style.display = "none";
	 document.getElementById("tabs4").style.display = "none";
	 document.getElementById("picker").style.display = "none";
	 document.getElementById("tictac").style.display = "none";
	 document.getElementById("me").style.display = "none";
	 document.getElementById("me2").style.display = "none";
	
}

function aboutMe() {
	document.getElementById("tabs1").style.display = "none";
	document.getElementById("tabs2").style.display = "none";
	document.getElementById("tabs3").style.display = "none";
	document.getElementById("tabs4").style.display = "none";
	document.getElementById("picker").style.display = "none";
	document.getElementById("me").style.display = "block";
	document.getElementById("me2").style.display = "block";
	document.getElementById("tictac").style.display = "none";
}

function tvShows() {
	document.getElementById("me").style.display = "none";
	document.getElementById("me2").style.display = "none";
	document.getElementById("tabs1").style.display = "block";
	document.getElementById("tabs2").style.display = "block";
	document.getElementById("tabs3").style.display = "block";
	document.getElementById("tabs4").style.display = "block";
	document.getElementById("picker").style.display = "none";
	document.getElementById("tictac").style.display = "none";
	
}

function example1() {
	document.getElementById("me").style.display = "none";
	document.getElementById("me2").style.display = "none";
	document.getElementById("tabs1").style.display = "none";
	document.getElementById("tabs2").style.display = "none";
	document.getElementById("tabs3").style.display = "none";
	document.getElementById("tabs4").style.display = "none";
	document.getElementById("tictac").style.display = "none";
	document.getElementById("picker").style.display = "block";
	
}

function example2() {
	document.getElementById("me").style.display = "none";
	document.getElementById("me2").style.display = "none";
	document.getElementById("tabs1").style.display = "none";
	document.getElementById("tabs2").style.display = "none";
	document.getElementById("tabs3").style.display = "none";
	document.getElementById("tabs4").style.display = "none";
	document.getElementById("picker").style.display = "none";
	document.getElementById("tictac").style.display = "block";
	
}

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
        max: 50,
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


var human = "<a>X</a>";
var computer = "<a>O</a>";
var blank = "<a></a>";
var board = [0,0,0,0,0,0,0,0,0];
var humanMove = 5;
var computerMove = 6;
var computerValidMove = false;
var winnerFound = false;
var drawFound = false;
var movesPlayed = 0;
var humanWinCount = 0;
var computerWinCount = 0;
var drawCount = 0;
var winDrawLose = "";

function back() {
	window.open("index.html", "_self");
}

function reset() {
	board = [0,0,0,0,0,0,0,0,0];	
	computerValidMove = false;
	winnerFound = false;
	movesPlayed = 0;
	drawFound = false;
	winDrawLose = "";
	$("#result").html("Result = ");

	$("#one").removeClass("full");
	$("#one").removeClass("winner");	
	$("#one").addClass("empty");
	$("#one").html(blank);

	$("#two").removeClass("full");
	$("#two").removeClass("winner");
	$("#two").addClass("empty");
	$("#two").html(blank);

	$("#three").removeClass("full");
	$("#three").removeClass("winner");
	$("#three").addClass("empty");
	$("#three").html(blank);

	$("#four").removeClass("full");
	$("#four").removeClass("winner");
	$("#four").addClass("empty");
	$("#four").html(blank);

	$("#five").removeClass("full");
	$("#five").removeClass("winner");
	$("#five").addClass("empty");
	$("#five").html(blank);

	$("#six").removeClass("full");
	$("#six").removeClass("winner");
	$("#six").addClass("empty");
	$("#six").html(blank);

	$("#seven").removeClass("full");
	$("#seven").removeClass("winner");
	$("#seven").addClass("empty");
	$("#seven").html(blank);

	$("#eight").removeClass("full");
	$("#eight").removeClass("winner");
	$("#eight").addClass("empty");
	$("#eight").html(blank);

	$("#nine").removeClass("full");
	$("#nine").removeClass("winner");
	$("#nine").addClass("empty");
	$("#nine").html(blank);

}

function buttonClicked(number) {

	var $numberId = $(number);

	if(!$numberId.hasClass("full") && winnerFound === false) {
	
		switch (number) {

			case one:
				board[0] = humanMove;
			break;
		
			case two:
				board[1] = humanMove;
			break;

			case three:
				board[2] = humanMove;
			break;

			case four:
				board[3] = humanMove;
			break;

			case five:
				board[4] = humanMove;
			break;

			case six:
				board[5] = humanMove;
			break;

			case seven:
				board[6] = humanMove;
			break;

			case eight:
				board[7] = humanMove;
			break;

			case nine:
				board[8] = humanMove;
			break;
		}

		$numberId.removeClass("empty");
		$numberId.addClass("full");
		$numberId.html(human);
		movesPlayed++;

		checkForWinner();

		if (!winnerFound && !drawFound) {
			computerPlay();
		}

		
	} 	
}

function computerPlay() {

	// win DONE
	// block DONE
	// fork win DONE
	// fork setup DONE
	// block fork DONE
	// center DONE
	// opposite corner DONE
	// empty corner DONE
	// random DONE

	computerValidMove = false;

	computerWin();

	if(!computerValidMove) {
		computerBlock();
	} 

	if(!computerValidMove) {
		computerForkWin();
	}

	if(!computerValidMove) {
		computerForkSetup();
	}

	if(!computerValidMove) {
		computerForkBlock();
	} 

	if(!computerValidMove) {
		computerCenter();
	} 

	 if(!computerValidMove) {
		computerOppositeCorner();
	} 

	if(!computerValidMove) {
		computerEmptyCorner();
	} 

	if(!computerValidMove) {
		computerRandom();
	}

	

	checkForWinner();
}

function computerWin() {

	var move = -1;
	
	for(var i = 0;i < 9;i += 3) {
		if(board[i] + board[i + 1] + board[i + 2] === computerMove * 2) {
			for (var j = 0;j < 3;j++) {
				if(board[i + j] === 0) {
					move = i + j;				
				}
			}
		}
	}

	for(var i = 0;i < 3;i++) {
		if(board[i] + board[i + 3] + board[i + 6] === computerMove * 2) {
			for (var j = 0;j < 9;j += 3) {
				if(board[i + j] === 0) {
					move = i + j;
				}
			}
		}
	}	

	if (board[0] + board[4] + board[8] === computerMove * 2) {
		if(board[0] === 0) {
			move = 0;
		} else if(board[4] === 0) {
			move = 4;
		} else if(board[8] === 0) {
			move = 8;
		}
	}

	if (board[2] + board[4] + board[6] === computerMove * 2) {
		if(board[2] === 0) {
			move = 2;
		} else if(board[4] === 0) {
			move = 4;
		} else if(board[6] === 0) {
			move = 6;
		}
	}

	if (move >= 0) {
		computerValidMove = true;
		board[move] = computerMove;
		$compJquery = numberConverter(move + 1);
		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}

}

function computerBlock() {

	var move = -1;
	
	for(var i = 0;i < 9;i += 3) {
		if(board[i] + board[i + 1] + board[i + 2] === humanMove * 2) {
			for (var j = 0;j < 3;j++) {
				if(board[i + j] === 0) {
					move = i + j;
				}
			}
		}
	}

	for(var i = 0;i < 3;i++) {
		if(board[i] + board[i + 3] + board[i + 6] === humanMove * 2) {
			for (var j = 0;j < 9;j += 3) {
				if(board[i + j] === 0) {
					move = i + j;
				}
			}
		}
	}	

	if (board[0] + board[4] + board[8] === humanMove * 2) {
		if(board[0] === 0) {
			move = 0;
		} else if(board[4] === 0) {
			move = 4;
		} else if(board[8] === 0) {
			move = 8;
		}
	}

	if (board[2] + board[4] + board[6] === humanMove * 2) {
		if(board[2] === 0) {
			move = 2;
		} else if(board[4] === 0) {
			move = 4;
		} else if(board[6] === 0) {
			move = 6;
		}
	}

	if (move >= 0) {
		computerValidMove = true;
		board[move] = computerMove;
		$compJquery = numberConverter(move + 1);
		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}

}

function computerForkWin() {
	var move = -1;
	
	if (board[0] === computerMove && board[7] === computerMove && board[6] === 0) {
		move = 6;
	} else if (board[0] === computerMove && board[5] === computerMove && board[2] === 0) {
		move = 2;
	} else if (board[2] === computerMove && board[7] === computerMove && board[8] === 0) {
		move = 8;
	} else if (board[2] === computerMove && board[3] === computerMove && board[0] === 0) {
		move = 0;
	} else if (board[1] === computerMove && board[8] === computerMove && board[2] === 0) {
		move = 2;
	} else if (board[3] === computerMove && board[8] === computerMove && board[6] === 0) {
		move = 6;
	} else if (board[1] === computerMove && board[6] === computerMove && board[6] === 0) {
		move = 6;
	} else if (board[5] === computerMove && board[6] === computerMove && board[8] === 0) {
		move = 8;
	} 

	if (move >= 0) {
		computerValidMove = true;

		board[move] = computerMove;

		var $compJquery = numberConverter(move + 1);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}
}

function computerForkSetup() {
	var move = -1;

	if(board[0] === computerMove) {
		if(board[4] === 0 && board[6] === 0 && board[7] === 0 && board[8] === 0) {
			move = 7;
		} else if(board[1] === 0 && board[2] === 0 && board[5] === 0 && board[8] === 0) {
			move = 5;
		} 
	}

	if(board[2] === computerMove) {
		if(board[5] === 0 && board[8] === 0 && board[6] === 0 && board[7] === 0) {
			move = 7;
		} else if(board[0] === 0 && board[1] === 0 && board[3] === 0 && board[6] === 0) {
			move = 3;
		} 
	}

	if(board[8] === computerMove) {
		if(board[0] === 0 && board[1] === 0 && board[2] === 0 && board[5] === 0) {
			move = 1;
		} else if(board[0] === 0 && board[3] === 0 && board[6] === 0 && board[7] === 0) {
			move = 3;
		} 
	}

	if(board[6] === computerMove) {
		if(board[0] === 0 && board[1] === 0 && board[2] === 0 && board[3] === 0) {
			move = 1;
		} else if(board[2] === 0 && board[5] === 0 && board[7] === 0 && board[8] === 0) {
			move = 5;
		} 
	}

	if(board[7] === computerMove) {
		if(board[0] === 0 && board[3] === 0 && board[6] === 0 && board[8] === 0) {
			move = 0;
		} else if(board[2] === 0 && board[5] === 0 && board[6] === 0 && board[8] === 0) {
			move = 2;
		} 
	}


	if(board[5] === computerMove) {
		if(board[0] === 0 && board[1] === 0 && board[2] === 0 && board[8] === 0) {
			move = 0;
		} else if(board[2] === 0 && board[6] === 0 && board[7] === 0 && board[8] === 0) {
			move = 6;
		} 
	}


	if(board[3] === computerMove) {
		if(board[0] === 0 && board[1] === 0 && board[2] === 0 && board[6] === 0) {
			move = 2;
		} else if(board[0] === 0 && board[6] === 0 && board[7] === 0 && board[8] === 0) {
			move = 8;
		} 
	}


	if(board[1] === computerMove) {
		if(board[0] === 0 && board[2] === 0 && board[3] === 0 && board[6] === 0) {
			move = 6;
		} else if(board[0] === 0 && board[2] === 0 && board[5] === 0 && board[8] === 0) {
			move = 8;
		} 
	}

	if (move >= 0) {
		computerValidMove = true;
		board[move] = computerMove;

		var $compJquery = numberConverter(move + 1);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}
}

function computerForkBlock() {

	var move = -1;
	
	if (board[0] === humanMove && board[7] === humanMove && board[6] === 0) {
		move = 6;
	} else if (board[0] === humanMove && board[5] === humanMove && board[2] === 0) {
		move = 2;
	} else if (board[2] === humanMove && board[7] === humanMove && board[8] === 0) {
		move = 8;
	} else if (board[2] === humanMove && board[3] === humanMove && board[0] === 0) {
		move = 0;
	} else if (board[1] === humanMove && board[8] === humanMove && board[2] === 0) {
		move = 2;
	} else if (board[3] === humanMove && board[8] === humanMove && board[6] === 0) {
		move = 6;
	} else if (board[1] === humanMove && board[6] === humanMove && board[6] === 0) {
		move = 6;
	} else if (board[5] === humanMove && board[6] === humanMove && board[8] === 0) {
		move = 8;
	} else if (board[0] === humanMove && board[8] === humanMove && board[7] === 0) {
		move = 7;
	} else if (board[2] === humanMove && board[6] === humanMove && board[7] === 0) {
		move = 7;
	}

	if (move >= 0) {
		computerValidMove = true;

		board[move] = computerMove;

		var $compJquery = numberConverter(move + 1);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}

}

function computerCenter() {
	if(board[4] === 0) {
		$("#five").removeClass("empty");
		$("#five").addClass("full");
		$("#five").html(computer);
		movesPlayed++;
		computerValidMove = true;
		board[4] = computerMove;	
	}
}

function computerOppositeCorner() {
	
	var move = -1;
	
	if (board[0] === humanMove && board[8] === 0) {
		move = 8;
	} else if (board[2] === humanMove && board[6] === 0) {
		move = 6;
	} else if (board[6] === humanMove && board[2] === 0) {
		move = 2;
	} else if (board[8] === humanMove && board[0] === 0) {
		move = 0;
	} 

	if (move >= 0) {
		computerValidMove = true;

		board[move] = computerMove;

		var $compJquery = numberConverter(move + 1);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}


}

function computerEmptyCorner() {
	
	var move = -1;

	
	if (board[0] === 0) {
		move = 0;
	} else if (board[2] === 0) {
		move = 2;
	} else if (board[6] === 0) {
		move = 6;
	} else if (board[8] === 0) {
		move = 8;
	} 

	if (move >= 0) {
		computerValidMove = true;

		board[move] = computerMove;

		var $compJquery = numberConverter(move + 1);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}

}


function computerRandom() {

	if(!winnerFound && movesPlayed < 9) {

		var move = Math.floor(Math.random() * 9 + 1);

		while (board[move - 1] != 0) {
			move = Math.floor(Math.random() * 9 + 1);
		}

		computerValidMove = true;

		board[move - 1] = computerMove;

		var $compJquery = numberConverter(move);

		$compJquery.removeClass("empty");
		$compJquery.addClass("full");
		$compJquery.html(computer);
		movesPlayed++;
	}
}

function checkForWinner() {

	var current = board[0] + board[1] + board[2];

	if (current === 15) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#two").removeClass("full");
		$("#two").addClass("winner");
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#two").removeClass("full");
		$("#two").addClass("winner");
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[3] + board[4] + board[5];

	if (current === 15) {
		winnerFound = true;
		$("#four").removeClass("full");
		$("#four").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#six").removeClass("full");
		$("#six").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#four").removeClass("full");
		$("#four").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#six").removeClass("full");
		$("#six").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[6] + board[7] + board[8];

	if (current === 15) {
		winnerFound = true;
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		$("#eight").removeClass("full");
		$("#eight").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		$("#eight").removeClass("full");
		$("#eight").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[0] + board[3] + board[6];

	if (current === 15) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#four").removeClass("full");
		$("#four").addClass("winner");
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#four").removeClass("full");
		$("#four").addClass("winner");
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[1] + board[4] + board[7];

	if (current === 15) {
		winnerFound = true;
		$("#two").removeClass("full");
		$("#two").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#eight").removeClass("full");
		$("#eight").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#two").removeClass("full");
		$("#two").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#eight").removeClass("full");
		$("#eight").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[2] + board[5] + board[8];

	if (current === 15) {
		winnerFound = true;
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		$("#six").removeClass("full");
		$("#six").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		$("#six").removeClass("full");
		$("#six").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		return;
	}

	current = board[0] + board[4] + board[8];

	if (current === 15) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#one").removeClass("full");
		$("#one").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#nine").removeClass("full");
		$("#nine").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	current = board[2] + board[4] + board[6];

	if (current === 15) {
		winnerFound = true;
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		humanWinCount++;
		winDrawLose = "Win";
		update();
		return;
	} else if (current === 18) {
		winnerFound = true;
		$("#three").removeClass("full");
		$("#three").addClass("winner");
		$("#five").removeClass("full");
		$("#five").addClass("winner");
		$("#seven").removeClass("full");
		$("#seven").addClass("winner");
		computerWinCount++;
		winDrawLose = "Lose";
		update();
		return;
	}

	// Check for Draw

	var checkForDraw = 0;

	for (var i = 0;i < 9; i++) {
		if (board[i] > 0) {
			checkForDraw++;
		}
	}

	if (checkForDraw === 9) {
		drawCount++;
		drawFound = true;
		winDrawLose = "Draw";
		update();
	}	
}

function numberConverter(number) {
	switch (number) {

	case 1:
		return $("#one");
	break;

	case 2:
		return $("#two");
	break;

	case 3:
		return $("#three");
	break;

	case 4:
		return $("#four");
	break;

	case 5:
		return $("#five");
	break;

	case 6:
		return $("#six");
	break;

	case 7:
		return $("#seven");
	break;

	case 8:
		return $("#eight");
	break;

	case 9:
		return $("#nine");
	break;
	}
}
	
function update() {
	$("#wins").html("Wins = " + humanWinCount);
	$("#losses").html("Lose = " + computerWinCount);
	$("#draws").html("Draws = " + drawCount);
	$("#result").html("Result = " + winDrawLose);
}
