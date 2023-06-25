#!/bin/bash
: <<HEADER
File:           arq_reader.sh
Last changed:   25/06/20 16:05
Purpose:        read lines from a file and print 10 lines at a time
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh arq_reader.sh           
HEADER

cont=0
while IFS= read -r line <&9; do
    echo "$line"
    ((cont=cont+1))
    if [ $cont == 10 ]; then

        echo Would you like to get another 10 lines [y/n]?
        
        read -r answer
        if [ $answer != 'y' ]; then
            exit
        else
            cont=0
        fi
    fi
done 9< "$1"
    

    