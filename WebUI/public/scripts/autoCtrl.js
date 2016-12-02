$(function() {

    posBtn("#colorTempPosbtn", "#colorTemp", "#AnalogWithCT");
    negBtn("#colorTempNegbtn", "#colorTemp", "#AnalogWithCT");

    posBtn("#colorBrightLuxPosbtn", "#colorBrightLux", "#AnalogWithCBL");
    negBtn("#colorBrightLuxNegbtn", "#colorBrightLux", "#AnalogWithCBL");

    posBtn("#colorBrightFootcandlesPosbtn", "#colorBrightFootcandles", "#AnalogWithCBFC");
    negBtn("#colorBrightFootcandlesNegbtn", "#colorBrightFootcandles", "#AnalogWithCBFC");


    posBtn("#HumidPosbtn", "#humidIn");
    negBtn("#HumidNegbtn", "#humidIn");

    posBtn("#autoTempPosbtn", "#AutoTemp");
    negBtn("#autoTempNegbtn", "#AutoTemp");

    posBtn("#wetAlarmThreshPosbtn", "#wetAlarmThresh");
    negBtn("#wetAlarmThreshNegbtn", "#wetAlarmThresh");

    analogToggleCheck("#AnalogWithCBFC", "#colorBrightFootcandles");
    analogToggleCheck("#AnalogWithCBL", "#colorBrightLux");
    analogToggleCheck("#AnalogWithCT", "#colorTemp");



});

