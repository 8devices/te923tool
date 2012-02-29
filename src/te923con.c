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

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "te923_intl.h"
#include "te923con.h"
#include "te923.h"
#include "te923_usb.h"
#include "te923_com.h"

unsigned short debug = 0;


void printData( Te923DataSet_t *data, char *iText ) {
	int i;
	printf( "%d:"  , data->timestamp );
	for ( i = 0; i <= 5; i++ ) {
		if ( data->_t[i] == 0 )  printf( "%0.2f:", data->t[i] );
		else                     printf( "%s:", iText );
		if ( data->_h[i] == 0 )  printf( "%d:", data->h[i] );
		else                     printf( "%s:", iText );
	}
	if ( data->_press == 0 ) printf( "%0.1f:", data->press );
	else                   printf( "%s:", iText );
	if ( data->_uv == 0 ) printf( "%0.1f:", data->uv );
	else                   printf( "%s:", iText );
	if ( data->_forecast == 0 ) printf( "%d:", data->forecast );
	else                   printf( "%s:", iText );
	if ( data->_storm == 0 ) printf( "%d:", data->storm );
	else                   printf( "%s:", iText );
	if ( data->_wDir == 0 ) printf( "%d:", data->wDir );
	else                   printf( "%s:", iText );
	if ( data->_wSpeed == 0 ) printf( "%0.1f:", data->wSpeed );
	else                   printf( "%s:", iText );
	if ( data->_wGust == 0 ) printf( "%0.1f:", data->wGust );
	else                   printf( "%s:", iText );
	if ( data->_wChill == 0 ) printf( "%0.1f:", data->wChill );
	else                   printf( "%s:", iText );
	if ( data->_RainCount == 0 ) printf( "%d", data->RainCount );
	else		       printf( "%s:", iText );
	printf( "\n" );
}



int main( int argc, char **argv ) {
	int i;
	char opt;
	opterr = 0;
	char output = 0;
	char *iText = "";

#ifdef ENABLE_GETTEXT
	setlocale( LC_MESSAGES, "" );
	textdomain( "te923con" );
	bind_textdomain_codeset( "te923con", "UTF-8" );
#endif

	while (( opt = getopt( argc, argv, "sdhvDi:" ) ) != -1 ) {
		switch ( opt ) {
			case 'D':
				debug = 1;
				break;
			case 's':
				output = 1;
				break;
			case 'd':
				output = 2;
				break;
			case 'h':
				usage();
				return 0;
				break;
			case 'i':
				iText = optarg;
				break;
			case 'v':
				printf( gettext( "te923con version %s\n" ), VERSION );
				return 0;
				break;
			case '?':
				if ( optopt == 'i' )
					fprintf( stderr, gettext( "Option -%c requires an argument.\n" ), optopt );
				else if ( isprint( optopt ) )
					fprintf( stderr, gettext( "Unknown option `-%c'.\n" ), optopt );
				else
					fprintf( stderr, gettext( "Unknown option character `\\x%x'.\n" ), optopt );
				return 1;
				break;
		}
	}

	struct usb_dev_handle *devh;
	devh = te923_handle();
	if ( devh == NULL )
		return 1;

	Te923DataSet_t *data;
	data = ( Te923DataSet_t* )malloc( sizeof( Te923DataSet_t ) );
	Te923DevSet_t *status;
	status = ( Te923DevSet_t* )malloc( sizeof( Te923DevSet_t ) );

	switch ( output ) {
		case 0:
			//get life data
			get_te923_lifedata( devh, data );
			printData( data, iText );
			break;
		case 1:
			//get device state
			get_te923_devstate( devh, status );
			printf( "0x%x:0x%x:0x%x:0x%x:0x%x:%d:%d:%d:%d:%d:%d:%d:%d\n",
			        status->SysVer, status->BarVer, status->UvVer, status->RccVer, status->WindVer,
			        status->batteryRain, status->batteryUV, status->batteryWind, status->battery5,
			        status->battery4, status->battery3, status->battery2, status->battery1
			      );
			break;
		case 2:
			//get dump from memory
			data->__src = 0;
			for ( i = 0; i < 208; i++ ) {
				get_te923_memdata( devh, data );
				printData( data, iText );
			}
			break;
	}


	te923_close( devh );
	return 0;
}


