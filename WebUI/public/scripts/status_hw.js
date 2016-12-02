var socket = io.connect();

$(function() {

    var exhaustFan=0;
    var intakeFan=0;
    var fogger=0;
    var cooler=0;
    var wetness=0;


    socket.on('commandReply', function(result) {
        var array = result.split(',');
        exhaustFan=array[0];
        intakeFan=array[1];
        fogger=array[2];
        cooler=array[3];
        wetness=array[4];
        circlulationFan=array[5];


        $("#intake").text(intakeFan);
        $("#exhaust").text(exhaustFan);
        $("#wet").text(wetness);
		$("#circlulationFan").text(circlulationFan);

        if(parseInt(fogger)==1) {
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

    setInterval(function(){ sendMsgCommand("get_hw_status"); }, 5000);

});
