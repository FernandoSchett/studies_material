#!bin/bash
arquivos=$1
if [ -x $arquivos ]; then
    exit 2
else
if [ -d "$arquivos" ]; then
    exit 1
else
if [ -f $arquivos ]; then
    exit 0
else
    exit 3
fi
fi
fi
