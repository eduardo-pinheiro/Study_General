<?php

//Plugins
remove_action('load-update-core.php','wp_update_plugins');
add_filter('pre_site_transient_update_plugins','__return_null');

//Core
add_action('after_setup_theme','remove_core_updates');
    function remove_core_updates(){
    if(! current_user_can('update_core')){return;}
    add_action('init', create_function('$a',"remove_action( 'init', 'wp_version_check' );"),2);
    add_filter('pre_option_update_core','__return_null');
    add_filter('pre_site_transient_update_core','__return_null');
}

//Notificações
function remove_updates_notification(){
    global $wp_version;return(object) array('last_checked'=> time(),'version_checked'=> $wp_version,);
}
add_filter('pre_site_transient_update_core','remove_updates_notification');
add_filter('pre_site_transient_update_plugins','remove_updates_notification');
add_filter('pre_site_transient_update_themes','remove_updates_notification');  

?>