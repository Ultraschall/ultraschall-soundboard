#include "Colors.h"

namespace Material
{
	namespace Color
	{
		namespace Surface
		{
			const Colour PrimaryOrSecondary{ uint8(55), uint8(91), uint8(143), 1.0f };
			const Colour Main{ uint8(60), uint8(60), uint8(60), 1.0f };
			const Colour Light{ uint8(129), uint8(129), uint8(129), 1.0f };
			const Colour Dark{ uint8(0), uint8(0), uint8(0), 1.0f };
			const Colour Base{ uint8(60), uint8(60), uint8(60), 1.0f };
		} // namespace Surface
		namespace Secondary
		{
            const Colour Main{ uint8(255), uint8(206), uint8(0), 1.0f };
            const Colour _900{ uint8(255), uint8(110), uint8(0), 1.0f };
            const Colour _800{ uint8(255), uint8(145), uint8(0), 1.0f };
            const Colour _700{ uint8(255), uint8(163), uint8(0), 1.0f };
            const Colour _600{ uint8(255), uint8(183), uint8(0), 1.0f };
            const Colour _500{ uint8(255), uint8(197), uint8(0), 1.0f };
            const Colour _400{ uint8(251), uint8(202), uint8(0), 1.0f };
            const Colour _300{ uint8(255), uint8(217), uint8(45), 1.0f };
            const Colour _200{ uint8(251), uint8(223), uint8(114), 1.0f };
            const Colour _100{ uint8(241), uint8(224), uint8(162), 1.0f };
            const Colour _050{ uint8(244), uint8(239), uint8(214), 1.0f };
		} // namespace Secondary
		namespace Primary
		{
            const Colour Main{ uint8(55), uint8(91), uint8(143), 1.0f };
            const Colour _900{ uint8(55), uint8(55), uint8(55), 1.0f };
            const Colour _800{ uint8(66), uint8(123), uint8(179), 1.0f };
            const Colour _700{ uint8(72), uint8(140), uint8(199), 1.0f };
            const Colour _600{ uint8(78), uint8(159), uint8(220), 1.0f };
            const Colour _500{ uint8(84), uint8(173), uint8(235), 1.0f };
            const Colour _400{ uint8(91), uint8(183), uint8(236), 1.0f };
            const Colour _300{ uint8(108), uint8(196), uint8(240), 1.0f };
            const Colour _200{ uint8(144), uint8(214), uint8(248), 1.0f };
            const Colour _100{ uint8(185), uint8(229), uint8(250), 1.0f };
            const Colour _050{ uint8(225), uint8(243), uint8(251), 1.0f };
		} // namespace Primary
		namespace Icons
		{
			namespace Black
			{
				const Colour Inactive{ uint8(0), uint8(0), uint8(0), 0.54f };
				const Colour Disabled{ uint8(0), uint8(0), uint8(0), 0.38f };
				const Colour Active{ uint8(0), uint8(0), uint8(0), 0.87f };
			} // namespace Black
			namespace White
			{
				const Colour Inactive{ uint8(255), uint8(255), uint8(255), 0.54f };
				const Colour Disabled{ uint8(255), uint8(255), uint8(255), 0.38f };
				const Colour Active{ uint8(255), uint8(255), uint8(255), 1.0f };
			} // namespace White
			namespace Selected
			{
				namespace OnSurface
				{
					const Colour Inactive{ uint8(255), uint8(255), uint8(255), 0.54f };
					const Colour Disabled{ uint8(255), uint8(255), uint8(255), 0.38f };
					const Colour Active{ uint8(255), uint8(255), uint8(255), 1.0f };
				} // namespace OnSurface
				namespace OnSecondary
				{
					const Colour Inactive{ uint8(0), uint8(0), uint8(0), 0.54f };
					const Colour Disabled{ uint8(0), uint8(0), uint8(0), 0.38f };
					const Colour Active{ uint8(0), uint8(0), uint8(0), 0.87f };
				} // namespace OnSecondary
				namespace OnPrimary
				{
					const Colour Inactive{ uint8(255), uint8(255), uint8(255), 0.54f };
					const Colour Disabled{ uint8(255), uint8(255), uint8(255), 0.38f };
					const Colour Active{ uint8(255), uint8(255), uint8(255), 1.0f };
				} // namespace OnPrimary
			} // namespace Selected
			const Colour Error{ uint8(176), uint8(0), uint8(32), 1.0f };
			const Colour PrimaryOrSecondary{ uint8(139), uint8(195), uint8(74), 1.0f };
		} // namespace Icons
	} // namespace Color
} // namespace Material
