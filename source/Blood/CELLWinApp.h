#pragma once


#include "CELLApp.h"


namespace Blood
{
	class CELLWINApp :public CELLApp
	{
	protected:
		HINSTANCE _hInstance;
		HWND _hWnd;

	public:
		CELLWINApp(HINSTANCE hInstance = 0,HWND hWnd = 0)
			:_hInstance(hInstance),_hWnd(hWnd)
		{
			//1.注册窗口类
			WNDCLASSEX wnd;
			memset(&wnd, 0, sizeof(wnd));
			wnd.cbSize = sizeof(wnd);
			wnd.lpfnWndProc = CELLWINApp::wndProc;
			wnd.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
			wnd.hCursor = GetCursor();
			wnd.hIcon = 0;
			wnd.hIconSm = 0;
			wnd.hInstance = hInstance;
			wnd.lpszClassName = _T("Blood");
			wnd.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

			RegisterClassEx(&wnd);
		}

		virtual ~CELLWINApp()
		{
			UnregisterClass(_T("Blood"),_hInstance);
		}

		/*********/
		/* 创建函数
		/*********/
		virtual bool	create(const char* title, int w, int h)
		{
			//2.创建窗口
			HWND _hWnd = CreateWindowEx(
				0
				, _T("Blood")
				, title
				, WS_TILEDWINDOW
				, 100
				, 100
				, w
				, h
				, 0
				, 0
				, _hInstance
				, this);

			if (_hWnd == 0)
			{
				return false;
			}

			UpdateWindow(_hWnd);
			ShowWindow(_hWnd, SW_SHOW);


			return true;
		}

		/*********/
		/* 消息循环
		/*********/
		virtual	int		main(int argc, char* argv[])
		{

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

			return 0;
		}

		/*********/
		/* 事件处理
		/*********/
		virtual	int		onEvent(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam)
		{

			switch (msgId)
			{
			case WM_LBUTTONDOWN:
			{
				int x = LOWORD(lParam);
				int y = HIWORD(lParam);
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
				return DefWindowProc(hWnd, msgId, wParam, lParam);
			}

			return S_OK;
		}

		/*********/
		/* 绘制函数
		/*********/
		virtual void	render()
		{
			
		}

	protected:
		static	LRESULT CALLBACK wndProc(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM lParam)
		{
			if (WM_CREATE == msgId)
			{
		
				CREATESTRUCT* create_struct = (CREATESTRUCT*)lParam;
				LPVOID lpCreateParams =	create_struct->lpCreateParams;
				if(lpCreateParams)
				{
					::SetWindowLong(hWnd, GWLP_USERDATA, (DWORD_PTR)lpCreateParams);
					CELLWINApp* pThis = (CELLWINApp*)lpCreateParams;


					return pThis->onEvent(hWnd, msgId, wParam, lParam);

				}	
				
			} 
			else
			{
				CELLWINApp* pThis = (CELLWINApp*)GetWindowLong(hWnd, GWLP_USERDATA);

				if (pThis != nullptr)
				{
					return pThis->onEvent(hWnd, msgId, wParam, lParam);
				}
			}

			return DefWindowProc(hWnd, msgId, wParam, lParam);
		}
	private:
	};

}
