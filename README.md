# Run SunOS 4.1.1 on TME Sun3/160 emulator

If you want to run SunOS 4.1.1 but don't have the resources and/or desire to own a real Sun3 then this is the repo for you.

## Jumpstarting

### The TME stuff

This repo comes with TME 0.8 which is the last version from the original developers.  If you want to use a different TME that's fine. Here's a link to the [TME development website](https://osdn.net/projects/nme/).

I like to put unpackaged software in a new subdirectory for it (and only it) under /opt instead of /usr/local. That way removing the package just requires removing that directory instead of trying to track down all the co-mingled files under /usr/local. If you are using SilverBlue or a similar distro you can substitute /usr/lib for /opt since /usr/lib is writable.

I had to [hack](https://github.com/PDP-10/its/blob/master/doc/humor/jargon.68#L778) the configure script because it's very doubtful that you can still convert configure.in to configure because of autoconf improvements causing `configure.in` to suffer from [bitrot](https://github.com/PDP-10/its/blob/master/doc/humor/jargon.68#L1358).  Fortunately it's just a very small change to make it link with `libX11.a`

The `configure.in` has
```
dnl Checks for X11.
AC_PATH_XTRA
```
But that doesn't seem to work. Maybe it worked in the past or maybe there's some incantation that makes it work now but I don't know so I just made this change.
```
$ diff -u configure.orig configure
--- configure.orig	2023-04-27 14:10:21.168561841 -0400
+++ configure	2023-04-27 14:14:09.473876973 -0400
@@ -12352,7 +12352,7 @@

   if test x"$no_gtk" = x ; then
     GTK_CFLAGS=`$PKG_CONFIG $pkg_config_args --cflags`
-    GTK_LIBS=`$PKG_CONFIG $pkg_config_args --libs`
+    GTK_LIBS="`$PKG_CONFIG $pkg_config_args --libs` -lX11"
     gtk_config_major_version=`$PKG_CONFIG --modversion gtk+-2.0 | \
            sed 's/\([0-9]*\).\([0-9]*\).\([0-9]*\)/\1/'`
     gtk_config_minor_version=`$PKG_CONFIG --modversion gtk+-2.0 | \
```
If there are missing package dependencies they will show up in the ./configure output.

At the least you will need the base development and GTK 2 packages.

### for Debian/Ubuntu/Mint
`sudo apt install build-essential libgtk2.0-dev`

### for Fedora
`sudo dnf group install "C Development Tools and Libraries" "Development Tools"`
`sudo dnf install gtk2-devel`

### for Arch
`yay -S base-devel gtk2`
or
`sudo pacman -S base-devel gtk2`
```
sudo mkdir /opt/tme  # or make some other directory
sudo chown $USER /opt/tme # to your personal account instead of the root account
cd tme-0.8_up
./configure --disable-shared --disable-warnings --enable-ltdl-install --prefix=/opt/tme # or use --prefix= set to some other directory
make
make install
cd ..
```
Note that the Ethernet MAC address for the emulated Sun3 is set in the mkroms script. You can edit that script.  Admittedly this repo doesn't provide instructions on gettng network to function at all.
```
./mkroms
```
Make a file for the emulated disk. By using the seek option to dd a [sparse file](https://wiki.archlinux.org/title/sparse_file) will be created.
```
dd if=/dev/zero of=sun3-disk.img bs=1 count=1 seek=999999999
```

You can read and/or edit TME configuration file, SUN3, to see if what it does and make any changes you like.

## The SunOS bits

The mklinks script will create symbolic links with numbers for names. That way the path names in the TME config files will be shorter in the SUN3 configuration file.  Also the sequence of the numbers matches what's in the ancient maketape1 and maketape2 scripts.
```
cd sunos411
./mklinks
cd ..
```
# Travel to mini-root land
Note that the TME emulator window depends on the size (resolution) of your screen. It will scale down to fit your screen and if your screen is too small the emulator window will be very small.
```
./run-tme SUN3
```
Because the disk image file is a blank disk, you will see some messages about "No label found" and "Device not found". You can ignore them. Once this disk is prepared they will no longer happen.

You should be at the boot prompt.  To boot from the tape drive use:

`> b st()`

There will be a warning about the clock gaining many days. This is because the time-of-day has advanced that many days since the system image was created back in the 1980s.

Note that the backspace key has to be a real ASCII 127 (DEL) so you can type the Delete key to backspace.  Using Ctrl-U will erase all the input you typed back to the beginning of the line (but not any further back).

At the menu select option `1  - install SunOS mini-root`

At the menu select option `1 - yes, run format`

At the menu select `disk` and press Enter to select disk 0 which is the only one.

None of the supplied disk types are big enough to hold all of SunOS 4.1.1:
```
Micropolis 1304  42 MB
Micropolis 1325  69 MB
Maxtor XT-1050   38 MB
Fujitsu M2243AS  71 MB
Vertex V185      71 MB
```
If you make a custom disk type it can be larger.

At the menu select `5. other`
```
Enter number of data cylinders: 2046
Enter number of alternate cylinders [2]:
Enter number of physical cylinders [2048]:
Enter number of heads: 16
Enter number of data sectors/track: 16
Enter rpm of drive [3600]:
Enter buffer skew [2]:
Enter write precomp cylinder [2048]:
Enter disk type name (remember quotes): Awesome
selecting sd0: <Awesome>
[disk formatted, no defect list found]
No defined partition tables.
```
disk partition sizes:
```
   Start  Length
a    0    156 cyl is about  20 MB (root) # blocks 39936
b  157    122 cyl is about  32 MB (swap) # blocks 32940
c    0   2046 cyl is about 512 MB (all ) # blocks 523776
g  278   1768 cyl is about 442 MB (/usr) # blocks 452608
```
Enter the partitioner and use these values:
```
format> partition

partition> a
Enter new starting cyl [0]:
Enter new # blocks [0, 0/0/0]; 39936

Repeat that for all of these values:

part  cyl   blocks
a       0    39936
b     157    40960
c       0   523776
g     317   442624
```
You can use the `print` command to see the partition table.
You can use `?` to display the menu.
```
partition> name
Enter table name (remember quotes): awesome
```
When you are satisfied that the partition table is correct, label the disk.
```
partition> label
Ready to label disk, continue? y

partition> quit
format> quit
```
The mini-root will automatically be installed into the swap partition.  Because you have to overwrite the real root file system, putting the mini-root in the swap enables avoids the mini-root being overwritten.  Because the system will not be running very much software swapping and/or paging will not happen and that prevents the mini-root file system from being overwritten by swapping and paging activity.

Select option 1 - reboot using the just-installed miniroot

Welcome to the mini-root.  At this point you can install SunOS.

You need to know the time zone because the installer will ask for it. In the emulator window (not the tmesh prompt) look under /usr/share/lib/zoneinfo/ for more options. The time zone information is old, sorry if the options don't include your locale. These work `US/Pacific` `US/Eastern`  `EST5EDT`.  If it's hopeless try something like `GMT+2` where +2 is the offset from GMT. Try if nothing is suitable `GMT` or `UTC` and just accept that.

To start the installation of SunOS run:

`# suninstall`

The quick installer doesn't understand the disk type so choose the custom installation.

Good luck filling out all the forms (screens).  There are menu prompts and a help system.  A copy of `800-3812-10A_Installing_the_SunOS_4.0.3_198904.pdf` is in the docs folder of this repo.  I haven't found a copy of the SunOS 4.1.1 installation but the 4.0.3 version should provide some help.

If or when it asks for the second tape, see the part about tapes near the end of the SUN3 configuration file.  You can use commands at the `tmesh>` prompt without stopping and starting the emulator.  To switch to the second tape:
```
tmesh> command tape0 unload
tmesh> command tape0 load sunos411/30 sunos411/30 sunos411/31 sunos411/32 sunos411/33 sunos411/34 sunos411/35 sunos411/36 sunos411/37 sunos411/38
```
