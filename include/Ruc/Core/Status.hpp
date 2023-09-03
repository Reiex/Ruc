///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! \file
//! \author Reiex
//! \copyright The MIT License (MIT)
//! \date 2023
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <Ruc/Core/CoreTypes.hpp>


namespace ruc
{
	struct Status
	{
		constexpr Status() = default;
		constexpr Status(const Status& status) = default;
		constexpr Status(Status&& status) = default;

		constexpr Status& operator=(const Status& status) = default;
		constexpr Status& operator=(Status&& status) = default;

		constexpr operator bool() const;

		constexpr Status& setErrorMessage(const std::string_view& funcName, uint64_t line, const std::string_view& message);
		constexpr Status& relayErrorMessage(const std::string_view& funcName, uint64_t line);

		constexpr ~Status() = default;

		std::string errorMessage;
	};
}

#define RUC_VOID

#define RUC_CHECK(status, returnValue, condition, message)					\
do {																		\
	if (!(condition))														\
	{																		\
		(status).setErrorMessage(__PRETTY_FUNCTION__, __LINE__, message);	\
		return returnValue;													\
	}																		\
} while (0)

#define RUC_RELAY(status, returnValue)										\
do {																		\
	ruc::Status& relayedStatus = (status);									\
	if (!relayedStatus)														\
	{																		\
		relayedStatus.relayErrorMessage(__PRETTY_FUNCTION__, __LINE__);		\
		return returnValue;													\
	}																		\
} while (0)
