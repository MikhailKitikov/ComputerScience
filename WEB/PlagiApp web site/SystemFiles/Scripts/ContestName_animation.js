var element_contest_name = document.getElementById("contest_name");
var contest_name_array = [' ', 'V', 'K', ' ', 'C', 'u', 'p', ' ', '2', '0', '1', '7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '];
var pointer = 0;
element_contest_name.innerHTML = " VK Cup 2017         ";
var animation_timer = setInterval (
    function contest_name_animation () {
    	if (element_contest_name.innerHTML.length >= 21) {
    		pointer = 0;
    		element_contest_name.innerHTML = "";
    	}
    	else
    		pointer++;
        element_contest_name.innerHTML = element_contest_name.innerHTML + contest_name_array[pointer];
    }, 
    100
);