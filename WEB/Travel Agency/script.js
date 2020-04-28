window.onload =  function () {
    var doc = document.documentElement, body = document.body;
    var ElStyle = document.getElementById('hidden_menu').style;
    ElStyle.transform = "translateX(20%)";
};

function f1() {
    var doc = document.documentElement, body = document.body;
    var ElStyle = document.getElementById('hidden_menu').style;
    ElStyle.transform = "";
}

function f2() {
    var doc = document.documentElement, body = document.body;
    var ElStyle = document.getElementById('hidden_menu').style;
    ElStyle.transform = "translateX(20%)";
}

function f3() {
    var doc = document.documentElement, body = document.body;
    alert("Ваша заявка принята! \n С Вами свяжутся в течении 24 часов.");
}