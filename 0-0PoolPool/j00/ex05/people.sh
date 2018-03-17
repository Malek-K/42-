ldapsearch -Q uid="z*" | grep "cn:" | sort -rf | cut -c 5-
