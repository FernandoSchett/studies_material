#!/bin/bash
: <<HEADER
File:           logger_usage.sh
Last changed:   25/06/20 16:05
Purpose:        manipulate logger command for info
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToExecute:   sh logger_usage.sh           
HEADER

logger -t log -p user.info "Starting checkfs"

set -x	
set -a	
set -e

ARQUIVOS=$(ls *)

for NOME in $ARQUIVOS
do
if [ -x $NOME ] 
then
    less echo $NOME"- Executável" >> user.log
    logger -p local0.notice -t arquivos $NOME"- Executável"
    logger -t log -s -p user.warn $NOME"- Executável" 
else

    echo $NOME"- Não Executável" >> user.log
     logger -p local0.notice -t arquivos $NOME"- Não Executável"
    logger -t log -s -p user.warn "$NOME- Não Executável"  
fi

done
logger -t log -p user.info "Finished checkfs" less
set +e
set +a	
set +x

