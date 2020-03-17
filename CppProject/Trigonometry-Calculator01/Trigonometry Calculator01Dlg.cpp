
// Trigonometry Calculator01Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Trigonometry Calculator01.h"
#include "Trigonometry Calculator01Dlg.h"
#include "afxdialogex.h"
#include <iomanip>
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace std;

int ORDER_NUM = 10;  //麦克劳林展开的阶数


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTrigonometryCalculator01Dlg 对话框



CTrigonometryCalculator01Dlg::CTrigonometryCalculator01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRIGONOMETRYCALCULATOR01_DIALOG, pParent)
	, m_editNUM(0)
	, m_editResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrigonometryCalculator01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM_EDIT, m_editNUM);
	DDX_Text(pDX, IDC_CAL_EDIT, m_editResult);
}

BEGIN_MESSAGE_MAP(CTrigonometryCalculator01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SIN_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedSinButton)
	ON_BN_CLICKED(IDC_COS_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedCosButton)
	ON_BN_CLICKED(IDC_TAN_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedTanButton)
	ON_BN_CLICKED(IDC_COT_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedCotButton)
	ON_BN_CLICKED(IDC_QUIT_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedQuitButton)
	ON_BN_CLICKED(IDC_CLC_BUTTON, &CTrigonometryCalculator01Dlg::OnBnClickedClcButton)
END_MESSAGE_MAP()


// CTrigonometryCalculator01Dlg 消息处理程序

BOOL CTrigonometryCalculator01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTrigonometryCalculator01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTrigonometryCalculator01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTrigonometryCalculator01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//求n的阶乘函数
LONG64 factorial(int n)    //7！就会超出int所能表示的范围，故要用long64
{
	LONG64 y = 1;
	for(int i = 1; i <= n; i++)
		y = y * i;
	return y;
}

void CTrigonometryCalculator01Dlg::OnBnClickedSinButton()
{
	// TODO: 计算sin函数
	// 将各控件中的数据保存到相应的变量   
	UpdateData(TRUE);

	//根据麦克劳林展开式计算sin函数
	m_editResult = 0;
	for (int i = 1; i <= ORDER_NUM; i++)
	{
		m_editResult += pow(-1, i - 1) * pow(m_editNUM, 2 * i - 1) / factorial(2 * i - 1);
	}		
		
	//m_editResult = sin(m_editNUM);

	// 根据各变量的值更新相应的控件，让输出结果编辑框显示m_editResult的值   
	UpdateData(FALSE);
}


void CTrigonometryCalculator01Dlg::OnBnClickedCosButton()
{
	// TODO: 计算cos函数
}


void CTrigonometryCalculator01Dlg::OnBnClickedTanButton()
{
	// TODO: 计算tan函数
}


void CTrigonometryCalculator01Dlg::OnBnClickedCotButton()
{
	// TODO: 计算cot函数
}


void CTrigonometryCalculator01Dlg::OnBnClickedQuitButton()
{
	// TODO: 退出窗口
	DestroyWindow();
}


void CTrigonometryCalculator01Dlg::OnBnClickedClcButton()
{
	// TODO: 清零结果框
	m_editResult = 0;
	UpdateData(FALSE);

}
