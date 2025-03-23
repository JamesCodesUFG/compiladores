#!/bin/bash

# Script: compile_flex.sh
# Uso: ./run.sh <arquivo.l>

if [ $# -eq 0 ]; then
    echo "Erro: Nenhum arquivo especificado."
    echo "Uso: $0 <arquivo.l> [<nome_do_executavel>]"
    exit 1
fi

INPUT_FILE=$1

# Etapa 1: Compilar com Flex
flex "$INPUT_FILE"

# Verificar se o Flex gerou o arquivo lex.yy.c
if [ ! -f "lex.yy.c" ]; then
    echo "Erro na compilação com Flex!"
    exit 1
fi

# Etapa 2: Compilar o código gerado com GCC
gcc lex.yy.c -o lex

# Verificar se o executável foi gerado
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida!"

    echo "Executando o programa..."
    ./lex    
else
    echo "Erro na compilação com GCC!"
    exit 1
fi