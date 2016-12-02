$(function() {

    $(".marker").on("mouseup", function() {
        var hex=hexToRgb($("#color").val());
        var r=hex.r;
        var g=hex.g;
        var b=hex.b;

        $("#Rcolor").val(r).css('background-color',"rgb("+r+",0,0)");
        $("#Gcolor").val(g).css('background-color',"rgb(0,"+g+",0)");
        $("#Bcolor").val(b).css('background-color',"rgb(0,0,"+b+")");

	rgbDataSend(r,g,b);

    });

        posBtn("#brightpos", "#manualbright");
        negBtn("#brightneg", "#manualbright");


	analogToggleSingleCheck("#intakeFan");
    analogToggleSingleCheck("#exhaustFan");
    analogToggleSingleCheck("#circulationFan");
    analogToggleSingleCheck("#fogger");
    analogToggleSingleCheck("#cooler");


}
);



function hexToRgb(hex) {
    // Expand shorthand form (e.g. "03F") to full form (e.g. "0033FF")
    var shorthandRegex = /^#?([a-f\d])([a-f\d])([a-f\d])$/i;
    hex = hex.replace(shorthandRegex, function(m, r, g, b) {
        return r + r + g + g + b + b;
    });

    var result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
    return result ? {
        r: parseInt(result[1], 16),
        g: parseInt(result[2], 16),
        b: parseInt(result[3], 16)
    } : null;
}
