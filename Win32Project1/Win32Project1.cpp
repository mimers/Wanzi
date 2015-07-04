// Win32Project1.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Win32Project1.h"

#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
ULONG_PTR gdiplusStartupToken;
UINT PNG_IDS[] = { IDB_PNG1, IDB_PNG2, IDB_PNG3, IDB_PNG4, IDB_PNG5, IDB_PNG6, IDB_PNG7,
	IDB_PNG8, IDB_PNG9, IDB_PNG10, IDB_PNG11, IDB_PNG12, IDB_PNG13, IDB_PNG14};
#define PNG_ID_COUNT sizeof(PNG_IDS)/sizeof(UINT)

LPCTSTR WanziYuLu[] = { _T("和朋友复习——只是一种不看书的借口而已。"),
	_T("一个鸭蛋下面长四条腿，就算鸟了。"),
	_T("不是为了零食，而是为了吃零食。"),
	_T("与其过别人的节，不如睡自己的觉。"),
	_T("丸尾被惭愧之河冲走了。"),
	_T("为什么连感冒病毒也不愿意理我呢?"),
	_T("他们根本不明白什么叫日常对话！"),
	_T("像这种没头脑的孩子才会自作自受。"),
	_T("只要活着，一定会遇上好事的。"),
	_T("听人夸奖原来这么舒服啊。"),
	_T("呀来不及了，鬼屋在向我招手啦！"),
	_T("咱们还是小孩呢!不必这么装模作样吧!"),
	_T("唉!星期天居然下雨，老天爷真的是瞎眼了。"),
	_T("喂，不要随便插话，你以为你是周星弛呀!"),
	_T("在关键时候，爷爷并不一定能保护你！"),
	_T("在有档次的餐厅吃饭，却尽说些没档次的话，如果盘子里的鱼听到，没死也得给气死了。"),
	_T("外婆的另一个名字叫零花钱。"),
	_T("大概只有贫穷的家庭，才会为这点小事高兴半天吧(羡慕吧!)"),
	_T("太贵了，只有和妈妈一起，才可以吃。"),
	_T("女人就喜欢胡思乱想，好听点说叫心细如法，另一种说法叫庸人自扰!"),
	_T("如果人的一生只吃松软的食物，不要求别的，那真是会后悔呀！"),
	_T("如果光吃菜营养就好的话，为什么还要吃肉呢？"),
	_T("如果和女生比的话，男生中傻瓜好象比较多。"),
	_T("妈妈!如果那位叔叔被车撞死了，我会开心的!"),
	_T("妈妈澄丽：一个女孩子没有点诽闻多可怜啊!"),
	_T("妈妈澄丽：孩子他爸，演戏也不用这样吧？"),
	_T("晚上陪我一起吃饭吧！睡觉也是！"),
	_T("妈妈要是不高兴，会把你多少年前的糗事一股脑端出来，人称“精神原子弹”。"),
	_T("妈妈！如果那位叔叔被车撞死了，我会开心的！"),
	_T("姐姐的心一下子冰冷起来。"),
	_T("姐姐美子：......在伊甸园里有棵苹果树，可是上帝却不让他们吃树上的果子。 小丸子：上帝为什么要这样?只是个苹果而已，好小气啊。 姐姐美子：我也不明白了!也许上帝也喜欢吃苹果，所以不愿意给人吃吧。"),
	_T("小丸子指着爸爸弘志,打扮得像忙人，其实最会偷懒。"),
	_T("小丸子：啊——男人真可恶！男人真可恶！姐姐：拜托你的语气不要像没人要的老女人一样好不好！小丸子：没人要？姐姐：就是没有好男人喜欢。"),
	_T("小丸子：姐姐，你有多少私房钱？姐姐幸子：不要打听别人的隐私！"),
	_T("小丸子：我们姐妹要骨肉分离了吗？姐姐美子：等将来结婚的时候我们也会分开的，做了女人就是这样的了。"),
	_T("小丸子：我去年写的愿望，三个月内就实现了。爸爸弘志：哦？你写的是什么愿望？小丸子：我希望长高1cm，就真的高了。"),
	_T("小丸子：我想拆掉这个闹钟。当年爱迪生就经常这样呢。 爷爷友藏：好呀，小丸子越来越伟大了!"),
	_T("小丸子：早上的空气多么清新。姐姐美子：每天都这么清新！你刚知道呀！"),
	_T("小丸子：爷爷也会作诗？我怎么不知道？爷爷友藏：我经常在心里作。"),
	_T("小丸子：爸爸怎么走来走去，不干正事？爸爸弘志：我是在为你操心才要走来走去！"),
	_T("小丸子：爸爸，你想要什么吗？别客气，告诉我吧！爸爸弘志：最想要的，就是小丸子的成绩更好。小丸子：不要老说些不着边际的话嘛！想想用钱能解决的。"),
	_T("小丸子：特大新闻！我们今天要吃法国大餐。姐姐幸子：胡说！小丸子：真的！不骗你！姐姐幸子：难道吃完后就全家自杀吗？"),
	_T("小丸子：该死的爷爷！爷爷：小孩子能用这么难的词语，真厉害！"),
	_T("小孩子总是惯用撒娇的手法来体会大人现在的心情如何。"),
	_T("小孩子总要给大人一点面子。"),
	_T("小时候，迟到的理由总是被戳穿，而长大以后，就有办法了......生理痛啊没想到迟到那么简单......"),
	_T("小玉：别这样抱它(流浪狗)，传染出感情就糟了!"),
	_T("小玉：别这样抱它（流浪狗），传染出感情就糟了！"),
	_T("心满意足享受每一点快乐，是走向幸福的唯一途径。"),
	_T("怎么看她都像都像咖喱酱包上面画的印度人，那个印度人好象叫甘地。"),
	_T("总要给大人一点面子。"),
	_T("我一直以为牛郎这个男人，是个对女孩子完全没有感觉的人，所以只有织女这么一个女友......"),
	_T("我以为夏天还早着呢!怪不得压岁钱都花光了。"),
	_T("我以为夏天还早着呢！怪不得压岁钱都花光了。"),
	_T("我对电视节目一直都有自己独特的品位。"),
	_T("我很单纯，最擅长丢掉包袱，绽开笑容。"),
	_T("我的日记只写到八月三号……现在已经是三十一号了"),
	_T("我纯真的心，由于牛排饭而欢呼不已。"),
	_T("我还以为是傻瓜呢，原来是一家人……毕竟是亲人，笨都笨到一块去了！"),
	_T("拿小孩子的话那么当真，爸爸真不像话。"),
	_T("摔跤虽然疼，但是看着别人一起摔，疼痛似乎也被人分担了一些！"),
	_T("摔跤虽然疼，但看着别人一起摔，似乎疼痛也被人分担了一些！"),
	_T("新年是个圈套，小孩子联合起来痛宰大人，哈哈。"),
	_T("春游开不开心，关键看车上的座位啦。"),
	_T("最可气的是这盆丝瓜。哎，全班只有我种得这么难看，还没完没了往上爬。其实我根本就没怎么理它。居然还没有死。"),
	_T("民主当然要忍受自己看不惯的事了，不然会被人当成野狗乱汪汪。"),
	_T("求求你啦……就依我一回吧！以后我再也不烦你们了，连丈夫都可以自己找！"),
	_T("爷爷友藏：人世太过硬邦邦是不好的。"),
	_T("爷爷，我和你一样笨，也挺好。"),
	_T("爸爸弘志：人真多呀！小丸子：他们可能是家里没有装空调，所以来乘凉的。"),
	_T("爸爸要是没有更好的工作，以后就给我当司机吧！"),
	_T("爸爸：和女人约会，你不失约，她怎么会对你印象深刻呢？"),
	_T("看爸爸不爱说话，以为他多有内涵。"),
	_T("老师只来坐15分钟，用不着这么打扫吧，他又不是首相？！"),
	_T("脾气不能够不发，宁可丢坏书本，不能憋坏身体！"),
	_T("虚弱的笑声是康复的标志。"),
	_T("虽然我做的好事不算多，也别这么折腾人呀。"),
	_T("让我睡觉吧！反正已经来不及了！"),
	_T("话这么多，我记不住。"),
	_T("说“芝麻开门”也不行的！这个童话不知会让多少小孩子上当！"),
	_T("这么差的骗术……怎么没人管？——因为警察只抓老实人。"),
	_T("这也太贵了点，只有和妈妈一起，才可以吃。"),
	_T("那么不知羞耻，一定活得很轻松呀!")};
#define WANZI_YULU_COUNT sizeof(WanziYuLu) / sizeof(LPCSTR)
#define IDR_EXIT 3000
#define IDR_LIKE 3001
#define IDR_ABOUT 3002
UINT pngIndex = 0;
UINT YuluIndex = 0;
HMENU hTrayMenu;

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
template<typename T>
VOID				DisorderArray(T *array, UINT size);
UINT				nextPngIndex();
LPCTSTR				nextYulu();

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;
	
	//AllocConsole();
	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDS_APP_TITLE, szWindowClass, MAX_LOADSTRING);
	Gdiplus::GdiplusStartupInput gdiInput;
	Gdiplus::GdiplusStartup(&gdiplusStartupToken,&gdiInput,NULL);
	DisorderArray(PNG_IDS, PNG_ID_COUNT);
	DisorderArray(WanziYuLu, WANZI_YULU_COUNT);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	
	//FreeConsole();
	return (int) msg.wParam;
}

template<typename T>
VOID DisorderArray(T *array, UINT size)
{
	srand(GetCurrentTime());
	for (UINT i = size - 1; i > 0; i--)
	{
		UINT target = rand() % i;
		T t = array[target];
		array[target] = array[i];
		array[i] = t;
	}

}

UINT nextPngIndex()
{
	pngIndex++;
	if (pngIndex == PNG_ID_COUNT)
	{
		pngIndex = 0;
	}
	return PNG_IDS[pngIndex];
}

LPCTSTR nextYulu()
{
	YuluIndex++;
	if (YuluIndex == WANZI_YULU_COUNT)
	{
		YuluIndex = 0;
	}
	return WanziYuLu[YuluIndex];
}

BOOL ImageFromIDResource(HINSTANCE hInst, UINT nID, LPCTSTR sTR, Gdiplus::Image * &pImg)
{
	HRSRC hRsrc = ::FindResource (hInst,MAKEINTRESOURCE(nID),sTR); // type
	if (!hRsrc)
		return FALSE;
	// load resource into memory
	DWORD len = SizeofResource(hInst, hRsrc);
	BYTE* lpRsrc = (BYTE*)LoadResource(hInst, hRsrc);
	if (!lpRsrc)
		return FALSE;
	// Allocate global memory on which to create stream
	HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
	BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
	memcpy(pmem,lpRsrc,len);
	IStream* pstm;
	CreateStreamOnHGlobal(m_hMem,FALSE,&pstm);
	// load from stream
	pImg=Gdiplus::Image::FromStream(pstm);
	// free/release stuff
	GlobalUnlock(m_hMem);
	pstm->Release();
	FreeResource(lpRsrc);
	return TRUE;
}
VOID MakeTransparentWindow(HWND hWnd, WORD imageID)
{
	ShowWindow(hWnd, SW_HIDE);
	Gdiplus::Image *image = NULL;
	ImageFromIDResource(hInst, imageID, _T("png"), image);
	if (!image)
	{
		return;
	}
	RECT workRect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &workRect, 0);
	int screenHeight = ::GetSystemMetrics(SM_CYSCREEN);
	int screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
	double factor = (screenHeight / 11.0) / (double) image->GetHeight();
	int targetWidth = (int)(image->GetWidth() * factor);
	int targetHeight = (int)(image->GetHeight() * factor);
	int posX = workRect.right - targetWidth - 100;
	int posY = workRect.bottom - targetHeight;
	MoveWindow(hWnd, posX, posY, targetWidth, targetHeight, TRUE);
	HDC hdc = GetDC(hWnd);
	HDC memDC = ::CreateCompatibleDC(hdc);
	HBITMAP memBitmap = ::CreateCompatibleBitmap(hdc, targetWidth, targetHeight);
	::SelectObject(memDC, memBitmap);
	Gdiplus::Graphics graphics(memDC);
	graphics.DrawImage(image, 0, 0, targetWidth, targetHeight);
	BLENDFUNCTION blend;
	blend.AlphaFormat = AC_SRC_ALPHA;
	blend.BlendFlags = 0;
	blend.BlendOp = AC_SRC_OVER;
	blend.SourceConstantAlpha = 240;
	HDC screenDC = GetDC(NULL);
	POINT ptSrc = {0, 0};
	SIZE wndSize = { targetWidth, targetHeight };
	UpdateLayeredWindow(hWnd, screenDC, &ptSrc, &wndSize, memDC, &ptSrc, 0, &blend, 2);
	MoveWindow(hWnd, posX, posY, targetWidth, targetHeight, TRUE);
	DeleteDC(memDC);
	DeleteObject(memBitmap);
	delete image;
	ShowWindow(hWnd, SW_SHOW);
}

//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDI_ICON2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中

	hWnd = CreateWindowEx(WS_EX_LAYERED|WS_EX_TOPMOST|WS_EX_TOOLWINDOW,
		szWindowClass,
		szTitle,
		WS_POPUP,
		200,
		200,
		180,
		180,
		NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	//UpdateWindow(hWnd);
	MakeTransparentWindow(hWnd, nextPngIndex());
	SetTimer(hWnd, 0, 20 * 60 *1000, NULL);
	NOTIFYICONDATA nd;
	nd.cbSize = sizeof(nd);
	nd.hWnd = hWnd;
	nd.uID = 0;
	nd.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nd.uCallbackMessage = WM_USER;
	nd.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON2));
	lstrcpy(nd.szTip, szTitle);
	Shell_NotifyIcon(NIM_ADD, &nd);
	hTrayMenu = CreatePopupMenu();
	AppendMenu(hTrayMenu, MF_STRING, IDR_LIKE, _T("爱你（づ￣3￣）づ╭❤～"));
	AppendMenu(hTrayMenu, MF_STRING, IDR_EXIT, _T("不爱你了(ಥ _ ಥ)"));
	AppendMenu(hTrayMenu, MF_SEPARATOR, 0, NULL);
	AppendMenu(hTrayMenu, MF_STRING, IDR_ABOUT, _T("我是谁(๑°ㅁ°๑)‼"));
	return TRUE;
}

VOID ShowTrayNotify(HWND hWnd)
{
	NOTIFYICONDATA nd;
	nd.cbSize = sizeof(nd);
	nd.hWnd = hWnd;
	nd.uID = 0;
	nd.uFlags = NIF_INFO;
	nd.dwInfoFlags = NIIF_LARGE_ICON;
	lstrcpy(nd.szInfoTitle, _T("~(๑•́ ₃ •̀๑)"));
	lstrcpy(nd.szInfo, nextYulu());
	Shell_NotifyIcon(NIM_MODIFY, &nd);
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, About);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		NOTIFYICONDATA nd;
		nd.cbSize = sizeof(nd);
		nd.hWnd = hWnd;
		nd.uID = 0;
		Shell_NotifyIcon(NIM_DELETE, &nd);
		break;
	case WM_NCHITTEST:
		return PRF_NONCLIENT;
	case WM_TIMER:
		MakeTransparentWindow(hWnd, nextPngIndex());
		break;
		case WM_GETMINMAXINFO:  
		MINMAXINFO *mminfo;
		mminfo=(PMINMAXINFO)lParam;
		mminfo->ptMinTrackSize.x = 0;
		mminfo->ptMinTrackSize.y = 0;
		break;
	case WM_USER:
		if (lParam == WM_LBUTTONUP)
		{
			BOOL showing = IsWindowVisible(hWnd);
			ShowWindow(hWnd, showing ? SW_HIDE : SW_SHOW);
		}
		else if (lParam == WM_RBUTTONUP)
		{
			POINT curPos;
			GetCursorPos(&curPos);
			SetForegroundWindow(hWnd);
			int result = TrackPopupMenu(hTrayMenu, TPM_RETURNCMD, curPos.x, curPos.y, NULL, hWnd, NULL);
			if (result == IDR_EXIT)
			{
				DestroyWindow(hWnd);
			}
			else if (result == IDR_LIKE)
			{
				ShowTrayNotify(hWnd);
			}
			else if (result == IDR_ABOUT)
			{
				PostMessage(hWnd, WM_COMMAND, IDM_ABOUT, NULL);
			}
		}
		break;
	case WM_NCLBUTTONDBLCLK:
		ShowTrayNotify(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
