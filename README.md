# ArpConnector


- performance without a screen, only midi keyboard  (midi controller to access the advanced midi learn features of qmidiarp required)

- screen only required for first time setup (connection between Keyboard, external midi clock, qmidiarp) and advanced configuration required (change of devices)

- autoconnect features: Add ArpConnector to the autostart programs (e.g. from usr/local/bin), ArpConnector starts qmidiarp ready to play in alsa mode (qmidiarp -a) and connects all required alsa midi connections (Keyboard, midi clock, qmidiarp)

- set the clock of qmidiarp to 'midi input' to start and stop qmidiarp via midi controller 

- restart ArpConnector after saving the changes (e.g. changing the path of the qmidiarp file).

REQUIRED

Linux (tested with Debian 9 and 10)

Qt5, qt5-default

build-essential

qmake

GNU Autotools (automake, autoconf, configure, make)

mesa-common-dev

libgl1-mesa-dev, libglu1-mesa-dev

ALSA

libasound2-dev

libasound2

gnome-terminal

qmidiarp


(gtk2: install qt5-style-plugins -> echo "export QT_QPA_PLATFORMTHEME=gtk2" >> ~/.profile)



INSTALL: ./INSTALL.sh



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





