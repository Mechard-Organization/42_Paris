#!/bin/sh

# 🎨 Couleurs ANSI
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
RED='\033[1;31m'
RESET='\033[0m'

# 🧭 Sauvegarde du dossier courant
INITIAL_DIR=$(pwd)

# 🔍 Recherche du projet (via Url)
URL=$2

# 🔍 Recherche du dossier 42_Paris (vrai repo Git racine)
case "$URL" in
  git@github.com:*/?*|git@github.com:*/?*.git)
	REPO_NAME=$(basename "${URL%.git}")
    ;;
  *)
    ;;
esac

# 🔍 Recherche du dossier 42_Paris (vrai repo Git racine)
CURRENT_DIR="$INITIAL_DIR"
CURRENT_DIR_NAME=""

if [ -d "$CURRENT_DIR/.git" ] || [ -f "$CURRENT_DIR/.git" ]; then
    CURRENT_DIR_NAME=$(echo "$CURRENT_DIR" | rev | cut -d'/' -f1 | rev)
else
	while [ "$CURRENT_DIR" != "/" ] && [ "$CURRENT_DIR" != "." ]; do
        CURRENT_DIR=$(dirname "$CURRENT_DIR")
        if [ -d "$CURRENT_DIR/.git" ] || [ -f "$CURRENT_DIR/.git" ]; then
            CURRENT_DIR_NAME=$(echo "$CURRENT_DIR" | rev | cut -d'/' -f1 | rev)
            break
        fi
    done
fi

# Fonction d'affichage du début
gbegin () {
	if [ "$REPO_NAME" ] && [ ! "$CURRENT_DIR_NAME" ]; then
		echo "📁 Dépôt .git détecté : ${BLUE}$REPO_NAME${RESET}"
	else
		if [ "$CURRENT_DIR_NAME" != "." ]; then
			echo "📁 Folder parent détecté : ${BLUE}"$CURRENT_DIR_NAME"${RESET}"
		fi
	fi
}

# Remplacement de la commande GIT clone
gclone() {
	if [ "$0" = "/home/mechard/.local/bin/git42" ] && [ "$1" ] && [ "$2" != "--recurse-submodules" ] && [ "$REPO_NAME" = "42_Paris" ]; then
		git $1 --recurse-submodules $2 $3
	else
		disp $@
	fi
}

# Remplacement de la commande GIT push
gpush() {
	if [ "$CURRENT_DIR_NAME" = "42_Paris" ] || [ "$CURRENT_DIR_NAME" = "Others" ] || [ "$CURRENT_DIR_NAME" = "Cursus_2023" ]; then
		
		# Sauvegarde de l'emplacement utilisateur
		LAST_PWD=$(pwd)

		echo "CD = $CURRENT_DIR" | rev | cut -d'/' -f1 | rev
		if [ "$CURRENT_DIR_NAME" = "Cursus_2023" ] || [ "$CURRENT_DIR_NAME" = "Others" ]; then
			if [ "$CURRENT_DIR_NAME" = "Cursus_2023" ]; then
				cd ..
			fi
			cd ..
		fi

		echo "---------------Push de 42_Paris---------------"
		# Push du repo Others
		cd Others
		echo "Push du submodule \"Others\""
		git add -A
		git commit -m "$(pwd) - update of $(date) by $(whoami)"
		git push origin main_perso
		echo

		# Push du repo Cursus_2023
		cd ../42_Paris_2023/Cursus_2023
		echo "Push du submodule \"Cursus_2023\""
		git add -A
		git commit -m "$(pwd) - update of $(date) by $(whoami)"
		git push origin main_cursus_2023
		echo

		# Push du repo principal
		cd ..
		echo "Push du folder \"42_Paris\""
		git add -A
		git commit -m "$(pwd) - update of $(date) by $(whoami)"
		git push
		echo

		# Retour de l'utilisateur à sa place
		cd $LAST_PWD
	else
		disp "$@"
	fi
}

# Remplacement de la commande GIT pull
gpull() {
	if [ "$CURRENT_DIR_NAME" = "42_Paris" ] || [ "$CURRENT_DIR_NAME" = "Others" ] || [ "$CURRENT_DIR_NAME" = "Cursus_2023" ]; then
		echo "$@"
	else
		disp "$@"
	fi
}

# Affichage des arguments
disp() {
	echo "\$0 = \""$0"\""
	echo "\$@ = \""$@"\""
	echo "\$# = \""$#"\""
}

# Remplacement de la commande GIT générale

gbegin
if [ "$1" = "clone" ]; then
	gclone $@ $CURRENT_DIR_NAME
elif [ "$1" = "push" ]; then
	gpush $@ $CURRENT_DIR_NAME
elif [ "$1" = "pull" ]; then
	gpull $@ $CURRENT_DIR_NAME
else
	if [ "$1" = "commit" ] && [ "$2" = "-m" ] ; then
		git "$@"
	else
		git "$@"
	fi
fi
