#!/bin/bash
# -*- coding: utf-8 -*-

echo -e "El camino preferido es el de generar el árbol\n" \
  "de directorios con las configuraciones primero.\n" \
  "Luego ejecutar los cálculos"

NUM_EXPS=0
APPLICATION="/bin/bash app1.sh"
if [ $# -eq 0 ]
then
  read -p '# de experimentos? ' NUM_EXPS
elif [ ! $# -eq 1 ]
then
  echo -e "Uso: este comando requiere un numero positivo de entrada"
  echo "\te.g. para diez experimentos, `basename $0` 10" >&2; exit 1
else
  NUM_EXPS=$1
fi

re="^[0-9]+$"
if ! [[ $NUM_EXPS =~ $re ]]
then
  echo "Error: valor [=$NUM_EXPS] no es un entero positivo" >&2; exit 1
fi

echo "Creando árbol de directorios y creando inputs"
echo -e "\033[0;31mAtención:\033[0m No copiamos app1.sh en cada ruta"
echo -e "          por duplicación y simplicidad"

for exp in `seq --format="%02g" ${NUM_EXPS}`
do
  EXP_NAME="exp_Nmax${exp}"
  echo -ne "\texp #${exp}: "
  mkdir -p results/${EXP_NAME}
  # No sobreescribimos carpetas existentes con información existente
  [ ! -f results/${EXP_NAME}/inputs ] && \
    echo -e "${EXP_NAME}\n${exp}\nresults/${EXP_NAME}/data.txt" \
      > results/${EXP_NAME}/inputs && \
    echo "hecho" || echo "existe"
done

echo "Ejecutando app1.sh"

# Pregunta para ustedes: ¿por qué usar find?
for input in `find results/ -name inputs -type f`
do
  echo -ne "\tejec ${input}: "
  out_log="${input///inputs//out.log}"
  err_log="${input///inputs//err.log}"
  ./app1.sh < $input 1> ${out_log} 2> ${err_log} && \
    echo "fin" || echo "error (revisar ${out_log} o ${err_log})"
done
