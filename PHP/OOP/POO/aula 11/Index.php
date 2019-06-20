<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php

        require_once 'Bolsista.php';
        require_once 'Aluno.php';
        require_once 'Visitante.php';

        $p1 = new Aluno('Aluno',10,'Masculino');
        $p2 = new Visitante('Visitante',20,'Masculino');
        $p3 = new Bolsista('Bolsista',30,'Masculino');


        $p1->setMatricula(1000);
        $p1->setCurso('Inglês');

        $p3->setMatricula(1000);
        $p3->setBolsa(25);
        $p3->setCurso('Inglês');

        $p2->fazerAniv();

        print_r($p2);
        print_r($p1);        
        print_r($p3);

        $p1->pagarMensalidade();
        $p3->pagarMensalidade();
        ?>
        </pre>
    </body>
</html>