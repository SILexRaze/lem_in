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
echo "flow one :\n"
while [ $i -lt $tryfo ]
do
	./generator --flow-one > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	l=$[$l+3]
	if [ $r -le $l ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	else
		echo "KO lines = $r - must be $l"
		cat tmp.map > crashreport/map.flo.$i
		ko=$[$ko+1]
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko\n flow ten :\n"
i="0"
ok="0"
ko="0"
while [ $i -lt $tryft ]
do
	./generator --flow-ten > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	l=$[$l+3]
	if [ $r -le $l ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	else
		echo "KO lines = $r - must be $l"
		cat tmp.map > crashreport/map.flt.$i
		ko=$[$ko+1]
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko\nflow thousand :\n"
i="0"
ok="0"
ko="0"
while [ $i -lt $tryfth ]
do
	./generator --flow-thousand > tmp.map
	l=`cat tmp.map | grep "lines" | tr '\n' ' ' | cut -d ' ' -f 16`
	r=`./lem-in < tmp.map | wc -l | cut -d ' ' -f 7`
	l=$[$l+3]
	if [ $r -le $l ]
	then
		echo "OK lines = $r"
		ok=$[$ok+1]
	else
		echo "KO lines = $r - must be $l"
		cat tmp.map > crashreport/map.flth.$i
		ko=$[$ko+1]
	fi
	i=$[$i+1]
done
echo "OK : $ok | KO : $ko"
