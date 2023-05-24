


##  Bash Script (Question 3)

This Bash script provides various functionalities related to user administration, application management, IP configuration, and more. It can be executed with different command-line options to perform specific tasks. Below is an overview of the available options and their respective functionalities:

## User Administration

### Option: `--uc`
- Description: Create a new user and assign administrator privileges.
- Usage: `--uc`
- Example: `./OS_Assignment_1.sh --uc`
- Prompts for the username and password of the new user.
- Creates a new user account, sets the password, and assigns administrator privileges.

## Application Management

### Option: `--ld`
- Description: List all installed applications.
- Usage: `--ld`
- Example: `./OS_Assignment_1.sh --ld`
- Displays a list of all installed applications using the `dpkg -l` command.

### Option: `--ins`
- Description: Install Dropbox.
- Usage: `--ins`
- Example: `./OS_Assignment_1.sh --ins`
- Updates the package list using `apt-get update`.
- Installs the Dropbox package (`nautilus-dropbox`) using `apt-get install`.

## IP Configuration

### Option: `--ipcon`
- Description: Set IP address, subnet mask, default gateway, and DNS server.
- Usage: `--ipcon IP MASK GATEWAY DNS`
- Example: `./OS_Assignment_1.sh --ipcon 192.168.0.100 255.255.255.0 192.168.0.1 8.8.8.8`
- Configures the network interface (`eth0`) with the provided IP address, subnet mask, default gateway, and DNS server.
- Updates the `/etc/resolv.conf` file with the specified DNS server.

## Help

### Option: `--help`
- Description: Display help information.
- Usage: `--help`
- Example: `./OS_Assignment_1.sh --help`
- Displays a help message with usage instructions and a description of all available options.

## Execution

To execute the script, open a terminal and navigate to the directory containing the script file. Then, use the following command:

```
./OS_Assignment_1.sh [OPTIONS]
```

Replace `[OPTIONS]` with the desired option according to the functionalities mentioned above.

**Note:** The script requires root privileges for certain operations. Make sure to run the script as a superuser or with sudo privileges.


## Copyright Notice:

This script is created by Muhammad Ali Ahson. It is provided as-is without any warranty. If you find this script useful, please show your appreciation by including an acknowledgment or attribution when using or distributing this code.

Your support and recognition are greatly appreciated!

Author: Muhammad Ali Ahson





