# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include(FindPkgConfig)
  PKG_CHECK_MODULES(PC_OPENTXS_PROTO "libopentxs-proto")


  find_path(
      OPENTXS_PROTO_INCLUDE_DIRS
      NAMES opentxs-proto/Version.hpp
      HINTS ${PC_OPENTXS_PROTO_INCLUDE_DIRS}
  )


  find_library(
      OPENTXS_PROTO_LIBRARIES
      NAMES libopentxs-proto.so libopentxs-proto.dylib libopentxs-proto.a
      HINTS ${PC_OPENTXS_PROTO_LIBRARY_DIRS}
  )


  include(FindPackageHandleStandardArgs)
  FIND_PACKAGE_HANDLE_STANDARD_ARGS(OPENTXS_PROTO DEFAULT_MSG OPENTXS_PROTO_LIBRARIES OPENTXS_PROTO_INCLUDE_DIRS)
  mark_as_advanced(OPENTXS_PROTO_LIBRARIES OPENTXS_PROTO_INCLUDE_DIRS)
