<?php

require_once 'Pessoa.php';

class Professor extends Pessoa{
    
    private $especialidade;
    private $salario;

    //Getters
    public function getEspecialidade(){
        return $this->$especialidade;
    }
    public function getSalario(){
        return $this->$salario;
    }

    //Setters
    public function setEspecialidade($especialidade){
        $this->especialidade = $especialidade;
    }
    public function setSalario($salario){
        $this->salario = $salario;
    }

    //Actions
    public function receberAumento($aumento){
        $this->salario += $aumento;
    }
}