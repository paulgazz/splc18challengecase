# SPLC18 Challenge Case Documentation

Instructions for retrieving the target systems for the SPLC 18 challenge case by Paul Gazzillo, Ugur Koc, ThanhVu Nguyen, and Shiyi Wei.

See the call for challenge cases here: http://splc2018.net/call-for-papers/call-for-challenge-cases/

See our paper describing the challenge here: http://splc2018.net/wp-content/uploads/2018/02/SPLC18_Challenge_Case4.pdf

## Benchmark Programs and Datasets

### Easy - Variability Bugs Database (Abal et. al ASE14)
This is a database of 98 software bugs occurring only under specific configurations, i.e., variability bugs. To create this database, Abal et. al (ASE14) studied software repositories of Linux, Busybox, Marlin, and Apache Httpd Server.

The online database is in here: http://vbdb.itu.dk/#search. In each entry, there is a table providing detailed information of the bug, such as the bug type and specific configurations that are involved. To find the configurations that lead to these bugs, there are two afternatives you could use in your experiments: **Simplified bug** and **Single function bug**

In this challenge, you are asked to find configrations for each the variability bug location in *Linux, Busybox*, and *Marlin*. Here, we provide a processed version of this database under the **vbdb** directory. For these programs, we modified the code snippets under the simple directory to resolve some compilation issues and to make the bug easier to observe (by adding assertions etc.). Moreover, for these programs, we also *include options_list.txt* files which include list of options that appear in all bug reports of that program. You should use these lists as the configuration space.

The *all_locations.txt* file contain all bug locations in question in this challenge.

#### Testing

Once you come up with a configuration for a variability bug with your approach, you can test it by preprocessing  the program with the configration flags that appear in the configration you generated + the *-E* flag. I.e.,

`gcc -E -Denabled_config_option1 -Denabled_config_option2 ... simple_code_snippet.c`

This will generate pre-processeed c file. In this c file, you should see the bug location. However, having this location does not necessarily mean the bug is actually in there (in some cases). To test this, you can actually compile the program

`gcc -Denabled_config_option1 -Denabled_config_option2 ... simple_code_snippet.c -o a.out`

Then, if running *a.out* results in the error mentioned in the database, this means you found a configuration which leads to the variability bug (in some cases, your config might differ from what is reported in the database).

### Medium - Axtls
The latest version of `Axtls` is available: http://axtls.sourceforge.net

To see list of available configuration options you can check the `config/.config` file after running `make allyesconfig`. An example `.config` file can be found under **examples** directory

### Hard - Busybox
Buysbox website: https://busybox.net

You can work with the version 1_28_stable which can be found in here: https://git.busybox.net/busybox/snapshot/busybox-1_28_stable.tar.gz

To see list of available configuration options you can check the `.config` file after running `make defconfig`.

### Ultimate - Linux Kernel
linux-stable-4.14.13 which can be found in here: https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git

To see list of available configuration options you can check the `.config` file after running `make allyesconfig`.


## Configuring the Target Systems

For the variability bugs database source files, `gcc -E -D CONFIG_VAR1 -D CONFIG_VAR2 ...` can be used to configure the source code with the C preprocessor.

To configure axTLS, BusyBox, and Linux, first run `allyesconfig` (or `defconfig`).  Then replace the `.config` file with the one from your solution program's output and run `make oldconfig`.  The system is now ready to be built with `make` under the new configuration.

## Evaluation

The solution programs will be evaluated on an 8-core, 2.90GHz processor with 32GB of RAM running a Linux distribution.  The challenge evaluation period is about three weeks, so solution that cannot finish in a substantially.  Please let the evaluation committee know of any special computing resource requirements (special machinery, runs requiring more than a day, etc).

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
