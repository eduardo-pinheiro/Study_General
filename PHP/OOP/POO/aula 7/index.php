<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php
        require_once 'Lutador.php';
        
        $l1 = new Lutador("Lucas Macedo", "Brasil", "25", "1.78", "60", 0, 0, 0);

        $l1->apresentar();
        echo("<br><br>");
        $l1->status();

        echo("<br><br> Ganhou!");
        $l1->ganharLuta();
        echo("<br>");
        $l1->status();

        echo("<br><br> Perdeu!");
        $l1->perderLuta();
        echo("<br>");
        $l1->status();

        echo("<br><br> Empatou!");
        $l1->empatarLuta();
        echo("<br>");
        $l1->status();       


        //var_dump($l1);
        ?>
        </pre>
    </body>
</html>