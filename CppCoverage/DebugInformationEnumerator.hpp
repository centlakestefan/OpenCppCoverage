// OpenCppCoverage is an open source code coverage for C++.
// Copyright (C) 2017 OpenCppCoverage
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "CppCoverageExport.hpp"

namespace boost
{
	namespace filesystem
	{
		class path;
	}
}

namespace CppCoverage
{
	//-------------------------------------------------------------------------
	class IDebugInformationHandler
	{
	  public:
		virtual ~IDebugInformationHandler() = default;
		virtual bool OnSourceFile(const boost::filesystem::path&) = 0;
		virtual void OnLine(int lineNumber, int64_t virtualAddress) = 0;
	};

	//-------------------------------------------------------------------------
	class CPPCOVERAGE_DLL DebugInformationEnumerator
	{
	  public:
		bool Enumerate(const boost::filesystem::path&,
		               IDebugInformationHandler&) const;
	};
}
