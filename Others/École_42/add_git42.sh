#!/bin/sh

pwd=$(pwd)

if [ "$1" = "-g" ] || [ ! "$1" ]; then
	if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
		echo "Push de 42_Paris et ces sous-dossiers en cours !"

		# Push de 42_paris
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		echo "42_Paris pusher !"

		# Push de Cursus_2023
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		echo "Cursus_2023 pusher !"

		# Push de Others
		
		echo "--------------------------------------------------------------------------------------------------------"
		cd ~/Downloads/42_paris/42_Paris_2023/Others
		git add -A > /dev/null 2>&1 && git commit -m "$(date) - $(pwd) update" > /dev/null 2>&1 && git push > /dev/null 2>&1
		if [ "$?" = "" ]
		echo "Other pusher !"
		echo "--------------------------------------------------------------------------------------------------------"

		cd $pwd

	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
		echo "Push de Cursus_2023 !"

		# Push de Cursus_2023

		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd

	elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Others")" ]; then
		echo "Push de Others !"

		# Push de Cursus_2023

		cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
		git add -A && git commit -m "$(date) - $(pwd) update" && git push
		cd $pwd

	else
		echo "This command can only be used in 42_Paris and 42_Paris's repositories"
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