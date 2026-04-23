/*
 * Copyright (c) 2026 BayLibre SAS
 * SPDX-License-Identifier: Apache-2.0
 *
 * Prelude header force-included into every XNNPACK source file when
 * building for Zephyr.
 *
 * Zephyr's <zephyr/sys/util.h> defines a function-like macro named
 * "clamp" in the global namespace (since commit 37717b229f5, Sept 2025,
 * which renamed Z_CLAMP -> clamp). XNNPACK uses "clamp" as an identifier
 * for a file-local static helper function (src/operators/fully-
 * connected-nc.c:45), which causes the macro to expand over the
 * function definition and break the build.
 *
 * By including util.h here and immediately undef'ing clamp, the
 * include guard on util.h prevents any later transitive include from
 * re-defining the macro, and XNNPACK's clamp() function compiles
 * cleanly.
 *
 * Only clamp is undef'd; min/max are left alone since they have C++
 * guards upstream and currently do not collide with XNNPACK's C code.
 */

#ifdef __ZEPHYR__
#include <zephyr/sys/util.h>
#undef clamp
#endif
