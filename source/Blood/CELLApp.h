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
		/* 创建函数                                                                  
		/*********/
		virtual bool	create(const char* title, int w, int h) = 0;

		/*********/
		/* 消息循环                                                                  
		/*********/
		virtual	int		main(int argc, char* argv[]) = 0;

		/*********/
		/* 事件处理                                                                  
		/*********/
		virtual	int		onEvent(HWND hWnd, UINT msgId, WPARAM wParam, LPARAM IParam) = 0;

		/*********/
		/* 绘制函数                                                                  
		/*********/
		virtual void	render() = 0;

	};

}