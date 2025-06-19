#!/bin/bash

# 🎨 Couleurs ANSI
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
RED='\033[1;31m'
RESET='\033[0m'

# 🧭 Sauvegarde du dossier courant
INITIAL_DIR=$(pwd)

# 🔍 Recherche du dossier 42_Paris (vrai repo Git racine)
CURRENT_DIR="$INITIAL_DIR"
while true; do
    if [ -d "$CURRENT_DIR/.git" ]; then
        break
    elif [ -f "$CURRENT_DIR/.git" ]; then
        :
    elif [ "$CURRENT_DIR" = "/" ]; then
        echo "❌ Impossible de trouver le dossier racine du dépôt 42_Paris."
        exit 1
    fi
    CURRENT_DIR=$(dirname "$CURRENT_DIR")
done

REPO_DIR="$CURRENT_DIR"
LOG_FILE="$REPO_DIR/pull_42.log"
echo "📁 Dossier racine du dépôt détecté : $REPO_DIR"
echo "📝 Création du log : $LOG_FILE"

# 🔄 Initialise ou écrase le log
echo "=== [$(date)] ===" > "$LOG_FILE"

# 📥 On s'y place
cd "$REPO_DIR" || exit 1

# 🔄 Mise à jour du dépôt principal
echo -n "📦 Dépôt principal : "
echo -n "📦 Dépôt principal : " >> "$LOG_FILE"
OUTPUT=$(git pull)
if [[ "$OUTPUT" == *"Already up to date."* ]]; then
    echo -e "${GREEN}✅ à jour${RESET}"
    echo "✅ dépôt principal à jour" >> "$LOG_FILE"
elif [[ "$OUTPUT" == *"Updating "* ]]; then
    echo -e "${GREEN}⬆️ mis à jour${RESET}"
    echo "$OUTPUT" >> "$LOG_FILE"
else
    echo -e "${RED}⚠️ erreur ou message inattendu${RESET}"
    echo "$OUTPUT" >> "$LOG_FILE"
fi

# 🔄 Mise à jour des submodules

# Cursus_2023
if [ -f "42_Paris_2023/Cursus_2023/.git" ]; then
    echo -n "📁 Cursus_2023 : "
    echo "➡️ Mise à jour de Cursus_2023..." >> "$LOG_FILE"
    cd 42_Paris_2023/Cursus_2023
    OUTPUT=$(git pull)
    if [[ "$OUTPUT" == *"Already up to date."* ]]; then
        echo -e "${GREEN}✅ à jour${RESET}"
        echo "✅ submodule Cursus_2023 à jour" >> "$LOG_FILE"
    elif [[ "$OUTPUT" == *"Updating "* ]]; then
        echo -e "${GREEN}⬆️ mis à jour${RESET}"
        echo "$OUTPUT" >> "$LOG_FILE"
    else
        echo -e "${RED}⚠️ erreur ou message inattendu${RESET}"
        echo "$OUTPUT" >> "$LOG_FILE"
    fi
    cd "$REPO_DIR"
fi

# Others
if [ -f "Others/.git" ]; then
    echo -n "📁 Others : "
    echo "➡️ Mise à jour de Others..." >> "$LOG_FILE"
    cd Others
    OUTPUT=$(git pull)
    if [[ "$OUTPUT" == *"Already up to date."* ]]; then
        echo -e "${GREEN}✅ à jour${RESET}"
        echo "✅ submodule Others à jour" >> "$LOG_FILE"
    elif [[ "$OUTPUT" == *"Updating "* ]]; then
        echo -e "${GREEN}⬆️ mis à jour${RESET}"
        echo "$OUTPUT" >> "$LOG_FILE"
    else
        echo -e "${RED}⚠️ erreur ou message inattendu${RESET}"
        echo "$OUTPUT" >> "$LOG_FILE"
    fi
    cd "$REPO_DIR"
fi

# ↩️ Retour au point de départ
echo "↩️ Retour à $INITIAL_DIR"
echo "↩️ Retour à $INITIAL_DIR" >> "$LOG_FILE"
cd "$INITIAL_DIR" || exit 0

