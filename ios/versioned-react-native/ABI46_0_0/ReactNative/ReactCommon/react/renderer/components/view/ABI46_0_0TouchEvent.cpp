/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ABI46_0_0TouchEvent.h"

namespace ABI46_0_0facebook {
namespace ABI46_0_0React {

#if ABI46_0_0RN_DEBUG_STRING_CONVERTIBLE

std::string getDebugName(TouchEvent const &touchEvent) {
  return "TouchEvent";
}

std::vector<DebugStringConvertibleObject> getDebugProps(
    TouchEvent const &touchEvent,
    DebugStringConvertibleOptions options) {
  return {
      {"touches", getDebugDescription(touchEvent.touches, options)},
      {"changedTouches",
       getDebugDescription(touchEvent.changedTouches, options)},
      {"targetTouches", getDebugDescription(touchEvent.targetTouches, options)},
  };
}

#endif

} // namespace ABI46_0_0React
} // namespace ABI46_0_0facebook
