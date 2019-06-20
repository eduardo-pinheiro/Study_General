<?php 

/* EXEMPLO

    function create_locais_post() {

        register_post_type( 'locais',
        
            array(

                'labels' => array(

                    'name' => 'Locais',
                    'singular_name' => 'Local'

                ),
                
                'public' => false,  
                'publicly_queryable' => true,
                'show_ui' => true,  
                'has_archive' => false,
                'taxonomies' => array('tipos'),
                'supports' => array('title')
                
            )

        );    

    }
    add_action('init', 'create_locais_post');


    function create_tipo_de_local(){    

        register_taxonomy('tipos', array('locais'), 
        
            array(

                'labels' => array(

                    'name' => 'Tipos',
                    'singular_name' => 'Tipo',
                    'menu_name' => 'Todos os tipos' 

                ),

                'hierarchical' => true,
                'public' => false,  
                'publicly_queryable' => true,
                'query_var' => true,            
                'has_archive' => false,

                'show_ui' => true,  
                'show_admin_column' => true,
                'show_in_menu' => false,            

                'capabilities' => array(
                    'manage_terms' => false,
                    'edit_terms' => false,
                    'delete_terms' => false,
                    'assign_terms' => true
                )

            )
        );

    }
    add_action('init', 'create_tipo_de_local');

EXEMPLO */
?>