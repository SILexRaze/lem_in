#!/bin/sh
rm -rf lemin_checker_log lem_in.dSYM lem_in
mkdir lemin_checker_log
make re -C ../
cp ../lem_in .
for i in `seq 0 6`
do
	echo "\n\n=== $i | "error_$i" ===\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_errorfile$i.txt" ./lem_in < "map.error$i"
	echo "\n=== LEAKS ===\n"
	grep "definitely lost:" lemin_checker_log/log_errorfile$i.txt | cut -d '=' -f 5 | cut -c5-
	sleep 1
done
