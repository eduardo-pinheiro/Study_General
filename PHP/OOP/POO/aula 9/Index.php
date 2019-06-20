<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <?php
        require_once "Pessoa.php";
        require_once "Livro.php";

        $p1 = new Pessoa("Gustavo", 23, "Masculino");
        $l1 = new Livro("Parcy Jakson", "Jofred Mayer", 320, 50, true, $p1);

        $l1->detalhes();

        $l1->fechar();

        $l1->avancarPag(); echo "<br>";        
            
        $l1->detalhes();
        ?>
    </body>
</html>