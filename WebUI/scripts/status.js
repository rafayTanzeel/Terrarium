$(function() {
    var chartTemp = MorrisBarCharGen("status_temp", 'Temperature', 26, "#B21516");
    var chartHumidity = MorrisBarCharGen("status_humidity", 'Humidity', 40, "#2196f3");

    var asyncCallback = function (chart, DataName, newData) {
        var ret = [];
        ret.push({
            y: DataName, x: newData
        });
        chart.setData(ret); // this will redraw the chart
    };

    setInterval(function () {
        asyncCallback(chartTemp, 'Temperature', Math.floor((Math.random() * 100) + 1));
    }, 300);
    setInterval(function () {
        asyncCallback(chartHumidity, 'Humidity', Math.floor((Math.random() * 100) + 1));
    }, 300);
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