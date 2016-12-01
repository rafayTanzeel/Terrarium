var socket = io.connect();

$(function() {

    var exhaustFan=0;
    var intakeFan=0;
    var fogger=0;
    var cooler=0;
    var wetness=0;


    socket.on('commandReply', function(result) {
        var array = result.split(',');
        exhaustFan=array[6];
        intakeFan=array[5];
        fogger=array[8];
        cooler=array[9];
        wetness=array[10];


        $("#intake").text(intakeFan);
        $("#exhaust").text(exhaustFan);
        $("#wet").text(wetness);

        if(parseInt(fogger)==1) {
		console.log(parseInt(fogger));
            $("#foggerStat").attr('checked', 'checked');
        }else if(parseInt(fogger)==0){
		
            $("#foggerStat").removeAttr('checked');
        }
	
	
        if(parseInt(cooler)==1) {
            $("#coolerStat").attr('checked', 'checked');
        }else if(parseInt(fogger)==0){
            $("#coolerStat").removeAttr('checked');
        }


    });

    setInterval(function(){ sendMsgCommand("get status"); }, 1500);

});
