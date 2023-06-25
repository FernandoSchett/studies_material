#!bin/bash
: <<HEADER
File:           get_sh_feedback.sh
Last changed:   25/06/20 16:05
Purpose:        get feedback from another script, then check arquive nature
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh get_sh_feedback.sh           
HEADER

bash arq_check_feedback.sh $1
resultado=$?

if [ $resultado == 1 ]; then
    echo "é diretorio"
else
if [ $resultado == 3 ]; then
    echo "ẽ outros"
else
if [ $resultado == 2 ]; then
    echo "é executavel"
else
    echo "é regular"
fi
fi
fi