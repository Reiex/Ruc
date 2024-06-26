///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! \file
//! \author P�l�grin Marius
//! \copyright The MIT License (MIT)
//! \date 2023-2024
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

// __PRETTY_FUNCTION__

#if defined(__GNUC__)
	// Already defined
#elif defined(_MSC_VER)
	#define __PRETTY_FUNCTION__ __FUNCSIG__
#else
	#define __PRETTY_FUNCTION__ __func__
#endif
