<?php

require_once 'Pessoa.php';

class Aluno extends Pessoa{
    private $matr;
    private $curso;

    //Getters
    public function getMatricula(){
        return $this->matr;
    }
    public function getCurso(){
        return $this->curso;
    }

    //Setters
    public function setMatricula($matr){
        $this->matr = $matr;
    }
    public function setCurso($curso){
        $this->curso = $curso;
    }

    //Actions
    public function cancelarMatricula(){
        echo "Matricula Cancelada";
    }
}