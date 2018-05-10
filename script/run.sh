#!/bin/bash

ME=../quruiz.filler
ABANLIN=../resources/players/abanlin.filler
CARLI=../resources/players/carli.filler
CHAMPELY=../resources/players/champely.filler
GRATI=../resources/players/grati.filler
HCAO=../resources/players/hcao.filler
SUPJEAN=../resources/players/superjeannot.filler

MAP0=../resources/maps/map00
MAP1=../resources/maps/map01
MAP2=../resources/maps/map02

make -C ../

for m in $MAP0 $MAP1 $MAP2;
do
	for a in $ABANLIN $CARLI $CHAMPELY $GRATI $HCAO $SUPJEAN;
	do
		echo $a $m
		for i in 1 2 3 4 5;
		do
			../resources/filler_vm -f $m -p1 $ME -p2 $a | grep fin | cut -d ":" -f 2 | ./me_p1
		done
		printf "\n\n"
	done
done

for m in $MAP0 $MAP1 $MAP2;
do
	for a in $ABANLIN $CARLI $CHAMPELY $GRATI $HCAO $SUPJEAN;
	do
		echo $a $m
		for i in 1 2 3 4 5;
		do
			../resources/filler_vm -f $m -p1 $a -p2 $ME | grep fin | cut -d ":" -f 2 | ./me_p2
		done
		printf "\n\n"
	done
done
