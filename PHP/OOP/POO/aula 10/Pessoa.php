<?php

class Pessoa{
    private $nome;
    private $idade;
    private $sexo;

    //Construct
    public function __construct($nome, $idade, $sexo){
        $this->nome = $nome;
        $this->idade = $idade;
        $this->sexo = $sexo;
    }

    //Getters
    public function getNome(){
        return $this->nome;
    }
    public function getIdade(){
        return $this->idade;
    }
    public function getSexo(){
        return $this->Sexo;
    }

    //Setters
    public function setNome($nome){
        $this->nome = $nome;
    }
    public function setIdade($idade){
        $this->idade = $idade;
    }
    public function setSexo($Sexo){
        $this->Sexo = $Sexo;
    }

    //Actions
    public function fazerAniv(){
        $this->idade ++;
    }
}