/* OBJECT LOAD HTML EX.

var load = {

    data: { action:'load_sob_medida', paged: 1 }

    before: function(){
        //CODE HERE
    }

    success: function(data){
        //CODE HERE
        
        / json example
            var obj = JSON.parse(data);
        /
    }
}

load_ajax( load );

*/

function load_ajax(load){

    $.ajax({

        type:'GET',
        data: load.data,
        dataType:'html',
        url:'/YOUR NAME SITE/wp-admin/admin-ajax.php',

        beforeSend: load.before(),

        success: function(data){ load.success(data) }

    });

}