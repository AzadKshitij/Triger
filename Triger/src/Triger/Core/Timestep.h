/*------------ Copyright © 2020 Azad Kshitij. All rights reserved. ------------
//
//   Project     : Triger
//   License     : https://opensource.org/licenses/MIT
//   File        : Timestep.h
//   Created On  : 10/11/2020
//   Updated On  : 10/11/2020
//   Created By  : Azad Kshitij @AzadKshitij
//--------------------------------------------------------------------------*/
#pragma once

namespace Triger
{

	class Timestep
	{
	public:
		/**
		 * @brief 
		 * @param time 
		*/
		Timestep(float time = 0.0f)
			: m_Time(time)
		{
		}

		/**
		 * @brief 
		*/
		operator float() const { return m_Time; }

		/**
		 * @brief 
		 * @return 
		*/
		float GetSeconds() const { return m_Time; }

		/**
		 * @brief 
		 * @return 
		*/
		float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};

}