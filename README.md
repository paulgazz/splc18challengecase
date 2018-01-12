# splc18challengecase
Instructions for the SPLC 18 challenge case

## Benchmark Programs and Datasets

### Variability Bugs Database (Abal et. al ASE14)
This is a database of 98 software bugs occurr under specific configurations, i.e., variability bugs. To create this database, Abal et. al (ASE14) mined software repositories of Linux, Busybox, Marlin, and Apache Httpd Server.

The database is in here; http://vbdb.itu.dk/#search
In each entry, there is a table which provides information about the bug like the the specific configurations that are inveolved and type of the bug. To find the configurations that lead to these bugs, there two afternatives you could use in your experiments; **Simplified bug** and **Single function bug**

The entire database can also be downloaded from; https://bitbucket.org/modelsteam/vbdb
This repository containts the simplifies bug snippets and some other tools to evaluate these snippets.


### Axtls
You can work with the latest version of `Axtls` which can be found in here; http://axtls.sourceforge.net
To see list of available configuration options use the command

### Busybox
Buysbox website; https://busybox.net
You can work with the version 1_28_stable which can be found in here; https://git.busybox.net/busybox/snapshot/busybox-1_28_stable.tar.gz
To see list of available configuration options you can check the `.config` file after running `makde defconfig`

### Linux Kernel
You can work with the version linux-stable-4.14.13 which can be found in here; https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
To see list of available configuration options use the command TODO

## Useful Program Analysis Tools

### KMax
KMax can be found in here; https://github.com/paulgazz/kmax. The repository also includes instructions for setup and a running example

### KBuildMiner
KBuildMiner can be found iin here; https://github.com/ckaestne/KBuildMiner

### iTree

### iGen
iGen can be found in here; https://bitbucket.org/nguyenthanhvuh/igen/wiki/Home. The repository also includes instructions for setup and a running example

### GOLEM
GOLEM is a part of a bigger toolchain called **undertaker** which can be found on https://i4gerrit.informatik.uni-erlangen.de/undertaker TODO


## ACM Reference
Paul Gazzillo, Ugur Koc, ThanhVu Nguyen, and Shiyi Wei. 2018. *Localizing Con gurations in Highly-Con gurable Systems*. In Proceedings of 22nd International Conference on Software Product Line (SPLC’18). ACM, New York, NY, USA, 4 pages. https://doi.org/10.1145/nnnnnnn.nnnnnnn
