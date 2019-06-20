
<!-- PULEI ESSA AULA !-->
<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php
        require_once 'Caneta.php';
        
        $c1 = new Caneta("BIC","Azul",0.5);

        print_r($c1);
        ?>
        </pre>
    </body>
</html>