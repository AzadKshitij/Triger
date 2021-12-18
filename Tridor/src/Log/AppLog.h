#pragma once
#include <iostream>
#include <string>
#include <vector>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

#include <glm/gtc/type_ptr.hpp>

namespace Triger
{

	class AppLog
	{
	public:
		AppLog()
		{
			m_AutoScroll = true;
			Clear();
		}

		void OnImGuiRender();
		void ShowExampleAppLog();

		ImGuiTextBuffer     m_Buf;
		ImGuiTextFilter     m_Filter;
		ImVector<int>       m_LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
		bool                m_AutoScroll;  // Keep scrolling if already at the bottom.

		void Clear();

		void AddLog(const char* fmt, ...) IM_FMTARGS(2)
		{
			int old_size = m_Buf.size();
			va_list args;
			va_start(args, fmt);
			m_Buf.appendfv(fmt, args);
			va_end(args);
			for (int new_size = m_Buf.size(); old_size < new_size; old_size++)
				if (m_Buf[old_size] == '\n')
					m_LineOffsets.push_back(old_size + 1);
		}

	};
}

