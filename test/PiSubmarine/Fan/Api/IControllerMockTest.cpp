#include <gtest/gtest.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Fan/Api/IControllerMock.h"

namespace PiSubmarine::Fan::Api
{
    TEST(IControllerMockTest, SetTargetSpeedReturnsConfiguredSuccess)
    {
        IControllerMock controllerMock;
        constexpr auto targetSpeed = NormalizedFraction(0.60);

        EXPECT_CALL(controllerMock, SetTargetSpeed(targetSpeed))
            .WillOnce(testing::Return(Error::Api::Result<void>{}));

        const auto result = controllerMock.SetTargetSpeed(targetSpeed);

        EXPECT_TRUE(result.has_value());
    }

    TEST(IControllerMockTest, GetTargetSpeedReturnsConfiguredValue)
    {
        const auto configuredTargetSpeed = NormalizedFraction(0.40);
        IControllerMock controllerMock;

        EXPECT_CALL(controllerMock, GetTargetSpeed())
            .WillOnce(testing::Return(Error::Api::Result<NormalizedFraction>(configuredTargetSpeed)));

        const auto result = controllerMock.GetTargetSpeed();

        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(result.value(), configuredTargetSpeed);
    }
}
