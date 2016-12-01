"use strict";
// Client-side interactions with the browser.

// Make connection to server when web page is fully loaded.
var socket = io.connect();
$(document).ready(function() {

	$('#btnCount').click(function(){
		sendMsgCommand("count");
	});
	$('#btnFirst').click(function(){
		sendMsgCommand("first 5");
	});
	$('#btnLast').click(function(){
		sendMsgCommand("last 5");
	});
	$('#btnStop').click(function(){
		sendMsgCommand("stop");
	});
	
	socket.on('commandReply', function(result) {
		var newDiv = $('<div></div>').text(result);
		$('#messages').append(newDiv);
		$('#messages').scrollTop($('#messages').prop('scrollHeight'));
	});
	
});

function sendMsgCommand(message) {
	socket.emit('msg', message);
};
