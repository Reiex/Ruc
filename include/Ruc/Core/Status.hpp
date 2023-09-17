///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! \file
//! \author Pélégrin Marius
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

		constexpr void setErrorMessage(const std::string_view& funcName, uint64_t line, const std::string_view& message);
		constexpr void relayErrorMessage(const std::string_view& funcName, uint64_t line);

		constexpr ~Status() = default;

		std::string errorMessage;
	};
}

#define RUC_VOID

#define RUC_CHECK(statusToSet, returnValue, condition, message)					\
do {																			\
	if (!(condition))															\
	{																			\
		(statusToSet).setErrorMessage(__PRETTY_FUNCTION__, __LINE__, message);	\
		return returnValue;														\
	}																			\
} while (0)

#define RUC_RELAYCOPY(statusToCheck, statusToSet, returnValue)		\
do {																\
	const ruc::Status& statusFrom = (statusToCheckAndSet);			\
	if (!statusFrom)												\
	{																\
		ruc::Status& statusTo = (statusToSet);						\
		statusTo.errorMessage = statusFrom.errorMessage;			\
		statusTo.relayErrorMessage(__PRETTY_FUNCTION__, __LINE__);	\
		return returnValue;											\
	}																\
}

#define RUC_RELAY(statusToCheckAndSet, returnValue)					\
do {																\
	ruc::Status& status = (statusToCheckAndSet);					\
	if (!status)													\
	{																\
		status.relayErrorMessage(__PRETTY_FUNCTION__, __LINE__);	\
		return returnValue;											\
	}																\
} while (0)
