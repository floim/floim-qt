Floim-Qt
======

A cross-platform native app for Floim.

Binaries
--------

To save you time and effort we've already built some binaries. If your
platform of choice is not supported please raise an issue (or, even
better, suggest a fix!).

 - [Windows][Binary/Windows]
   After downloading, extract the zip, then:
   1. Install the bundled Visual C++ Redistributable (next next next...)
   2. Install the bundled OpenSSL libraries (next next next...)
   3. Open Floim :)
 - [Mac OS X][Binary/OSX]
   Unzip, drag to Applications, open.
 - [Linux 32bit][Binary/Linux32] or [Linux 64bit][Binary/Linux64]
   You may need to install `openssl-dev` or `openssl-devel` to remove
the warning about no OpenSSL support. (Floim only runs over SSL for
security reasons.)

We've not yet had time to wrap these apps in lovely little
installers/packages - sorry!

Building it yourself?
---------------------

Contributions very welcome!

 1. Clone this repo
 2. Download [floim-osx.icns][floim-osx.icns] into the root dir `./`, and [floim.png][floim.png] into `./images/`
 3. Download and install the Qt SDK if you haven't already (v4.8.1+)
 4. You can open `Floim.pro` in *Qt Creator*.

[Binary/Linux32]: http://s.floim.com/Floim-Qt-Ubuntu-32bit.tgz
[Binary/Linux64]: http://s.floim.com/Floim-Qt-Ubuntu-64bit.tgz
[Binary/Windows]: http://s.floim.com/Floim-Qt-Win32.zip
[Binary/OSX]: http://s.floim.com/Floim-Qt-OSX.zip
[floim.png]: http://s.floim.com/floim.png
[floim-osx.icns]: http://s.floim.com/floim-osx.icns
