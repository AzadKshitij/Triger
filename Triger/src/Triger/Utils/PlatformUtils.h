/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : PlatformUtils.h
//   Created On  : 29/11/2020
//   Updated On  : 29/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

#include <string>

namespace Triger
{

	class FileDialogs
	{
	public:
		// These return empty strings if cancelled

		static std::string OpenFile(const char *filter);
		static std::string SaveFile(const char *filter);
	};
}
