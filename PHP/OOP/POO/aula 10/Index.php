<!DOCTYPE html>
<html>
    <head>
        <title>Page Title</title>
    </head>
    <body>
        <pre>
        <?php

        require_once 'Pessoa.php';
        require_once 'Aluno.php';
        require_once 'Professor.php';

        $p1 = new Aluno('Eduardo',20,'Masculino');
        $p2 = new Professor('Patrícia',40,'Feminino');

        $p1->setMatricula(31538);
        $p1->setCurso('Inglês');

        $p2->setEspecialidade('Inglês');
        $p2->setSalario(2500);

        print_r($p1);
        print_r($p2);

        $p2->receberAumento(1);

        print_r($p2);
        ?>
        </pre>
    </body>
</html>