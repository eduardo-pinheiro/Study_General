<<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php
        require_once 'Caneta.php';
        
        $c1 = new Caneta("BIC","Azul",0.5);
        $c2 = new Caneta("Pentel","Vermelha",1.5);

        //echo "Eu tenho uma caneta {$c1->getModelo()} de ponta {$c1->getPonta()}";
        print_r($c1);
        print_r($c2);
        ?>
        </pre>
    </body>
</html>