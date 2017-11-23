cat $1 | grep 'bauer' | sed 'n;d' | awk '{print $(NF-1)}' | sed 'n;d'
