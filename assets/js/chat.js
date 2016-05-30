function unix_ts_to_string(unix_timestamp) {
	var date = new Date(unix_timestamp*1000);
	var hours = date.getHours();
	var minutes = "0" + date.getMinutes();
	var seconds = "0" + date.getSeconds();
	var formatted = hours + ':' + minutes.substr(-2) + ':' + seconds.substr(-2);

	return formatted;
}

function insert_chat_entry(sender, text, timestamp) {
	var div_text = "<div><span title=\"";
	div_text+= unix_ts_to_string(timestamp) + "\"" + "style='color: blue;'>" + sender + ": " + "</span>";
	div_text += "<span>" + text + "</span></div>";
    $("#chatbox").append(div_text);
    $("#chatbox").scrollTop($("#chatbox")[0].scrollHeight);
}


var last = 0;

function process_chat_response(response) {
    var answer = JSON.parse(response);
	var len = answer.length - 1;
	var last_message = answer[len];
	if(last_message[0] == last)
		return;
	console.log(last_message[0]);
	for(var idx = 0; idx < answer.length; ++idx) {
		insert_chat_entry(answer[idx][2], answer[idx][3], answer[idx][1]);
	}
	last = last_message[0];
}

function send(sender, text) {
	data = { "sender": sender , "message": text};
	$.post("chat/insert_message", JSON.stringify(data), process_chat_response);
}


function get_all_messages() {
	$.get("chat/get_all_messages", process_chat_response);
}

function load_last_messages(){
	var url = "chat/get_messages_after/" + last;
    $.get(url, process_chat_response);

    setTimeout(load_last_messages, 500);
}

function send_chat_message() {
	var sender = $("#username").val();
	var text = $("#usermsg").val();
	send(sender, text);
}

window.onload = function(){
	get_all_messages();
	load_last_messages();
};