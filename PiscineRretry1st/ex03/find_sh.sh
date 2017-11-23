find . -name "*.sh" | sed "s/...$//" | rev |cut -d/ -f1  | rev
