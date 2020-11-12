/**
 *  @file   Application.h
 *  @brief  Applicatoin creation base
 *  @author Kshitij Azad
 *  @date   November 2, 2020
 ***********************************************/
#pragma once

#include "Core.h"
#include "Window.h"
#include "Triger/Events/ApplicationEvent.h"
#include "Triger/Events/Event.h"
#include "Triger/Layers/LayerStack.h"
#include "Triger/ImGui/ImGuiLayer.h"

namespace Triger
{
  
  class Application
  {
  public:
    /**
   * @brief 
   */
    Application();
    /**
   * @brief 
   * @param 
   * @return 
   */
    virtual ~Application() = default;

    /**
   * @brief Runs the applications
   * @return (void)
   */
    void Run();

    /**
   * @brief check if the event has been triggered
   * @param e An Event
   * @return (void)
   */
    void OnEvent(Event &e);

    /**
   * @brief push layer into layer stack
   * @param layer layer object
   * @return (void)
   * @see Layer
   * @see LayerStack
   */
    void PushLayer(Layer *layer);
 
    /**
     * @brief 
     * @param layer 
    */
    void PushOverlay(Layer *layer);

    /**
   * @brief To get the current window 
   * @return the current window
   */
    inline Window &GetWindow() { return *m_Window; }

    /**
   * @brief 
   * @return 
   */
    inline static Application &Get() { return *s_Instance; }

  private:
    /**
   * @brief 
   * @param e
   * @return 
   */
    bool OnWindowClose(WindowCloseEvent &e);
    /**
   * @brief 
   * @param e
   * @return 
   */
    bool OnWindowResize(WindowResizeEvent &e);

  private:
    /**
     * @brief 
    */
    std::unique_ptr<Window> m_Window;
    
    /**
     * @brief 
    */
    bool m_Running = true;
    
    /**
     * @brief 
    */
    bool m_Minimized = false;

    /**
     * @brief 
    */
    ImGuiLayer *m_ImGuiLayer;
    
    /**
     * @brief 
    */
    LayerStack m_LayerStack;
    
    /**
     * @brief 
    */
    float m_LastFrameTime = 0.0f;

  private:
    /**
     * @brief 
    */
    static Application *s_Instance;
  };

  /**
  * @brief This will be defined in the Client. Everytime you want to make a new app you have to call this function
  * @return 
  */
  Application *CreateApplication();
} // namespace Triger
