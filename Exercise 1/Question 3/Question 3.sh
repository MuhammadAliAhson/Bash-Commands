#!/bin/bash

# user and administration privilages
create_user() {
    echo "Creating user..."
    sudo useradd -m -s /bin/bash $1
    echo "$1:$2" | sudo chpasswd
    sudo usermod -aG sudo $1
    echo "User $1 is created and administrator privileges are assigned."
}

# all applications
list_apps() {
    echo "Listing installed applications..."
    dpkg -l
}

# Dropbox
install_dropbox() {
    echo "Installing..."
    sudo apt-get update
    sudo apt-get install -y nautilus-dropbox
}

# Function to set IP configuration
set_ip_config() {
    echo "IP configuration..."
    sudo ifconfig eth0 $1 netmask $2
    sudo route add default gw $3
    sudo sed -i '1s/^/nameserver '$4'\n/' /etc/resolv.conf
}

# Main function
main() {
    echo "Muhammad Ali Ahson"

    # Create user
    if [ "$1" == "--uc" ]; then
        read -p "Enter usern: " user
        read -p "Enter passwd: " password
        create_user $user $password
    fi

    # applications
    if [ "$1" == "--ld" ]; then
        list_apps
    fi

    # Dropbox
    if [ "$1" == "--ins" ]; then
        install_dropbox
    fi

    # Set IP
    if [ "$1" == "--ipcon" ]; then
        set_ip_config $2 $3 $4 $5
    fi

    # help
    if [ "$1" == "--help" ]; then
        echo "Usage: ./OS_Assignment_1.sh [OPTIONS]"
        echo "Options:"
        echo "  --uc                  Create a new user and assign administrator privileges."
        echo "  --ld                  List all installed applications."
        echo "  --ins                 Install Dropbox."
        echo "  --ipcon IP MASK GATEWAY DNS  Set IP address, mask, gateway, and DNS."
        echo "  --help                Display this help message."
    fi
}

# Call main function with arguments
main "$@"

