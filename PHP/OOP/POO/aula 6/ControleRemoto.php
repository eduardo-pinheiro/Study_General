<?php

require_once 'Controlador.php';

class ControleRemoto implements Controlador{    

    //Atributos
    private $ligado;
    private $volume;
    private $tocando;

    //Constructor
    public function __construct(){
        $this->setLigado(false);
        $this->setVolume(60);
        $this->setTocando(false);
    }

    //Getters
    private function getLigado(){
        return($this->ligado);
    }
    private function getVolume(){
        return($this->volume);
    }
    private function getTocando(){
        return($this->tocando);
    }

    //Setters
    private function setLigado($l){
        $this->ligado = $l;
    }
    private function setVolume($v){
        $this->volume = $v;
    }
    private function setTocando($t){
        $this->tocando = $t;
    }

    

    //Métodos Abstratos
    public function ligar(){
        $this->setLigado(true);
    }
    public function desligar(){
        $this->setLigado(false);        
    }

    /** PAREI DE FAZER AQUI, FUI PRO PRÓXIMO VÍDEO */
    
    public function abrirMenu(){
        
    }
    public function fecharMenu(){
        
    }
    public function maisVolume(){
        
    }
    public function menosVolume(){
        
    }
    public function ligarMudo(){
        
    }
    public function desligarMudo(){
        
    }
    public function play(){
        
    }
    public function pause(){
        
    }
}

?>