///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! \file
//! \author Reiex
//! \copyright The MIT License (MIT)
//! \date 2023
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Ruc/Core/CoreDecl.hpp>


namespace ruc
{
	constexpr Status::operator bool() const
	{
		return errorMessage.empty();
	}

	constexpr Status& Status::setErrorMessage(const std::string_view& funcName, uint64_t line, const std::string_view& message)
	{
		errorMessage = std::format("{}:{}\n\n{}", funcName, line, message);
		return *this;
	}

	constexpr Status& Status::relayErrorMessage(const std::string_view& funcName, uint64_t line)
	{
		errorMessage = std::format("{}:{}\n{}", funcName, line, errorMessage);
		return *this;
	}
}
