<?php

require_once 'Lutador.php';

class Luta{
    private $desafiado;
    private $desafiante;
    private $aprovada;

    //Getters
    public function getDesafiado(){
        return $this->desafiado;
    }
    public function getDesafiante(){
        return $this->desafiante;
    }
    public function getAprovada(){
        return $this->aprovada;
    }
    
    //Setters
    public function setDesafiado($desafiado){
        $this->desafiado = $desafiado;
    }
    public function setDesafiante($desafiante){
        $this->desafiante = $desafiante;
    }
    public function setAprovada($aprovada){
        $this->aprovada = $aprovada;
    }

    //Public
    public function marcarLuta($l1, $l2){
        if ($l1->getCategoria() == $l2->getCategoria()
        && $l1 != $l2){
            $this->aprovada = true;
            $this->desafiado = $l1;
            $this->desafiante = $l2;
        } else {
            $this->aprovada = false;
            $this->desafiado = null;
            $this->desafiante = null;
        }
    }
    public function lutar(){
        if ($this->aprovada = true){
            $this->desafiante->apresentar(); echo "<br><br>";
            $this->desafiado->apresentar(); echo "<br><br>";
            $vencedor = rand(0,2);
            switch($vencedor){
                case 0:
                    echo "A luta empatou"; echo "<br><br>";
                    $this->desafiado->setEmpates(1);
                    $this->desafiante->setEmpates(1);
                    break;
                case 1:
                    echo "O {$this->desafiado->getNome()} Venceu"; echo "<br><br>";
                    $this->desafiado->setVitorias(1);
                    $this->desafiante->setDerrotas(1);
                    break;
                case 2:
                    echo "O {$this->desafiante->getNome()} Ganhou"; echo "<br><br>";                     
                    $this->desafiado->setDerrotas(1);
                    $this->desafiante->setVitorias(1);
                    break;
            }
            $this->desafiado->status(); echo "<br><br>";
            $this->desafiante->status();
        }else{
            echo "Esta luta não pode acontecer!";
        }
    }
}