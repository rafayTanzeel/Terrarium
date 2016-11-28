// Morris.js Charts sample data for SB Admin template

$(function() {

    Morris.Bar({
        element: 'morris-humidity-chart',
        data: [{
            device: 'Humidity',
            humidity: 120
        }],
        xkey: 'device',
        ykeys: ['humidity'],
        labels: ['Humidity'],
        barRatio: 0.4,
        xLabelAngle: 0,
        hideHover: 'auto',
        resize: true,
        barColors: ["#1f3aff"]
    });

    Morris.Bar({

        element: 'morris-temperature-chart',
        data: [{
            device: 'Temperature',
            temperature: 136
        }],
        xkey: 'device',
        ykeys: ['temperature'],
        labels: ['Temperature'],
        barRatio: 0.4,
        xLabelAngle: 0,
        hideHover: 'auto',
        resize: true,
        barColors: ["#ff534f"]
    });


});
