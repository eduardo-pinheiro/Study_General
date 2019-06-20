<?php

class Lutador {
    
    //atributos
    private $nome;
    private $nacionalidade;
    private $idade;
    private $altura;
    private $peso;
    private $categoria;
    private $vitorias;
    private $derrotas;
    private $empates;

    //Construtor
    function __construct($nome, $nacionalidade, $idade, $altura, $peso, $vitorias, $derrotas, $empates){
        $this->nome = $nome;
        $this->nacionalidade = $nacionalidade;
        $this->idade = $idade;
        $this->altura = $altura;
        $this->peso = $peso;
        $this->vitorias = $vitorias;
        $this->derrotas = $derrotas;
        $this->empates = $empates;
    }

    //Getters
    public function getNome(){
        return $this->nome;
    }
    public function getNacionalidade(){
        return $this->nacionalidade;
    }
    public function getIdade(){
        return $this->idade;
    }
    public function getAltura(){
        return $this->altura;
    }
    public function getPeso(){
        return $this->peso;
    }
    public function getCategoria(){
        return $this->categoria;
    }
    public function getVitorias(){
        return $this->vitorias;
    }
    public function getDerrotas(){
        return $this->derrotas;
    }
    public function getEmpates(){
        return $this->empates;
    }


    //Setters
    function setNome($value){
        $this->nome = $value;
    }
    public function setNacionalidade($value){
        $this->nacionalidade = $value;
    }
    public function setIdade($value){
        $this->idade = $value;
    }
    public function setAltura($value){
        $this->altura = $value;
    }
    public function setPeso($value){
        $this->peso = $value;
        
        if ($value < 53){
            $this->setCategoria("Invalido");
        }else if( $value >= 53 ){
            $this->setCategoria("Leve");
        }else if( $value >= 70 ){
            $this->setCategoria("Medio");
        }else if( $value >= 95 ){
            $this->setCategoria("Pesado");
        }else{
            $this->setCategoria("Invalido");
        }
    }
    private function setCategoria($value){
        $this->categoria = $value;
    }
    public function setVitorias($value){
        $this->vitorias += $value;
    }
    public function setDerrotas($value){
        $this->derrotas += $value;
    }
    public function setEmpates($value){
        $this->empates += $value;
    }

    //Abstracts
    public function apresentar(){
        echo("Apresento {$this->getNome()}, vindo diretamente do(e) {$this->getNacionalidade()} etc e tal. Heeeee!!!!!");
    }
    public function status(){
        echo("Nome: {$this->nome} <br>Nacionalidade: {$this->nacionalidade}<br>idade: {$this->idade}<br>altura: {$this->altura}<br>peso: {$this->peso}<br>vitorias: {$this->vitorias}<br>derrotas: {$this->derrotas}<br>empates: {$this->empates}<br>");
    }
    public function ganharLuta(){
        $this->setVitorias(1);
    }
    public function perderLuta(){
        $this->setDerrotas(1);
    }
    public function empatarLuta(){
        $this->setEmpates(1);
    }
}
