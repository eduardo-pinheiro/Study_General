"use strict";function load_ajax(t){$.ajax({type:"GET",data:t.data,dataType:"html",url:"/YOUR_SITE_NAME/wp-admin/admin-ajax.php",beforeSend:t.before(),success:t.success(data)()})}function first_animation(){timing=1e3,setTimeout(function(){document.documentElement.style.overflow="auto",regular_animation_start()},timing+300)}function regular_animation_start(){function i(t){var a=[],e=t.find(".anime"),n=1e3*e.css("transition").replace("all ","").replace("s ease 0s","");n*=.5,timing=n,e.each(function(){a.push($(this))}),a=bubbleSortByAttr(a,"attr","data-anime-order");for(var i=0;i<a.length;i++){var o=a[i].attr("data-anime-order");if((null!=a[i+1]?a[i+1].attr("data-anime-order"):null)==o&&i++,1==o)for(var r=0;r<a.length;r++)a[r].attr("data-anime-order")==o&&a[r].removeAttr("data-anime-type");else{for(r=0;r<a.length;r++)a[r].attr("data-anime-order")==o&&m(a[r],timing);timing+=n}}t.removeClass("anime-start"),setTimeout(function(){e.removeClass("anime"),e.removeAttr("data-anime-order")},n*(1+n))}function m(t,a){setTimeout(function(){t.removeAttr("data-anime-type")},a)}$(document).ready(function(){for(var t=$(window).height()+$(window).scrollTop(),a=$(".anime-start").length,e=0;e<a;e++){var n=$(".anime-start").eq(0);n.offset().top+n.height()/3<t&&i(n)}}),0!=$(".anime-start").length&&$(window).scroll(function(){if(0!=$(".anime-start").length){var t=$(window).height()+$(window).scrollTop(),a=$(".anime-start").eq(0);a.offset().top+a.height()/3<t&&i(a)}})}$(document).ready(function(){0==cont&&first_animation()}),window.onload=function(){0==cont&&first_animation()},$("a").click(function(t){$(this).attr("target")});