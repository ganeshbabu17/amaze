csv=`ls -1 ~/CSV/*.csv`
if [ ! -d "/home/gbabu/Backup" ]; then
   mkdir -p "/home/gbabu/Backup"
fi
for i in $csv
do
 echo $i
 #readcsv $i
 if [ $? -eq 0 ]; then
   mv $i ./Backup/
 fi
done
