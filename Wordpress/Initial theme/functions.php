<?php

// Carrega CSS no head
function load_css_js() {
    wp_enqueue_style( 'style', get_stylesheet_uri() );
    //wp_enqueue_script( 'plugins', get_template_directory_uri() . '/js/plugins.js', array (), null);
    //wp_enqueue_script( 'main', get_template_directory_uri() . '/js/main.js', array (), null);    
}
add_action( 'wp_enqueue_scripts', 'load_css_js' );

//Limpa o head
require('php/limpa_head_wp.php');

//Remove notificação de atalização
require('php/remove_notificacao.php');

//Adiciona opção de duplicar posts
require('php/duplicate_post.php');

//Adiciona Custon Post Type's & Custon Taxonomies
require('php/custon_post_types.php');

//Altera configuração dos Post Type's nativos
require('php/edit_post_type.php');  

/*AJAX*/
    //Exemplo
    require('php/ajax/exemplo.php');
?>