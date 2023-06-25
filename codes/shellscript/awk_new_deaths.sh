#!bin/bash/
: <<HEADER
File:           awk_new_deaths.sh
Last changed:   25/06/20 16:05
Purpose:        get quantity of NEW DEATHS that occurred in Salvador, Bahia, during the period from 01/05/2022 to 31/05/2022 DATABASE: https://covid.saude.gov.br/   
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh awk_new_deaths.sh           
HEADER



awk -F ";" 'BEGIN{val=0}{if($8>="2022-05-01" && $8<="2022-05-31" && $3=="Salvador" && $2=="BA"){ val=val + $14}}END{print val}' $1 >> output.txt
