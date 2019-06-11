function Convert (arr) {
	var result = String(arr[0]) + ':';
	for (var i = 1; i <= 2; i++){
		if (arr[i] >= 10)
			result = result + String(arr[i]);
		else
			result = result + '0' + String(arr[i]);
		if(i == 1)
			result = result + ':';
	}
	return result;
}
var current_time = [5, 0, 0];
var element_timer = document.getElementById("time");
element_timer.innerHTML = Convert(current_time);
var time_left = setInterval (
	function Update_time ()
	{
		if (current_time[2] == 0)
		{
			if (current_time[1] == 0)
			{
				if (current_time[0] == 0)
				{
					element_timer.innerHTML = "Time is over";
					return;
				}
				else
					current_time[0]--;
				current_time[1] = 59;
			}
			else
				current_time[1]--;
			current_time[2] = 59;
		}
		else
			current_time[2]--;
		element_timer.innerHTML = Convert(current_time);
	}, 
	1000
);