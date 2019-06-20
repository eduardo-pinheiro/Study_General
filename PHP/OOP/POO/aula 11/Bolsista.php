<?php

require_once 'Aluno.php';

class Bolsista extends Aluno{
    private $bolsa;
    
    //Getters
    public function getBolsa(){
        return $this->bolsa;
    }

    //Setters
    public function setBolsa($bolsa){
        $this->bolsa = $bolsa;
    }
        
    //Actions
    public function renovarBolsa(){
        echo "<br><br>Bolsa renovada com sucesso!";
    }
    public function pagarMensalidade(){
        $valor = ($this->getMatricula() - ( ( $this->getMatricula() * $this->getBolsa() ) / 100 ) );
        echo "<br><br>Matricula paga no valor de R$ {$valor}";
    }           
}