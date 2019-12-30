#Eisha
#17k-3730
#sec C

echo -e "Checking Numbers From 1 to 999 for sum of cubes\n"
no=1
for i in {1..999}
do

    sum=0
    p=$no
    while [[ $p -ne 0 ]]
    do
        ((tmp=$p%10))
        ((p=$p/10))
        ((q=$tmp*$tmp*$tmp))
        ((sum=$sum+$q))
    done

    if [[$sum -eq $no]]
    then
        echo $no
    fi
    ((no=$no+1))

done
