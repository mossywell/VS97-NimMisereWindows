// GameW.h : main header file for the GAMEW application
//

#if !defined(AFX_GAMEW_H__A8DFD7C7_903A_11D1_9B98_000407C10000__INCLUDED_)
#define AFX_GAMEW_H__A8DFD7C7_903A_11D1_9B98_000407C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGameWApp:
// See GameW.cpp for the implementation of this class
//

class CGameWApp : public CWinApp
{
public:
	CGameWApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGameWApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEW_H__A8DFD7C7_903A_11D1_9B98_000407C10000__INCLUDED_)
