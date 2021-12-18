#include "AppLog.h"

namespace Triger
{
	void AppLog::Clear()
	{
		m_Buf.clear();
		m_LineOffsets.clear();
		m_LineOffsets.push_back(0);
	}

	void  AppLog::OnImGuiRender()
	{

		/*if (!ImGui::Begin(title, p_open))
		{
			ImGui::End();
			return;
		}*/

		// Options menu
		if (ImGui::BeginPopup("Options"))
		{
			ImGui::Checkbox("Auto-scroll", &m_AutoScroll);
			ImGui::EndPopup();
		}

		// Main window
		if (ImGui::Button("Options"))
			ImGui::OpenPopup("Options");
		ImGui::SameLine();
		bool clear = ImGui::Button("Clear");
		ImGui::SameLine();
		bool copy = ImGui::Button("Copy");
		ImGui::SameLine();
		m_Filter.Draw("Filter", -100.0f);

		ImGui::Separator();
		ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

		if (clear)
			Clear();
		if (copy)
			ImGui::LogToClipboard();

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		const char* buf = m_Buf.begin();
		const char* buf_end = m_Buf.end();
		if (m_Filter.IsActive())
		{
			for (int line_no = 0; line_no < m_LineOffsets.Size; line_no++)
			{
				const char* line_start = buf + m_LineOffsets[line_no];
				const char* line_end = (line_no + 1 < m_LineOffsets.Size) ? (buf + m_LineOffsets[line_no + 1] - 1) : buf_end;
				if (m_Filter.PassFilter(line_start, line_end))
					ImGui::TextUnformatted(line_start, line_end);
			}
		}
		else
		{
			ImGuiListClipper clipper;
			clipper.Begin(m_LineOffsets.Size);
			while (clipper.Step())
			{
				for (int line_no = clipper.DisplayStart; line_no < clipper.DisplayEnd; line_no++)
				{
					const char* line_start = buf + m_LineOffsets[line_no];
					const char* line_end = (line_no + 1 < m_LineOffsets.Size) ? (buf + m_LineOffsets[line_no + 1] - 1) : buf_end;
					ImGui::TextUnformatted(line_start, line_end);
				}
			}
			clipper.End();
		}
		ImGui::PopStyleVar();

		if (m_AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
			ImGui::SetScrollHereY(1.0f);

		ImGui::EndChild();
		ImGui::End();
	}

	void AppLog::ShowExampleAppLog()
	{
		static AppLog log;

		// For the demo: add a debug button _BEFORE_ the normal log window contents
		// We take advantage of a rarely used feature: multiple calls to Begin()/End() are appending to the _same_ window.
		// Most of the contents of the window will be added by the log.Draw() call.
		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
		ImGui::Begin("Logs");
		if (ImGui::SmallButton("[Debug] Add 5 entries"))
		{
			static int counter = 0;
			const char* categories[3] = { "info", "warn", "error" };
			const char* words[] = { "Bumfuzzled", "Cattywampus", "Snickersnee", "Abibliophobia", "Absquatulate", "Nincompoop", "Pauciloquent" };
			for (int n = 0; n < 5; n++)
			{
				const char* category = categories[counter % IM_ARRAYSIZE(categories)];
				const char* word = words[counter % IM_ARRAYSIZE(words)];
				log.AddLog("[%05d] [%s] Hello, current time is %.1f, here's a word: '%s'\n",
					ImGui::GetFrameCount(), category, ImGui::GetTime(), word);
				counter++;
			}
		}

		// Actually call in the regular Log helper (which will Begin() into the same window as we just did)
		log.OnImGuiRender();
		ImGui::End();
	}
}
