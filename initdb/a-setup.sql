CREATE DATABASE IF NOT EXISTS DARKEDEN;
CREATE DATABASE IF NOT EXISTS USERINFO;

CREATE USER 'elcastle'@'%' IDENTIFIED BY 'elca110';
GRANT ALL PRIVILEGES ON DARKEDEN.* TO 'elcastle'@'%';
GRANT ALL PRIVILEGES ON USERINFO.* TO 'elcastle'@'%';
