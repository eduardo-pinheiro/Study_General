<?php 

/* EXEMPLO

//Edita Blocos do content para os Posts
function my_gutenberg_blocks() {
    return array(
        'core/paragraph',
        'core/gallery',
        'core/cover',
        'core/video',
    );
}
add_filter( 'allowed_block_types', 'my_gutenberg_blocks' );


//Desabilita Gutenberg nas páginas
function disable_gutenberg_in_page($is_enabled, $post_type) {
    if ($post_type === 'page') return false;    
    return $is_enabled;    
}
add_filter('use_block_editor_for_post_type', 'disable_gutenberg_in_page', 10, 2);

//Remove Comentarios
function remove_comment() {
	remove_menu_page( 'edit-comments.php' );
}
add_action( 'admin_menu', 'remove_comment' );

//Edita "Páginas"
function edit_page($args, $post_type){
    if ($post_type == 'page'){        
        $args['capabilities']['delete_others_posts'] = false;
        $args['capabilities']['create_posts'] = false;
    }        
    return $args;
}
add_filter('register_post_type_args', 'edit_page', 10, 2);

//Remove Taxonomias Categoria & Tag
function remove_category() {
    $args = array(
        'public'       => false,
    );
     
    register_taxonomy( 'category', $args );
    register_taxonomy( 'post_tag', $args );
}
add_action( 'init', 'remove_category', 0 );

EXEMPLO */
?>