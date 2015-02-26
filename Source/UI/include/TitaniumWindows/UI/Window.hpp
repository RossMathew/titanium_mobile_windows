/**
 * Titanium.UI.Window for Windows
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUMWINDOWS_UI_WINDOW_HPP_
#define _TITANIUMWINDOWS_UI_WINDOW_HPP_

#include "TitaniumWindows/UI/detail/UIBase.hpp"
#include "ViewBase.hpp"

namespace TitaniumWindows
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.Window implementation for
		  Windows.
		*/
// Silence 4275 about ViewBase for now. We need to merge View and ViewBase and then remove this pragma! TIMOB-18422
#pragma warning(push)
#pragma warning(disable : 4275)
		class TITANIUMWINDOWS_UI_EXPORT Window final : public Titanium::UI::Window, public JSExport<Window>, public ViewBase
		{
#pragma warning(pop)
		public:
			virtual void close(const JSObject& params, JSObject& this_object) const TITANIUM_NOEXCEPT override final;
			virtual void open(const JSObject& params, JSObject& this_object) const TITANIUM_NOEXCEPT override final;
			virtual void add(const JSObject& view, JSObject& this_object) TITANIUM_NOEXCEPT;

			Window(const JSContext&, const std::vector<JSValue>& arguments = {}) TITANIUM_NOEXCEPT;

			virtual ~Window();

			Window(const Window&) = default;
			Window& operator=(const Window&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			Window(Window&&) = default;
			Window& operator=(Window&&) = default;
#endif

			static void JSExportInitialize();

			virtual void hide(JSObject& this_object) TITANIUM_NOEXCEPT;
			virtual void show(JSObject& this_object) TITANIUM_NOEXCEPT;

			virtual void set_fullscreen(const bool& fullscreen) TITANIUM_NOEXCEPT override final;
			virtual void set_backgroundColor(const std::string& backgroundColor) TITANIUM_NOEXCEPT override final;
			virtual void set_bottom(const std::string& bottom) TITANIUM_NOEXCEPT override final;
			virtual void set_height(const std::string& height) TITANIUM_NOEXCEPT override final;
			virtual void set_layout(const std::string& layout) TITANIUM_NOEXCEPT override final;
			virtual void set_left(const std::string& left) TITANIUM_NOEXCEPT override final;
			virtual void set_right(const std::string& right) TITANIUM_NOEXCEPT override final;
			virtual void set_top(const std::string& top) TITANIUM_NOEXCEPT override final;
			virtual void set_width(const std::string& width) TITANIUM_NOEXCEPT override final;

			virtual void onLayoutEngineCallback(Titanium::LayoutEngine::Rect rect, const std::string& name);
			virtual void onComponentSizeChange(const Titanium::LayoutEngine::Rect&);

		private:
			Windows::UI::Xaml::Controls::Canvas^ canvas__;
		};
	} // namespace UI
} // namespace TitaniumWindows

#endif  // _TITANIUMWINDOWS_UI_WINDOW_HPP_
