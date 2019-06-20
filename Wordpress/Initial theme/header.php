<!DOCTYPE html>

<html lang="pt-br">
<head>

    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">    
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">    
    <meta name="theme-color" content="black">

    <meta name="theme-color" content="red">
    <meta name="msapplication-navbutton-color" content="red">
    <meta name="apple-mobile-web-app-capable" content="yes">
    <meta name="apple-mobile-web-app-status-bar-style" content="black">

    <title><?php echo get_bloginfo('name') ?> | <?php the_title(); ?></title>   
    <meta property="og:site_name" content="<?php echo get_bloginfo('name') ?>">
    <meta name="og:title" property="og:title" content="<?php the_title() ?>">
    <meta property="og:locale" content="pt_BR">

    <meta name="description" content="<?php the_field('seo_description') ?>">
    <meta property="og:description" content="<?php the_field('seo_description') ?>">
    <meta property="og:image" content="<?php the_field('seo_image') ?>">    

    <?php if( get_post_type() == 'post' ): ?>

        <meta property="og:type" content="article">
        <meta property="article:author" content="Author name here">
        <meta property="article:published_time" content="<?php echo get_the_date('Y-m-d') ?>">
        <meta property="article:section" content="AGUARDAR TAXONOMY | TAXONOMY NAME HERE">
        <meta property="article:tag" content="AGUARDAR TAXONOMY | TAG NAMES HERE">
        
    <?php else: ?>

        <meta property="og:type" content="website">

    <?php endif; ?>

    <?php wp_head(); ?>
</head>
<body> 
    <div class="loading-animation">
    
    </div>
    <script type="text/javascript">

        //Trava o scroll da página
        document.documentElement.style.overflow = 'hidden';

        //Pega o tempo estimado de carregamento da página e converte para a unidade de medida de tempo do javascript
        var perfData = window.performance.timing,
        EstimatedTime = -(perfData.loadEventEnd - perfData.navigationStart),
        time = parseInt((EstimatedTime/1000)%60)*100;
        
        /** CODE "loading-animation" HERE */

        //Executa a primeira animação logo após tempo de carregamento estimado da página
        setTimeout(function(){    
            try {
                first_animation();
            }catch (e) {
                console.log('first_animation() ainda não foi carregado');
            }
            
        }, time);
        
    </script>   
    <header>  

    </header>