// GameWDlg.h : header file
//

///////////////
// MST START
///////////////

#define MYLISTBOX 1
#define MYEDITBOX 2

///////////////
// MST END
///////////////


#if !defined(AFX_GAMEWDLG_H__A8DFD7C9_903A_11D1_9B98_000407C10000__INCLUDED_)
#define AFX_GAMEWDLG_H__A8DFD7C9_903A_11D1_9B98_000407C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGameWDlg dialog

class CGameWDlg : public CDialog
{
// Construction
public:
	CGameWDlg(CWnd* pParent = NULL);	// standard constructor

	///////////////
	// MST START
	///////////////

	bool MyNextPosition(UINT *pPos, bool bLastPosition, UINT *pIncrement);
	UINT MyDbMemoryRequirement(UINT *pMemRequirement);
	bool MyCompare(UINT *pPos, UINT **ppDataBase);
	void MyPrintCurrentPosition(UINT *pPos, int WhereToPrint, int PrintStyle);

	///////////////
	// MST END
	///////////////

// Dialog Data
	//{{AFX_DATA(CGameWDlg)
	enum { IDD = IDD_GAMEW_DIALOG };
	CProgressCtrl	m_TotalProgress;
	CListBox	m_OutputListBox;
	UINT	m_uiTotalPositions;
	UINT	m_uiBase;
	UINT	m_uiColumns;
	int		m_RadioSetting;
	CString	m_CurrentPositionEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameWDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	///////////////
	// MST START
	///////////////

	HICON m_hIcon;
	UINT	m_uiCurrentPosition;
	UINT	m_uiLostPositions;
	UINT	m_uiMemNeeded;

	///////////////
	// MST END
	///////////////

	// Generated message map functions
	//{{AFX_MSG(CGameWDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExitButton();
	afx_msg void OnGoButton();
	afx_msg void OnClearButton();
	afx_msg void OnDeltaposColumnsSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposBaseSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeBaseEdit();
	afx_msg void OnChangeColumnsEdit();
	afx_msg void OnHelpAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEWDLG_H__A8DFD7C9_903A_11D1_9B98_000407C10000__INCLUDED_)
