# ArpConnector


- performance without a screen, only midi keyboard  (midi controller to access the advanced midi learn features of qmidiarp required)

- screen required for first time setup (connection between Keyboard, external midi clock, qmidiarp) and advanced configuration required (change of devices)

- autoconnect features: Add ArpConnector to the autostart programs (e.g. from usr/local/bin), ArpConnector starts qmidiarp ready to play in alsa mode (qmidiarp -a) and connects all required alsa midi connections (Keyboard, midi clock, qmidiarp)

- please set the clock of qmidiarp to 'midi input' to start and stop qmidiarp via midi controller 

- please restart ArpConnector after saving changes (e.g. changing the path of the qmidiarp file).

- required: libasound2-dev, (gnome-terminal)

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

Please read the license of the ALSA library inside of the ALSA folder.


INSTALL


qmake  
mv Makefile Makefile.am  
aclocal  
automake --add-missing --foreign  
autoconf  
mv Makefile.am Makefile  
./configure  
make  


(Create configure.ac file: 
AC_INIT([AtpConnector], 0.x.0) 
AM_INIT_AUTOMAKE 
AC_PROG_CC 
AC_CONFIG_FILES(Makefile) 
AC_OUTPUT )

