// GameWDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GameW.h"
#include "GameWDlg.h"


///////////////
// MST START
///////////////

#include "General.h"
#include "Combination.h"

///////////////
// MST END
///////////////

//////////////
// MST START
///////////////

// # Defines
#define WON 1
#define LOST 0

#define MAXMEM_REQUESTED 60000

#define MAXCOLS 9
#define MINCOLS 2
#define DEFCOLS 3

#define MAXBASE 100
#define MINBASE 2
#define DEFBASE 10

#define OUTPUTWIDTH 10 //The width of each output field

#define LOSTONLY 0
#define ALL 1
#define ALLWITHLOST 2

#define NORMAL 0
#define BOLD 1

///////////////
// MST END
///////////////


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameWDlg dialog

CGameWDlg::CGameWDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameWDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameWDlg)
	m_uiTotalPositions = 0;
	m_uiBase = 0;
	m_uiColumns = 0;
	m_RadioSetting = -1;
	m_uiLostPositions = 0;
	m_uiMemNeeded = 0;
	m_uiCurrentPosition = 0;
	m_CurrentPositionEdit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameWDlg::DoDataExchange(CDataExchange* pDX)
{
	///////////////
	// MST START
	///////////////

	// To switch on validation, uncomment the two validation lines below

	///////////////
	// MST START
	///////////////

	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameWDlg)
	DDX_Control(pDX, IDC_TOTAL_PROGRESS, m_TotalProgress);
	DDX_Control(pDX, IDC_OUTPUT_LIST, m_OutputListBox);
	DDX_Text(pDX, IDC_TOTAL_EDIT, m_uiTotalPositions);
	DDX_Text(pDX, IDC_BASE_EDIT, m_uiBase);
	DDX_Text(pDX, IDC_COLUMNS_EDIT, m_uiColumns);
	DDX_Radio(pDX, IDC_LOST_RADIO, m_RadioSetting);
	DDX_Text(pDX, IDC_LOST_EDIT, m_uiLostPositions);
	DDX_Text(pDX, IDC_RESERVED_EDIT, m_uiMemNeeded);
	DDX_Text(pDX, IDC_CURRENT_EDIT, m_uiCurrentPosition);
	DDX_Text(pDX, IDC_CURRENTPOSITION_EDIT, m_CurrentPositionEdit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGameWDlg, CDialog)
	//{{AFX_MSG_MAP(CGameWDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, OnExitButton)
	ON_BN_CLICKED(IDC_GO_BUTTON, OnGoButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, OnClearButton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_COLUMNS_SPIN, OnDeltaposColumnsSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_BASE_SPIN, OnDeltaposBaseSpin)
	ON_EN_CHANGE(IDC_BASE_EDIT, OnChangeBaseEdit)
	ON_EN_CHANGE(IDC_COLUMNS_EDIT, OnChangeColumnsEdit)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_ACTIONS_CLEAR, OnClearButton)
	ON_COMMAND(ID_ACTIONS_GOLOST, OnGoButton)
	ON_COMMAND(ID_FILE_EXIT, OnExitButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameWDlg message handlers

BOOL CGameWDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	///////////////
	// MST START
	///////////////

	m_RadioSetting = 0;
	m_uiBase = DEFBASE;
	m_uiColumns = DEFCOLS;
	UpdateData(FALSE);

	///////////////
	// MST END
	///////////////
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGameWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGameWDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGameWDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGameWDlg::OnExitButton() 
{
	// TODO: Add your control notification handler code here

	///////////////
	// MST START
	///////////////

	OnOK();	

	///////////////
	// MST END
	///////////////

}

void CGameWDlg::OnGoButton() 
{
	// TODO: Add your control notification handler code here

	///////////////
	// MST START
	///////////////


	//	OK		 - All went well
	//	NOMEMORY - not enough memory
	//	BADINPUT - A combination was attempted with R > N
	//
	
	
	// START OF INITIALISATION STUFF
	// Initialise a whole lot of stuff each time the Go button is pressed.
	// Remember that it may be pressed after a memory allocation error, so
	// we've got to think if initialising just about everything!
	
	UINT i = 999, j = 999; // General variables
	UINT **ppDataBase; // Pointer to pointer to database of UINTs
	UINT *pPos; // Pointer to the zeroth column of the working position
	UINT uiRetVal = 999; // General return value variable

	bool bLastPosition= WON; // On the first go, bLastPosition
							 // must be initialised to WON

	// Set up a pointer to the lost position increment
	UINT *pIncrement = new UINT;
	*pIncrement = 999;
	
	// Need to check the values of m_uiColumns and m_uiBase
	// In fact, this code is currently redundent because we're doing validation
	// of the UINT so the user will be prompted to change invalid entries. However
	// we'll leave it in anyway, just in case I get bored with automatic
	// validation! (It's a bit unfriendly!)
	// I just got bored with it and commented out the validation!!
	if(! UpdateData(TRUE))
	{
		return; // If crap is entered let the user try again.
	}
	m_uiColumns = (m_uiColumns == 0 ? MINCOLS : m_uiColumns);
	m_uiColumns = (m_uiColumns < MINCOLS ? MINCOLS : m_uiColumns);
	m_uiColumns = (m_uiColumns > MAXCOLS ? MAXCOLS : m_uiColumns);
	
	m_uiBase = (m_uiBase == 0 ? MINBASE : m_uiBase);
	m_uiBase = (m_uiBase < MINBASE ? MINBASE : m_uiBase);
	m_uiBase = (m_uiBase > MAXBASE ? MAXBASE : m_uiBase);

	// Clear the list box first...
	OnClearButton();

	
	// Create a new position. There's a potential memory leak here because
	// we're not checking so see if it's already been created beforehand
	pPos = new UINT[m_uiColumns];

	// Zero all the columns
	for(i = 0; i < m_uiColumns; i++)
	{
		*(pPos + i) = 0;
	}
	// END OF INITIALISATION STUFF


	// Work out how many positions in total there are
	UINT *pCombRes = new UINT;
	uiRetVal = MyCombination((m_uiColumns + m_uiBase - 1), m_uiColumns, pCombRes);
	switch(uiRetVal)
	{
	case OK:
		break;
	case NOMEMORY:
		MessageBox("Pants.\nFunction MyCombination ran out of memory.\nBest to exit because it could be serious!",
			"Big Memory Pants",
			MB_OK + MB_ICONSTOP);
		OnOK(); // Close the window
		return; // Exit the function
		break;
	case BADINPUT:
		MessageBox("Big Pants.\nFunction MyCombination is telling me that there's a bug in the code!\nLet's get out of here...",
			"Coding Error",
			MB_OK + MB_ICONSTOP);
		OnOK(); // Close the window
		return; // Exit the function
		break;
	case OVERFLOW:
		MessageBox ("The MyCombination function has overflowed, which in English means that you've flown past the end of an UINT!\nHave another go...",
			"Bang!",
			MB_OK + MB_ICONSTOP);
		return;  // Exit the function to have another go
		break;
	default:
		MessageBox("Pants.\nFunction MyCombination is grumbling about something.\nBest to exit in case it's a memory problem.",
			"General Gubbins",
			MB_OK + MB_ICONSTOP);
		OnOK(); // Close the window
		return; // Exit the function
		break;
	}


	// Bung it on the screen and set the progress bar range
	m_uiTotalPositions = *pCombRes - 1;
	m_TotalProgress.SetRange(0, m_uiTotalPositions);

	UpdateData(FALSE);


	// Lost or all?
	switch(m_RadioSetting)
	{
	case LOSTONLY:
	case ALLWITHLOST: 
	
		// Allocate enough memory for the database. 
		uiRetVal = MyDbMemoryRequirement(&m_uiMemNeeded);
		// If the memory allocation wasn't OK we dont necessarily need to blow 
		// the program out - we can just exit the Go function to let the user have
		// another go. No need to zero variables first because they might be useful
		// info to the user. (Interestingly, if m_uiMemNeeded != 0 then it means
		// Combination didn't return an error!)
		switch(uiRetVal)
		{
		case OK:
			break;
		case NOMEMORY:
			MessageBox("Pants.\nFunction MyDbMemoryRequirement ran out of memory.\nBest to exit because it could be serious!",
				"Big Memory Pants",
				MB_OK + MB_ICONSTOP);
			OnOK(); // Close the window
			return; // Exit the function
			break;
		case BADINPUT:
			MessageBox("Big Pants.\nFunction MyDbMemoryRequirement is telling me that there's a bug in the code!\nLet's get out of here...",
				"Coding Error",
				MB_OK + MB_ICONSTOP);
			OnOK(); // Close the window
			return; // Exit the function
			break;
		case OVERFLOW:
			MessageBox ("The MyCombination function has overflowed, which in English means that you've flown past the end of an UINT!\nHave another go...",
				"Bang!",
				MB_OK + MB_ICONSTOP);
			return;  // Exit the function to have another go
			break;
		default:
			MessageBox("Pants.\nFunction MyDbMemoryRequirement is grumbling about something.\nBest to exit in case it's a memory problem.",
				"General Gubbins",
				MB_OK + MB_ICONSTOP);
			OnOK(); // Close the window
			return; // Exit the function
			break;
		}
		UpdateData(FALSE); // Put the m_uiMemNeeded on the screen
	
	
		// Check what the memory needed is. If > MAXMEM_REQUESTED shut down!
		if(m_uiMemNeeded > MAXMEM_REQUESTED)
		{
			CString strMessage;
			char strColumns[5];
			char strBase[3];
			char strMemNeeded[10];
			
			itoa(m_uiColumns, strColumns, 10);
			itoa(m_uiBase, strBase, 10);
			itoa(m_uiMemNeeded * sizeof(UINT), strMemNeeded, 10);
	
			strMessage = (CString) "By asking for " +
				strColumns +
				" columns and a base of " +
				strBase +
				", you're asking me to reserve " +
				strMemNeeded +
				" Bytes of memory.\nMy dear chap, it's quite preposterous: pure hokum...";
			MessageBox(strMessage, "Bugger Off", MB_OK + MB_ICONSTOP);
			return; // Exit the function
		}
	
		
		// OK. Lets reserve the memory now we know how much...
		// Note that a failure at this point will not release allocated
		// memory because our clear up stuff is done at the end.
		if((ppDataBase = (UINT **) new UINT[m_uiMemNeeded]) == NULL)
		{
			MessageBox("Out of memory",
				"Memory Error",
				MB_OK + MB_ICONSTOP);
			OnOK();
			return;
		}
		for(i = 0; i < m_uiMemNeeded; i++)
		{
			if((ppDataBase[i] = (UINT *) new UINT[m_uiColumns]) == NULL)
			{
			MessageBox("Out of memory",
				"Memory Error",
				MB_OK + MB_ICONSTOP);
			OnOK();
			return;
			}
		}
	
		// Update the window with the value of m_uiMemNeeded
		UpdateData(FALSE);
	
		// Zero the whole lot of database elements...
		for(i = 0; i < m_uiMemNeeded; i++)
		{
			for(j = 0; j < m_uiColumns; j++)
			{
				*(*(ppDataBase + i) + j) = 0;
			}
		}
	
		// Let's do the work
		// Note that the first call to NextPosition will set it
		// to all zeros except the zeroth column, which will be set
		// to one
	
		switch(m_RadioSetting)
		{
		case LOSTONLY:
			while(MyNextPosition(pPos, bLastPosition, pIncrement))
			{
				MyPrintCurrentPosition(pPos, MYEDITBOX, NORMAL);
				
				m_uiCurrentPosition += *pIncrement;
				UpdateData(FALSE);
	
				bLastPosition = MyCompare(pPos, ppDataBase);
				if(bLastPosition == LOST)
				{
					// Add it to the database of lost positions
					for(i = 0; i < m_uiColumns; i++)
					{
						*(ppDataBase[m_uiLostPositions] + i) = *(pPos + i);
					}
					// Print it out if it's lost
					MyPrintCurrentPosition(ppDataBase[m_uiLostPositions], MYLISTBOX, NORMAL);
					m_uiLostPositions++;
					UpdateData(FALSE);
				}
				// Update the progress bar
				m_TotalProgress.SetPos( (int) m_uiCurrentPosition);
			}
			break;

		case ALLWITHLOST:
			while(MyNextPosition(pPos, bLastPosition, pIncrement))
			{
				MyPrintCurrentPosition(pPos, MYEDITBOX, NORMAL);
				
				m_uiCurrentPosition += *pIncrement;
				UpdateData(FALSE);
	
				bLastPosition = MyCompare(pPos, ppDataBase);
				if(bLastPosition == LOST)
				{
					// Add it to the database of lost positions
					for(i = 0; i < m_uiColumns; i++)
					{
						*(ppDataBase[m_uiLostPositions] + i) = *(pPos + i);
					}
					// Print it out if it's lost
					MyPrintCurrentPosition(ppDataBase[m_uiLostPositions], MYLISTBOX, BOLD);
					m_uiLostPositions++;
					UpdateData(FALSE);
				}
				else
				{
					MyPrintCurrentPosition(pPos, MYLISTBOX, NORMAL);
				}
				// Set the bLastPosition to WON to ensure that we look at all positions
				bLastPosition = WON;
				
				// Update the progress bar
				m_TotalProgress.SetPos( (int) m_uiCurrentPosition);
			}
			break;
		}

		// Let's clear up memory after us!
		delete pPos;

		for(i = 0; i < m_uiMemNeeded; i++)
		{
			delete ppDataBase[i];
		}
		delete ppDataBase;		
		break;

	case ALL: // All positions
		// Let's do the work
		// Note that the first call to NextPosition will set it
		// to all zeros except the zeroth column, which will be set
		// to one
	
		while(MyNextPosition(pPos, bLastPosition, pIncrement))
		{
			MyPrintCurrentPosition(pPos, MYEDITBOX, NORMAL);

			m_uiCurrentPosition++;
			UpdateData(FALSE);
	
			// Print it out and update the progress bar
			MyPrintCurrentPosition(pPos, MYLISTBOX, NORMAL);
			m_TotalProgress.SetPos( (int) m_uiCurrentPosition);
		}
		break;
	}
	
	///////////////
	// MST END
	///////////////
}



// Function name: PrintCurrentPosition
// Return values
//
void CGameWDlg::MyPrintCurrentPosition(UINT *pPos, int iWhereToPrint, int iStyle)
{
	UINT i, j;
	
	char strHolder[MAXBASE];
	CString strTotal = "";

	for(i = m_uiColumns - 1; i > 0; i--) // Don't do column 0 because i is a
										 // UINT and also because we want something
										 // different for the last column
	{
		itoa(*(pPos + i), strHolder, 10);
		// Don't use the CString::Format function because it's buggy
		strTotal += (CString) strHolder;
		for(j = 1; j < (OUTPUTWIDTH - strlen(strHolder)); j++)
		{
			strTotal += " ";
		} 
	}
	// Do column 0 here...
	itoa(*pPos, strHolder, 10);
	strTotal += (CString) strHolder;

	// The string has been created. Let's put it on the screen...
	switch(iWhereToPrint)
	{
	case MYLISTBOX:
		if(iStyle == NORMAL)
		{
			m_OutputListBox.SetCurSel(m_OutputListBox.AddString(strTotal));
		}
		else
		{
			strTotal += " *";
			m_OutputListBox.SetCurSel(m_OutputListBox.AddString(strTotal));
		}
				
		UpdateWindow(); // Send a WM_PAINT message bypassing the message Q.
						// Causes both listbox and edit boxes to update OK.
		// RedrawWindow(); // Completely redraws the whole dialog box! Flashes a
						   // but works OK apart from that.
		// OnPaint(); // Almost same as UpdateWindows, except that the edit boxes
					  // don't get updated during calculations.
		// Invalidate(); // Invalidates the whole dialog: causes buttons to vanish
						 // during calculations, but listbox gets updated OK! Strange.
		break;
	
	case MYEDITBOX:
		m_CurrentPositionEdit = (CString) strTotal;
		UpdateWindow();
		break;
	}

}


// Function name: Compare
// Return values
//	LOST - The position tested is lost
//	WON  - The position tested is won
//
bool CGameWDlg::MyCompare(UINT *pPos, UINT **ppDataBase)
{
	// The placeholder keeps track of whether how many matches are found
	// between the database and the current position
	// No need to do a memory check (excessive)!
	UINT i = 999;
	UINT uiItems = 999;

	UINT iPos = 999, iDbCol = 999, iDbRow = 999;
	UINT uiMatches = 999;
	bool bDone = false;
	bool bPosition = LOST;
	
	int *pPlaceHolder = new int[m_uiColumns];

	// Zero all the placeholders. Use the loop to see if it's the first go.
	for(iPos = 0; iPos < m_uiColumns; iPos++)
	{
		pPlaceHolder[iPos] = 0;
	}


	// If it's the fisrt go: make an exception to the general case. Note that
	// m_uiLostPositions is only zero on the very first go, and it's incremented
	// in OnGoButton().
	if(m_uiLostPositions == 0)
		return (LOST);
	

	// For every other situation...
	// For every row in the database...
	bPosition = LOST;
	for(iDbRow = 0; iDbRow <= (m_uiLostPositions - 1) && bPosition == LOST; iDbRow++)
	{
		uiMatches = 0;
		// For each element of the current position...
		for(iPos = 0; iPos < m_uiColumns; iPos++)
		{
			// Start at the first database column and compare with the current
			// position's element that we're looking at. Of course, if the current
			// position's element that we're looking at has already been matched,
			// don't bother.
			bDone = false;
			for(iDbCol = 0; iDbCol < m_uiColumns && bDone == false; iDbCol++)
			{
				if(*(pPos + iPos) == *(ppDataBase[iDbRow] + iDbCol) && pPlaceHolder[iDbCol] != 1)
				{
					pPlaceHolder[iDbCol] = 1;
					bDone = true;
					uiMatches++;
				}
			}
		}

		// We've been through every element of the current position and there
		// are iMatches. If it's number of columns minus one,
		// the current position is won and there's no point in carrying on.
		// (The outer for loop makes use of this flag.) Otherwise, re-zero the
		// place holders and try again.
		if(uiMatches == (m_uiColumns - 1))
		{
			bPosition = WON;
		}
		else
		{
			for(i = 0; i < m_uiColumns; i++)
			{
				pPlaceHolder[i] = 0;
			}

		}
	}

	return (bPosition);
}


// Function name: DbMemoryRequirement
// Return values
//	Whatever Combination returns with! (Currently...)
//	OK		 - All went well
//	NOMEMORY - not enough memory
//	BADINPUT - A combination was attempted with R > N
//	OVERFLOW - The calculation overflowed a UINT
//
UINT CGameWDlg::MyDbMemoryRequirement(UINT *pMemRequirement)
{
	UINT uiBaseTemp = 999,
		 p = 999;
	
	int i =999,
		iCount = 0;

	// Check that the number of colums are odd. If not, round up.
	UINT uiTempColumns = 999;
	if(m_uiColumns % 2 != 1)
	{
		uiTempColumns = m_uiColumns + 1;
	}
	else
	{
		uiTempColumns = m_uiColumns;
	}

	// Calculate "p"
	uiBaseTemp = m_uiBase - 1;
	while(uiBaseTemp != 1)
	{
		uiBaseTemp /= 2;
		iCount++;
	}
	
	for(i = 1; i <= iCount; i++)
	{
		uiBaseTemp *= 2;
	}
	p = uiBaseTemp;

	// Calculate the number of losing positions.
	// NOTE: this formula only works for odd numbers. Even numbers
	// are assumed to be the next highest odd number. You should be 
	// able to work out what the formula is from the code because the
	// code follows the formula exactly!

	UINT x = 999;
	UINT part1, part2;
	UINT uiTotalSoFar = 0;
	UINT uiRetVal = 999;

	for(x = 1; x <= (uiTempColumns + 1) / 2 ; x++)
	{
		uiRetVal = MyCombination((p + 2 * x - 2), p, &part1);
		if(uiRetVal != OK)
			return (uiRetVal);

		uiRetVal = MyCombination((m_uiBase - p + uiTempColumns - 2 * x), (uiTempColumns + 1 - 2 * x), &part2);
		if(uiRetVal != OK)
			return (uiRetVal);

		uiTotalSoFar += (part1 * part2 / (2 * x - 1));
	}

	// Get ready to send the result back to calling function
	*pMemRequirement = uiTotalSoFar;

	return (OK);
}


// Function name: NextPosition
// Return values
//	bMoreToDo - Boolean telling calling function if there are
//             any more positions
//
bool CGameWDlg::MyNextPosition(UINT *pPos, bool bLastPosition, UINT *pInc)
{

	bool bKeepGoing = true, bMoreToDo = true;
	UINT i = 0, j = 0;

	// If the LastPosition was LOST, there's no point in incrementing
	// the zeroth column, so start with the first column instead.
	*pInc = 1;
	if(bLastPosition == LOST)
	{
		i++;
		*pInc = m_uiBase - *pPos;
	}

	// While we don't finish ...
	while(bKeepGoing == true && bMoreToDo == true)
	{
		// Increment the column being pointed to
		(*(pPos + i))++;
		if(*(pPos + i) != m_uiBase) // If it hasn't gone over the top...
		{
			if(i) // If we're not looking at the zeroth column...
			{
				// Set up a loop to set all earlier columns
				// to the same value as this new one
				for(j = 0; j <= (i - 1); j++)
				{
					*(pPos + j) = *(pPos + i);
				}
			}
			bKeepGoing = false;
		}
		else // If it has gone over the top...
		{
			i++; // Try the next column...
			// Just make sure we're not at the end...
			if(i == m_uiColumns)
			{
				bMoreToDo = false;
				// Set the columns to maximum. Not really needed
				// but it guarantees not getting any higher if this
				// function's return code isn't checked for properly!
				for(i = 0; i < m_uiColumns; i++)
				{
					(*(pPos + i))--;
				}
			}
		}
	}

	return (bMoreToDo);
}

void CGameWDlg::OnClearButton() 
{
	// TODO: Add your control notification handler code here
	
	///////////////
	// MST START
	///////////////

	// This function is called near the start of OnGoButton

	m_OutputListBox.ResetContent();
	m_uiCurrentPosition = 0;
	m_uiLostPositions = 0;
	m_uiMemNeeded = 0;
	m_uiTotalPositions = 0;
	m_TotalProgress.SetPos(0);
	m_CurrentPositionEdit = (CString) "";
	UpdateData(FALSE);

	///////////////
	// MST END
	///////////////
}


void CGameWDlg::OnDeltaposColumnsSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	///////////////
	// MST START
	///////////////
	
	// Firstly, save whatever is in the boxes
	if(! UpdateData(TRUE))
	{
		return;
	}
		
	// pNMUpDown -> iDelta only gives 1 or -1
	switch(pNMUpDown -> iDelta)
	{
	case 1:
		if(m_uiColumns > MINCOLS)
		{
			m_uiColumns--;
			UpdateData(FALSE);
		}
		break;
	case -1:
		if(m_uiColumns < MAXCOLS)
		{
			m_uiColumns++;
			UpdateData(FALSE);
		}
		break;
	}

	///////////////
	// MST END
	///////////////

	*pResult = 0;
}

void CGameWDlg::OnDeltaposBaseSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	///////////////
	// MST START
	///////////////
	
	// Firstly, save whatever is in the boxes
	if(! UpdateData(TRUE))
	{
		return;
	}

	// pNMUpDown -> iDelta only gives 1 or -1
	switch(pNMUpDown -> iDelta)
	{
	case 1:
		if(m_uiBase > MINBASE)
		{
			m_uiBase--;
			UpdateData(FALSE);
		}
		break;
	case -1:
		if(m_uiBase < MAXBASE)
		{
			m_uiBase++;
			UpdateData(FALSE);
		}
		break;
	}

	///////////////
	// MST END
	///////////////

	*pResult = 0;
}

void CGameWDlg::OnChangeBaseEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
	///////////////
	// MST START
	///////////////	

	// I'm not going to update the data on a change because the BN_CHANGE event
	// is sent after the slightest change. Problem is with vaildation of 2 - 100
	// is that if the user tries to input 100, they enter the first 1, which
	// is immediately subject to validation and is declared as invalid!
	// Instead, we'll do an UpdateData when one of the Go or All buttons is
	// pressed.
	// UpdateData(TRUE);

	///////////////
	// MST END
	///////////////	

}

void CGameWDlg::OnChangeColumnsEdit() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here

	///////////////
	// MST START
	///////////////	

	// I'm not going to update the data on a change because the BN_CHANGE event
	// is sent after the slightest change. Problem is with vaildation of 2 - 100
	// is that if the user tries to input 100, they enter the first 1, which
	// is immediately subject to validation and is declared as invalid!
	// Instead, we'll do an UpdateData when one of the Go or All buttons is
	// pressed.
	// UpdateData(TRUE);

	///////////////
	// MST END
	///////////////	

}

void CGameWDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
		
	///////////////
	// MST START
	///////////////	

	// Create a new object of type CAboutDlg
	CAboutDlg dlg;

	// Bung it on the screen as a modal
	dlg.DoModal();

	///////////////
	// MST END
	///////////////	
}
