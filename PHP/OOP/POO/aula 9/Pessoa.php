<?php

class Pessoa{
    private $nome;
    private $idade;
    private $sexo;

    //Construct
    public function __construct($nome, $idade, $sexo){
        $this->nome = $nome;
        $this->sexo = $sexo;
        $this->idade = $idade;
    }

    //Getters
    public function getNome(){
        return $this->nome;
    }
    public function getIdade(){
        return $this->idade;
    }
    public function getSexo(){
        return $this->sexo;
    }

    //Setters
    public function setNome($nome){
        $this->nome = $nome;
    }
    public function setIdade($idade){
        $this->idade = $idade;
    }
    public function setSexo($sexo){
        $this->sexo = $sexo;
    }

    //Actions
    public function fazerAniversario(){
        $this->idade += 1;
    }
}