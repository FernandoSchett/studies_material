#!/bin/bash
: <<HEADER
File:           check_arq.sh
Last changed:   25/06/20 16:05
Purpose:        check executable and non-executables files in current directory   
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh check_arq.sh           
HEADER

ARQUIVOS=$(ls *)

for NOME in $ARQUIVOS
do
if [ -x $NOME ] 
then

    echo $NOME"- Executável"
else

    echo $NOME"- Não Executável"

done