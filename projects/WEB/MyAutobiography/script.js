function TimeDelay(doc) {
	url = doc.href;
	setTimeout('location.href=url', 300);
	doc.href='javascript:void(0)';
}

window.onload =  function () {
	$preloader = $('.loaderArea'),
	  $loader = $preloader.find('.loader');
	 setTimeout("$loader.delay(350).fadeOut();	$preloader.delay(350).fadeOut('slow');", 500);
};

window.onscroll = function() {
	var doc = document.documentElement, body = document.body;
 	var ElStyle = document.getElementById('overlay').style;
 	var introStyle = document.getElementById('intro').style; 	
 	if(doc.scrollTop > 10) {
 		introStyle.opacity = 0.7;
 	   ElStyle.opacity = 0.4;
 	}
 	else {
 		introStyle.opacity = 0;
 		ElStyle.opacity = "";
 	}
};

window.onresize = function() {
	if(document.body.clientWidth < 600) {
		var ImageMap = function (map) {
            var n,
                areas = map.getElementsByTagName('area'),
                len = areas.length,
                coords = [];
            for (n = 0; n < len; n++) {
                coords[n] = areas[n].coords.split(',');
            }
            var n, m, clen;
                for (n = 0; n < len; n++) {
                    clen = coords[n].length;
                    for (m = 0; m < clen; m++) {
                        coords[n][m] *= 0.5;
                    }
                    areas[n].coords = coords[n].join(',');
                }
        },
        imageMap = new ImageMap(document.getElementById('map'));
    	imageMap.resize();
	}
	else {
		var ImageMap = function (map) {
            var n,
                areas = map.getElementsByTagName('area'),
                len = areas.length,
                coords = [];
            for (n = 0; n < len; n++) {
                coords[n] = areas[n].coords.split(',');
            }
            var n, m, clen;
                for (n = 0; n < len; n++) {
                    clen = coords[n].length;
                    for (m = 0; m < clen; m++) {
                        coords[n][m] *= 2;
                    }
                    areas[n].coords = coords[n].join(',');
                }
        },
        imageMap = new ImageMap(document.getElementById('map'));
    	imageMap.resize();
	}
}

function f1() {
	var doc = document.documentElement, body = document.body;
 	var ElStyle = document.getElementById('mapMenu').style;
 	ElStyle.animation = "none";
}

function f2() {
	var doc = document.documentElement, body = document.body;
 	var ElStyle = document.getElementById('mapMenu').style;
 	ElStyle.animation = "";
}