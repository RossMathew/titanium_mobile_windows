/**
 * Windows Native Wrapper for Windows.UI.Xaml.Controls.ControlTemplate
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Windows.UI.Xaml.Controls.ControlTemplate.hpp"
#include "Windows.UI.Xaml.FrameworkTemplate.hpp"

namespace Titanium
{
	namespace Windows
	{
		namespace UI
		{
			namespace Xaml
			{
				namespace Controls
				{

		ControlTemplate::ControlTemplate(const JSContext& js_context) TITANIUM_NOEXCEPT
			: Windows::UI::Xaml::FrameworkTemplate(js_context)
		{
			TITANIUM_LOG_DEBUG("ControlTemplate::ctor");
		}

		void ControlTemplate::postCallAsConstructor(const JSContext& context, const std::vector<JSValue>& arguments)
		{
			TITANIUM_LOG_DEBUG("ControlTemplate::postCallAsConstructor ", this);
			if (arguments.size() == 0) {

				wrapped__ = ref new ::Windows::UI::Xaml::Controls::ControlTemplate();
			}

		}

		::Windows::UI::Xaml::Controls::ControlTemplate^ ControlTemplate::unwrapWindows_UI_Xaml_Controls_ControlTemplate() const
		{
			return dynamic_cast<::Windows::UI::Xaml::Controls::ControlTemplate^>(wrapped__);
		}

		::Windows::UI::Xaml::Controls::ControlTemplate^ ControlTemplate::unwrap() const
		{
			return unwrapWindows_UI_Xaml_Controls_ControlTemplate();
		}

		void ControlTemplate::wrap(::Windows::UI::Xaml::Controls::ControlTemplate^ object)
		{
			wrapped__ = object;
		}

		void ControlTemplate::JSExportInitialize()
		{
			JSExport<ControlTemplate>::SetClassVersion(1);
			JSExport<ControlTemplate>::SetParent(JSExport<Windows::UI::Xaml::FrameworkTemplate>::Class());

			TITANIUM_ADD_PROPERTY(ControlTemplate, TargetType);
		}

		TITANIUM_PROPERTY_SETTER(ControlTemplate, TargetType)
		{
			auto object_value = static_cast<JSObject>(argument);
			::Windows::UI::Xaml::Interop::TypeName value;
			// Assign fields explicitly since we didn't use a constructor

			auto object_value_Name_ = TitaniumWindows::Utility::ConvertUTF8String(static_cast<std::string>(object_value_Name));


			auto object_value_Kind_ = static_cast<::Windows::UI::Xaml::Interop::TypeKind>(static_cast<int32_t>(object_value_Kind)); // TODO Look up enum in metadata to know what type it's value is? 


			unwrap()->TargetType = value;
			return true;
		}

		TITANIUM_PROPERTY_GETTER(ControlTemplate, TargetType)
		{
			auto value = unwrap()->TargetType;
			auto context = get_context();

			auto result = context.CreateObject();


			auto value_Kind_ = context.CreateNumber(static_cast<int32_t>(static_cast<int>(value.Kind))); // FIXME What if the enum isn't an int based one?!


		}

				} // namespace Controls
			} // namespace Xaml
		} // namespace UI
	} // namespace Windows
} // namespace Titanium