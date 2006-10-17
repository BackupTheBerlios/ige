#include "IGEMainApplication.h"
#include "IGEMainApplicationFrame.h"
#include "IGEMangaloreManager.h"
//nebula:mangalore
#include "application/statehandler.h"
#include "application/gamestatehandler.h"
#include "properties/videocameraproperty.h"
#include "properties/lightproperty.h"
#include "properties/graphicsproperty.h"
#include "properties/physicsproperty.h"
#include "managers/entitymanager.h"
#include "managers/factorymanager.h"
#include "managers/focusmanager.h"
//nebula
#include "gui/nguiserver.h"
#include "gui/nguiwindow.h"
#include "gui/nguilabel.h"
#include "gui/nguitextlabel.h"
#include "kernel/nfileserver2.h"
#include "physics/materialtable.h"
#include "physics/level.h"
#include "scene/nsceneserver.h"

using namespace IGE;
using namespace Application;

MangaloreManager* MangaloreManager::mInstance = 0;

MangaloreManager* MangaloreManager::Instance()
{
	return MangaloreManager::mInstance;
}

bool MangaloreManager::Open()
{
	mInstance = this;

	if( App::Open() )
	{
		// mangalore::app::gui hardcoded fix
		nGuiServer* guiServer = nGuiServer::Instance();
		guiServer->SetDisplaySize(vector2(float(GetDisplayMode().GetWidth()), float(GetDisplayMode().GetHeight())));

		return true;
	}

	return false;
}

void MangaloreManager::SetupFromProfile()
{
	nDisplayMode2 mode;
    nString windowTitle = "illusion graphics editor";
    mode.SetWindowTitle(windowTitle.Get());
    mode.SetXPos(0);
    mode.SetYPos(0);
	// use command line or default command line values.
	mode.SetWidth(MainApplication::Instance()->GetRenderWinWidth());
    mode.SetHeight(MainApplication::Instance()->GetRenderWinHeight());
	mode.SetType(nDisplayMode2::ChildWindow);
    mode.SetVerticalSync(false);
    mode.SetDialogBoxMode(false);
    mode.SetIcon("Icon");
    this->SetDisplayMode(mode);

	this->AttachRenderWindow();
}

void MangaloreManager::OnFrame()
{
	MainApplication::Instance()->Update();
}

void MangaloreManager::SetupStateHandlers()
{
    Ptr<Application::GameStateHandler> gameStateHandler = n_new( Application::GameStateHandler );
    gameStateHandler->SetName( "Game" );
    gameStateHandler->SetExitState( "Exit" );

	gameStateHandler->SetSetupMode( Application::GameStateHandler::NewGame );

    this->AddStateHandler( gameStateHandler );
    this->SetState( "Game" );
}

void MangaloreManager::AttachRenderWindow()
{
	nEnv* env;

	if( (env =(nEnv*)nKernelServer::Instance()->New("nenv","/sys/env/parent_hwnd")) )
 	{
		void* nebulaWindowHandle = MainApplication::Instance()->GetRenderWindow()->GetHandle();
		env->SetI( (int)nebulaWindowHandle );
	}	
}