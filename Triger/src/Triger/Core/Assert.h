#pragma once

#include "Triger/Core/Base.h"
#include "Triger/Core/Log.h"
#include <filesystem>

#ifdef TR_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define TR_INTERNAL_ASSERT_IMPL(type, check, msg, ...) \
    {                                                  \
        if (!(check))                                  \
        {                                              \
            HZ##type##ERROR(msg, __VA_ARGS__);         \
            TR_DEBUGBREAK();                           \
        }                                              \
    }
#define TR_INTERNAL_ASSERT_WITH_MSG(type, check, ...) TR_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define TR_INTERNAL_ASSERT_NO_MSG(type, check) TR_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TR_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define TR_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define TR_INTERNAL_ASSERT_GET_MACRO(...) TR_EXPAND_MACRO(TR_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, TR_INTERNAL_ASSERT_WITH_MSG, TR_INTERNAL_ASSERT_NO_MSG))

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define TR_ASSERT(...) TR_EXPAND_MACRO(TR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__))
#define TR_CORE_ASSERT(...) TR_EXPAND_MACRO(TR_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
#define TR_ASSERT(...)
#define TR_CORE_ASSERT(...)
#endif
