#include "IGEMainApplicationFrame.h"
#include "IGEMainApplication.h"
#include "IGEMangaloreManager.h"

using namespace IGE;

MainApplicationFrame* MainApplicationFrame::mInstance = 0;

MainApplicationFrame::MainApplicationFrame()
: wxFrame( NULL, wxID_ANY, "Illusion Graphics Previs Editor",
		  wxPoint( 0, 0 ), wxSize( 1024, 768 ),
		  wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxMAXIMIZE )
{
	mInstance = this;
}

MainApplicationFrame::~MainApplicationFrame()
{
	this->Close();
}

MainApplicationFrame* MainApplicationFrame::Instance()
{
	return MainApplicationFrame::mInstance;
}

void MainApplicationFrame::startFrame()
{
	mMenuBar = new wxMenuBar();

	mFileMenu = new wxMenu;
	mFileMenu->Append( wxID_EXIT, wxT("&Exit"), wxEmptyString );
	mMenuBar->Append( mFileMenu, wxT("&Editor") );

	wxFrame::SetMenuBar( mMenuBar );
	wxFrame::SetBackgroundColour( wxColour( 0, 0, 0 ) );
}

void MainApplicationFrame::closeMainFrame( wxCommandEvent& event )
{
	// exit only through mangalore
	MangaloreManager::Instance()->RequestState("Exit");
}

BEGIN_EVENT_TABLE( MainApplicationFrame, wxFrame )
	EVT_MENU( wxID_EXIT, MainApplicationFrame::closeMainFrame )
END_EVENT_TABLE()
