var socket = io.connect();

$(function () {
        //Init Main Page
        init();

        //$(".nav>li>ul>li a, .navbar-brand").click(function () {
        //
        //    //var navItem = $(this).attr('alt');
        //    //if (navItem != "home") {
        //    //    navItem = navItem.split('_')[0] + '/' + navItem;
        //    //}
        //    //
        //    //$("article").fadeOut("fast", function () {
        //    //    $.get(navItem + ".html", function (data) {
        //    //        $("article").replaceWith(data);
        //    //    });
        //    //    $('article').fadeIn("fast");
        //    //});
        //    //
        //    //displayNav();
        //});

        $(window).resize(function () {
            displayNav();
        });


	//socket.on('commandReply', function(result) {

	//var array = $('#searchKeywords').val().split(",");
   //     console.log(result);
  //  });


    }
);


function init() {
    //$(function(){
    //    $('article').load( 'home.html' );
    //});
    //$.get("home.html", function (data) {
    //    alert($(this));
    //    $("article").replaceWith(data)
    //});
    displayNav();
}


function animCollapse(ele) {
    ele.classList.toggle("change");
}

/* Set the width of the side navigation to 250px */
function openNav() {
    $('.sidenav').attr("id", "Sidenav").css("width", "250px");
    $("#main").css("margin-left", "250px");
}


function closeNav() {
    $(".sidenav").removeAttr('id').css("width", "100%");
    $("#main").css("margin-left", "0px");
}

function displayNav() {
    if ($(".icon-bar").is(":visible")) {
        closeNav();
    }
    else {
        openNav();
    }
}


function negBtn(idBtn, inputField){
    $(idBtn).on("click", function(){
        var btnVal=$(inputField).val();
        $(inputField).val(parseInt(btnVal)-5);
	var res=inputField.substring(1, inputField.length)
        sendMsgCommand(res+' '+$(inputField).val());
    });
}


function posBtn(idBtn, inputField){
    $(idBtn).on("click", function(){
        var btnVal=$(inputField).val();
        $(inputField).val(parseInt(btnVal)+5);
	var res=inputField.substring(1, inputField.length)
        sendMsgCommand(res+' '+$(inputField).val());
        
    });
}


function analogToggleCheck(inputField) {
    $(inputField).on("click", function () {
            var res = inputField.substring(1, inputField.length)
            if ($(inputField).is(':checked')) {
                sendMsgCommand(res + ' checked');
            }
            else {
                sendMsgCommand(res + ' unchecked');
            }
        }
    );
}

function rgbDataSend(r,g,b){
	socket.emit('msg', "rgb "+r+','+g+','+b);
}



function sendMsgCommand(message) {
    socket.emit('msg', message);
};







