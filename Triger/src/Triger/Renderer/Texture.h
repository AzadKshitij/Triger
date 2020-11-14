#pragma once

#include <string>

#include "Triger/Core/Core.h"

namespace Triger {

	class Texture
	{
	public:
		virtual ~Texture() = default;
		/**
		 * @brief 
		 * @return 
		*/
		virtual uint32_t GetWidth() const = 0;
		/**
		 * @brief 
		 * @return 
		*/
		virtual uint32_t GetHeight() const = 0;
		/**
		 * @brief 
		 * @param data 
		 * @param size 
		*/
		virtual void SetData(void* data, uint32_t size) = 0;
		/**
		 * @brief 
		 * @param slot 
		*/
		virtual void Bind(uint32_t slot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		/**
		 * @brief 
		 * @param width 
		 * @param height 
		 * @return 
		*/
		static Ref<Texture2D> Create(uint32_t width, uint32_t height);
		/**
		 * @brief 
		 * @param path 
		 * @return 
		*/
		static Ref<Texture2D> Create(const std::string& path);
	};

}