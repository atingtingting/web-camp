window.onload = function() {
    window.onscroll = function() {
        var H = document.documentElement.scrollTop;
        var nav = document.getElementById("land-nav");
        var text = document.getElementById("ln-text");
        var text2 = document.getElementById("ln-text-2")
        if( H > 560 ) {
            nav.style = "position:fixed;top:0;";
            text.style = "display:none;";
            text2.style = "display:inline-block;";
        } else {
            nav.style = "";
            text.style = "display:inline-block;";
            text2.style = "display:none;";
        }
    }

}
email.onchange = function(){
        var text = document.getElementById("warn1");
        var email = this.value;
        var e = document.getElementById("email");
        var reg = /^([a-zA-Z]|[0-9])(\w|\-)+@[a-zA-Z0-9]+\.([a-zA-Z]{2,4})$/;
        if(email === ""){
            text.innerHTML = "Do not be empty.";
            text.style.color = "#d91f12";
            e.style.border = "1px solid #d91f12";
        }else if(reg.test(email)){
            text.innerHTML = "Alright.";
            text.style.color = "#5d4732";
            e.style.border = "1px solid transparent";
        }else{
            text.innerHTML = "Please input the correct email address.";
            text.style.color = "#d91f12";
            e.style.border = "1px solid #d91f12";
        }
    }
password.onchange = function(){
    var text = document.getElementById("warn2");
    var password = this.value;
    var p = document.getElementById("password");
    if(password === ""){
        text.innerHTML = "Do not be empty.";
        text.style.color = "#d91f12";
        p.style.border = "1px solid #d91f12";
    }else{
        text.innerHTML = "Alright.";
        text.style.color = "#5d4732";
        e.style.border = "1px solid transparent";
    }
}