<?php

// Funções para limpar o Header
remove_action('wp_head','rsd_link');
remove_action('wp_head', 'index_rel_link'); 
remove_action('wp_head','wlwmanifest_link');
remove_action('wp_head','start_post_rel_link', 10, 0 );
remove_action('wp_head', 'wp_shortlink_wp_head', 10, 0);
remove_action('wp_head','adjacent_posts_rel_link_wp_head', 10, 0);
remove_action('wp_head','parent_post_rel_link', 10, 0 );
remove_action('wp_head','feed_links_extra', 3);
remove_action('wp_head', 'feed_links', 2 ); 
remove_action('wp_head','wp_generator');
remove_action('wp_head','wp_alternate');
remove_action('wp_head', 'wp_resource_hints', 2);
remove_action('wp_head','print_emoji_detection_script', 7);
remove_action('admin_print_scripts','print_emoji_detection_script');
remove_action('wp_print_styles','print_emoji_styles');
remove_action('admin_print_styles','print_emoji_styles');
remove_action( 'wp_head','rest_output_link_wp_head');
remove_action( 'wp_head','wp_oembed_add_discovery_links');
remove_action('wp_head', 'adjacent_posts_rel_link', 10, 0);
remove_action('template_redirect', 'wp_shortlink_header', 11);  
remove_filter( 'the_content_feed', 'wp_staticize_emoji' );
remove_filter( 'comment_text_rss', 'wp_staticize_emoji' );  
remove_filter( 'wp_mail', 'wp_staticize_emoji_for_email' );
add_filter( 'woocommerce_enqueue_styles', '__return_empty_array' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_title' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_price' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_excerpt' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_add_to_cart' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_meta' );
remove_action( 'woocommerce_single_product_summary', 'woocommerce_template_single_sharing' );
if (!is_admin()) add_action("wp_enqueue_scripts", "my_jquery_enqueue", 11);
function my_jquery_enqueue() {
   wp_deregister_script('jquery');
   wp_enqueue_script('jquery');
}
function removeinline_adminbar_css_frontend() {
    if ( has_filter( 'wp_head', '_admin_bar_bump_cb' ) ){
        remove_filter( 'wp_head', '_admin_bar_bump_cb' );
    }
}
add_filter( 'wp_head', 'removeinline_adminbar_css_frontend', 1 );

?>