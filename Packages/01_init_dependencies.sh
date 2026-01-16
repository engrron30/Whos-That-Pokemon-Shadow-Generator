#!/bin/bash

# === Constants ===
REQUIRED_PACKAGES=(
  libx11-dev
  libxrandr-dev
  libxi-dev
  libxinerama-dev
  libxcursor-dev
  libgl1-mesa-dev
  libudev-dev
  libasound2-dev
  libpulse-dev
  libdrm-dev
)

# === Functions ===
is_package_installed() {
  dpkg -s "$1" &> /dev/null
}

check_missing_packages() {
  MISSING=()
  echo "🔍 Checking for required packages..."
  for pkg in "${REQUIRED_PACKAGES[@]}"; do
    if is_package_installed "$pkg"; then
      echo "[INSTALLED] $pkg"
    else
      echo "[MISSING] $pkg (about to install...)"
      MISSING+=("$pkg")
    fi
  done
}

install_missing_packages() {
  if [ ${#MISSING[@]} -eq 0 ]; then
    echo "✅ All required packages are already installed!"
    return
  fi

  echo "📦 Installing missing packages: ${MISSING[*]}"
  sudo apt update
  sudo apt install -y "${MISSING[@]}"
}

# === Main ===
main() {
  check_missing_packages
  install_missing_packages
}

main "$@"

