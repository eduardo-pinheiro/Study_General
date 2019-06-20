<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php
        require_once 'Lobo.php';
        require_once 'Cachorro.php';

        $lobo = new Lobo(10, 10, 4);       
        $cachorro = new Cachorro(20, 20, 4);       

        print_r($lobo);
        print_r($cachorro);

        $lobo->emitirSom();
        $cachorro->emitirSom();        
        ?>
        </pre>
    </body>
</html>