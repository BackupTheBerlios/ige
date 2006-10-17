///////////////////////////////////////////////////////////////////////////////
// Name:        IGEMainApplication.h
// Purpose:     wxWidgets automatically calls the wxApp OnInit
// Author:      Joe Espindola
// Modified by:
// Created:     10.05.2006
// RCS-ID:      $Id: IGEMainApplication.h,v 1.1 2006/10/17 13:35:47 gramulho Exp $
// Copyright:   (c) 2006 Joe Espindola <gramulho@hotmail.com>
// Licence:     LGPL
///////////////////////////////////////////////////////////////////////////////

#ifndef IGEMAINAPPLICATION
#define IGEMAINAPPLICATION

//ige
#include "IGEIncludes.h"
#include "IGEMangaloreManager.h"
//wxwidgets
#include "wx/wx.h"
#include "wx/app.h"
#include "wx/minifram.h"
#include "wx/cmdline.h"
#include "wx/window.h"
#include "wx/splash.h"

namespace IGE
{
	class MainApplication : public wxApp
	{
	public:
		static MainApplication* Instance();

		virtual bool OnInit();
		virtual int MainLoop();

		void Update();

		wxWindow* GetRenderWindow();

		int GetRenderWinWidth();
		int GetRenderWinHeight();

	protected:
		void parseCmds();

	private:
		static MainApplication* mInstance;
		MainApplicationFrame* mMainApplicationFrame;

		//command line arguments result
		double renderWinWidth;
		double renderWinHeight;
		double renderWinPosx;
		double renderWinPosy;
		wxString title;

		MangaloreManager* mMangaloreManager;
		wxMiniFrame* mRenderWindow;

		wxSplashScreen* splash;
		
	};
}

#endif