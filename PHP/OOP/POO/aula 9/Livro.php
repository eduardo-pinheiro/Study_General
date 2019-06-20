<?php

require_once "Pessoa.php";
require_once "Publicacao.php";

class Livro implements Publicacao{

    private $titulo;
    private $autor;
    private $totPaginas;
    private $pagAtual;
    private $aberto;
    private $leitor;

    //Contruct
    public function __construct($titulo, $autor, $totPaginas, $pagAtual, $aberto, $leitor){
        $this->titulo = $titulo;
        $this->autor = $autor;
        $this->totPaginas = $totPaginas;
        $this->pagAtual = $pagAtual;
        $this->aberto = $aberto;
        $this->leitor = $leitor;
    }

    //Getters
    public function getTitulo(){
        return $this->titulo;
    }
    public function getAutor(){
        return $this->autor;
    }
    public function getTotPaginas(){
        return $this->totPaginas;
    }
    public function getPagAtual(){
        return $this->pagAtual;
    }
    public function getAberto(){
        if ($this->aberto == true){
            return "Aberto";
        }else{
            return "Fechado";
        }
    }
    public function getLeitor(){
        return $this->leitor;
    }

    //Setters
    public function setTitulo($titulo){
        $this->titulo = $titulo;
    }
    public function setAutor($autor){
        $this->autor = $autor;
    }
    public function setTotPaginas($totPaginas){
        $this->totPaginas = $totPaginas;
    }
    public function setPagAtual($pagAtual){
        $this->pagAtual = $pagAtual;
    }
    public function setAberto($aberto){
        $this->aberto = $aberto;
    }
    public function setLeitor($leitor){
        $this->leitor = $leitor;
    }

    //Actions
    public function detalhes(){
        echo "Titulo: {$this->getTitulo()}<br>Autor: {$this->getAutor()}<br>Total de páginas: {$this->getTotPaginas()}<br>Pagina Atual: {$this->getPagAtual()}<br>Aberto: {$this->getAberto()}<br>Leitor: {$this->getLeitor()->getNome()}<br>";
    }

    //Interface
    public function abrir(){
        $this->setAberto(true);
    }
    public function fechar(){
        $this->setAberto(false);
    }
    public function avancarPag(){
        $this->pagAtual += 1;
    }
    public function voltarPag(){
        $this->pagAtual -= 1;
    }
}