/**************************************************************************
 *									  *
 * 		 Copyright (C) 2000, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/*
 * renderhints.h - $Revision: 1.1 $
 */

#ifndef __RENDERHINTS_H__
#define __RENDERHINTS_H__

#include "types.h"

class Renderhints {
public:
    			Renderhints( void );
    void		init( void );
    int			isProperty( long );
    REAL 		getProperty( long );
    void		setProperty( long, REAL );

    REAL 		display_method;		/* display mode */
    REAL 		errorchecking;		/* activate error checking */
    REAL 		subdivisions;		/* maximum number of subdivisions per patch */
    REAL 		tmp1;			/* unused */

    int			displaydomain;
    int			maxsubdivisions;
    int			wiretris;
    int			wirequads;
};

#endif /* __RENDERHINTS_H__ */
