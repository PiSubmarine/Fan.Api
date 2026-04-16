#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::Fan::Api
{
    class IController
    {
    public:
        virtual ~IController() = default;

        [[nodiscard]] virtual Error::Api::Result<void> SetTargetSpeed(NormalizedFraction targetSpeed) = 0;
        [[nodiscard]] virtual Error::Api::Result<NormalizedFraction> GetTargetSpeed() const = 0;
    };
}
