#!/bin/sh
rm -rf lemin_checker_log lem-in.dSYM lem-in
mkdir lemin_checker_log
make re -C ../
cp ../lem-in .
for i in `seq 0 6`
do
	echo "\n\n=== $i | "error_$i" ===\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_errorfile$i.txt" ./lem-in < "map.error$i"
	echo "\n=== LEAKS ===\n"
	grep "definitely lost:" lemin_checker_log/log_errorfile$i.txt | cut -d '=' -f 5 | cut -c5-
	sleep 1
done
for i in `seq 0 3`
do
	echo "\n\n=== $i | "Correct_$i" ===\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_correctfile$i.txt" ./lem-in < "map.ok$i"
	echo "\n=== LEAKS ===\n"
	grep "definitely lost:" lemin_checker_log/log_errorfile$i.txt | cut -d '=' -f 5 | cut -c5-
	sleep 1
done
rm -rf lem-in.dSYM lem-in
