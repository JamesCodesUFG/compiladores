#!/bin/bash

# Script: compile_flex.sh
# Uso: ./run.sh <arquivo.l>

if [ ! -d "./out" ]; then
    mkdir ./out
fi

if [ $# -eq 0 ]; then
    echo "Erro: Nenhum arquivo especificado."
    echo "Uso: $0 <arquivo.l> [<nome_do_executavel>]"
    exit 1
fi

INPUT_FILE=$1

# Etapa 1: Compilar com Flex
flex  -o ./out/lex.yy.c "$INPUT_FILE"

# Verificar se o Flex gerou o arquivo lex.yy.c
if [ ! -f "./out/lex.yy.c" ]; then
    echo "Erro na compilação com Flex!"
    exit 1
fi

# Etapa 2: Compilar o código gerado com GCC
gcc ./out/lex.yy.c -o ./out/lex

# Verificar se o executável foi gerado
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida!"

    echo "Executando o programa..."
    ./out/lex    
else
    echo "Erro na compilação com GCC!"
    exit 1
fi

rm -rf ./out