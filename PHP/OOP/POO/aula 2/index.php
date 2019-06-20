<<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <?php
        require_once 'Caneta.php';
        $c1 = new Caneta;
        $c1->cor = 'azul';
        $c1->ponta = 0.5;
        $c1->tampada = true;

        $c1->destampar();
        //$c1->rabiscar();

        $c2 = new Caneta;
        $c2->cor="verde";
        $c2->tampada=true;
        print_r($c2);
        ?>
    </body>
</html>