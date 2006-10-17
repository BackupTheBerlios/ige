///////////////////////////////////////////////////////////////////////////////
// Name:        IGEMangaloreManager.h
// Purpose:     A manager to handle Mangalore and Nebula objects. Similar to App class.
// Author:      Joe Espindola
// Modified by:
// Created:     10.05.2006
// RCS-ID:      $Id: IGEMangaloreManager.h,v 1.1 2006/10/17 13:35:47 gramulho Exp $
// Copyright:   (c) 2006 Joe Espindola <gramulho@hotmail.com>
// Licence:     LGPL
///////////////////////////////////////////////////////////////////////////////

#ifndef IGEMANGALOREMANAGER
#define IGEMANGALOREMANAGER

//ige
#include "IGEIncludes.h"
//nebula:mangalore
#include "application/app.h"
#include "application/statehandler.h"
#include "application/gamestatehandler.h"

namespace IGE
{
	class MangaloreManager : public Application::App
	{
	public:
		static MangaloreManager* Instance();

		virtual bool Open();
		virtual void SetupFromProfile();
		virtual void OnFrame();

	protected:
		virtual void SetupStateHandlers();
		void AttachRenderWindow();
		
	private:
		static MangaloreManager* mInstance;

	};
}

#endif