$(function() {

    posBtn("#dayBrightLuxPosbtn", "#dayBrightLux", "#AnalogWithDBL");
    negBtn("#dayBrightLuxNegbtn", "#dayBrightLux", "#AnalogWithDBL");

    posBtn("#nightBrightLuxPosbtn", "#nightBrightLux", "#AnalogWithNBL");
    negBtn("#nightBrightLuxNegbtn", "#nightBrightLux", "#AnalogWithNBL");

    posBtn("#dayBrightFCPosbtn", "#dayBrightFC", "#AnalogWithDBFC");
    negBtn("#dayBrightFCNegbtn", "#dayBrightFC", "#AnalogWithDBFC");

    posBtn("#nightBrightFCPosbtn", "#nightBrightFC", "#AnalogWithNBFC");
    negBtn("#nightBrightFCNegbtn", "#nightBrightFC", "#AnalogWithNBFC");


    posBtn("#DayHumidPosbtn", "#DayhumidIn");
    negBtn("#DayHumidNegbtn", "#DayhumidIn");

    posBtn("#NightHumidPosbtn", "#NighthumidIn");
    negBtn("#NightHumidNegbtn", "#NighthumidIn");

    posBtn("#dayColorTempPosbtn", "#dayColorTemp", "#AnalogWithDCT");
    negBtn("#dayColorTempNegbtn", "#dayColorTemp", "#AnalogWithDCT");

    posBtn("#nightColorTempPosbtn", "#nightColorTemp", "#AnalogWithNCT");
    negBtn("#nightColorTempNegbtn", "#nightColorTemp", "#AnalogWithNCT");


    posBtn("#dayTempPosbtn", "#dayTemp");
    negBtn("#dayTempNegbtn", "#dayTemp");

    posBtn("#nightTempPosbtn", "#nightTemp");
    negBtn("#nightTempNegbtn", "#nightTemp");

    analogToggleCheck("#AnalogWithDBL", "#dayBrightLux");
    analogToggleCheck("#AnalogWithNBL", "#nightBrightLux");
    analogToggleCheck("#AnalogWithDBFC", "#dayBrightFC");
    analogToggleCheck("#AnalogWithNBFC", "#nightBrightFC");

    analogToggleCheck("#AnalogWithDCT", "#dayColorTemp");
    analogToggleCheck("#AnalogWithNCT", "#nightColorTemp");


    $('.timepicker').wickedpicker();

});

