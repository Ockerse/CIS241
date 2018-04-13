#!/bin/bash

if [ $# -eq 0 ]
	then 
		echo "ERROR: no arguements passed"
		exit 1
fi

[ -d ~/backup ] && echo "Backup Directory Exists" || mkdir ~/backup

for l in "$@"; do
	if [[ "$l" = "--help" ]] 
		then
			echo "commands list: -l, -n, --help"
			echo "-l: lists the name of the files and"
			echo "directories in the backup directory"
			echo "-n: lists the number of files and directories"
			echo "in the backup directory and file size"

	elif [[ "$l" = "-n" ]]
		then
			echo "Number of Files and/or Directories in Backup"
			ls -q ~/backup | wc -l
			echo "Number of Bytes Taken Up"
			find ~/backup -type f -mtime -30 -exec ls -l {} \; | awk '{ s+=$5 } END { print s }'	

	elif [[ "$l" = "-l" ]]
		then 
			echo "Files and Directories Within Backup"
			ls -la ~/backup
			
	else
		if [[ -e "$l" ]]
			then
				
				cp -ir "$l" ~/backup
				echo "Backed up $l"
		else
			echo "The following file does not exist: $l"
		fi
	fi
done
