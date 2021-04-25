from debian:buster

#Exposing ports that may be used
EXPOSE 80 443

#Setting ENVIRENEMENT VARIABLE [export DEBIAN_FRONTEND=noninteractive]
ENV		DEBIAN_FRONTEND noninteractive

#Auto selection for mysql-5.7
RUN		echo "mysql-apt-config mysql-apt-config/select-server select mysql-5.7" | debconf-set-selections

#install user needs and primary server dependencies
RUN		apt-get update &&\
		apt-get -y upgrade &&\
		apt-get -y install vim nginx php7.3 php7.3-fpm wget lsb-release gnupg php-mysql 

#install mysql-server --version 5.7
RUN 	wget https://dev.mysql.com/get/mysql-apt-config_0.8.14-1_all.deb \
		&& dpkg -i mysql-apt-config_0.8.14-1_all.deb \
		&& apt-get update \
		&& rm -rf mysql-apt-config_0.8.14-1_all.deb 

RUN		apt-get -y install mysql-server

#install remaining server dependecies
RUN		apt-get -y install php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip

RUN		apt install -y php-mbstring  \
		&& wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz \
		&& tar xvf phpMyAdmin-4.9.2-all-languages.tar.gz \
		&& mv phpMyAdmin-4.9.2-all-languages/ /var/www/html/phpmyadmin \
		&& rm -rf phpMyAdmin-4.9.2-all-languages.tar.gz

COPY    srcs/wp-config.php /
COPY    srcs/wordpress_db.sql /
COPY 	srcs/script.sh  /
COPY    srcs/default /etc/nginx/sites-available/
COPY    srcs/config.inc.php /var/www/html/phpmyadmin/
RUN 	chmod 777 script.sh

CMD	["sh", "script.sh"]