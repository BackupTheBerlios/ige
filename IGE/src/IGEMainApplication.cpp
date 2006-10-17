#include "IGEMainApplication.h"
#include "IGEMainApplicationFrame.h"
#include "IGEMangaloreManager.h"
#include "wx/wx.h"

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_OPTION, "rww", "rwwidth", "render window width" },
    { wxCMD_LINE_OPTION, "rwh", "rwheight", "render window height" },

    { wxCMD_LINE_OPTION, "rwx", "rwposx", "render window pos x" },
    { wxCMD_LINE_OPTION, "rwy", "rwposy", "render window pos y" },

    { wxCMD_LINE_OPTION, "rwt", "rwtitle", "render window title" },

    { wxCMD_LINE_NONE }
};

using namespace IGE;

MainApplication* MainApplication::mInstance = 0;

MainApplication* MainApplication::Instance()
{
	return MainApplication::mInstance;
}

void MainApplication::parseCmds()
{
	wxCmdLineParser parser(argc,argv);
	parser.SetDesc(cmdLineDesc);
	parser.Parse();

	wxString rwWidth, rwHeight;
	wxString rwPosx, rwPosy;
	wxString rwTitle;

	if( !parser.Found( "rww", &rwWidth ) )
		rwWidth = wxString("640");
	if( !parser.Found( "rwh", &rwHeight ) )
		rwHeight = wxString("480");

	if( !parser.Found( "rwx", &rwPosx ) )
		rwPosx = wxString("0");
	if( !parser.Found( "rwy", &rwPosy ) )
		rwPosy = wxString("40");

	if( !parser.Found( "rwt", &rwTitle ) )
		rwTitle = wxString("ige - render window");

	rwWidth.ToDouble(&renderWinWidth);
	rwHeight.ToDouble(&renderWinHeight);
	rwPosx.ToDouble(&renderWinPosx);
	rwPosy.ToDouble(&renderWinPosy);
	title = rwTitle;
}

bool MainApplication::OnInit()
{
	mInstance = this;

	parseCmds();

	wxImage::AddHandler( new wxPNGHandler );
	wxBitmap bitmap;
	if(bitmap.LoadFile("illusionintro.png", wxBITMAP_TYPE_PNG))
	{
		this->splash = new wxSplashScreen( bitmap,
			wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_NO_TIMEOUT,
			0, NULL, -1, wxDefaultPosition, wxDefaultSize,
			wxSIMPLE_BORDER|wxSTAY_ON_TOP );
	}
	this->Yield();

	mMainApplicationFrame = new MainApplicationFrame();
	mMainApplicationFrame->startFrame();

	mRenderWindow = new wxMiniFrame( mMainApplicationFrame, wxID_ANY, title,
										wxPoint( int(renderWinPosx), int(renderWinPosy) ), wxSize( int(renderWinWidth), int(renderWinHeight) ),
										wxCAPTION | wxNO_BORDER,
										wxEmptyString );

	mMangaloreManager = new MangaloreManager();

	this->SetTopWindow( mMainApplicationFrame );

	return true;
}

int MainApplication::MainLoop()
{
	if( mMangaloreManager->Open() )
	{
		// delete splash screen after everything has been loaded
		delete this->splash;
		// only show the windows after nebula and mangalore has been created
		mMainApplicationFrame->Show(true);
		mRenderWindow->Show(true);

		// start the app loop
		mMangaloreManager->Run();
	}

	// shutdown
	mMangaloreManager->Close();

	delete mMangaloreManager;
	delete mMainApplicationFrame;

	return 0;
}

wxWindow* MainApplication::GetRenderWindow()
{
	return (wxWindow*)mRenderWindow;
}

int MainApplication::GetRenderWinWidth()
{
	return (int)renderWinWidth;
}

int MainApplication::GetRenderWinHeight()
{
	return (int)renderWinHeight;
}

void MainApplication::Update()
{
	//windows stuff back to wxwidgets
	MSG msg;

	if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
			TranslateMessage(&msg);                    
			DispatchMessage(&msg);
	}
}

DECLARE_APP( MainApplication );
IMPLEMENT_APP( MainApplication );
