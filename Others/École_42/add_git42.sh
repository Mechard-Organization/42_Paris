#!/bin/sh

pwd=$(pwd)

if [ "$1" = "-g" ] || [ ! "$1" ]; then
	echo "-g"
	if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
		echo "42_paris"
		cd ~/Downloads/42_paris
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd ~/Downloads/42_paris/42_Paris_2023/Others
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
		echo "Cursus_2023"
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	fi
elif [ "$1" = "-p" ]; then
	echo "-p"
	if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
		echo "42_paris"
		cd ~/Downloads/42_paris
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
		echo "Cursus_2023"
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		# git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd
	fi
else
	echo "Usage: 42git { -g | -p }\n"
fi