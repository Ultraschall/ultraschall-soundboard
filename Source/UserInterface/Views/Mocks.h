#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"
#include "AppBar.h"
#include "BottomBar.h"
#include "../../LookAndFeel/Material.h"

namespace mock {
	
	template<class T>
	class UserInterfaceMock : public Component {
	public:
		explicit UserInterfaceMock() {
			setLookAndFeel(&lookAndFeel);
			LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);
		}

		~UserInterfaceMock() {
			removeAllChildren();
			mock = nullptr;
			setLookAndFeel(nullptr);
			LookAndFeel::setDefaultLookAndFeel(nullptr);
			Material::Fonts::deleteInstance();
			Material::Typefaces::deleteInstance();
		}

		template<class... TArgs>
		T* createMock(TArgs&&... args) {
			mock = std::make_unique<T>(std::forward<TArgs>(args)...);
			addAndMakeVisible(mock.get());
			return mock.get();
		}

		void paint(Graphics &g) override {
			g.fillAll(Material::Color::Surface::Main);
		}

		void resized() override {
			if (mock.get() != nullptr) {
				mock->setBounds(getLocalBounds());
			}
		}

	private:
		std::unique_ptr<T> mock;
		MaterialLookAndFeel lookAndFeel;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UserInterfaceMock)
	};

	class AppBarMock : public UserInterfaceMock<AppBar> {
        public:
			AppBarMock() {
				createMock();
			};
	};

	class BottomBarMock : public UserInterfaceMock<BottomBar> {
	public:
		BottomBarMock() {
			auto control = createMock();
			control->colourChanged();
			control->talkoverButton.onClick = [=] {

			};
		};
	};
}