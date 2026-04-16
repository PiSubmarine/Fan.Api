#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Fan/Api/IController.h"

namespace PiSubmarine::Fan::Api
{
    class IControllerMock : public IController
    {
    public:
        MOCK_METHOD((Error::Api::Result<void>), SetTargetSpeed, (NormalizedFraction targetSpeed), (override));
        MOCK_METHOD((Error::Api::Result<NormalizedFraction>), GetTargetSpeed, (), (const, override));
    };
}
