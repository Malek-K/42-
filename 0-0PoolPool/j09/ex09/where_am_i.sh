var=$(ifconfig | grep 'inet ' | rev |  awk '{print  $(NF-1)}' | rev)

if test -z "$var"
then
	echo "Je suis perdu"
else 
	echo $var | tr ' ' '\n'
fi
