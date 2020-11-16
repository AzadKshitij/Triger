/**
 *  @file   KeyCodes.h
 *  @brief  Keycodes for all keybord events
 *  @author Kshitij Azad
 *  @date   November 9, 2020
 ***********************************************/
#pragma once

namespace Triger
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define TR_KEY_SPACE           ::Triger::Key::Space
#define TR_KEY_APOSTROPHE      ::Triger::Key::Apostrophe    /* ' */
#define TR_KEY_COMMA           ::Triger::Key::Comma         /* , */
#define TR_KEY_MINUS           ::Triger::Key::Minus         /* - */
#define TR_KEY_PERIOD          ::Triger::Key::Period        /* . */
#define TR_KEY_SLASH           ::Triger::Key::Slash         /* / */
#define TR_KEY_0               ::Triger::Key::D0
#define TR_KEY_1               ::Triger::Key::D1
#define TR_KEY_2               ::Triger::Key::D2
#define TR_KEY_3               ::Triger::Key::D3
#define TR_KEY_4               ::Triger::Key::D4
#define TR_KEY_5               ::Triger::Key::D5
#define TR_KEY_6               ::Triger::Key::D6
#define TR_KEY_7               ::Triger::Key::D7
#define TR_KEY_8               ::Triger::Key::D8
#define TR_KEY_9               ::Triger::Key::D9
#define TR_KEY_SEMICOLON       ::Triger::Key::Semicolon     /* ; */
#define TR_KEY_EQUAL           ::Triger::Key::Equal         /* = */
#define TR_KEY_A               ::Triger::Key::A
#define TR_KEY_B               ::Triger::Key::B
#define TR_KEY_C               ::Triger::Key::C
#define TR_KEY_D               ::Triger::Key::D
#define TR_KEY_E               ::Triger::Key::E
#define TR_KEY_F               ::Triger::Key::F
#define TR_KEY_G               ::Triger::Key::G
#define TR_KEY_H               ::Triger::Key::H
#define TR_KEY_I               ::Triger::Key::I
#define TR_KEY_J               ::Triger::Key::J
#define TR_KEY_K               ::Triger::Key::K
#define TR_KEY_L               ::Triger::Key::L
#define TR_KEY_M               ::Triger::Key::M
#define TR_KEY_N               ::Triger::Key::N
#define TR_KEY_O               ::Triger::Key::O
#define TR_KEY_P               ::Triger::Key::P
#define TR_KEY_Q               ::Triger::Key::Q
#define TR_KEY_R               ::Triger::Key::R
#define TR_KEY_S               ::Triger::Key::S
#define TR_KEY_T               ::Triger::Key::T
#define TR_KEY_U               ::Triger::Key::U
#define TR_KEY_V               ::Triger::Key::V
#define TR_KEY_W               ::Triger::Key::W
#define TR_KEY_X               ::Triger::Key::X
#define TR_KEY_Y               ::Triger::Key::Y
#define TR_KEY_Z               ::Triger::Key::Z
#define TR_KEY_LEFT_BRACKET    ::Triger::Key::LeftBracket   /* [ */
#define TR_KEY_BACKSLASH       ::Triger::Key::Backslash     /* \ */
#define TR_KEY_RIGHT_BRACKET   ::Triger::Key::RightBracket  /* ] */
#define TR_KEY_GRAVE_ACCENT    ::Triger::Key::GraveAccent   /* ` */
#define TR_KEY_WORLD_1         ::Triger::Key::World1        /* non-US #1 */
#define TR_KEY_WORLD_2         ::Triger::Key::World2        /* non-US #2 */


#define TR_KEY_ESCAPE          ::Triger::Key::Escape
#define TR_KEY_ENTER           ::Triger::Key::Enter
#define TR_KEY_TAB             ::Triger::Key::Tab
#define TR_KEY_BACKSPACE       ::Triger::Key::Backspace
#define TR_KEY_INSERT          ::Triger::Key::Insert
#define TR_KEY_DELETE          ::Triger::Key::Delete
#define TR_KEY_RIGHT           ::Triger::Key::Right
#define TR_KEY_LEFT            ::Triger::Key::Left
#define TR_KEY_DOWN            ::Triger::Key::Down
#define TR_KEY_UP              ::Triger::Key::Up
#define TR_KEY_PAGE_UP         ::Triger::Key::PageUp
#define TR_KEY_PAGE_DOWN       ::Triger::Key::PageDown
#define TR_KEY_HOME            ::Triger::Key::Home
#define TR_KEY_END             ::Triger::Key::End
#define TR_KEY_CAPS_LOCK       ::Triger::Key::CapsLock
#define TR_KEY_SCROLL_LOCK     ::Triger::Key::ScrollLock
#define TR_KEY_NUM_LOCK        ::Triger::Key::NumLock
#define TR_KEY_PRINT_SCREEN    ::Triger::Key::PrintScreen
#define TR_KEY_PAUSE           ::Triger::Key::Pause
#define TR_KEY_F1              ::Triger::Key::F1
#define TR_KEY_F2              ::Triger::Key::F2
#define TR_KEY_F3              ::Triger::Key::F3
#define TR_KEY_F4              ::Triger::Key::F4
#define TR_KEY_F5              ::Triger::Key::F5
#define TR_KEY_F6              ::Triger::Key::F6
#define TR_KEY_F7              ::Triger::Key::F7
#define TR_KEY_F8              ::Triger::Key::F8
#define TR_KEY_F9              ::Triger::Key::F9
#define TR_KEY_F10             ::Triger::Key::F10
#define TR_KEY_F11             ::Triger::Key::F11
#define TR_KEY_F12             ::Triger::Key::F12
#define TR_KEY_F13             ::Triger::Key::F13
#define TR_KEY_F14             ::Triger::Key::F14
#define TR_KEY_F15             ::Triger::Key::F15
#define TR_KEY_F16             ::Triger::Key::F16
#define TR_KEY_F17             ::Triger::Key::F17
#define TR_KEY_F18             ::Triger::Key::F18
#define TR_KEY_F19             ::Triger::Key::F19
#define TR_KEY_F20             ::Triger::Key::F20
#define TR_KEY_F21             ::Triger::Key::F21
#define TR_KEY_F22             ::Triger::Key::F22
#define TR_KEY_F23             ::Triger::Key::F23
#define TR_KEY_F24             ::Triger::Key::F24
#define TR_KEY_F25             ::Triger::Key::F25

/* Keypad */
#define TR_KEY_KP_0            ::Triger::Key::KP0
#define TR_KEY_KP_1            ::Triger::Key::KP1
#define TR_KEY_KP_2            ::Triger::Key::KP2
#define TR_KEY_KP_3            ::Triger::Key::KP3
#define TR_KEY_KP_4            ::Triger::Key::KP4
#define TR_KEY_KP_5            ::Triger::Key::KP5
#define TR_KEY_KP_6            ::Triger::Key::KP6
#define TR_KEY_KP_7            ::Triger::Key::KP7
#define TR_KEY_KP_8            ::Triger::Key::KP8
#define TR_KEY_KP_9            ::Triger::Key::KP9
#define TR_KEY_KP_DECIMAL      ::Triger::Key::KPDecimal
#define TR_KEY_KP_DIVIDE       ::Triger::Key::KPDivide
#define TR_KEY_KP_MULTIPLY     ::Triger::Key::KPMultiply
#define TR_KEY_KP_SUBTRACT     ::Triger::Key::KPSubtract
#define TR_KEY_KP_ADD          ::Triger::Key::KPAdd
#define TR_KEY_KP_ENTER        ::Triger::Key::KPEnter
#define TR_KEY_KP_EQUAL        ::Triger::Key::KPEqual

#define TR_KEY_LEFT_SHIFT      ::Triger::Key::LeftShift
#define TR_KEY_LEFT_CONTROL    ::Triger::Key::LeftControl
#define TR_KEY_LEFT_ALT        ::Triger::Key::LeftAlt
#define TR_KEY_LEFT_SUPER      ::Triger::Key::LeftSuper
#define TR_KEY_RIGHT_SHIFT     ::Triger::Key::RightShift
#define TR_KEY_RIGHT_CONTROL   ::Triger::Key::RightControl
#define TR_KEY_RIGHT_ALT       ::Triger::Key::RightAlt
#define TR_KEY_RIGHT_SUPER     ::Triger::Key::RightSuper
#define TR_KEY_MENU            ::Triger::Key::Menu