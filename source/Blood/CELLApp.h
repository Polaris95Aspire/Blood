#pragma once


namespace Blood
{
	class  CELLApp
	{
	public:
		CELLApp()
		{}
		virtual ~CELLApp()
		{}
	
		/*********/
		/* ��������                                                                  
		/*********/
		virtual bool	create(const char* title, int w, int h) = 0;

		/*********/
		/* ��Ϣѭ��                                                                  
		/*********/
		virtual	int		main(int argc, char* argv[]) = 0;

		/*********/
		/* �¼�����                                                                  
		/*********/
		virtual	int		onEvent(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM IParam) = 0;

		/*********/
		/* ���ƺ���                                                                  
		/*********/
		virtual void	render() = 0;

	};

}