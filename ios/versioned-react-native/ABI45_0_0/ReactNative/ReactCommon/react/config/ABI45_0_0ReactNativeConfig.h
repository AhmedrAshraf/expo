/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <string>

namespace ABI45_0_0facebook {
namespace ABI45_0_0React {

/**
 * ABI45_0_0ReactNative configuration as provided by the hosting app.
 * Provide a sub-class implementation to allow app specific customization.
 */
class ABI45_0_0ReactNativeConfig {
 public:
  ABI45_0_0ReactNativeConfig();
  virtual ~ABI45_0_0ReactNativeConfig();

  virtual bool getBool(const std::string &param) const = 0;
  virtual std::string getString(const std::string &param) const = 0;
  virtual int64_t getInt64(const std::string &param) const = 0;
  virtual double getDouble(const std::string &param) const = 0;
};

/**
 * Empty configuration that will always provide "falsy" values.
 */
class EmptyABI45_0_0ReactNativeConfig : public ABI45_0_0ReactNativeConfig {
 public:
  EmptyABI45_0_0ReactNativeConfig();

  bool getBool(const std::string &param) const override;
  std::string getString(const std::string &param) const override;
  int64_t getInt64(const std::string &param) const override;
  double getDouble(const std::string &param) const override;
};

} // namespace ABI45_0_0React
} // namespace ABI45_0_0facebook
