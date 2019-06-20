var scroll_down;
var toggle_scroll = true;
var antes_scroll;
var depois_scroll;


$( window ).scroll( function(){
    
    toggle_scroll ? depois_scroll = $(this).scrollTop() : null;
    antes_scroll = $(this).scrollTop()
    toggle_scroll = !toggle_scroll;
    toggle_scroll ? ( 
        scroll_down = antes_scroll > depois_scroll ? true : false 
    ) : null;

    if(scroll_down){
        
        //Code here

    }else{

        //Code here

    }

});