#pragma once

#include "JuceHeader.h"

namespace Material {
    namespace Color {
        namespace Surface {
            const Colour PrimaryOrSecondary{uint8(139), uint8(195), uint8(74), 1.0f};
            const Colour Main{uint8(60), uint8(60), uint8(60), 1.0f};
            const Colour Light{uint8(129), uint8(129), uint8(129), 1.0f};
            const Colour Dark{uint8(0), uint8(0), uint8(0), 1.0f};
            const Colour Base{uint8(60), uint8(60), uint8(60), 1.0f};
        }
        namespace Secondary {
            const Colour Main{uint8(104), uint8(159), uint8(56), 1.0f};
            const Colour _900{uint8(51), uint8(105), uint8(30), 1.0f};
            const Colour _800{uint8(85), uint8(139), uint8(47), 1.0f};
            const Colour _700{uint8(104), uint8(159), uint8(56), 1.0f};
            const Colour _600{uint8(124), uint8(179), uint8(66), 1.0f};
            const Colour _500{uint8(139), uint8(195), uint8(74), 1.0f};
            const Colour _400{uint8(156), uint8(204), uint8(101), 1.0f};
            const Colour _300{uint8(174), uint8(213), uint8(129), 1.0f};
            const Colour _200{uint8(197), uint8(225), uint8(165), 1.0f};
            const Colour _100{uint8(220), uint8(237), uint8(200), 1.0f};
            const Colour _050{uint8(241), uint8(248), uint8(233), 1.0f};
        }
        namespace Primary {
            const Colour Main{uint8(139), uint8(195), uint8(74), 1.0f};
            const Colour _900{uint8(51), uint8(105), uint8(30), 1.0f};
            const Colour _800{uint8(85), uint8(139), uint8(47), 1.0f};
            const Colour _700{uint8(104), uint8(159), uint8(56), 1.0f};
            const Colour _600{uint8(124), uint8(179), uint8(66), 1.0f};
            const Colour _500{uint8(139), uint8(195), uint8(74), 1.0f};
            const Colour _400{uint8(156), uint8(204), uint8(101), 1.0f};
            const Colour _300{uint8(174), uint8(213), uint8(129), 1.0f};
            const Colour _200{uint8(197), uint8(225), uint8(165), 1.0f};
            const Colour _100{uint8(220), uint8(237), uint8(200), 1.0f};
            const Colour _050{uint8(241), uint8(248), uint8(233), 1.0f};
        }
        namespace Icons {
            namespace Black {
                const Colour Inactive{uint8(0), uint8(0), uint8(0), 0.54f};
                const Colour Disabled{uint8(0), uint8(0), uint8(0), 0.38f};
                const Colour Active{uint8(0), uint8(0), uint8(0), 0.87f};
            }
            namespace White {
                const Colour Inactive{uint8(255), uint8(255), uint8(255), 0.54f};
                const Colour Disabled{uint8(255), uint8(255), uint8(255), 0.38f};
                const Colour Active{uint8(255), uint8(255), uint8(255), 1.0f};
            }
            namespace Selected {
                namespace OnSurface {
                    const Colour Inactive{uint8(255), uint8(255), uint8(255), 0.54f};
                    const Colour Disabled{uint8(255), uint8(255), uint8(255), 0.38f};
                    const Colour Active{uint8(255), uint8(255), uint8(255), 1.0f};
                }
                namespace OnSecondary {
                    const Colour Inactive{uint8(0), uint8(0), uint8(0), 0.54f};
                    const Colour Disabled{uint8(0), uint8(0), uint8(0), 0.38f};
                    const Colour Active{uint8(0), uint8(0), uint8(0), 0.87f};
                }
                namespace OnPrimary {
                    const Colour Inactive{uint8(0), uint8(0), uint8(0), 0.54f};
                    const Colour Disabled{uint8(0), uint8(0), uint8(0), 0.38f};
                    const Colour Active{uint8(0), uint8(0), uint8(0), 0.87f};
                }
            }
            const Colour Error{uint8(176), uint8(0), uint8(32), 1.0f};
            const Colour PrimaryOrSecondary{uint8(139), uint8(195), uint8(74), 1.0f};
        }
    }
}
