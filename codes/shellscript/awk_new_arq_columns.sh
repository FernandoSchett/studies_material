#!bin/bash/
: <<HEADER
File:           awk_new_arq_columns.sh
Last changed:   25/06/20 16:05
Purpose:        Create an output file with data about the city of Salvador, Bahia, containing the columns DATE, NEW CASES, and NEW DEATHS. DATABASE: https://covid.saude.gov.br/
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh awk_new_arq_columns.sh           
HEADER
awk -F ";" '$2=="BA" && $3=="Salvador"{print "DATA:" $8 ";CASOS NOVOS:" $12 ";OBITOS NOVOS: " $14}' $1 > output.txt
