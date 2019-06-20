<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php
        require_once 'Lutador.php';
        require_once 'Luta.php';
        
        $l1 = new Lutador("Lucas", "Brasil", "18", "1.69", "60", 0, 0, 0);
        $l2 = new Lutador("Douglas", "Brasil", "25", "1.78", "60", 0, 0, 0);
        $luta = new luta();

        $luta->marcarLuta($l1,$l2);
        $luta->lutar();
        ?>
        </pre>
    </body>
</html>