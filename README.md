# splc18challengecase
Instructions for the SPLC 18 challenge case

## Benchmark Programs and Datasets

### Variability Bugs Database (Abal et. al ASE14)
This is a database of 98 software bugs occurring only under specific configurations, i.e., variability bugs. To create this database, Abal et. al (ASE14) studied software repositories of Linux, Busybox, Marlin, and Apache Httpd Server.

The database is in here: http://vbdb.itu.dk/#search

In each entry, there is a table providing detailed information of the bug, such as the bug type and specific configurations that are involved. To find the configurations that lead to these bugs, there are two afternatives you could use in your experiments: **Simplified bug** and **Single function bug**

The entire database can also be downloaded from https://bitbucket.org/modelsteam/vbdb

### Axtls
The latest version of `Axtls` is available: http://axtls.sourceforge.net

To see list of available configuration options use the command TODO

### Busybox
Buysbox website: https://busybox.net

You can work with the version 1_28_stable which can be found in here: https://git.busybox.net/busybox/snapshot/busybox-1_28_stable.tar.gz

To see list of available configuration options you can check the `.config` file after running `makde defconfig`.

### Linux Kernel
linux-stable-4.14.13 which can be found in here: https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git

To see list of available configuration options use the command TODO

## Useful Program Analysis Tools

### KMax
KMax can be found in here: https://github.com/paulgazz/kmax

### KBuildMiner
KBuildMiner can be found iin here: https://github.com/ckaestne/KBuildMiner

### iTree

### iGen
iGen can be found in here: https://bitbucket.org/nguyenthanhvuh/igen/wiki/Home

### GOLEM
GOLEM is a part of a bigger toolchain called **undertaker** which can be found at: https://i4gerrit.informatik.uni-erlangen.de/undertaker TODO


## References
Paul Gazzillo, Ugur Koc, ThanhVu Nguyen, and Shiyi Wei. 2018. *Localizing Configurations in Highly-Configurable Systems*. 2018.
