#!bin/sh
openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=hello.com" -addext "subjectAltName=DNS:hello.com" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
nginx
service mysql restart
echo "CREATE DATABASE wordpress_db;" | mysql
echo "CREATE USER 'lain'@'localhost' IDENTIFIED BY 'lainislain';"| mysql
echo "GRANT ALL PRIVILEGES ON *.* TO 'lain'@'localhost' IDENTIFIED BY 'lainislain' WITH GRANT OPTION;" | mysql
echo "FLUSH PRIVILEGES;" | mysql
chown -R mysql:mysql /var/lib/mysql\
&& service mysql start && service nginx start
service php7.3-fpm start
cd  /var/www/html/phpmyadmin
mkdir tmp && chmod 777 tmp
cd  /var/www/html/
wget wordpress.org/latest.tar.gz
tar xvf latest.tar.gz wordpress
rm -rf latest.tar.gz
cp /wp-config.php wordpress/
mysql --password=lainislain --user=lain wordpress_db < /wordpress_db.sql
cd 
sh
