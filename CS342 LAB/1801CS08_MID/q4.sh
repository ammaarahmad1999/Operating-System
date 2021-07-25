
#!/bin/bash
folder="$1"
k="$2"
tr -d [:punct:] < $folder | tr -d [:digit:] | tr -s [:blank:]  "\n" | sort | uniq -c | sort -bnr | awk -v k=$k '$1>k{print $2}' > tmp
while read p; do
    sed -i "s/\b$p\b/MASKED/g" *.txt
done < tmp
echo "Replaced occurence in each file"
for FILE in *.txt ; do
 echo -n "$FILE " >> tmp2
 grep -o "MASKED" $FILE | wc -l >> tmp2
done;
cat tmp2 | sort -k2 -bnr | awk -v k=$k  '$2>k && c < k { c++;print $1}'
rm tmp
rm tmp2
