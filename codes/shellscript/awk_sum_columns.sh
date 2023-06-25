#!bin/bash
File:           awk_sum_columns.sh
Last changed:   25/06/20 16:05
Purpose:        creates a file with the sum of the existing columns between the columns "casosAcumulados" and "emAcompanhamentosNovos" for the period between 01/05/2022 and 31/05/2022 in Salvador, Bahia. DATABASE: https://covid.saude.gov.br/
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh awk_sum_columns.sh           
HEADER

awk -F ";" '{total=0;if($8>="2022-05-01" && $8<="2022-05-31" && $3=="Salvador" && $2=="BA"){for(i=11;i<=16;i++){total=total+$i};print total}}' $1 >> output.txt
 


