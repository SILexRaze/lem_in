#!/bin/sh
i="0"
ok="0"
ko="0"
echo "How many test ?"
read try
while [ $i -lt $try ]
do
	./generator --flow-ten > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	if [ $l -eq $r ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	elif [ $l -gt 1 ]
	then
		echo "KO lines = $r - must be $l"
		ko=$[$ko+1]
	else
		exit 0
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko"
