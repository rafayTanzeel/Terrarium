var socket = io.connect();

$(function() {

    var chartTemp = MorrisBarCharGen("status_temp", 'Temperature', 26, "#B21516");
    var chartHumidity = MorrisBarCharGen("status_humidity", 'Humidity', 40, "#2196f3");
    var Humidity=0;
    var Temperature=0;

    var asyncCallback = function (chart, DataName, newData) {
        var ret = [];
        ret.push({
            y: DataName, x: newData
        });
        chart.setData(ret); // this will redraw the chart
    };

    setInterval(function () {
        asyncCallback(chartTemp, 'Temperature', Humidity);
    }, 10000);
    setInterval(function () {
        asyncCallback(chartHumidity, 'Humidity', Temperature);
    }, 10000);


    socket.on('commandReply', function(result) {
        var array = result.split(',');
        Humidity=array[0];
        Temperature=array[1];
    });

    setInterval(function(){ sendMsgCommand("get_env_status"); }, 10000);



});

function MorrisBarCharGen(idVal, xVal, yVal, color) {
    return Morris.Bar({
        element: idVal,
        data: [
            {y: xVal, x: yVal}
        ],
        xkey: 'y',
        ykeys: 'x',
        labels: xVal,
        resize: true,
        barColors: [color]
    });
}
