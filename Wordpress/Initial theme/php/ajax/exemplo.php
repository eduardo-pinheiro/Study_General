<?php

/* EXEMPLO

function load_blog(){

    $paged = ( isset( $_GET['paged'] ) ? $_GET['paged'] : 1);

    $args = array(

        'post_type' => 'post',
        'post_status' => 'publish',
        'orderby' => 'date',
        'order' => 'DESC',
        'posts_per_page' => 5,
        'paged' => $paged,
    );
    $posts = new WP_Query( $args );
?>

    <?php if ( $posts->have_posts() ): while ( $posts->have_posts() ): $posts->the_post(); ?>  
        
        //OUTPUT HERE

    <?php endwhile; endif; ?>

<?php
    wp_die();

}

add_action('wp_ajax_load_blog', 'load_blog');
add_action('wp_ajax_nopriv_load_blog', 'load_blog');

EXEMPLO */
?>