# SPLC18 Challenge Case Documentation

Instructions for retrieving the target systems for the SPLC 18 challenge case by Paul Gazzillo, Ugur Koc, ThanhVu Nguyen, and Shiyi Wei.

See the call for challenge cases here: http://splc2018.net/call-for-papers/call-for-challenge-cases/

See our paper describing the challenge here: TBD

## Benchmark Programs and Datasets

### Variability Bugs Database (Abal et. al ASE14)
This is a database of 98 software bugs occurring only under specific configurations, i.e., variability bugs. To create this database, Abal et. al (ASE14) studied software repositories of Linux, Busybox, Marlin, and Apache Httpd Server.

The online database is in here: http://vbdb.itu.dk/#search

In each entry, there is a table providing detailed information of the bug, such as the bug type and specific configurations that are involved. To find the configurations that lead to these bugs, there are two afternatives you could use in your experiments: **Simplified bug** and **Single function bug**

In this repository, we provide a processed version of this database to be used for the easy challenge (under the **vbdb** directory). For Linux, Busybox, and Marlin, we modified the code snippets under the simple directory to fix some compilation issues and to make the bug easier to observe (by adding assertions etc.). Moreover, for these programs, we also *include options_list.txt* files which include list of options that appear in all bug reports of that program. You should use these lists as the configuration space.

### Axtls
The latest version of `Axtls` is available: http://axtls.sourceforge.net

To see list of available configuration options you can check the `config/.config` file after running `make allyesconfig`. An example `.config` file can be found under **examples** directory

### Busybox
Buysbox website: https://busybox.net

You can work with the version 1_28_stable which can be found in here: https://git.busybox.net/busybox/snapshot/busybox-1_28_stable.tar.gz

To see list of available configuration options you can check the `.config` file after running `make defconfig`.

### Linux Kernel
linux-stable-4.14.13 which can be found in here: https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git

To see list of available configuration options you can check the `.config` file after running `make allyesconfig`.


## Configuring the Target Systems

For the variability bugs database source files, `gcc -E -D CONFIG_VAR1 -D CONFIG_VAR2 ...` can be used to configure the source code with the C preprocessor.

To configure axTLS, BusyBox, and Linux, first run `allyesconfig` (or `defconfig`).  Then replace the `.config` file with the one from your solution program's output and run `make oldconfig`.  The system is now ready to be built with `make` under the new configuration.


## Useful Program Analysis Tools

### KMax
KMax can be found in here: https://github.com/paulgazz/kmax

### KBuildMiner
KBuildMiner can be found iin here: https://github.com/ckaestne/KBuildMiner

### iTree

Contact authors of iTree paper (ICSE2014).

### iGen
iGen can be found in here: https://bitbucket.org/nguyenthanhvuh/igen/wiki/Home

### GOLEM
GOLEM is a part of a bigger toolchain called **undertaker** which can be found at: https://i4gerrit.informatik.uni-erlangen.de/undertaker


## References
Paul Gazzillo, Ugur Koc, ThanhVu Nguyen, and Shiyi Wei. 2018. *Localizing Configurations in Highly-Configurable Systems*. 2018.
