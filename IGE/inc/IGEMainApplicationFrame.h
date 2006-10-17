///////////////////////////////////////////////////////////////////////////////
// Name:        IGEMainApplicationFrame.h
// Purpose:     wxWidgets Application TOP Frame
// Author:      Joe Espindola
// Modified by:
// Created:     10.05.2006
// RCS-ID:      $Id: IGEMainApplicationFrame.h,v 1.1 2006/10/17 13:35:47 gramulho Exp $
// Copyright:   (c) 2006 Joe Espindola <gramulho@hotmail.com>
// Licence:     LGPL
///////////////////////////////////////////////////////////////////////////////


#ifndef IGEMAINAPPLICATIONFRAME
#define IGEMAINAPPLICATIONFRAME

//ige
#include "IGEIncludes.h"
//wxwidgets
#include "wx/wx.h"
#include "wx/frame.h"
#include "wx/menu.h"
#include "wx/menuitem.h"

namespace IGE
{
	class MainApplicationFrame : public wxFrame
	{
	public:
		MainApplicationFrame();
		~MainApplicationFrame();
		static MainApplicationFrame* Instance();

		void startFrame();

	protected:
		DECLARE_EVENT_TABLE()

		void closeMainFrame( wxCommandEvent& event );

	private:
		static MainApplicationFrame* mInstance;

		wxMenuBar* mMenuBar;
		wxMenu* mFileMenu;

	};
}

#endif