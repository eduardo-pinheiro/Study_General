<?php

abstract class Mamifero{
    private $peso;
    private $idade;
    private $membro;

    //Construct
    public function __construct($peso, $idade, $membro)
    {
        $this->peso = $peso;
        $this->idade = $idade;
        $this->membro = $membro;
    }

    //Setters
    public function setPeso($peso){
        $this->peso = $peso;
    }
    public function setIdade($idade){
        $this->idade = $idade;
    }
    public function setMembro($membro){
        $this->membro = $membro;
    }

    //Getters
    public function getPeso(){
        return $this->peso;
    }
    public function getIdade(){
        return $this->idade;
    }
    public function getMembro(){
        return $this->membro;
    }
    
    //Actions
    public abstract function emitirSom();
}