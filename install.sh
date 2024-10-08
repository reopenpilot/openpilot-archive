#!/bin/bash

# Check if branch name is provided
if [ -z "$1" ]; then
  echo "Please provide a branch name as an argument."
  exit 1
fi

BRANCH_NAME=$1

# Check if /data/openpilot directory exists
if [ ! -d "/data/openpilot" ]; then
  read -p "/data/openpilot directory does not exist. This system does not appear to be an openpilot system. Do you want to force installation in the local directory? (y/n): " force_install < /dev/tty
  if [[ $force_install != [yY] ]]; then
    echo "Installation aborted."
    exit 1
  else
    INSTALL_DIR="."
  fi
else
  INSTALL_DIR="/data"
fi

# Execute commands
cd $INSTALL_DIR

# Check if openpilot.bak exists and remove it
if [ -d "openpilot.bak" ]; then
  rm -fr openpilot.bak
fi

# Move the current openpilot to openpilot.bak if it exists
if [ -d "openpilot" ]; then
  mv openpilot openpilot.bak
fi

declare -A REPO_SHORT_NAMES=(
    ["sp"]="sunnypilot/sunnypilot"
    ["dp"]="dragonpilot-community/dragonpilot"
    ["fp"]="FrogAi/FrogPilot"
)

# Check if BRANCH_NAME contains a slash
if [[ "$BRANCH_NAME" == */* ]]; then
  # Extract the short name and the actual branch name
  SHORT_NAME=${BRANCH_NAME%%/*}
  BRANCH_NAME=${BRANCH_NAME#*/}

  # Replace reopenpilot with the corresponding GitHub account name
  if [[ -n "${REPO_SHORT_NAMES[$SHORT_NAME]}" ]]; then
    GITHUB_REPO_URL=${REPO_SHORT_NAMES[$SHORT_NAME]}
    REPO_URL="https://github.com/$GITHUB_REPO_URL.git"
  else
    echo "Unknown short name: $SHORT_NAME. Installation aborted."
    exit 1
  fi
else
  REPO_URL="https://github.com/reopenpilot/openpilot.git"
fi

# Clone the repository
if ! git clone --single-branch $REPO_URL openpilot -b $BRANCH_NAME; then
  echo "Failed to clone the repository. Installation aborted."
  exit 1
fi

cd openpilot
git submodule update --init

# Prompt user for reboot confirmation
read -p "Are you sure you want to reboot the system? (y/n): " confirm < /dev/tty
if [[ $confirm == [yY] ]]; then
  sudo reboot
else
  echo "System reboot has been canceled."
fi