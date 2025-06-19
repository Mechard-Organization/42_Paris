#!/bin/sh

echo "$1"

if [ "$(pwd | grep "42_paris")" ] && [ ! "$(pwd | grep "Cursus_2023")" ]; then
	echo "42_paris"
	pwd=$(pwd)
	cd ~/Downloads/42_paris
	git add -A && git commit -m "$(date) - $(pwd) update" && git push
	cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
	git add -A && git commit -m "$(date) - $(pwd) update" && git push
	cd $pwd
elif [ "$(pwd | grep "42_paris")" ] && [ "$(pwd | grep "Cursus_2023")" ]; then
	echo "Cursus_2023"
	cd ~/Downloads/42_paris/42_Paris_2023/Cursus_2023
	git add -A && git commit -m "$(date) - $(pwd) update" && git push
	cd $pwd
fi
