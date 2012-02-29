/***************************************************************************
 *   Copyright (C) 2009 by Sebastian John   *
 *   basti@fukz.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#define VERSION 	"0.4"


void usage() {
	printf( gettext( "te923con, connector for TE923 weatherstations v%s - (c) by Sebastian John 2009 (basti@fukz.de)\n" ),
	        VERSION );
	printf( gettext( "This program is free software, distributed under the terms of the GNU General Public Licens.\n\n"));
	printf( gettext( "usage: te923con [options]\n" ) );
	printf( gettext( "  -D - Debug output to find errors or send to developer\n" ) );
	printf( gettext( "  -d - dump all values from internal memory\n" ) );
	printf( gettext( "  -s - get status from weatherstation\n" ) );
	printf( gettext( "  -i - set the output for invalid values (unreachable sensors)\n" ) );
	printf( gettext( "  -h - print this help informations\n" ) );
	printf( gettext( "  -v - print version number of this program\n" ) );
	printf( "\n" );
	printf( gettext( "Output format is colon separatet values. Invalid values or values from not present sensors\n" ) );
	printf( gettext( "are hidden by default. You can set output with -i option. For weatherdata is:\n\n" ) );
	printf( gettext( "T0:H0:T1:H1:T2:H2:T3:H3:T4:H4:T5:H5:PRESS:UV:FC:STORM:WD:WS:WG:WC:RC\n\n" ) );
	printf( gettext( "  T0    - temperature from internal sensor in °C\n" ) );
	printf( gettext( "  H0    - humidity from internal sensor in %% rel\n" ) );
	printf( gettext( "  T1..5 - temperature from external sensor 1..4 in °C\n" ) );
	printf( gettext( "  H1..5 - humidity from external sensor 1...4 in %% rel\n" ) );
	printf( gettext( "  PRESS - air pressure in mBar\n" ) );
	printf( gettext( "  UV    - UV index from UV sensor\n" ) );
	printf( gettext( "  FC    - station forecast, see below for more details\n" ) );
	printf( gettext( "  STORM - stormwarning; 0 - no warning, 1 - fix your dog \n" ) );
	printf( gettext( "  WD    - wind direction in n x 22.5°; 0 -> north\n" ) );
	printf( gettext( "  WS    - wind speed in m/s\n" ) );
	printf( gettext( "  WG    - wind gust speed in m/s\n" ) );
	printf( gettext( "  WC    - windchill temperature in °C\n" ) );
	printf( gettext( "  RC    - rain counter (maybe since station starts measurement) as value\n" ) );
	printf( "\n" );
	printf( gettext( "    weather forecast means (as precisely as possible)\n" ) );
	printf( gettext( "      0 - heavy snow\n" ) );
	printf( gettext( "      1 - little snow\n" ) );
	printf( gettext( "      2 - heavy rain\n" ) );
	printf( gettext( "      3 - little rain\n" ) );
	printf( gettext( "      4 - cloudy\n" ) );
	printf( gettext( "      5 - some clouds\n" ) );
	printf( gettext( "      6 - sunny\n" ) );
	printf( "\n" );
	printf( gettext( "For status od the station is:\n\n" ) );
	printf( gettext( "SYSSW:BARSW:EXTSW:RCCSW:WINSW:BATR:BATU:BATW:BAT5:BAT4:BAT5:BAT2:BAT1\n\n" ) );
	printf( gettext( "  SYSSW  - software version of system controller\n" ) );
	printf( gettext( "  BARSW  - software version of barometer\n" ) );
	printf( gettext( "  EXTSW  - software version of UV and channel controller\n" ) );
	printf( gettext( "  RCCSW  - software version of rain controller\n" ) );
	printf( gettext( "  WINSW  - software version of wind controller\n" ) );
	printf( gettext( "  BATR   - battery of rain sensor (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BATU   - battery of UV sensor (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BATW   - battery of wind sensor (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BAT5   - battery of sensor 5 (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BAT4   - battery of sensor 4 (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BAT3   - battery of sensor 3 (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BAT2   - battery of sensor 2 (1-good (not present), 0-low)\n" ) );
	printf( gettext( "  BAT1   - battery of sensor 1 (1-good (not present), 0-low)\n" ) );
	printf("\n");
	printf( gettext( "For updates, bugfixes and support visit http://www.fukz.de.\n"));
	printf( gettext( "Special thanks to Ivo Schooneman for Dutch translation.\n\n"));
}
