# ArpConnector

ArpConnector turns a mini computer like raspberry pi into a live performance alsa-qmidiarp box, which requires no screen (tested with raspberry pi 3 and Ubuntu Mate).

- performance without a screen, only midi keyboard  (midi controller to access the advanced midi learn features of qmidiarp required)

- screen only for first time setup (connection between Keyboard, external midi clock, qmidiarp) and advanced configuration required (change of devices)

- autoconnect features: Add ArpConnector to the autostart programs (e.g. from usr/local/bin), ArpConnector starts qmidiarp ready to play in alsa mode (qmidiarp -a) and connects all required alsa midi connections (Keyboard, midi clock, qmidiarp)

- please set the clock of qmidiarp to midi input to start and stop qmidiarp via midi controller 

- please restart ArpConnector after saving changes (e.g. changing the path of the qmidiarp file).

- required: libasound2-dev

ArpConnector: Copyright (c) 2016 A. Klumpp

// *  This program is free software; you can redistribute it and/or modify
// *  it under the terms of the GNU General Public License as published by
// *  the Free Software Foundation; either version 2 of the License, or
// *  (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// *  GNU General Public License for more details.
// *
// *  You should have received a copy of the GNU General Public License
// *  along with this program; if not, write to the Free Software
// *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
// *

Please also read the license of the alsa library inside of the alsa folder.


INSTALL


[[1.1) Create makefile for Qt source (execute commands and create files inside of gnulocsys-1.9.5 folder)
qmake
1.1.1) Edit makefile
-remove absolute paths:
old: /home/username/gnulocsys
new: gnulocsys
-add $(DESTDIR) and remove local in install path:
old: @test -d $(INSTALL_ROOT)/usr/local/bin 
new: @test -d $(INSTALL_ROOT)$(DESTDIR)/usr/bin 
1.2) Create configure file
1.2.1) Create configure.ac file:
AC_INIT([gnulocsys], 1.9.5)
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_CONFIG_FILES(Makefile)
AC_OUTPUT
1.2.2) Rename Makefile into Makefile.am
1.2.3) aclocal
1.2.4) automake --add-missing --foreign
1.2.5) autoconf
1.2.6) Rename Makefile.am into Makefile]]

1.3) If makefile is already available Configure: make, make install

1.3.1
./configure

1.3.2
make

1.3.3 (optional)
sudo make install
