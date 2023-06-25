#!bin/bash

vogais=('a' 'e' 'i' 'o' 'u' 'A' 'E' 'I' 'O' 'U')
consoantes=('b' 'c' 'd' 'f' 'g' 'h' 'j' 'k' 'l' 'm' 'n' 'p' 'q' 'r' 's' 't' 'v' 'x' 'w' 'y' 'z' 'B' 'C' 'D' 'F' 'G' 'H' 'J' 'K' 'L' 'M' 'N' 'P' 'Q' 'R' 'S' 'T' 'V' 'X' 'W' 'Y' 'Z')
chave=`date`
echo $chave
case $1 in
  BACKUP)
    arquivos=$(ls *)
    mkdir BACKUP
    if (( $? == 0 )); then
        echo "DIRETORIO BACKUP CRIADO"
        for i in $arquivos 
        do
            cp ./$i ./BACKUP
        done
    else
      echo "DIRETORIO BACKUP NÃO FOI CRIADO"
    fi
    ;;
  TEMPORARIO1)
    mkdir TMP
    if (( $? == 0 )); then
        echo "DIRETORIO TMP CRIADO"
        for i in 0 1 2 3 4 5 6 7 8  
        do
            tent=$(ls ${vogais[$i]}*)
            data=$(date "+%Y.%m.%d-%H.%M.%S")
            for j in $tent 
            do
            	nomedata=$j.$data
                echo "MOVENDO $j PARA TMP"
                cp ./$j ./TMP/$nomedata	
            done
        done
    else
      echo "DIRETORIO TMP NÃO FOI CRIADO"
    fi
    ;;
  TEMPORARIO2)
    mkdir TMP
    if (( $? == 0 )); then
        echo "DIRETORIO TMP CRIADO"
        for i in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41
        do
            tent2=$(ls ${consoantes[$i]}*)
            echo ${consoantes[$i]}
            echo $tent2
            for j in $tent2
            do
                cp ./$j ./TMP
            done
        done
    else
      echo "DIRETORIO TMP NÃO FOI CRIADO"
    fi
    ;;
  *)
    rm -r BACKUP
    if (( $? == 0 )); then
      echo "DIRETORIO BACKUP REMOVIDO"
    fi
    rm -r TMP 
    if (( $? == 0 )); then
      echo "DIRETORIO TEMP REMOVIDO"
    fi
    ;;
esac
