# ft_server

![logo](https://upload.wikimedia.org/wikipedia/commons/7/79/Docker_%28container_engine%29_logo.png)

## Description

This statement is intended to introduce you to basic system and network administration. 
It will allow you to install a complete web server, thanks to a deployment technology called Docker.

### Components

- ```Nginx```: Is an HTTP and reverse proxy server, a mail proxy server, and a generic TCP/UDP proxy server.

- ```MariaDB```: Is a database management system derived from MySQL with a GPL (General Public License).

- ```Wordpress```: Is a CMS(Content Managament System) focused on the creation of any type of web page.

- ```phpMyAdmin```: Is a free software tool intended to handle the administration of MySQL over the web.


### Technologies

- ```Docker```: Is a open-source project that automates the deployment of applications within software containers.

- ```OpenSSL```: Is a robust, commercial-grade, and full-featured toolkit for the (TLS) and (SSL) protocols. Allows create digital certificates that can work on a server.

- ```Diffie-Hellman``` cryptographic protocol: Is a protocol for establishing keys between parties that have not had previous contact, using an insecure channel and anonymously.

---

### Installation

> Step 1: Update System and Install Required Packages

```shell
# Before installing any software, you need to update and upgrade the system you are working on.
sudo apt-get update -y
sudo apt-get upgrade -y
# Also, make sure to install (or check whether you already have) the following required packages:
sudo apt-get install curl
sudo apt-get install apt-transport-https
sudo apt-get install ca-certificates
sudo apt-get install software-properties-common
```

> Step 2: Install Docker

```shell
# First add the GPG key for the official Docker repository to your system.
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
# Add the Docker repository to APT sources.
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu focal stable"
# Next, update the package database with the Docker packages from the newly added repo.
sudo apt update
# Make sure you are about to install from the Docker repo instead of the default Ubuntu repo.
apt-cache policy docker-cesudo
# Finally, install Docker.
sudo apt-get install docker-ce
# Docker should now be installed, the daemon started, and the process enabled to start on boot.
# Check that it’s running.
sudo systemctl status docker
# To avoid typing sudo whenever you run the docker command, add your username to the docker group:
sudo usermod -aG docker $(whoami);
# To apply the new group membership, log out of the server and back in, or type the following.
su - ${USER}
# You will be prompted to enter your user’s password to continue.
# Confirm that your user is now added to the docker group by typing.
id -nG
# Using docker consists of passing it a chain of options and commands followed by arguments.
docker [option] [command] [arguments]
# To view all available subcommands, type:
docker
```

### Usage

```shell
# Download
git clone https://github.com/parismart/ft_server.git
cd ft_server
# Create image
docker build . -t ft_server
# Launch container
docker run -it -p 80:80 -p 443:443 -e AUTOINDEX=on --name ft_server ft_server bash
# Launch WebBrowser
https://localhost/
```

---

## References

- Learn Docker - [NetworkChuck](https://www.youtube.com/watch?v=eGz9DS-aIeY&ab_channel=NetworkChuck)
- Curso Docker - [Fazt Code](https://www.youtube.com/watch?v=NVvZNmfqg6M&t=1987s&ab_channel=FaztCode)
- Dockerfile reference - [Docker Documentation](https://docs.docker.com/engine/reference/builder/)
- Installing MariaDB - [MariaDB](https://mariadb.com/kb/en/getting-installing-and-upgrading-mariadb/)
- PHP Manual - [Command line usage](https://www.php.net/manual/en/features.commandline.options.php)

---