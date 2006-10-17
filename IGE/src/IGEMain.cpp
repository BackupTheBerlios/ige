///////////////////////////////////////////////////////////////////////////////
// Name:        IGEMain.cpp
// Purpose:     Main Application Entry
// Author:      Joe Espindola
// Modified by:
// Created:     10.05.2006
// RCS-ID:      $Id: IGEMain.cpp,v 1.1 2006/10/17 13:35:47 gramulho Exp $
// Copyright:   (c) 2006 Joe Espindola <gramulho@hotmail.com>
// Licence:     LGPL
///////////////////////////////////////////////////////////////////////////////

#include "IGEMainApplication.h"
#include "tools/ncmdlineargs.h"

int main(int argc, const char **argv)
{
	nCmdLineArgs args(argc, argv);

	IGE::MainApplication* mMainApplication = new IGE::MainApplication();
	mMainApplication->setApplicationArguments( args );

	delete mMainApplication;

	return 0;
}