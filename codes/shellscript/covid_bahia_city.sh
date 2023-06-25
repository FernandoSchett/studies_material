#!bin/bash
: <<HEADER
File:           filne_name.sh
Last changed:   25/06/20 16:05
Purpose:                 
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh file_name           
HEADER

awk -F ";" '{if($2=="BA" && $3!=""){print $0 > $3;};}' $1

ARQUIVOS=$(ls *)

SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

for NOME in *
do
echo $NOME

if [ -x $NOME ] 
then
    echo $NOME "Erro ao ler o arquivo."
else
   awk -F ";" 'BEGIN{total=0;cidade="";data=""}{if(total<$14){total=$14;cidade=$3;data=$8}}END{print cidade ";" total ";" data}' $NOME >> output.txt
fi
done 

IFS=$SAVEIFS
