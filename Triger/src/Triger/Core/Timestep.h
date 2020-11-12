/**
 *  @file   Timestep.h
 *  @brief  
 *  @author Kshitij Azad
 *  @date   November 9, 2020
 ***********************************************/
#pragma once

namespace Triger {

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