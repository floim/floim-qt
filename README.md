Pim-Qt
======

A cross-platform native app for Pim.

Binaries
--------

To save you time and effort we've already built some binaries. If your
platform of choice is not supported please raise an issue (or, even
better, suggest a fix!).

 - [Windows][Binary/Windows]  
   After downloading, extract the zip, then:
   1. Install the bundled Visual C++ Redistributable (next next next...)
   2. Install the bundled OpenSSL libraries (next next next...)
   3. Open Pim :)
 - [Mac OS X][Binary/OSX]  
   Unzip, drag to Applications, open.
 - [Linux 32bit][Binary/Linux32] or [Linux 64bit][Binary/Linux64]  
   You may need to install `openssl-dev` or `openssl-devel` to remove
the warning about no OpenSSL support. (Pim only runs over SSL for
security reasons.)

We've not yet had time to wrap these apps in lovely little
installers/packages - sorry!

Building it yourself?
---------------------

Contributions very welcome!

 1. Clone this repo
 2. Download [pim-osx.icns][pim-osx.icns] into the root dir `./`, and [pim.png][pim.png] into `./images/`
 3. Download and install the Qt SDK if you haven't already (v4.8.1+)
 4. You can open `pim-qt.pro` in *Qt Creator*.

[Binary/Linux32]: http://s.p.im/Pim-Qt-Ubuntu-32bit.tgz
[Binary/Linux64]: http://s.p.im/Pim-Qt-Ubuntu-64bit.tgz
[Binary/Windows]: http://s.p.im/Pim-Qt-Win32.zip
[Binary/OSX]: http://s.p.im/Pim-Qt-OSX.zip
[pim.png]: http://s.p.im/pim.png
[pim-osx.icns]: http://s.p.im/pim-osx.icns
