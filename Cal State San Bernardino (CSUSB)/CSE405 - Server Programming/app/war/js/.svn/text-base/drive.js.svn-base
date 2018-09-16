var CLIENT_ID = '221035450913.apps.googleusercontent.com';
var SCOPES = 'https://www.googleapis.com/auth/drive';
var fileId = '0';
var fileName = 'CSUSB Google Drive Test File.txt';


 
/**
* Called when the client library is loaded to start the auth flow.
*/
function handleClientLoad() {
  window.setTimeout(checkAuth, 1);
}
 
/**
* Check if the current user has authorized the application.
*/
function checkAuth() {
  gapi.auth.authorize(
    {'client_id': CLIENT_ID, 'scope': SCOPES, 'immediate': true},
    handleAuthResult);
}
 
/**
* Called when authorization server replies.
*
* @param {Object} authResult Authorization result.
*/
function handleAuthResult(authResult) {
  var authButton = document.getElementById('authorizeButton');
  var doitButton = document.getElementById('doitButton');
  var readButton = document.getElementById('readButton');
  authButton.style.display = 'none';
  doitButton.style.display = 'none';
  readButton.style.display = 'none';
  if (authResult && !authResult.error) {
    // Access token has been successfully retrieved, requests can be sent to the API.
    getFileId(fileName);
	doitButton.style.display = 'block';
    doitButton.onclick = uploadFile;
    readButton.style.display = 'block';
    readButton.onclick = downloadFile; 
  } else {
    // No access token could be retrieved, show the button to start the authorization flow.
    authButton.style.display = 'block';
    authButton.onclick = function() {
      gapi.auth.authorize(
      {'client_id': CLIENT_ID, 'scope': SCOPES, 'immediate': false},
      handleAuthResult);
    };
  }
}
 
/**
* Start the file upload.
*
* @param {Object} evt Arguments from the file selector.
*/
function uploadFile(evt) {
  gapi.client.load('drive', 'v2', function() {
	  getFileId(fileName);
	  insertFile();
  });
}
 
function downloadFile(evt) {
  gapi.client.load('drive', 'v2', function() {
	  readFile();
  });
 }
      
function getFileId(fileName) {
  var request = gapi.client.request({
    'path': 'drive/v2/files',
    'method': 'GET',
    'params': {
    	 'q':"trashed != true and title = '" + fileName + "'"
    	  }
  });
  request.execute(listItems);
}
    	  
function listItems(resp) {
	var result = resp.items;
	
	if (result != 0) {
      fileId = result[0].id; 
	}
    else {
      fileId = 0;
    }
}
   
/**
* Insert new file.
*/
function insertFile() {
  getFileId(fileName);
    	  
  const boundary = '-------314159265358979323846264';
  const delimiter = "\r\n--" + boundary + "\r\n";
  const close_delim = "\r\n--" + boundary + "--";
  var appState = $("#textArea").val();
         
  var contentType = 'text/plain';
  var metadata = {
    'title': fileName,
    'mimeType': contentType
  };
        
  var base64Data = btoa(appState);
  var multipartRequestBody =
    delimiter +
    'Content-Type: application/json\r\n\r\n' +
    JSON.stringify(metadata) +
    delimiter +
    'Content-Type: ' + contentType + '\r\n' +
    'Content-Transfer-Encoding: base64\r\n' +
    '\r\n' +
    base64Data +
    close_delim;
        
    if(fileId == "0") {       
      var request = gapi.client.request({
        'path': '/upload/drive/v2/files',
        'method': 'POST',
        'params': {'uploadType': 'multipart'},
        'headers': {
        'Content-Type': 'multipart/mixed; boundary="' + boundary + '"'
      },
        'body': multipartRequestBody});     	
    } else {    	
      var request = gapi.client.request({
        'path': '/upload/drive/v2/files/' + fileId,
        'method': 'PUT',
        'params': {'uploadType': 'multipart'},
        'headers': {
          'Content-Type': 'multipart/mixed; boundary="' + boundary + '"'
         },
         'body': multipartRequestBody});	
    }
        
    request.execute(function(arg) {
    $('#pMessage').html($("#textArea").val());
    $("#textArea").val("");
    $("#localMessageAlert").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You've submitted your personal message to Google Drive successfully.</div>");
    getFileId(fileName);
    console.log(arg);
  });
}
        
function readFile() {
  getFileId(fileName);
        	
  if (fileId != "0") {
        		
    var request = gapi.client.drive.files.get({
      'fileId': fileId
    });
        		  
    request.execute(function(resp) {
      var accessToken = gapi.auth.getToken().access_token;
      var xhr = new XMLHttpRequest();
      xhr.open('GET', resp.downloadUrl);
      xhr.setRequestHeader('Authorization', 'Bearer ' + accessToken);
      xhr.onreadystatechange = function( theProgressEvent ) {
        if (xhr.readyState == 4) {
          if ( xhr.status == 200 ) {
            $('#pMessage').html(xhr.response);
            localStorage.localMessage = xhr.response;    
            $("#localMessageAlert").html("<div class= 'alert alert-success fade in'><a class= 'close' data-dismiss='alert'>x</a>You've read your personal message from Google Drive successfully.</div>");
          }
        }
      }
      xhr.send();
    });
  } 
  else {
    $("#localMessageAlert").html("<div class= 'alert alert-error fade in'><a class= 'close' data-dismiss='alert'>x</a>There was no personal message in Google Drive to read.</div>");
  }
}