var socket = io.connect();

$(function() {

    var colorTemp=0;
    var brightLux=0;
    var brightFC=0;
    var AnalogLedBright=0;
    var r=0;
    var g=0;
    var b=0;

    socket.on('commandReply', function(result) {
        array = result.split(',');
        colorTemp=array[0];
        brightLux=array[1];
        brightFC=array[2];
        AnalogLedBright=array[11];
        r=parseInt(array[12]);
        g=parseInt(array[13]);
        b=parseInt(array[14]);

        $("#ctemp").text(colorTemp);
        $("#fcolor").text(brightFC);
        $("#blux").text(brightLux);
        $("#ALedBright").text(AnalogLedBright);

        $("#colorStatus").val(rgbToHex(r,g,b));
        $("#RcolorStatus").val(r);
        $("#GcolorStatus").val(g);
        $("#BcolorStatus").val(b);

    });

    setInterval(function(){ sendMsgCommand("get status"); }, 1500);

});



function componentToHex(c) {
    var hex = c.toString(16);
    return hex.length == 1 ? "0" + hex : hex;
}

function rgbToHex(r, g, b) {
    return "#" + componentToHex(r) + componentToHex(g) + componentToHex(b);
}
