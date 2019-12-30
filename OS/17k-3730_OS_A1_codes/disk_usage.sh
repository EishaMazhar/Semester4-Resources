#Eisha
#17k-3730
#sec C
#task: Disk usage

if [ $# -lt 1 ]
then
    echo "No directory is given as argument. Exiting"
    exit 1
else
    dir=$1
    if [-d $dir]
    then
        echo "Directory Exists"
        if [$# -eq 2]
        then 
            num=$2
        else
            num=10
        fi
#exited if
        cd $dir
        sudo du -a  $dir | sort -n -r | head -n $num
    else
        echo "Directory doesn't exist.Exiting"
        exit 1
    fi
fi