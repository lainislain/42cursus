#!/bin/bash

arg=" a 1 2 5 45"
	echo "______Lancer push_swap avec des paramètres non numériques. Le programmedoit afficher "Error"__________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[Error] calculate : `wc -l cmd`"

arg=" 45 1 2 5 45"
	echo "_______Lancer push_swap avec un doublon dans les paramètres. Le programmedoit afficher "Error"_____________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[error] calculate : `wc -l cmd`"

arg="0 2 5 77 2147483648"
	echo "______________MAXINT____________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[Error] calculate : `wc -l cmd`"

arg="0 1 2 5 2147483647"
	echo "_________________________MAXINT______________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"

arg=" 4 1 2 5 -2147483649"
	echo "_______________MAXINT_______________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[Error] calculate : `wc -l cmd`"

arg="-2147483648 4 1 2 5"
	echo "_______________MAXINT_______________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"

arg=""
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"
	echo "_________________________________________"

arg="42"
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"

arg="0 1 2 3"
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"


arg="0 1 2 3 4 5 6 7 8 9"
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[0] calculate : `wc -l cmd`"

arg="2 1 0"
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[3] calculate : `wc -l cmd`"

arg="1 5 2 4 3"
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[12] calculate : `wc -l cmd`"

arg=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')" 2> /dev/null)
	echo "_________________________________________"
	echo $arg
	./push_swap $arg > cmd
	./checker $arg < cmd
	echo "expected[12] calculate :  `wc -l cmd`"

echo "100 random values"
	echo "_________________________________________"
	bash push_swap_tester/tester.sh . 100 10
	echo "expected [700=>5, 900=>4, 1100=>3, 1300=>2, 1500=>1] calculate : `wc -l cmd`"


echo "500 random values"
	bash push_swap_tester/tester.sh . 500 10
	echo "expected[5500=>5, 7000=>4, 8500=>3, 10000=>2, 15000=>1] calculate : `wc -l cmd`"

