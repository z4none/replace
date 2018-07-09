# replace

A text replacing tool for windows console.

usage:

```
$ replace test.txt ${foo} "world"
hello, world!!
```

```
$ replace my.ini.template ${path} "D:\mysql" > my.ini
```

content of my.ini.template:

```
[mysqld]
port=3306
server-id=1
innodb_buffer_pool_size=64M
innodb_log_file_size=16M
character-set-server=utf8
basedir=${path}
datadir=${path}/data
max_connections=50
```