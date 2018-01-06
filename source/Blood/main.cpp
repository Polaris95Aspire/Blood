#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <tchar.h>
#include "main.h"

int main()
{
	printf("Hello World!\n");
	return 0;
}

LRESULT CALLBACK wndProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM IParam) 
{
	switch (msgId)
	{
	case WM_LBUTTONDOWN:
			{
				int x = LOWORD(IParam);
				int y = HIWORD(IParam);
				char szBuff[64];
				sprintf_s(szBuff, "x=%d		y=%d\n", x, y);
				//OutputDebugStringA(szBuff);
			}
			break;
	case WM_LBUTTONUP:
		break;
	case WM_LBUTTONDBLCLK:
		break;

	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_RBUTTONDBLCLK:
		break;

	case WM_MBUTTONDOWN:
		break;
	case WM_MBUTTONUP:
		break;
	case WM_MBUTTONDBLCLK:
		break;

	case WM_MOUSEMOVE:
		break;
	case WM_MOUSEWHEEL:
		break;

	case WM_KEYDOWN:
		{
			if (wParam == 'W')
			{
				//MessageBox(0,0,0,0);
			}
		}
		break;
	case WM_KEYUP:
		break;

	case WM_CREATE:
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		{
			PostQuitMessage(0);//中断窗口从消息队列中获取数据
		}
		break;

	default:
		return DefWindowProc(hWnd,msgId,wParam,IParam);
	}

	return S_OK;
}

void render()
{

}

int CALLBACK WinMain(
					__in HINSTANCE hInstance
					,__in_opt HINSTANCE hPrevInstance
					,__in_opt LPSTR IpCmdLine
					,__in int nShowCmd
					)
{
	//1.注册窗口类
	WNDCLASSEX wnd;
	memset(&wnd,0,sizeof(wnd));
	wnd.cbSize			=	sizeof(wnd);
	wnd.lpfnWndProc		=	wndProc;
	wnd.hbrBackground	=	0;
	wnd.hCursor			=	GetCursor();
	wnd.hIcon			=	0;
	wnd.hIconSm			=	0;
	wnd.hInstance		=	hInstance;
	wnd.lpszClassName = _T("Blood");
	wnd.style		 = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	RegisterClassEx(&wnd);

	//2.创建窗口
	HWND hWnd = CreateWindowEx(
								0
								, _T("Blood")
								,_T("血腥大地")
								,WS_TILEDWINDOW
								,100
								,100
								,640
								,480
								,0
								,0
								,hInstance
								,0);

	if (hWnd == 0)
	{
		return -1;
	}

	UpdateWindow(hWnd);
	ShowWindow(hWnd, SW_SHOW);

	//3.消息循环
	MSG msg = { 0 };
	/*
	while (GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			render();
		}
	}

	//4.退出
	UnregisterClass(_T("Blood"),hInstance);

	return 0;
}