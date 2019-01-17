#!/bin/sh
i="0"
ok="0"
ko="0"
mkdir crashreport
echo "How many test ? (--flow-one)"
read tryfo
echo "How many test ? (--flow-ten)"
read tryft
echo "How many test ? (--flow-thousand)"
read tryfth
while [ $i -lt $tryfo ]
do
	./generator --flow-one > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	r=$[$r+2]
	if [ $l -lt $r ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	elif [ $l -gt 2 ]
	then
		echo "KO lines = $r - must be $l"
		ko=$[$ko+1]
	else
		cat tmp.map > crashreport/map.crash.flowone$i
		exit 0
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko"
i="0"
ok="0"
ko="0"
while [ $i -lt $tryft ]
do
	./generator --flow-ten > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	r=$[$r+2]
	if [ $l -lt $r ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	elif [ $l -gt 2 ]
	then
		echo "KO lines = $r - must be $l"
		ko=$[$ko+1]
	else
		cat tmp.map > crashreport/map.crash.flowten$i
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko"
i="0"
ok="0"
ko="0"
while [ $i -lt $tryfth ]
do
	./generator --flow-thousand > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	r=$[$r+2]
	if [ $l -lt $r ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	elif [ $l -gt 2 ]
	then
		echo "KO lines = $r - must be $l"
		ko=$[$ko+1]
	else
		cat tmp.map > crashreport/map.crash.flowthousand$i
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko"
