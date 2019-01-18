#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "Common.h"

namespace Material
{
	namespace Shadows
	{
		class DropShadowerBase
		{
		public:
			DropShadowerBase(const DropShadow &umbraShadow, const DropShadow &penumbraShadow, const DropShadow &ambientShadow)
				: umbraShadow(umbraShadow), penumbraShadow(penumbraShadow), ambientShadow(ambientShadow),
				umbraShadower(umbraShadow), penumbraShadower(penumbraShadow), ambientShadower(ambientShadow)
			{
			}
			virtual ~DropShadowerBase() = default;

			/** Attaches the DropShadower to the component you want to shadow. */
			void setOwner(Component *componentToFollow)
			{
				umbraShadower.setOwner(componentToFollow);
				penumbraShadower.setOwner(componentToFollow);
				ambientShadower.setOwner(componentToFollow);
			}

			/** Renders a drop-shadow based on the alpha-channel of the given image. */
			void drawForImage(Graphics &g, const Image &srcImage) const
			{
				umbraShadow.drawForImage(g, srcImage);
				penumbraShadow.drawForImage(g, srcImage);
				ambientShadow.drawForImage(g, srcImage);
			}

			/** Renders a drop-shadow based on the shape of a path. */
			void drawForPath(Graphics &g, const Path &path) const
			{
				umbraShadow.drawForPath(g, path);
				penumbraShadow.drawForPath(g, path);
				ambientShadow.drawForPath(g, path);
			}

			/** Renders a drop-shadow for a rectangle.
					 Note that for speed, this approximates the shadow using gradients.
					 */
			void drawForRectangle(Graphics &g, const Rectangle<int> &area) const
			{
				umbraShadow.drawForRectangle(g, area);
				penumbraShadow.drawForRectangle(g, area);
				ambientShadow.drawForRectangle(g, area);
			}

		private:
			DropShadow umbraShadow;
			DropShadow penumbraShadow;
			DropShadow ambientShadow;
			DropShadower umbraShadower;
			DropShadower penumbraShadower;
			DropShadower ambientShadower;
		};

		class DropShadower1dp : public DropShadowerBase
		{
		public:
			DropShadower1dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(2), Point<int>(px(0), px(0))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(2), Point<int>(px(0), px(2))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(3), Point<int>(px(0), px(1)))) {}
		};

		class DropShadower2dp : public DropShadowerBase
		{
		public:
			DropShadower2dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(4), Point<int>(px(0), px(0))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(4), Point<int>(px(0), px(3))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(5), Point<int>(px(0), px(1)))) {}
		};

		class DropShadower3dp : public DropShadowerBase
		{
		public:
			DropShadower3dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(3), Point<int>(px(0), px(3))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(4), Point<int>(px(0), px(3))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(8), Point<int>(px(0), px(1)))) {}
		};

		class DropShadower4dp : public DropShadowerBase
		{
		public:
			DropShadower4dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(4), Point<int>(px(0), px(2))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(5), Point<int>(px(0), px(4))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(10), Point<int>(px(0), px(1)))) {}
		};

		class DropShadower6dp : public DropShadowerBase
		{
		public:
			DropShadower6dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(10), Point<int>(px(0), px(6))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(18), Point<int>(px(0), px(1))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(5), Point<int>(px(0), px(3)))) {}
		};

		class DropShadower8dp : public DropShadowerBase
		{
		public:
			DropShadower8dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(10), Point<int>(px(0), px(8))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(14), Point<int>(px(0), px(3))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(15), Point<int>(px(0), px(4)))) {}
		};

		class DropShadower9dp : public DropShadowerBase
		{
		public:
			DropShadower9dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(12), Point<int>(px(0), px(9))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(16), Point<int>(px(0), px(3))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(6), Point<int>(px(0), px(5)))) {}
		};

		class DropShadower12dp : public DropShadowerBase
		{
		public:
			DropShadower12dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(17), Point<int>(px(0), px(12))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(22), Point<int>(px(0), px(5))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(8), Point<int>(px(0), px(7)))) {}
		};

		class DropShadower16dp : public DropShadowerBase
		{
		public:
			DropShadower16dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(24), Point<int>(px(0), px(16))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(30), Point<int>(px(0), px(6))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(10), Point<int>(px(0), px(8)))) {}
		};

		class DropShadower24dp : public DropShadowerBase
		{
		public:
			DropShadower24dp() : DropShadowerBase(DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.14f), px(38), Point<int>(px(0), px(24))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.12f), px(46), Point<int>(px(0), px(9))),
				DropShadow(Colour(0.0f, 0.0f, 0.0f, 0.20f), px(15), Point<int>(px(0), px(11)))) {}
		};
	} // namespace Shadows
} // namespace Material
